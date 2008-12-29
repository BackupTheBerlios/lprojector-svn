#include "CodeEdit.h"
#include "LineNumberWidget.h"
#include <QSize>



LineNumberWidget::LineNumberWidget(CodeEdit* editor, QWidget* parent)
        : QWidget( parent) , m_editor( editor ) {
}

LineNumberWidget::~LineNumberWidget() {
}
QSize LineNumberWidget::sizeHint() {
    return QSize(m_editor->lineNumberWidgetWidth(), 0);
}
void LineNumberWidget::paintEvent(QPaintEvent* event) {
    m_editor->lineNumberWidgetPaintEvent(event);
}
