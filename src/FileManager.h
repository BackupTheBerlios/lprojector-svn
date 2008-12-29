
#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QList>
#include <QHash>
#include <QObject>

class Document;
class Project;

class FileManager : public QObject {

    Q_OBJECT

    public:
        FileManager();
        ~FileManager();

        static QString cleanPath(const QString& filename);
        static QStringList absoluteSplittedPath(const QString& path);
        static QStringList relativeSplittedPath(const QString& basepath, const QString& path);

    ///Regarding Documents
    public:
        Document* newDocument();
        Document* openDocument(const QString& filename, QString* error=0);
        bool saveDocument(Document* document, const QString& filename, QString* error=0);
        void closeDocument(Document* document);
        bool isDocumentOpen(const QString& filename) const;
        const QList<Document*>& documents() const;
        const int fileCount() const {return m_documents.count();}
        Document* activeDocument() const;
        void activateDocument(Document* document);
    signals:
        void aboutToCloseDocument(Document* document);
        void documentOpened(Document* document);
        void activeDocumentChanged(Document* document);

    ///Regarding Projects
    public:
        Project* newProject(const QString& name, const QString& rootPath, QString* error=0);
        Project* openProject(QString filename, QString* error=0);
        bool saveProject(Project* project, QString filename, QString* error=0);
        void closeProject(Project* project);
        bool isProjectOpen(const QString& filename) const;
        const QList<Project*>& projects() const;
        int indexOfProject(const Project* project) const;
        int projectCount() const;
        Project* activeProject() const;
        void activateProject(Project* project);
    signals:
        void aboutToCloseProject(Project* project);
        void projectOpened(Project* project);
        void activeProjectChanged(Project* project);

    private:
        QString m_lastError;
        QList<Document*> m_documents;//List of Documents
        QHash<QString, Document*> m_documentMap;//Map from file path to docpointer
        Document* m_activeDocument;
        QList<Project*> m_projects;//List of Projects
        QHash<QString, Project*> m_projectMap;//Map from file path to projectpointer
        Project* m_activeProject;
};

#endif // FILEMANAGER_H
