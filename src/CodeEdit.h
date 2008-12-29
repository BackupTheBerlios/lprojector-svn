#ifndef CODEEDIT_H
#define CODEEDIT_H

#include "LineNumberWidget.h"
#include <QPlainTextEdit>
class QResizeEvent;
class QPaintEvent;
class QRect;

class CodeEdit : public QPlainTextEdit
{
    Q_OBJECT

    public:
        CodeEdit(QWidget*);
        ~CodeEdit();
        int lineNumberWidgetWidth();

    public slots:
        void updateLineNumberWidgetWidth(int newBlockCount);
        void updateLineNumberWidget(const QRect& rect, int dy);
        void lineNumberWidgetPaintEvent(QPaintEvent* event);
        void reloadSettings();

    private slots:
        void resizeEvent(QResizeEvent* e);
        void highlightCurrentLine();

    private:
        LineNumberWidget* m_lineNumberWidget;
};

#endif // CODEEDIT_H
