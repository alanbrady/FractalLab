#include "fractaldisplaywidget.h"

#include <QMouseEvent>

FractalDisplayWidget::FractalDisplayWidget(QWidget *parent) :
    QWidget(parent), m_fractalMap(width(), height())
{
    m_rubberBand = 0;
    m_rightClicked = false;
//    fractal = new SierpinskiFractal(6, 0, 0, width(), height());
    m_fractal = new MandelbrotFractal(-2.2, 1.2, -1.5, 1.5, 100, 0, 0,
                                    width(), height());
    setMouseTracking(true);
}

void FractalDisplayWidget::setFractal(AbstractFractal *fractal)
{
    m_fractal = fractal;
    m_fractal->setHeight(height());
    m_fractal->setWidth(width());
    update();

}

void FractalDisplayWidget::paintEvent(QPaintEvent *) {
    if (m_fractal->needsRedraw()) {
        m_fractalMap = QPixmap(size());
        QPainter p1(&m_fractalMap);
        m_fractal->drawMe(&p1);
    }
    QPainter p2(this);
    p2.drawPixmap(QPoint(), m_fractalMap);
}

void FractalDisplayWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::RightButton) return;
    m_rightClicked = false;
    m_mouseDown = event->pos();
    if (!m_rubberBand)
        m_rubberBand = new QRubberBand(QRubberBand::Rectangle, this);
    m_rubberBand->setGeometry(QRect(m_mouseDown, QSize()));
    m_rubberBand->show();
}

void FractalDisplayWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (m_rubberBand)
        m_rubberBand->setGeometry(QRect(m_mouseDown, event->pos()).normalized());
}

void FractalDisplayWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::RightButton) {
        m_rightClicked = true;
        m_rubberBand->hide();
        return;
    }
    if (!m_rightClicked) {
        m_rubberBand->hide();
        m_fractal->setZoomRect(QRect(m_mouseDown, event->pos()).normalized());
        update();
    }
}

void FractalDisplayWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    m_fractalMap.scaled(width(), height());
    m_fractal->setWidth(width());
    m_fractal->setHeight(height());
}

