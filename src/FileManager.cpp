#include "FileManager.h"

#include "DocumentInfo.h"
#include "Document.h"
#include "Project.h"
#include "EncodingDetector.h"
#include "ApplicationManager.h"
#include "Settings.h"

#include <QtAlgorithms>
#include <QFileInfo>
#include <QTextCodec>
#include <QFile>
#include <QDir>

#include <QDebug>

FileManager::FileManager() : m_documents(), m_documentMap(), m_activeDocument(0),
                             m_projects(), m_projectMap(), m_activeProject(0)
{
    qDebug() << "FileManager: Initialized instance";
}

FileManager::~FileManager()
{
//    qDeleteAll(m_documents);
}

QString FileManager::cleanPath(const QString& path) {
    //This is nice even for files
    #ifdef Q_OS_WIN
    return QDir(path).absolutePath().toLower();
    #else
    return QDir(path).absolutePath();
    #endif
}
QStringList FileManager::absoluteSplittedPath(const QString& path) {
    //All separators are already normalized to '/'
    return cleanPath(path).split("/",QString::SkipEmptyParts);
}

///Regarding Documents

Document* FileManager::newDocument() {
    const QString filenameScheme = QObject::tr("New File %0");
    static int counter = 0;

    QString filename;
    bool findNewFilename = false;
    do {
        filename = filenameScheme.arg(++counter);
        foreach(Document* d, m_documents) {
            if(d->documentInfo()->fileName() == filename) {
                findNewFilename = true;
                break;
            }
        }
    }while(findNewFilename);

    QTextCodec* codec = ApplicationManager::settings()->defaultEncoding();
    DocumentInfo docinfo(filename,codec->name(),0);

    Document* doc = new Document(docinfo, QString());

    m_documents.append(doc);
    m_documentMap.insert(filename, doc);

    emit documentOpened(doc);
    return doc;
}

Document* FileManager::openDocument(const QString& filename, QString* error) {
    QFileInfo fi(filename);
    QFile file(filename);

    if (!(fi.exists() && fi.isFile())){
        if(error)
            *error = tr("The file <br>\"%0\" <br>does not "
                        "exist or is no file.")
                        .arg(fi.absolutePath());
        return 0;
    }

    if (!file.open(QIODevice::ReadOnly|QIODevice::Text)){
        if(error)
            *error = tr("Unable to open the file<br>\"%0\" <br>"
                        "Check permissions or wether other programs "
                        "are locking the file.")
                        .arg(fi.absolutePath());
        return 0;
    }

    QByteArray contents = file.readAll();
    EncodingDetector detector(contents);
    QTextCodec* codec = detector.GetFontEncoding();//TODO:Delete?
    DocumentInfo docinfo(cleanPath(filename),codec->name(),fi.size());

    Document* doc = new Document(docinfo, codec->toUnicode(contents));
    file.close();

    m_documents.append(doc);
    m_documentMap.insert(cleanPath(filename), doc);

    emit documentOpened(doc);
    return doc;
}

bool FileManager::saveDocument(Document* doc, const QString& filename, QString* error) {
//    QFileInfo fi(filename);//doc->documentInfo()->absoluteFilePath());
    QString path = cleanPath(filename);
    QFile file(path);
    if(!file.open(QIODevice::WriteOnly|QIODevice::Text)){
        if(error)
            *error = tr("Unable to open <br>\"%0\" <br>for writing.")
                        .arg(path);
        return false;
    }
    QTextCodec* codec = QTextCodec::codecForName(doc->documentInfo()->encodingName().toAscii());//TODO:Delete?
    if(-1 == file.write(codec->fromUnicode(doc->text()))){
        if(error)
            *error = tr("Writing to <br>\"%0\" <br>failed.")
                        .arg(path);
        return false;
    }
    file.close();
    doc->documentInfo()->setAbsoluteFilePath(path);
    return true;
}

void FileManager::closeDocument(Document* document) {
    emit aboutToCloseDocument(document);
    m_documentMap.remove(document->documentInfo()->absoluteFilePath());
   m_documents.removeAll(document);
//     m_documents.removeOne(document);
    if(m_activeDocument == document) {
        m_activeDocument = 0;
        emit activeDocumentChanged(m_activeDocument);
    }
    Q_ASSERT(!m_documents.contains(document));
    delete document;
}

bool FileManager::isDocumentOpen(const QString& path) const {
    return m_documentMap.contains(cleanPath(path));
}

const QList<Document*>& FileManager::documents() const {
    return m_documents;
}

