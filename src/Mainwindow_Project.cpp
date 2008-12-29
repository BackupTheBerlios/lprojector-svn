
#include "Mainwindow.h"
#include "ApplicationManager.h"
#include "FileManager.h"
#include "Project.h"
#include "Logger.h"
#include "Document.h"

#include <QFile>
#include <QFileDialog>
#include <QDebug>

void Mainwindow::projectNew() {
//    Project* p = new Project("Testprojekt", "D:\\test\\");
////    Project* p = new Project("Testprojekt", "D:\\programmierung\\");
//    p->addFile("D:\\programmierung\\aktuell\\LWE\\LWE\\debug\\DocumentIO.o");
//    p->addFile("D:\\programmierung\\aktuell\\LWE\\LWE\\debug\\test.exe");
//    p->addFile("D:\\programmierung\\aktuell\\LWE\\LWE\\debug\\ulk");
//    p->addFile("D:\\programmierung\\aktuell\\LWE\\LWE");
//    p->addFile("D:\\programmierung\\aktuell\\LWE\\LWE\\release\\Highlighter.o");
////    p->addFile("D:\\programmierung");
//    syslog.send("Mainwindow: New Project created.",Logger::Informative);
//    m_projects << p;

//    QFile file("test/test.proj");
//    if(!file.open(QIODevice::ReadOnly)) {
//        qDebug() << "Unable to open project file";
//        return;
//    }
//    Project* p = Project::fromXml(&file, ".");
//    file.close();
//    if(p != 0)
//        m_projects << p;
//    Q_ASSERT(p != 0);
    QString error;
    Project* p;
    p = ApplicationManager::fileManager()->newProject(
        "D:\\programmierung\\aktuell\\LWE\\LWE\\test","test2.proj",&error);
    if(!p){
        syslog.send(error,Logger::Warning);
        return;
    }
    ApplicationManager::fileManager()->activateProject(p);
    syslog.send(tr("Created new project."),Logger::Medium);
}
void Mainwindow::projectOpen() {

    // Asking for a filename
    QString filename = QFileDialog::getOpenFileName(this, tr("Open Project"),
                            "", tr("LWE Project (*.proj *.lwe)"));
    if(filename.isEmpty())
        return;
    QString error;
    Project* p;
    p = ApplicationManager::fileManager()->openProject(filename,&error);
    if(!p){
        syslog.send(error,Logger::Warning);
        return;
    }
    ApplicationManager::fileManager()->activateProject(p);
    syslog.send(tr("Project successfully opened."),Logger::Medium);
}

void Mainwindow::projectSaveAs() {
    qDebug() << "Mainwindow::projectSaveAs() is not yet implemented!";
    Project* project = ApplicationManager::fileManager()->activeProject();
    if(!project)
        return;
    QString path = QFileDialog::getSaveFileName(this,tr("Save Project"),project->filename());
    if(path.isEmpty())
        return;
    qDebug() << "Project save path: " << path;
    QString error;
    if(!ApplicationManager::fileManager()->saveProject(project, path, &error))
        syslog.send(error, Logger::Warning);
    else
        syslog.send(tr("File successfully saved."),Logger::Medium);
}

void Mainwindow::projectSave() {
    qDebug() << "Mainwindow::projectSave()";

    Project* project = ApplicationManager::fileManager()->activeProject();
    if(!project)
        return;
    if(!QFile::exists(project->filename()))
        return projectSaveAs();
    QString error;
    if(!ApplicationManager::fileManager()->saveProject(project,project->filename(),&error))
        syslog.send(error,Logger::Warning);
    syslog.send(tr("Project saved."),Logger::Medium);
}

void Mainwindow::projectClose() {
    qDebug() << "Mainwindow::projectClose() is not yet implemented!";
    Project* project = ApplicationManager::fileManager()->activeProject();
    if(!project)
        return;
    ApplicationManager::fileManager()->closeProject(project);
    syslog.send(tr("Project closed."),Logger::Medium);
}

void Mainwindow::projectAddCurrentFile() {
    Document* doc = ApplicationManager::fileManager()->activeDocument();
    Project* project = ApplicationManager::fileManager()->activeProject();
    if(doc && project) {
        QString f = doc->documentInfo()->absoluteFilePath();
        if(project->addFile(f))
            syslog.send(tr("Appended current file to project."),Logger::Medium);
        else
            syslog.send(tr("Unable to append the file to the project."),Logger::Warning);
    }
}
