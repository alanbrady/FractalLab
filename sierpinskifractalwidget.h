#ifndef SIERPINSKIFRACTALWIDGET_H
#define SIERPINSKIFRACTALWIDGET_H

#include <QWidget>
#include "sierpinskifractal.h"

namespace Ui {
class SierpinskiFractalWidget;
}

class SierpinskiFractalWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SierpinskiFractalWidget(QWidget *parent = 0);
    ~SierpinskiFractalWidget();

    AbstractFractal* getFractal() { return &fractal; }
    
private:
    Ui::SierpinskiFractalWidget *ui;
    SierpinskiFractal fractal;
};

#endif // SIERPINSKIFRACTALWIDGET_H