Document* FileManager::activeDocument() const {
    return m_activeDocument;
}
void FileManager::activateDocument(Document* document) {
    qDebug() << "FileManager::activateDocument(Document* document)";
//    filename = cleanPath(filename);
//    if(!m_documentMap.contains(filename))
//        return false;
    m_activeDocument = document;//m_documentMap.value(filename);
    emit activeDocumentChanged(m_activeDocument);
//    return true;
}

///Regarding Projects
Project* FileManager::newProject(const QString& name, const QString& rootPath, QString* error) {
    QString filename = cleanPath(name + "/" + rootPath);
    QFile file(filename);
    if(m_documentMap.contains(filename) || m_projectMap.contains(filename)) {
        if(error)
            *error = tr("A file with the name <br>\"%0\" <br>is already open.").arg(filename);
        return 0;
    }
    if(!file.open(QIODevice::Truncate|QIODevice::WriteOnly|QIODevice::Text)) {
        if(error)
            *error = tr("Unable to open the file <br>\"%0\"").arg(filename);
        return 0;
    }
    Project* project = new Project(name, rootPath);
    if(!project->isValid()) {
        delete project;
        if(error)
            *error = tr("Invalid project parameters.");
    }
    project->setFilename(filename);
    project->toXml(&file);
    file.close();
    m_projects.append(project);
    m_projectMap.insert(filename, project);
    emit projectOpened(project);
    return project;
}
Project* FileManager::openProject(QString filename, QString* error) {
    filename = cleanPath(filename);
    QFileInfo fi(filename);
    QFile file(filename);

    if(!fi.exists()) {
        if(error)
            *error = tr("The file \"%0\"<br>does not exist.").arg(filename);
        return 0;
    }
    if(!fi.isFile()) {
        if(error)
            *error = tr("\"%0\"<br>is not a file.").arg(filename);
        return 0;
    }
    if(m_documentMap.contains(filename) || m_projectMap.contains(filename)) {
        if(error)
            *error = tr("A file with the name <br>\"%0\" <br>is already open.").arg(filename);
        return 0;
    }
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text)) {
        if(error)
            *error = tr("Unable to open the file <br>\"%0\".").arg(filename);
        return 0;
    }
    Project* project = Project::fromXml(&file,cleanPath(fi.absolutePath()));
    file.close();
    if(!project) {
        if(error)
            *error = tr("Unable to read the project file <br>\"%0\".").arg(filename);
        return 0;
    }
    if(!project->isValid()) {
        delete project;
        if(error)
            *error = tr("Invalid project.");
    }
    project->setFilename(filename);
    m_projects.append(project);
    m_projectMap.insert(filename, project);
    emit projectOpened(project);
    return project;
}

bool FileManager::saveProject(Project* project, QString filename, QString* error) {
    Q_ASSERT(project);

    //Prepare file
    filename = cleanPath(filename);
    QFile file(filename);
    if(!file.open(QIODevice::WriteOnly|QIODevice::Text)) {
        if(error)
            *error = tr("Unable to open the file <br>\"%0\".").arg(filename);
        return false;
    }

    //Save project
    project->toXml(&file);
    file.close();

    //Store new filename
    if(filename != project->filename()) {
        project->setFilename(filename);
        m_projectMap.remove(project->filename());
        m_projectMap.insert(filename, project);
    }
    return true;
}

void FileManager::closeProject(Project* project) {
    emit aboutToCloseProject(project);
    m_projectMap.remove(project->filename());
   m_projects.removeAll(project);
//     m_projects.removeOne(project);
    if(m_activeProject == project) {
        m_activeProject = 0;
        emit activeProjectChanged(m_activeProject);
    }
    Q_ASSERT(!m_projects.contains(project));
    delete project;
}

bool FileManager::isProjectOpen(const QString& path) const {
    return m_projectMap.contains(cleanPath(path));
}

const QList<Project*>& FileManager::projects() const {
    return m_projects;
}

int FileManager::indexOfProject(const Project* project) const {
    return m_projects.indexOf(const_cast<Project*>(project));//TODO:This ain't nice!
}

int FileManager::projectCount() const {
    return m_projects.count();
}

Project* FileManager::activeProject() const {
    return m_activeProject;
}
void FileManager::activateProject(Project* project) {
    qDebug() << "FileManager::activateProject(Project* project)";
//    filename = cleanPath(filename);
//    if(!m_projectMap.contains(filename))
//        return false;
    m_activeProject = project;//m_projectMap.value(filename);
    emit activeProjectChanged(m_activeProject);
}
