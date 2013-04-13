#include "mandelbrotfractal.h"

MandelbrotFractal::MandelbrotFractal(double minReal, double maxReal, double minImag,
                                     double maxImag, int iter, int ix, int iy,
                                     int width, int height)
    : AbstractFractal(ix, iy, width, height),
      m_minReal(minReal), m_maxReal(maxReal),
      m_minImag(minImag), m_maxImag(maxImag),
      m_iter(iter) {
    m_realFactor = (m_maxReal-m_minReal)/(getWidth()-1);
    m_imagFactor = (m_maxImag-m_minImag)/(getHeight()-1);
}

void MandelbrotFractal::drawMe(QPainter *painter) {
//    painter->setBrush(Qt::black);
    QColor color = Qt::white;

    for (int y = 0; y < getHeight(); y++) {
        double c_imag = m_maxImag - (y*m_imagFactor);
        for (int x = 0; x < getWidth(); x++) {
            double c_real = m_minReal + (x*m_realFactor);
            double z_imag = c_imag;
            double z_real = c_real;

            bool isInside = true;
            int k;
            for (k = 0; k < m_iter; k++) {
                double z_real2 = z_real*z_real;
                double z_imag2 = z_imag*z_imag;
                if (z_real2 + z_imag2 > 4) {
                    isInside = false;
                    break;
                }
                z_imag = 2*z_real*z_imag + c_imag;
                z_real = z_real2 - z_imag2 + c_real;
            }
            if (isInside) {
                painter->setPen(Qt::black);
                painter->drawPoint(x, y);
            } else {


                if (k < (m_iter/2)-1) {
                    double red = ((double)k/(double)m_iter)*255.0;
                    color.setRgb(red, 0, 0);
                    painter->setPen(color);
                    painter->drawPoint(x,y);
                } else {
                    double red = 255-(((double)k/(double)m_iter)*255.0);
                    color.setRgb(red, 0, 0);
                    painter->setPen(color);
                    painter->drawPoint(x,y);
                }
            }
        }
    }
}

void MandelbrotFractal::setMinReal(double minReal)
{
    m_minReal = minReal;
    m_realFactor = (m_maxReal-m_minReal)/(getWidth()-1);
}

void MandelbrotFractal::setMaxReal(double maxReal)
{
    m_maxReal = maxReal;
    m_realFactor = (m_maxReal-m_minReal)/(getWidth()-1);
}

void MandelbrotFractal::setMinImag(double minImag)
{
    m_minImag = minImag;
    m_imagFactor = (m_maxImag-m_minImag)/(getHeight()-1);
}

void MandelbrotFractal::setMaxImag(double maxImag)
{
    m_maxImag = maxImag;
    m_imagFactor = (m_maxImag-m_minImag)/(getHeight()-1);
}


void MandelbrotFractal::setHeight(int height)
{
    AbstractFractal::setHeight(height);
    m_imagFactor = (m_maxImag-m_minImag)/(getHeight()-1);
}


void MandelbrotFractal::setWidth(int width)
{
    AbstractFractal::setWidth(width);
    m_realFactor = (m_maxReal-m_minReal)/(getWidth()-1);
}
