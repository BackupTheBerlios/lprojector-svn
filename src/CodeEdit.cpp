#include "CodeEdit.h"
#include "ApplicationManager.h"
#include "Settings.h"

#include <cmath>

#include <QPainter>
#include <QBrush>
#include <QPen>
#include <QTextBlock>
#include <QPlainTextEdit>

#include <QDebug>

CodeEdit::CodeEdit(QWidget* parent) : QPlainTextEdit(parent) {
    m_lineNumberWidget = new LineNumberWidget(this,this);

    connect(ApplicationManager::instance(), SIGNAL(settingsChanged()), this, SLOT(reloadSettings()));
    connect(this, SIGNAL(blockCountChanged(int)), this, SLOT(updateLineNumberWidgetWidth(int)));
    connect(this, SIGNAL(updateRequest(const QRect&,int)), this, SLOT(updateLineNumberWidget(const QRect&,int)));
    updateLineNumberWidgetWidth(0);
    reloadSettings();

    qDebug() << "Initialized CodeEdit instance";
}
CodeEdit::~CodeEdit() {
    //dtor
}
void CodeEdit::reloadSettings() {
    if(ApplicationManager::settings()->highlightCurrentLine()) {
        connect(this, SIGNAL(cursorPositionChanged()), this, SLOT(highlightCurrentLine()));
        highlightCurrentLine();
    }else{
        connect(this, SIGNAL(cursorPositionChanged()), this, SLOT(highlightCurrentLine()));
    }
}
int CodeEdit::lineNumberWidgetWidth() {
//    qDebug() << "CodeEdit::lineNumberWidgetWidth()";
    return 3 + fontMetrics().width('9') * (std::log10(blockCount()) + 1);
}
void CodeEdit::updateLineNumberWidgetWidth(int newBlockCount) {
//    qDebug() << "CodeEdit::updateLineNumberWidgetWidth()";
    setViewportMargins(lineNumberWidgetWidth(), 0, 0, 0);
}
void CodeEdit::updateLineNumberWidget(const QRect& rect, int dy) {
//    qDebug() << "CodeEdit::updateLineNumberWidget()";
    if(dy > 0)
        m_lineNumberWidget->scroll(0, dy);
    else
        m_lineNumberWidget->update(0,rect.y(),m_lineNumberWidget->width(),rect.height());
    if(rect.contains(viewport()->rect()))
        updateLineNumberWidgetWidth(0);
}
void CodeEdit::resizeEvent(QResizeEvent* e) {
//    qDebug() << "CodeEdit::resizeEvent()";
    QPlainTextEdit::resizeEvent(e);
    QRect cr = contentsRect();
    m_lineNumberWidget->setGeometry(QRect(cr.left(),cr.top(),lineNumberWidgetWidth(),cr.height()));
}
void CodeEdit::highlightCurrentLine() {
//    qDebug() << "CodeEdit::highlightCurrentLine()";

    QList<QTextEdit::ExtraSelection> extraSelections;
    if (!isReadOnly()) {
        QTextEdit::ExtraSelection selection;
        selection.format.setBackground(QBrush(ApplicationManager::settings()->currentLineHighlightColor()));
        selection.format.setProperty(QTextFormat::FullWidthSelection, true);
        selection.cursor = textCursor();
        selection.cursor.clearSelection();
        extraSelections << selection;
    }
    setExtraSelections(extraSelections);
}
void CodeEdit::lineNumberWidgetPaintEvent(QPaintEvent* event) {
//    qDebug() << "CodeEdit::lineNumberWidgetPaintEvent()";
    QPainter painter(m_lineNumberWidget);
    painter.setPen(QPen(ApplicationManager::settings()->lineNumberColor()));
    painter.fillRect(event->rect(), QBrush(ApplicationManager::settings()->lineNumberBackgroundColor()));

    QTextBlock block = firstVisibleBlock();
    int top = (int)blockBoundingGeometry(block).translated(contentOffset()).top();
    int bottom;

    while (block.isValid() && top <= event->rect().bottom()) {
        bottom = top + (int)blockBoundingRect(block).height();
        if (block.isVisible() && bottom >= event->rect().top()) {
            painter.drawText(0, top, m_lineNumberWidget->width(), fontMetrics().height(),Qt::AlignRight, QString::number(block.blockNumber() + 1));
        }
        block = block.next();
        top = bottom;
    }
}
