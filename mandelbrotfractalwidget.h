#ifndef MANDELBROTFRACTALWIDGET_H
#define MANDELBROTFRACTALWIDGET_H

#include <QWidget>
#include "abstractfractalwidget.h"
#include "mandelbrotfractal.h"

namespace Ui {
class MandelbrotFractalWidget;
}

class MandelbrotFractalWidget : public AbstractFractalWidget
{
    Q_OBJECT
    
public:
    explicit MandelbrotFractalWidget(QWidget *parent = 0);
    ~MandelbrotFractalWidget();

    AbstractFractal* getFractal() { return &m_fractal; }

public slots:
    void generate();
    void resetFractalZoom();
    void zoomed();

private:
    Ui::MandelbrotFractalWidget *ui;
    MandelbrotFractal m_fractal;

    void updateFractal();
};

#endif // MANDELBROTFRACTALWIDGET_H
