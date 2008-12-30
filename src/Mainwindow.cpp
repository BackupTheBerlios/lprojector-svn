
#include "Mainwindow.h"

#include "Logger.h"
#include "Document.h"
#include "DocumentInfo.h"
#include "DocStatusWidget.h"
#include "Project.h"
#include "ProjectItem.h"
#include "ProjectModel.h"

#include "ApplicationManager.h"
#include "FileManager.h"

#include <QMainWindow>
#include <QString>
#include <QtAlgorithms>

#include <QTreeView>
#include <QTableView>//TODO:REMOVE
#include <QDockWidget>
#include <QDebug>

Mainwindow::Mainwindow(QWidget* parent) : QMainWindow(parent) {
    setupUi(this);
    tabWidget->clear();

    m_docStatusWidget = new DocStatusWidget();
    statusBar()->addPermanentWidget(m_docStatusWidget);

//    projectNew();
////    projectSave();

    ProjectModel* model = new ProjectModel(this);

    QTreeView* view = new QTreeView(this);
    view->setModel(model);
    QDockWidget* dock = new QDockWidget(this);
    dock->setWidget(view);
    addDockWidget(Qt::LeftDockWidgetArea, dock);
//     connect(ApplicationManager::fileManager(),SIGNAL(projectOpened(Project*)),view,SLOT(reset()));
    connect(ApplicationManager::fileManager(),SIGNAL(activeProjectChanged(Project*)),view,SLOT(reset()));

    setupActions();
    updateActionStates();

    qDebug() << "Initialized Mainwindow instance";
}
Mainwindow::~Mainwindow() {
    delete m_docStatusWidget;
//    qDeleteAll(m_projects);
}

void Mainwindow::setupActions() {
    // Project Menu
    connect(actionProjectNew,SIGNAL(triggered(bool)), this, SLOT(projectNew()));
    connect(actionProjectOpen,SIGNAL(triggered(bool)), this, SLOT(projectOpen()));
   connect(actionProjectSaveAs,SIGNAL(triggered(bool)), this, SLOT(projectSaveAs()));
    connect(actionProjectSave,SIGNAL(triggered(bool)), this, SLOT(projectSave()));
   connect(actionProjectClose,SIGNAL(triggered(bool)), this, SLOT(projectClose()));
   connect(actionProjectAddFile,SIGNAL(triggered(bool)), this, SLOT(projectAddFile()));
    connect(actionProjectAddCurrentFile,SIGNAL(triggered(bool)), this, SLOT(projectAddCurrentFile()));
    // File Menu
    connect(actionFileNew,SIGNAL(triggered(bool)), this, SLOT(fileNew()));
    connect(actionFileOpen,SIGNAL(triggered(bool)), this, SLOT(fileOpen()));
    connect(actionFileSaveAs,SIGNAL(triggered(bool)), this, SLOT(fileSaveAs()));
    connect(actionFileSave,SIGNAL(triggered(bool)), this, SLOT(fileSave()));
    connect(actionFileClose,SIGNAL(triggered(bool)), this, SLOT(fileClose()));
    // Messages
    connect(&syslog,SIGNAL(notify(const QString&)),
        this, SLOT(showTempStatus(const QString&)));

//    connect(this->tabWidget,SIGNAL(currentChanged(int)),this,SIGNAL(documentSwitched()));
//    connect(this,SIGNAL(documentSwitched()),this,SLOT(onDocumentSwitched()));

    // List of Actions which are only available for changed Documents
    m_changedDocumentActions.append(actionFileSave);
}
void Mainwindow::updateActionStates() {
    Document* doc = static_cast<Document*>(tabWidget->currentWidget());
    bool enabled = doc ? doc->documentInfo()->isModified() : false;
    if((!m_changedDocumentActions.empty()) &&
       m_changedDocumentActions[0]->isEnabled() != enabled) {
        //Set Actions to the right state
        foreach(QAction* action, m_changedDocumentActions) {
            action->setEnabled(enabled);
        }
    }
}

void Mainwindow::showTempStatus(const QString& message) {
    statusBar()->showMessage(message,3000);
}

//void Mainwindow::updateStatsAndActions() {
//    syslog.send("Mainwindow::updateStatsAndActions()",Logger::Informative);
//    Document* doc = static_cast<Document*>(tabWidget->currentWidget());
//    bool enabled;
//    if(doc) {
//        // Update Statistics in status Bar
//        docStatusLabel_->setDocument(doc);
//        enabled = doc->documentInfo()->isModified();
//    }
//    else {
//        enabled = false;
//    }
//    //Set Actions to the right state
//    foreach(QAction* action, m_changedDocumentActions) {
//        action->setEnabled(enabled);
//    }
//}
//void Mainwindow::onTextChanged() {
//    //Just for testing
//    Q_ASSERT(tabWidget->currentWidget() == ApplicationManager::fileManager()->activeDocument());
//    updateActionStates();
//}
void Mainwindow::onTabWidgetCurrentChanged() {
    qDebug() << "Mainwindow::onTabWidgetCurrentChanged()";

    Document* doc = static_cast<Document*>(tabWidget->currentWidget());
    ApplicationManager::fileManager()->activateDocument(doc);
}
//void Mainwindow::onDocumentSwitched() {
//    qDebug() << "onDocumentSwitched()";
//    disconnect(this, SLOT(onTextChanged()));
//    Document* doc = static_cast<Document*>(tabWidget->currentWidget());
//    m_docStatusWidget->setDocument(doc); //Even if doc == 0
//    if(doc)
//        connect(doc, SIGNAL(textChanged()), this, SLOT(onTextChanged()));
//    updateActionStates();
//    ApplicationManager::fileManager()->activateDocument(doc);
//}
