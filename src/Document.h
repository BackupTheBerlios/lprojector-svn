#ifndef DOCUMENT_H_INCLUDED
#define DOCUMENT_H_INCLUDED

#include "DocumentInfo.h"

#include <QWidget>
//#include <QPlainTextEdit>

class QString;
class QSyntaxHighlighter;
class LineNumberWidget;
class QHBoxLayout;
class CodeEdit;

class Document : public QWidget {
        Q_OBJECT

    public:
        Document(const DocumentInfo& docinfo,
            const QString & text, QWidget* parent=0);
        ~Document();

        DocumentInfo* documentInfo() { return &docinfo_; }
        QString text() const;

        int currentLine() const;
        int currentColumn() const;
        int lines() const;
        int length() const;
        int selectionStart() const;
        int selectionEnd() const;
        int selectionLength() const;

    protected:
        DocumentInfo docinfo_;
        QSyntaxHighlighter* highlighter;
        CodeEdit* m_textEdit;
//        LineNumberWidget* m_lineNumberWidget;
        QHBoxLayout* m_layout;

    signals:
        void aboutToClose(Document* sender);
        void textChanged();
        void cursorPositionChanged();

    public slots:
        void close();
    protected slots:
        void onTextChanged();
};




#endif // DOCUMENT_H_INCLUDED
