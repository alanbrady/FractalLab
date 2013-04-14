#include "fractalwidget.h"

#include <QMouseEvent>

FractalWidget::FractalWidget(QWidget *parent) :
    QWidget(parent), m_fractalMap(width(), height())
{
//    fractal = new SierpinskiFractal(6, 0, 0, width(), height());
    fractal = new MandelbrotFractal(-2.2, 1.2, -1.5, 1.5, 200, 0, 0,
                                    width(), height());
    setMouseTracking(true);
    redrawFractal();
}

void FractalWidget::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.drawPixmap(this->rect(), m_fractalMap);
//        fractal->setWidth(width());
//        fractal->setHeight(height());
//        fractal->drawMe(&painter);
}

void FractalWidget::mousePressEvent(QMouseEvent *event)
{
    mouseDown = event->pos();
}

void FractalWidget::mouseReleaseEvent(QMouseEvent *event)
{
    fractal->setZoomRect(QRect(mouseDown, event->pos()));
    redrawFractal();
}

void FractalWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    m_fractalMap.scaled(width(), height());
    fractal->setWidth(width());
    fractal->setHeight(height());
    redrawFractal();
}

void FractalWidget::redrawFractal()
{
    QPainter painter;
    painter.begin(&m_fractalMap);
    fractal->drawMe(&painter);
    painter.end();
}
