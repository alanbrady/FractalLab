#ifndef JULIAFRACTALWIDGET_H
#define JULIAFRACTALWIDGET_H

#include <QWidget>
#include "abstractfractalwidget.h"
#include "juliafractal.h"

namespace Ui {
class JuliaFractalWidget;
}

class JuliaFractalWidget : public AbstractFractalWidget
{
    Q_OBJECT
    
public:
    explicit JuliaFractalWidget(QWidget *parent = 0);
    ~JuliaFractalWidget();

    AbstractFractal* getFractal() { return &m_fractal; }
    
public slots:
    void generate();
    void resetFractalZoom();
    void zoomed();
    void setIterations();

private:
    Ui::JuliaFractalWidget *ui;
    JuliaFractal m_fractal;

    void updateFractal();
};

#endif // JULIAFRACTALWIDGET_H
