#ifndef MANDELBROTFRACTAL_H
#define MANDELBROTFRACTAL_H

#include "abstractfractal.h"

class MandelbrotFractal : public AbstractFractal
{
public:
    MandelbrotFractal(double minReal, double maxReal, double minImag, double maxImag,
                      int iter, int ix, int iy, int width, int height);

    void drawMe(QPainter *painter);

    void setMinReal(double minReal);
    void setMaxReal(double maxReal);
    void setMinImag(double minImag);
    void setMaxImag(double maxImag);
    void setWidth(int width);
    void setHeight(int height);
    void setZoomRect(QRect rect);
    void setIterations(int iters) { m_iter = iters; }

private:
    double m_minReal;
    double m_maxReal;
    double m_minImag;
    double m_maxImag;

    double m_zMinReal;
    double m_zMaxReal;
    double m_zMinImag;
    double m_zMaxImag;

    double m_realFactor;
    double m_imagFactor;

    int m_iter;

};

#endif // MANDELBROTFRACTAL_H
