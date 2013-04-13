#include "fractalwidget.h"

FractalWidget::FractalWidget(QWidget *parent) :
    QWidget(parent)
{
    fractal = new SierpinskiFractal(8, 0, 0, width(), height());
}

void FractalWidget::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    fractal->setWidth(width());
    fractal->setHeight(height());
    fractal->drawMe(&painter);
}
