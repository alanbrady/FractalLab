#ifndef SIERPINSKIFRACTALWIDGET_H
#define SIERPINSKIFRACTALWIDGET_H

#include <QWidget>
#include "sierpinskifractal.h"
#include "abstractfractalwidget.h"

namespace Ui {
class SierpinskiFractalWidget;
}

class SierpinskiFractalWidget : public AbstractFractalWidget
{
    Q_OBJECT
public:
    explicit SierpinskiFractalWidget(QWidget *parent = 0);
    ~SierpinskiFractalWidget();

    AbstractFractal* getFractal() { return &m_fractal; }
    
public slots:
    void generate();

private:
    Ui::SierpinskiFractalWidget *ui;
    SierpinskiFractal m_fractal;
};

#endif // SIERPINSKIFRACTALWIDGET_H
