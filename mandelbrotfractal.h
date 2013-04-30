#ifndef MANDELBROTFRACTAL_H
#define MANDELBROTFRACTAL_H

#include "abstractfractal.h"

class MandelbrotFractal : public AbstractFractal
{
public:
    MandelbrotFractal(double minReal, double maxReal, double minImag, double maxImag,
                      int iter, int ix, int iy, int width, int height);

    MandelbrotFractal();

    virtual void drawMe(QPainter *painter);

    double getMinReal() const { return m_minReal; }
    double getMaxReal() const { return m_maxReal; }
    double getMinImag() const { return m_minImag; }
    double getMaxImag() const { return m_maxImag; }
    double getRealFactor () const { return m_realFactor; }
    double getImagFactor() const { return m_imagFactor; }
    double getIterations() const { return m_iter; }

    void setMinReal(double minReal);
    void setMaxReal(double maxReal);
    void setMinImag(double minImag);
    void setMaxImag(double maxImag);
    void setWidth(int width);
    void setHeight(int height);
    void setZoomRect(QRect rect);
    void setIterations(int iters) { m_iter = iters; m_redraw = true; }
    void resetZoom();

private:

    double m_minReal;
    double m_maxReal;
    double m_minImag;
    double m_maxImag;

//    double m_zMinReal;
//    double m_zMaxReal;
//    double m_zMinImag;
//    double m_zMaxImag;

    double m_realFactor;
    double m_imagFactor;

    int m_iter;

};

#endif // MANDELBROTFRACTAL_H
