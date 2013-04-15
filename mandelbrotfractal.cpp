#include "mandelbrotfractal.h"

MandelbrotFractal::MandelbrotFractal(double minReal, double maxReal, double minImag,
                                     double maxImag, int iter, int ix, int iy,
                                     int width, int height)
    : AbstractFractal(ix, iy, width, height),
      m_minReal(minReal), m_maxReal(maxReal),
      m_minImag(minImag), m_maxImag(maxImag),
      m_zMinReal(minReal), m_zMaxReal(maxReal),
      m_zMinImag(minImag), m_zMaxImag(maxImag),
      m_iter(iter) {
    m_realFactor = (m_maxReal-m_minReal)/(getWidth()-1);
    m_imagFactor = (m_maxImag-m_minImag)/(getHeight()-1);
}

void MandelbrotFractal::drawMe(QPainter *painter) {
    QColor color = Qt::white;

    for (int y = 0; y < getHeight(); y++) {
        double c_imag = m_zMaxImag - (y*m_imagFactor);
        for (int x = 0; x < getWidth(); x++) {
            double c_real = m_zMinReal + (x*m_realFactor);
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
                double halfIter = (double)m_iter/2.0;
                if (k < (m_iter/2)) {
                    double cFactor = (k/halfIter)*255.0;
                    color.setRgb(cFactor, 0, 0);
                    painter->setPen(color);
                    painter->drawPoint(x,y);
                } else {
                    double cFactor = ((k-halfIter)/halfIter)*255.0;
                    color.setRgb(255, cFactor, cFactor);
                    painter->setPen(color);
                    painter->drawPoint(x,y);
                }
            }
        }
    }
    m_redraw = false;
}

void MandelbrotFractal::setMinReal(double minReal)
{
    m_minReal = minReal;
    m_zMinReal = ((getZoomRect().x()/(double)getWidth())*(m_zMaxReal-m_zMinReal))+m_zMinReal;
    m_realFactor = (m_zMaxReal-m_zMinReal)/(getWidth()-1);
    m_redraw = true;
}

void MandelbrotFractal::setMaxReal(double maxReal)
{
    m_maxReal = maxReal;
    m_zMaxReal = (((getZoomRect().x()+getZoomRect().width())/(double)getWidth()) *
                  (m_zMaxReal-m_zMinReal))+m_zMinReal;
    m_realFactor = (m_zMaxReal-m_zMinReal)/(getWidth()-1);
    m_redraw = true;
}

void MandelbrotFractal::setMinImag(double minImag)
{
    m_minImag = minImag;
    m_zMinImag = m_zMaxImag - ((getZoomRect().y()+getZoomRect().height())/(double)getHeight()*
                              (m_zMaxImag-m_zMinImag));
    m_imagFactor = (m_zMaxImag-m_zMinImag)/(getHeight()-1);
    m_redraw = true;
}

void MandelbrotFractal::setMaxImag(double maxImag)
{
    m_maxImag = maxImag;
    m_zMaxImag = m_zMaxImag - ((getZoomRect().y()/(double)getHeight())*(m_zMaxImag-m_zMinImag));
    m_imagFactor = (m_maxImag-m_minImag)/(getHeight()-1);
    m_redraw = true;
}


void MandelbrotFractal::setHeight(int height)
{
    AbstractFractal::setHeight(height);
    m_imagFactor = (m_zMaxImag-m_zMinImag)/(getHeight()-1);
    m_redraw = true;
}

void MandelbrotFractal::setWidth(int width)
{
    AbstractFractal::setWidth(width);
    m_realFactor = (m_zMaxReal-m_zMinReal)/(getWidth()-1);
    m_redraw = true;
}

void MandelbrotFractal::setZoomRect(QRect rect)
{
    AbstractFractal::setZoomRect(rect);
    double totalImag = (m_zMaxImag-m_zMinImag);
    double totalReal = (m_zMaxReal-m_zMinReal);
    m_zMaxReal = (((rect.x()+rect.width())/(double)getWidth()) *
                  totalReal)+m_zMinReal;
    m_zMinReal = ((rect.x()/(double)getWidth())*totalReal)+m_zMinReal;
    m_zMinImag = m_zMaxImag - ((rect.y()+rect.height())/(double)getHeight()*
                              totalImag);
    m_zMaxImag = m_zMaxImag - ((rect.y()/(double)getHeight())*totalImag);
    m_imagFactor = (m_zMaxImag-m_zMinImag)/(getHeight()-1);
    m_realFactor = (m_zMaxReal-m_zMinReal)/(getWidth()-1);
    m_redraw = true;
}

