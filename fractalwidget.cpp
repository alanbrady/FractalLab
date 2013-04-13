#include "fractalwidget.h"

FractalWidget::FractalWidget(QWidget *parent) :
    QWidget(parent)
{
//    fractal = new SierpinskiFractal(6, 0, 0, width(), height());
    fractal = new MandelbrotFractal(-2.0, 1.2, -1.0, 1, 30, 0, 0,
                                    width(), height());
}

void FractalWidget::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    fractal->setWidth(width());
    fractal->setHeight(height());
    fractal->drawMe(&painter);
}
