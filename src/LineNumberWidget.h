#ifndef LINENUMBERWIDGET_H
#define LINENUMBERWIDGET_H

#include <QWidget>
class CodeEdit;
class QPaintEvent;

class LineNumberWidget: public QWidget {
public:
    LineNumberWidget(CodeEdit*, QWidget* parent);
    ~LineNumberWidget();

protected:
    QSize sizeHint();
    virtual void paintEvent( QPaintEvent* );

private:
    CodeEdit* m_editor;
};

#endif // LINENUMBERWIDGET_H
