#ifndef DOCSTATUSLABEL_H_INCLUDED
#define DOCSTATUSLABEL_H_INCLUDED

#include "ui_DocStatusWidget.h"
#include <QWidget>

class Document;

class DocStatusWidget : public QWidget, private Ui::DocStatusWidget {

    Q_OBJECT

    public:
        DocStatusWidget(Document* doc=0, QWidget* parent=0, Qt::WindowFlags f=0);
        void setDocument(Document* doc);
    protected:
        Document* doc_;
        void setupSignals();

    public slots:
        void refreshText();
};

#endif // DOCSTATUSLABEL_H_INCLUDED
