/********************************************************************************
** Form generated from reading ui file 'Mainwindow.ui'
**
** Created: Mon Dec 29 19:49:24 2008
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Mainwindow
{
public:
    QAction *actionQuit;
    QAction *actionFileOpen;
    QAction *actionFileClose;
    QAction *actionFileSave;
    QAction *actionEditUndo;
    QAction *actionEditRedo;
    QAction *actionEditCut;
    QAction *actionEditCopy;
    QAction *actionEditPaste;
    QAction *actionEditSelect_All;
    QAction *actionEditComment;
    QAction *actionEditUncomment;
    QAction *actionEditToggle_Comment;
    QAction *actionEditFind;
    QAction *actionActionEditDelete;
    QAction *actionFind_in_Files;
    QAction *actionProjectOpen;
    QAction *actionProjectNew;
    QAction *actionProjectSave;
    QAction *actionProjectSave_As;
    QAction *actionProjectClose;
    QAction *actionFileSaveAs;
    QAction *actionFileNew;
    QAction *actionProjectAddFile;
    QAction *actionProjectAddCurrentFile;
    QAction *actionSettingsGeneral_Settings;
    QAction *actionHelpAbout;
    QAction *actionViewZoom_In;
    QAction *actionZoom_Out;
    QAction *actionViewDefault_Zoom;
    QAction *actionBuildBuild_Project;
    QAction *actionBuildCheck_File;
    QWidget *centralwidget;
    QVBoxLayout *vboxLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;
    QMenuBar *menubar;
    QMenu *menuProjekt;
    QMenu *menuDatei;
    QMenu *menuBearbeiten;
    QMenu *menuFenster;
    QMenu *menuZoom;
    QMenu *menuGeben_Sie_Text_ein;
    QMenu *menuNavigatoin;
    QMenu *menuBuild;
    QMenu *menuSelect_Target;
    QMenu *menuSettings;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Mainwindow)
    {
    if (Mainwindow->objectName().isEmpty())
        Mainwindow->setObjectName(QString::fromUtf8("Mainwindow"));
    Mainwindow->resize(713, 574);
    Mainwindow->setAcceptDrops(false);
    Mainwindow->setAutoFillBackground(false);
    Mainwindow->setDockNestingEnabled(true);
    Mainwindow->setDockOptions(QMainWindow::AllowNestedDocks|QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks|QMainWindow::ForceTabbedDocks);
    actionQuit = new QAction(Mainwindow);
    actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
    actionFileOpen = new QAction(Mainwindow);
    actionFileOpen->setObjectName(QString::fromUtf8("actionFileOpen"));
    actionFileClose = new QAction(Mainwindow);
    actionFileClose->setObjectName(QString::fromUtf8("actionFileClose"));
    actionFileSave = new QAction(Mainwindow);
    actionFileSave->setObjectName(QString::fromUtf8("actionFileSave"));
    actionEditUndo = new QAction(Mainwindow);
    actionEditUndo->setObjectName(QString::fromUtf8("actionEditUndo"));
    actionEditRedo = new QAction(Mainwindow);
    actionEditRedo->setObjectName(QString::fromUtf8("actionEditRedo"));
    actionEditCut = new QAction(Mainwindow);
    actionEditCut->setObjectName(QString::fromUtf8("actionEditCut"));
    actionEditCopy = new QAction(Mainwindow);
    actionEditCopy->setObjectName(QString::fromUtf8("actionEditCopy"));
    actionEditPaste = new QAction(Mainwindow);
    actionEditPaste->setObjectName(QString::fromUtf8("actionEditPaste"));
    actionEditSelect_All = new QAction(Mainwindow);
    actionEditSelect_All->setObjectName(QString::fromUtf8("actionEditSelect_All"));
    actionEditComment = new QAction(Mainwindow);
    actionEditComment->setObjectName(QString::fromUtf8("actionEditComment"));
    actionEditUncomment = new QAction(Mainwindow);
    actionEditUncomment->setObjectName(QString::fromUtf8("actionEditUncomment"));
    actionEditToggle_Comment = new QAction(Mainwindow);
    actionEditToggle_Comment->setObjectName(QString::fromUtf8("actionEditToggle_Comment"));
    actionEditFind = new QAction(Mainwindow);
    actionEditFind->setObjectName(QString::fromUtf8("actionEditFind"));
    actionActionEditDelete = new QAction(Mainwindow);
    actionActionEditDelete->setObjectName(QString::fromUtf8("actionActionEditDelete"));
    actionFind_in_Files = new QAction(Mainwindow);
    actionFind_in_Files->setObjectName(QString::fromUtf8("actionFind_in_Files"));
    actionProjectOpen = new QAction(Mainwindow);
    actionProjectOpen->setObjectName(QString::fromUtf8("actionProjectOpen"));
    actionProjectNew = new QAction(Mainwindow);
    actionProjectNew->setObjectName(QString::fromUtf8("actionProjectNew"));
    actionProjectSave = new QAction(Mainwindow);
    actionProjectSave->setObjectName(QString::fromUtf8("actionProjectSave"));
    actionProjectSave_As = new QAction(Mainwindow);
    actionProjectSave_As->setObjectName(QString::fromUtf8("actionProjectSave_As"));
    actionProjectClose = new QAction(Mainwindow);
    actionProjectClose->setObjectName(QString::fromUtf8("actionProjectClose"));
    actionFileSaveAs = new QAction(Mainwindow);
    actionFileSaveAs->setObjectName(QString::fromUtf8("actionFileSaveAs"));
    actionFileNew = new QAction(Mainwindow);
    actionFileNew->setObjectName(QString::fromUtf8("actionFileNew"));
    actionProjectAddFile = new QAction(Mainwindow);
    actionProjectAddFile->setObjectName(QString::fromUtf8("actionProjectAddFile"));
    actionProjectAddCurrentFile = new QAction(Mainwindow);
    actionProjectAddCurrentFile->setObjectName(QString::fromUtf8("actionProjectAddCurrentFile"));
    actionSettingsGeneral_Settings = new QAction(Mainwindow);
    actionSettingsGeneral_Settings->setObjectName(QString::fromUtf8("actionSettingsGeneral_Settings"));
    actionHelpAbout = new QAction(Mainwindow);
    actionHelpAbout->setObjectName(QString::fromUtf8("actionHelpAbout"));
    actionViewZoom_In = new QAction(Mainwindow);
    actionViewZoom_In->setObjectName(QString::fromUtf8("actionViewZoom_In"));
    actionZoom_Out = new QAction(Mainwindow);
    actionZoom_Out->setObjectName(QString::fromUtf8("actionZoom_Out"));
    actionViewDefault_Zoom = new QAction(Mainwindow);
    actionViewDefault_Zoom->setObjectName(QString::fromUtf8("actionViewDefault_Zoom"));
    actionBuildBuild_Project = new QAction(Mainwindow);
    actionBuildBuild_Project->setObjectName(QString::fromUtf8("actionBuildBuild_Project"));
    actionBuildCheck_File = new QAction(Mainwindow);
    actionBuildCheck_File->setObjectName(QString::fromUtf8("actionBuildCheck_File"));
    centralwidget = new QWidget(Mainwindow);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    vboxLayout = new QVBoxLayout(centralwidget);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    tabWidget = new QTabWidget(centralwidget);
    tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
    tabWidget->setTabShape(QTabWidget::Triangular);
    tabWidget->setUsesScrollButtons(true);
    tab = new QWidget();
    tab->setObjectName(QString::fromUtf8("tab"));
    tabWidget->addTab(tab, QString());
    tab_2 = new QWidget();
    tab_2->setObjectName(QString::fromUtf8("tab_2"));
    tabWidget->addTab(tab_2, QString());

    vboxLayout->addWidget(tabWidget);

    Mainwindow->setCentralWidget(centralwidget);
    menubar = new QMenuBar(Mainwindow);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setGeometry(QRect(0, 0, 713, 21));
    menuProjekt = new QMenu(menubar);
    menuProjekt->setObjectName(QString::fromUtf8("menuProjekt"));
    menuDatei = new QMenu(menubar);
    menuDatei->setObjectName(QString::fromUtf8("menuDatei"));
    menuBearbeiten = new QMenu(menubar);
    menuBearbeiten->setObjectName(QString::fromUtf8("menuBearbeiten"));
    menuFenster = new QMenu(menubar);
    menuFenster->setObjectName(QString::fromUtf8("menuFenster"));
    menuZoom = new QMenu(menuFenster);
    menuZoom->setObjectName(QString::fromUtf8("menuZoom"));
    menuGeben_Sie_Text_ein = new QMenu(menuFenster);
    menuGeben_Sie_Text_ein->setObjectName(QString::fromUtf8("menuGeben_Sie_Text_ein"));
    menuNavigatoin = new QMenu(menubar);
    menuNavigatoin->setObjectName(QString::fromUtf8("menuNavigatoin"));
    menuBuild = new QMenu(menubar);
    menuBuild->setObjectName(QString::fromUtf8("menuBuild"));
    menuSelect_Target = new QMenu(menuBuild);
    menuSelect_Target->setObjectName(QString::fromUtf8("menuSelect_Target"));
    menuSettings = new QMenu(menubar);
    menuSettings->setObjectName(QString::fromUtf8("menuSettings"));
    menuHelp = new QMenu(menubar);
    menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
    Mainwindow->setMenuBar(menubar);
    statusbar = new QStatusBar(Mainwindow);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    Mainwindow->setStatusBar(statusbar);

    menubar->addAction(menuProjekt->menuAction());
    menubar->addAction(menuDatei->menuAction());
    menubar->addAction(menuBearbeiten->menuAction());
    menubar->addAction(menuFenster->menuAction());
    menubar->addAction(menuBuild->menuAction());
    menubar->addAction(menuNavigatoin->menuAction());
    menubar->addAction(menuSettings->menuAction());
    menubar->addAction(menuHelp->menuAction());
    menuProjekt->addAction(actionProjectNew);
    menuProjekt->addAction(actionProjectOpen);
    menuProjekt->addAction(actionProjectSave_As);
    menuProjekt->addAction(actionProjectSave);
    menuProjekt->addAction(actionProjectClose);
    menuProjekt->addSeparator();
    menuProjekt->addAction(actionProjectAddFile);
    menuProjekt->addAction(actionProjectAddCurrentFile);
    menuProjekt->addSeparator();
    menuProjekt->addAction(actionQuit);
    menuDatei->addAction(actionFileNew);
    menuDatei->addAction(actionFileOpen);
    menuDatei->addAction(actionFileSaveAs);
    menuDatei->addAction(actionFileSave);
    menuDatei->addAction(actionFileClose);
    menuDatei->addSeparator();
    menuBearbeiten->addAction(actionEditUndo);
    menuBearbeiten->addAction(actionEditRedo);
    menuBearbeiten->addSeparator();
    menuBearbeiten->addAction(actionEditCut);
    menuBearbeiten->addAction(actionEditCopy);
    menuBearbeiten->addAction(actionEditPaste);
    menuBearbeiten->addAction(actionActionEditDelete);
    menuBearbeiten->addSeparator();
    menuFenster->addAction(menuZoom->menuAction());
    menuFenster->addSeparator();
    menuFenster->addAction(menuGeben_Sie_Text_ein->menuAction());
    menuZoom->addAction(actionViewZoom_In);
    menuZoom->addAction(actionZoom_Out);
    menuZoom->addAction(actionViewDefault_Zoom);
    menuNavigatoin->addAction(actionEditFind);
    menuNavigatoin->addAction(actionFind_in_Files);
    menuBuild->addAction(actionBuildBuild_Project);
    menuBuild->addAction(actionBuildCheck_File);
    menuBuild->addAction(menuSelect_Target->menuAction());
    menuSelect_Target->addAction(actionZoom_Out);
    menuSettings->addAction(actionSettingsGeneral_Settings);
    menuHelp->addAction(actionHelpAbout);

    retranslateUi(Mainwindow);
    QObject::connect(actionQuit, SIGNAL(triggered()), Mainwindow, SLOT(close()));

    QMetaObject::connectSlotsByName(Mainwindow);
    } // setupUi

    void retranslateUi(QMainWindow *Mainwindow)
    {
    Mainwindow->setWindowTitle(QApplication::translate("Mainwindow", "MainWindow", 0, QApplication::UnicodeUTF8));
    actionQuit->setText(QApplication::translate("Mainwindow", "Quit", 0, QApplication::UnicodeUTF8));
    actionFileOpen->setText(QApplication::translate("Mainwindow", "Open...", 0, QApplication::UnicodeUTF8));
    actionFileClose->setText(QApplication::translate("Mainwindow", "Close", 0, QApplication::UnicodeUTF8));
    actionFileSave->setText(QApplication::translate("Mainwindow", "Save", 0, QApplication::UnicodeUTF8));
    actionEditUndo->setText(QApplication::translate("Mainwindow", "Undo", 0, QApplication::UnicodeUTF8));
    actionEditRedo->setText(QApplication::translate("Mainwindow", "Redo", 0, QApplication::UnicodeUTF8));
    actionEditCut->setText(QApplication::translate("Mainwindow", "Cut", 0, QApplication::UnicodeUTF8));
    actionEditCopy->setText(QApplication::translate("Mainwindow", "Copy", 0, QApplication::UnicodeUTF8));
    actionEditPaste->setText(QApplication::translate("Mainwindow", "Paste", 0, QApplication::UnicodeUTF8));
    actionEditSelect_All->setText(QApplication::translate("Mainwindow", "Select All", 0, QApplication::UnicodeUTF8));
    actionEditComment->setText(QApplication::translate("Mainwindow", "Comment", 0, QApplication::UnicodeUTF8));
    actionEditUncomment->setText(QApplication::translate("Mainwindow", "Uncomment", 0, QApplication::UnicodeUTF8));
    actionEditToggle_Comment->setText(QApplication::translate("Mainwindow", "Toggle Comment", 0, QApplication::UnicodeUTF8));
    actionEditFind->setText(QApplication::translate("Mainwindow", "Find", 0, QApplication::UnicodeUTF8));
    actionActionEditDelete->setText(QApplication::translate("Mainwindow", "Delete", 0, QApplication::UnicodeUTF8));
    actionFind_in_Files->setText(QApplication::translate("Mainwindow", "Find in Files...", 0, QApplication::UnicodeUTF8));
    actionProjectOpen->setText(QApplication::translate("Mainwindow", "Open...", 0, QApplication::UnicodeUTF8));
    actionProjectNew->setText(QApplication::translate("Mainwindow", "New", 0, QApplication::UnicodeUTF8));
    actionProjectSave->setText(QApplication::translate("Mainwindow", "Save", 0, QApplication::UnicodeUTF8));
    actionProjectSave_As->setText(QApplication::translate("Mainwindow", "Save As...", 0, QApplication::UnicodeUTF8));
    actionProjectClose->setText(QApplication::translate("Mainwindow", "Close", 0, QApplication::UnicodeUTF8));
    actionFileSaveAs->setText(QApplication::translate("Mainwindow", "Save As...", 0, QApplication::UnicodeUTF8));
    actionFileNew->setText(QApplication::translate("Mainwindow", "New", 0, QApplication::UnicodeUTF8));
    actionProjectAddFile->setText(QApplication::translate("Mainwindow", "Add File...", 0, QApplication::UnicodeUTF8));
    actionProjectAddCurrentFile->setText(QApplication::translate("Mainwindow", "Add Current File", 0, QApplication::UnicodeUTF8));
    actionSettingsGeneral_Settings->setText(QApplication::translate("Mainwindow", "General Settings...", 0, QApplication::UnicodeUTF8));
    actionHelpAbout->setText(QApplication::translate("Mainwindow", "About...", 0, QApplication::UnicodeUTF8));
    actionViewZoom_In->setText(QApplication::translate("Mainwindow", "Zoom In", 0, QApplication::UnicodeUTF8));
    actionZoom_Out->setText(QApplication::translate("Mainwindow", "Zoom Out", 0, QApplication::UnicodeUTF8));
    actionViewDefault_Zoom->setText(QApplication::translate("Mainwindow", "Default Zoom", 0, QApplication::UnicodeUTF8));
    actionBuildBuild_Project->setText(QApplication::translate("Mainwindow", "Build Project", 0, QApplication::UnicodeUTF8));
    actionBuildCheck_File->setText(QApplication::translate("Mainwindow", "Check File", 0, QApplication::UnicodeUTF8));
    tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Mainwindow", "Tab 1", 0, QApplication::UnicodeUTF8));
    tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Mainwindow", "Tab 2", 0, QApplication::UnicodeUTF8));
    menuProjekt->setTitle(QApplication::translate("Mainwindow", "Project", 0, QApplication::UnicodeUTF8));
    menuDatei->setTitle(QApplication::translate("Mainwindow", "File", 0, QApplication::UnicodeUTF8));
    menuBearbeiten->setTitle(QApplication::translate("Mainwindow", "Edit", 0, QApplication::UnicodeUTF8));
    menuFenster->setTitle(QApplication::translate("Mainwindow", "View", 0, QApplication::UnicodeUTF8));
    menuZoom->setTitle(QApplication::translate("Mainwindow", "Zoom", 0, QApplication::UnicodeUTF8));
    menuGeben_Sie_Text_ein->setTitle(QApplication::translate("Mainwindow", "Geben Sie Text ein", 0, QApplication::UnicodeUTF8));
    menuNavigatoin->setTitle(QApplication::translate("Mainwindow", "Navigation", 0, QApplication::UnicodeUTF8));
    menuBuild->setTitle(QApplication::translate("Mainwindow", "Build", 0, QApplication::UnicodeUTF8));
    menuSelect_Target->setTitle(QApplication::translate("Mainwindow", "Select Target", 0, QApplication::UnicodeUTF8));
    menuSettings->setTitle(QApplication::translate("Mainwindow", "Settings", 0, QApplication::UnicodeUTF8));
    menuHelp->setTitle(QApplication::translate("Mainwindow", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Mainwindow: public Ui_Mainwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
