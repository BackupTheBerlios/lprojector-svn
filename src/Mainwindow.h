#ifndef HAUPTFENSTER_H_INCLUDED
#define HAUPTFENSTER_H_INCLUDED

#include "Project.h"
#include "ui_Mainwindow.h"

#include <QMainWindow>
#include <QList>

class DocStatusWidget;
class QAction;

class Mainwindow : public QMainWindow, private Ui::Mainwindow {

    Q_OBJECT

    private:
        DocStatusWidget* m_docStatusWidget;
//        QList<Project*> m_projects;
        QList<QAction*> m_changedDocumentActions;

    public:
        Mainwindow(QWidget* parent);
        ~Mainwindow();
//        Project* getProject(const QString& name);
//        void addProject(Project* project);

    private:
        void setupActions();
        void updateActionStates();

    signals:
//        void documentSwitched();

    public slots:
        void fileNew();
        void fileOpen();
        void fileSaveAs();
        void fileSave();
        void fileClose();
        void showTempStatus(const QString& message);
//        void updateStatsAndActions();

        void projectNew();
        void projectOpen();
        void projectSaveAs();
        void projectSave();
        void projectClose();
        void projectAddFile();
        void projectAddCurrentFile();

    protected slots:
//        void onTextChanged();
        void onTabWidgetCurrentChanged();
//        void onDocumentSwitched();
};


#endif // HAUPTFENSTER_H_INCLUDED
