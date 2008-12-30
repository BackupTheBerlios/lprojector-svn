
#include "Mainwindow.h"
#include "ApplicationManager.h"
#include "FileManager.h"
#include "Project.h"
#include "Logger.h"
#include "Document.h"

#include <QFile>
#include <QFileInfo>
#include <QFileDialog>
#include <QDebug>

void Mainwindow::projectNew() {
    qDebug() << "Mainwindow::projectNew()";
    
    //Assert valid filename
    QString path = QFileDialog::getSaveFileName(this,tr("Choose new a project's filename"), 
                                                QString(), tr("LP Project (*.lproj)"));
    if(path.isEmpty())
        return;
    QFileInfo fi(path);
    if(!fi.dir().exists())
        return;
    //Try to create project
    QString error;
    Project* p;
    p = ApplicationManager::fileManager()->newProject(fi.fileName(), fi.absolutePath(), &error);
    if(!p){
        syslog.send(error,Logger::Warning);
        return;
    }
    //Save project file
    if(!ApplicationManager::fileManager()->saveProject(p, &error)){
        ApplicationManager::fileManager()->closeProject(p);
        syslog.send(error,Logger::Warning);
        return;
    }
    //Make the new project active and return
    ApplicationManager::fileManager()->activateProject(p);
    syslog.send(tr("Created new project."),Logger::Medium);
}
void Mainwindow::projectOpen() {
    qDebug() << "Mainwindow::projectOpen()";
    
    //Asking for a filename
    QString filename = QFileDialog::getOpenFileName(this, tr("Open Project"),
                            "", tr("LP Project (*.lproj)"));
    if(filename.isEmpty())
        return;
    //Open project
    QString error;
    Project* p;
    p = ApplicationManager::fileManager()->openProject(filename,&error);
    if(!p){
        syslog.send(error,Logger::Warning);
        return;
    }
    //Make the opened project active and return
    ApplicationManager::fileManager()->activateProject(p);
    syslog.send(tr("Project successfully opened."),Logger::Medium);
}

void Mainwindow::projectSaveAs() {
    qDebug() << "Mainwindow::projectSaveAs() is not yet implemented!";
    
    //Get current project
    Project* project = ApplicationManager::fileManager()->activeProject();
    if(!project)
        return;
        
    //Get valid filename
    QString path = QFileDialog::getSaveFileName(this,tr("Save Project"),project->name(),
                                                tr("LP Project (*.lproj)"));
    if(path.isEmpty())
        return;
    QFileInfo fi(path);
    if(!fi.dir().exists())
        return;
        
    //Save project file
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
    qDebug() << "Mainwindow::projectClose()";
    
    Project* project = ApplicationManager::fileManager()->activeProject();
    if(!project)
        return;
    //TODO: Add confirmation and saving
    ApplicationManager::fileManager()->closeProject(project);
    syslog.send(tr("Project closed."),Logger::Medium);
}

void Mainwindow::projectAddFile() {
    qDebug() << "Mainwindow::projectAddFile()";
    
    //TODO: Implements
}

void Mainwindow::projectAddCurrentFile() {
    qDebug() << "Mainwindow::projectAddCurrentFile()";
    
    Document* doc = ApplicationManager::fileManager()->activeDocument();
    Project* project = ApplicationManager::fileManager()->activeProject();
    if(doc && project) {
        QString f = doc->documentInfo()->absoluteFilePath();
        if(project->addFile(f))
            syslog.send(tr("Appended current file to project."),Logger::Medium);
        else
            syslog.send(tr("Unable to append the file to the project."),Logger::Warning);
    }
    else if(!doc){
        syslog.send(tr("No active document."),Logger::Warning);
    }
    else if(!project){
        syslog.send(tr("No active project."),Logger::Warning);
    }
}
