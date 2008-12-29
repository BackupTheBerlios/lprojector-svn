

#include "Mainwindow.h"
#include "Document.h"
#include "ApplicationManager.h"
#include "FileManager.h"
#include "Logger.h"

#include <QFileDialog>
#include <QDebug>

void Mainwindow::fileNew() {
    Document* doc = ApplicationManager::fileManager()->newDocument();
    int i = tabWidget->addTab(doc, doc->documentInfo()->fileName());
    tabWidget->setTabToolTip(i, doc->documentInfo()->absoluteFilePath());
    tabWidget->setCurrentIndex(i);
    ApplicationManager::fileManager()->activateDocument(doc);
    syslog.send(tr("Datei erfolgreich erstellt."),Logger::Medium);
//    emit documentSwitched();
//    updateStatsAndActions();
}

void Mainwindow::fileOpen() {

    // Asking for filenames
    QStringList files = QFileDialog::getOpenFileNames(this);
    if(files.isEmpty())
        return;
    // Opening files
    QString error;
    Document* doc = 0;
    foreach(QString filename, files) {
        doc = ApplicationManager::fileManager()->openDocument(filename,&error);
        if(!doc) {
            syslog.send(error,Logger::Warning);
            return;
        }
        int i = tabWidget->addTab(doc, doc->documentInfo()->fileName());
        tabWidget->setTabToolTip(i, doc->documentInfo()->absoluteFilePath());
        tabWidget->setCurrentIndex(i);
        syslog.send(tr("File successfully loaded."),Logger::Medium);
    }
    if(doc)
        ApplicationManager::fileManager()->activateDocument(doc);
//    emit documentSwitched();
}

void Mainwindow::fileSaveAs() {
    Document* doc = static_cast<Document*>(tabWidget->currentWidget());
    if(!doc)
        return;
    QString path = QFileDialog::getSaveFileName(this,tr("Save File"),doc->documentInfo()->absoluteFilePath());
    if(path.isEmpty())
        return;
    qDebug() << "Save file path: " <<path;
    QString error;
    if(!ApplicationManager::fileManager()->saveDocument(doc, path,&error))
        syslog.send(error,Logger::Warning);
//        syslog.send(tr("File couldn't be saved."),Logger::Warning);
    else
        syslog.send(tr("File successfully saved."),Logger::Medium);
//    updateStatsAndActions();
    updateActionStates();
}

void Mainwindow::fileSave() {
    Document* doc = static_cast<Document*>(tabWidget->currentWidget());
    if(!doc)
        return;
    QString path = doc->documentInfo()->absoluteFilePath();
    if(!QFileInfo(path).exists())
        return fileSaveAs();
    qDebug() << "Save file path: " <<path;
    QString error;
    if(!ApplicationManager::fileManager()->saveDocument(doc, path, &error))
        syslog.send(error, Logger::Warning);
//        syslog.send(tr("File couldn't be saved."),Logger::Warning);
    else
        syslog.send(tr("File successfully saved."),Logger::Medium);
//    updateStatsAndActions();
    updateActionStates();
}

void Mainwindow::fileClose() {
    //Closing doc
    Document* doc = static_cast<Document*>(tabWidget->currentWidget());
    tabWidget->removeTab(tabWidget->currentIndex());
    ApplicationManager::fileManager()->closeDocument(doc);
    //Activating new one
    doc = static_cast<Document*>(tabWidget->currentWidget());
    if(doc)
        ApplicationManager::fileManager()->activateDocument(doc);
//    emit documentSwitched();
}
