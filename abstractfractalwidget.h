#ifndef ABSTRACTFRACTALWIDGET_H
#define ABSTRACTFRACTALWIDGET_H

#include <QWidget>
#include "abstractfractal.h"

class AbstractFractalWidget : public QWidget
{
    Q_OBJECT
public:
    explicit AbstractFractalWidget(QWidget *parent = 0);
    ~AbstractFractalWidget() {}

    virtual AbstractFractal* getFractal() = 0;

signals:
    void needsRedraw();
    
public slots:
    
};

#endif // ABSTRACTFRACTALWIDGET_H
