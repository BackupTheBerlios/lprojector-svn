
#include "DocStatusWidget.h"
#include "Logger.h"
#include "Document.h"

#include <QTextCursor>

DocStatusWidget::DocStatusWidget(Document* doc, QWidget* parent, Qt::WindowFlags f)
    : QWidget(parent,f), doc_(doc)
{
    setupUi(this);
    syslog.send("DocStatusWidget::DocStatusWidget()",Logger::Informative);
    refreshText();
    setupSignals();
}

void DocStatusWidget::setupSignals() {
    if(doc_)
        connect(doc_,SIGNAL(cursorPositionChanged()),this,SLOT(refreshText()));
}

void DocStatusWidget::setDocument(Document* doc) {
    syslog.send("DocStatusWidget::setDocument()",Logger::Informative);
//    disconnect(doc_,SIGNAL(cursorPositionChanged()),this,SLOT(refreshText()));
    disconnect(this,SLOT(refreshText()));
//    disconnect(doc_,0,this,0);
    doc_ = doc;
    refreshText();
    setupSignals();
}

void DocStatusWidget::refreshText() {
    syslog.send("DocStatusWidget::refreshText()",Logger::Informative);
    const QString statusFormat = tr("Ln: %1 Col: %2 Sel: %3");
    const QString infoFormat = tr("Lines: %2, Characters: %1");
//    const QString infoFormat = tr("Characters: %1");
    const QString encFormat = tr("Encoding: %1");

    if(doc_) {
        statusInfo->setText(statusFormat
            .arg(doc_->currentLine() + 1)
            .arg(doc_->currentColumn() + 1)
            .arg(doc_->selectionEnd() - doc_->selectionStart()));
//        c.movePosition(QTextCursor::End);
        docInfo->setText(infoFormat.arg(doc_->lines(),doc_->length()));
        encInfo->setText(encFormat.arg(doc_->documentInfo()->encodingName()));
        this->setVisible(true);
    }
    else {
        statusInfo->setText(tr(""));
        docInfo->setText(tr(""));
        encInfo->setText(tr(""));
        this->setVisible(false);
    }
}
