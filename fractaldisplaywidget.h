#ifndef FRACTALWIDGET_H
#define FRACTALWIDGET_H

#include <QWidget>
#include <QPixmap>
#include <QRubberBand>
#include "sierpinskifractal.h"
#include "mandelbrotfractal.h"

class FractalDisplayWidget : public QWidget
{
    Q_OBJECT
public:
    explicit FractalDisplayWidget(QWidget *parent = 0);
    
    void setFractal(AbstractFractal* fractal);

signals:
    
public slots:
    void saveImage();

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
