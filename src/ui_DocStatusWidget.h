/********************************************************************************
** Form generated from reading ui file 'DocStatusWidget.ui'
**
** Created: Mon Dec 29 23:39:39 2008
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_DOCSTATUSWIDGET_H
#define UI_DOCSTATUSWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DocStatusWidget
{
public:
    QHBoxLayout *hboxLayout;
    QLabel *statusInfo;
    QFrame *line2;
    QLabel *docInfo;
    QFrame *line1;
    QLabel *encInfo;

    void setupUi(QWidget *DocStatusWidget)
    {
    if (DocStatusWidget->objectName().isEmpty())
        DocStatusWidget->setObjectName(QString::fromUtf8("DocStatusWidget"));
    DocStatusWidget->resize(406, 18);
    DocStatusWidget->setLayoutDirection(Qt::RightToLeft);
    hboxLayout = new QHBoxLayout(DocStatusWidget);
    hboxLayout->setSpacing(6);
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    hboxLayout->setContentsMargins(2, 2, 2, 2);
    statusInfo = new QLabel(DocStatusWidget);
    statusInfo->setObjectName(QString::fromUtf8("statusInfo"));

    hboxLayout->addWidget(statusInfo);

    line2 = new QFrame(DocStatusWidget);
    line2->setObjectName(QString::fromUtf8("line2"));
    line2->setFrameShape(QFrame::VLine);
    line2->setFrameShadow(QFrame::Sunken);

    hboxLayout->addWidget(line2);

    docInfo = new QLabel(DocStatusWidget);
    docInfo->setObjectName(QString::fromUtf8("docInfo"));

    hboxLayout->addWidget(docInfo);

    line1 = new QFrame(DocStatusWidget);
    line1->setObjectName(QString::fromUtf8("line1"));
    line1->setFrameShape(QFrame::VLine);
    line1->setFrameShadow(QFrame::Sunken);

    hboxLayout->addWidget(line1);

    encInfo = new QLabel(DocStatusWidget);
    encInfo->setObjectName(QString::fromUtf8("encInfo"));

    hboxLayout->addWidget(encInfo);


    retranslateUi(DocStatusWidget);

    QMetaObject::connectSlotsByName(DocStatusWidget);
    } // setupUi

    void retranslateUi(QWidget *DocStatusWidget)
    {
    DocStatusWidget->setWindowTitle(QApplication::translate("DocStatusWidget", "Form", 0, QApplication::UnicodeUTF8));
    statusInfo->setText(QApplication::translate("DocStatusWidget", "Ln: 22 Col: 43 Sel: 234", 0, QApplication::UnicodeUTF8));
    docInfo->setText(QApplication::translate("DocStatusWidget", "Characters: 123767,  Lines: 2454", 0, QApplication::UnicodeUTF8));
    encInfo->setText(QApplication::translate("DocStatusWidget", "Encoding: System ", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(DocStatusWidget);
    } // retranslateUi

};

namespace Ui {
    class DocStatusWidget: public Ui_DocStatusWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCSTATUSWIDGET_H
