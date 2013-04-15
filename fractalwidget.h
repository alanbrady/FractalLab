#ifndef FRACTALWIDGET_H
#define FRACTALWIDGET_H

#include <QWidget>
#include <QPixmap>
#include <QRubberBand>
#include "sierpinskifractal.h"
#include "mandelbrotfractal.h"

class FractalWidget : public QWidget
{
    Q_OBJECT
public:
    explicit FractalWidget(QWidget *parent = 0);
    
    void setFractal(AbstractFractal* fractal) { m_fractal = fractal; update(); }

signals:
    
public slots:

private:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent * event);
    void resizeEvent(QResizeEvent *event);

    AbstractFractal* m_fractal;
    QPoint m_mouseDown;
    QPixmap m_fractalMap;
    QRubberBand* m_rubberBand;
    bool m_rightClicked;
};

#endif // FRACTALWIDGET_H
