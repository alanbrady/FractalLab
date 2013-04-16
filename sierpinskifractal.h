#ifndef SIERPINSKIFRACTAL_H
#define SIERPINSKIFRACTAL_H

#include <QPainter>
#include <QPolygonF>
#include <QList>

#include "abstractfractal.h"
#include "triangle.h"

class SierpinskiFractal : public AbstractFractal
{
public:
    SierpinskiFractal(int iterations, int ix, int iy,
                      int width, int height);

    void drawMe(QPainter *painter);
    void setIterations(int iter) { m_iter = iter; m_redraw = true;}

private:
    int m_iter;

    QList<Triangle> makeEquilateralTriangles();
    QList<Triangle> makeEquilateralTriangles(Triangle* root, int iter);

};

#endif // SIERPINSKIFRACTAL_H
