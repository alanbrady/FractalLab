#ifndef FRACTALWIDGET_H
#define FRACTALWIDGET_H

#include <QWidget>
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
    AbstractFractal* fractal;
    
};

#endif // FRACTALWIDGET_H
