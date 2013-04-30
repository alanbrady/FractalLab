#include "juliafractal.h"

JuliaFractal::JuliaFractal(double minReal, double maxReal, double minImag,
                           double maxImag, double kReal, double kImag, int iter,
                           int ix, int iy, int width, int height)
    : MandelbrotFractal(minReal, maxReal, minImag, maxImag, iter,
                        ix, iy, width, height),
      m_kReal(kReal), m_kImag(kImag) {

}

JuliaFractal::JuliaFractal()
    : MandelbrotFractal(-1.2, 1.2, -1.5, 1.5, 100, 0, 0, 0, 0),
      m_kReal(0.3), m_kImag(0.49){
}

void JuliaFractal::drawMe(QPainter *painter)
{
    QColor color = Qt::white;

    for (int y = 0; y < getHeight(); y++) {
        for (int x = 0; x < getWidth(); x++) {
            double z_imag = getMaxImag() - (y*getImagFactor());
            double z_real = getMinReal() + (x*getRealFactor());
//            double z_imag = c_imag;
//            double z_real = c_real;

            bool isInside = true;
            int k;
            for (k = 0; k < getIterations(); k++) {
                double z_real2 = z_real*z_real;
                double z_imag2 = z_imag*z_imag;
                if (z_real2 + z_imag2 > 4) {
                    isInside = false;
                    break;
                }
                z_imag = 2*z_real*z_imag + m_kImag;
                z_real = z_real2 - z_imag2 + m_kReal;
            }
            if (isInside) {
                painter->setPen(Qt::black);
                painter->drawPoint(x, y);
            } else {
//                painter->setPen(Qt::white);
//                painter->drawPoint(x, y);
                double halfIter = (double)getIterations()/2.0;
                if (k < (getIterations()/2)) {
                    double cFactor = (k/halfIter)*255.0;
                    color.setRgb(0, 0, cFactor);
                    painter->setPen(color);
                    painter->drawPoint(x,y);
                } else {
                    double cFactor = ((k-halfIter)/halfIter)*255.0;
                    color.setRgb(cFactor, cFactor, 255);
                    painter->setPen(color);
                    painter->drawPoint(x,y);
                }
            }
        }
    }
    m_redraw = false;
}
