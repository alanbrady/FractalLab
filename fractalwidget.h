#ifndef FRACTALWIDGET_H
#define FRACTALWIDGET_H

#include <QWidget>
#include <QPixmap>
#include "sierpinskifractal.h"
#include "mandelbrotfractal.h"

class FractalWidget : public QWidget
{
    Q_OBJECT
public:
    explicit FractalWidget(QWidget *parent = 0);
    
signals:
    
public slots:

private:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent * event);
    void resizeEvent(QResizeEvent *event);
    void redrawFractal();

    AbstractFractal* fractal;
    QPoint mouseDown;
    QPixmap m_fractalMap;
    
};

#endif // FRACTALWIDGET_H
