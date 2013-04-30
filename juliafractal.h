#ifndef JULIAFRACTAL_H
#define JULIAFRACTAL_H

#include "mandelbrotfractal.h"

class JuliaFractal : public MandelbrotFractal
{
public:
    JuliaFractal(double minReal, double maxReal, double minImag, double maxImag,
                 double kReal, double kImag, int iter, int ix, int iy,
                 int width, int height);

    JuliaFractal();

    double getKReal() const { return m_kReal; }
    double getKImag() const { return m_kImag; }

    void setKReal(double kReal) { m_kReal = kReal; m_redraw = true; }
    void setKImag(double kImag) { m_kImag = kImag; m_redraw = true; }

    void drawMe(QPainter *painter);

private:
    double m_kReal;
    double m_kImag;
};

#endif // JULIAFRACTAL_H
