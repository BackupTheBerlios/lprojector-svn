
#include "CodeEdit.h"
#include "Document.h"
#include "DocumentInfo.h"
#include "LineNumberWidget.h"
//#include "Highlighter.h"

#include <QSyntaxHighlighter>
#include <QDebug>
#include <QHBoxLayout>

Document::Document(const DocumentInfo& docinfo, const QString& text, QWidget* parent)
    : QWidget(parent), docinfo_(docinfo) {

    QHBoxLayout* m_layout = new QHBoxLayout(this);
    m_layout->setSpacing(0);
    m_layout->setMargin(0);

    m_textEdit = new CodeEdit(this);
//    m_textEdit->setAcceptRichText(false);
    m_textEdit->setPlainText(text);
    m_textEdit->setLineWrapMode(QPlainTextEdit::NoWrap);

//    m_lineNumberWidget = new LineNumberWidget(m_textEdit,this);
//    highlighter = new LatexHighlighter(document());
    connect(m_textEdit,SIGNAL(textChanged()),this,SLOT(onTextChanged()));
    connect(m_textEdit,SIGNAL(textChanged()),this,SIGNAL(textChanged()));
    connect(m_textEdit,SIGNAL(cursorPositionChanged()),this,SIGNAL(cursorPositionChanged()));//TODO:Deselection?!

//    m_lineNumberWidget->setFixedWidth(50);
//    m_layout->addWidget(m_lineNumberWidget);
    m_layout->addWidget(m_textEdit);

    qDebug() << "Document: Initialized instance";
}
Document::~Document() {
    delete m_textEdit;
//    delete m_lineNumberWidget;
}
QString Document::text() const {
    return m_textEdit->toPlainText();
}

int Document::currentLine() const {
    return m_textEdit->textCursor().blockNumber();
}
int Document::currentColumn() const {
    return m_textEdit->textCursor().columnNumber();
}
int Document::lines() const {
    return m_textEdit->document()->blockCount();
}
int Document::length() const {
    return 13;
}
int Document::selectionStart() const {
    return m_textEdit->textCursor().selectionStart();
}
int Document::selectionEnd() const {
    return m_textEdit->textCursor().selectionEnd();
}
int Document::selectionLength() const {
    QTextCursor c = m_textEdit->textCursor();
    return c.selectionEnd() - c.selectionStart();
}

void Document::close() {
    emit aboutToClose(this);
}

void Document::onTextChanged() {
    if(documentInfo()->isModified())
        documentInfo()->setIsModified(true);
}
