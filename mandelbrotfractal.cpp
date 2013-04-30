#include "mandelbrotfractal.h"

MandelbrotFractal::MandelbrotFractal(double minReal, double maxReal, double minImag,
                                     double maxImag, int iter, int ix, int iy,
                                     int width, int height)
    : AbstractFractal(ix, iy, width, height),
      m_minReal(minReal), m_maxReal(maxReal),
      m_minImag(minImag), m_maxImag(maxImag),
//      m_zMinReal(minReal), m_zMaxReal(maxReal),
//      m_zMinImag(minImag), m_zMaxImag(maxImag),
      m_iter(iter) {
    m_realFactor = (m_maxReal-m_minReal)/(getWidth()-1);
    m_imagFactor = (m_maxImag-m_minImag)/(getHeight()-1);
    setZoomRect(QRect(QPoint(), QPoint(getWidth(), getHeight())));
}

MandelbrotFractal::MandelbrotFractal()
    : AbstractFractal(0, 0, 0, 0),
      m_minReal(-2.2), m_maxReal(1.2),
      m_minImag(-1.0), m_maxImag(1.0),
//      m_zMinReal(0), m_zMaxReal(0),
//      m_zMinImag(0), m_zMaxImag(0),
      m_iter(100) {
}

void MandelbrotFractal::drawMe(QPainter *painter) {
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
//    m_minReal = minReal;
//    if (m_zMinReal == 0) m_zMinReal = m_minReal;
//    m_zMinReal = ((getZoomRect().x()/(double)getWidth())*(m_zMaxReal-m_zMinReal))+m_zMinReal;
//    m_realFactor = (m_zMaxReal-m_zMinReal)/(getWidth()-1);
//    m_redraw = true;
//    if (m_zMinReal == 0) m_zMinReal = minReal;

//    if (m_minReal == minReal) return;

    m_minReal = minReal;
    m_realFactor = (m_maxReal-m_minReal)/(getWidth()-1);
    m_redraw = true;
//    resetZoom();
}

void MandelbrotFractal::setMaxReal(double maxReal)
{
//    m_maxReal = maxReal;
//    if (m_zMaxReal == 0) m_zMaxReal = m_maxReal;
//    m_zMaxReal = (((getZoomRect().x()+getZoomRect().width())/(double)getWidth()) *
//                  (m_zMaxReal-m_zMinReal))+m_zMinReal;
//    m_realFactor = (m_zMaxReal-m_zMinReal)/(getWidth()-1);
//    m_redraw = true;
//    if (m_zMaxReal == 0) m_zMaxReal = maxReal;

//    if (m_maxReal == maxReal) return;

    m_maxReal = maxReal;
    m_realFactor = (m_maxReal-m_minReal)/(getWidth()-1);
    m_redraw = true;
//    resetZoom();
}

void MandelbrotFractal::setMinImag(double minImag)
{
//    m_minImag = minImag;
//    if (m_zMinImag == 0) m_zMinImag = m_minImag;
//    m_zMinImag = m_zMaxImag - ((getZoomRect().y()+getZoomRect().height())/(double)getHeight()*
//                              (m_zMaxImag-m_zMinImag));
//    m_imagFactor = (m_zMaxImag-m_zMinImag)/(getHeight()-1);
//    m_redraw = true;
//    if (m_zMinImag == 0) m_zMinImag = minImag;

//    if (m_minImag == minImag) return;

    m_minImag = minImag;
    m_imagFactor = (m_maxImag-m_minImag)/(getHeight()-1);
    m_redraw = true;
//    resetZoom();
}

void MandelbrotFractal::setMaxImag(double maxImag)
{
//    m_maxImag = maxImag;
//    if (m_zMaxImag == 0) m_zMaxImag = m_maxImag;
//    m_zMaxImag = m_zMaxImag - ((getZoomRect().y()/(double)getHeight())*(m_zMaxImag-m_zMinImag));
//    m_imagFactor = (m_maxImag-m_minImag)/(getHeight()-1);
//    m_redraw = true;
//    if (m_zMaxImag == 0) m_zMaxImag = maxImag;

//    if (m_maxImag == maxImag) return;

    m_maxImag = maxImag;
    m_imagFactor = (m_maxImag-m_minImag)/(getHeight()-1);
    m_redraw = true;
//    resetZoom();
}


void MandelbrotFractal::setHeight(int height)
{
    AbstractFractal::setHeight(height);
//    m_imagFactor = (m_zMaxImag-m_zMinImag)/(getHeight()-1);
    m_imagFactor = (m_maxImag-m_minImag)/(getHeight()-1);
    m_redraw = true;
}

void MandelbrotFractal::setWidth(int width)
{
    AbstractFractal::setWidth(width);
    //    m_realFactor = (m_zMaxReal-m_zMinReal)/(getWidth()-1);
    m_realFactor = (m_maxReal-m_minReal)/(getWidth()-1);
    m_redraw = true;
}

void MandelbrotFractal::setZoomRect(QRect rect)
{
//    AbstractFractal::setZoomRect(rect);
//    double totalImag = (m_zMaxImag-m_zMinImag);
//    double totalReal = (m_zMaxReal-m_zMinReal);
//    m_zMaxReal = (((rect.x()+rect.width())/(double)getWidth()) *
//                  totalReal)+m_zMinReal;
//    m_zMinReal = ((rect.x()/(double)getWidth())*totalReal)+m_zMinReal;
//    m_zMinImag = m_zMaxImag - ((rect.y()+rect.height())/(double)getHeight()*
//                              totalImag);
//    m_zMaxImag = m_zMaxImag - ((rect.y()/(double)getHeight())*totalImag);
//    m_imagFactor = (m_zMaxImag-m_zMinImag)/(getHeight()-1);
//    m_realFactor = (m_zMaxReal-m_zMinReal)/(getWidth()-1);
//    m_redraw = true;
    AbstractFractal::setZoomRect(rect);
    double totalImag = (m_maxImag-m_minImag);
    double totalReal = (m_maxReal-m_minReal);
    m_maxReal = (((rect.x()+rect.width())/(double)getWidth()) *
                    totalReal)+m_minReal;
    m_minReal = ((rect.x()/(double)getWidth())*totalReal)+m_minReal;
    m_minImag = m_maxImag - ((rect.y()+rect.height())/(double)getHeight()*
                              totalImag);
    m_maxImag = m_maxImag - ((rect.y()/(double)getHeight())*totalImag);
    m_imagFactor = (m_maxImag-m_minImag)/(getHeight()-1);
    m_realFactor = (m_maxReal-m_minReal)/(getWidth()-1);
    emit zoomed();
    m_redraw = true;
}

void MandelbrotFractal::resetZoom()
{
//    m_zMinReal = m_minReal;
//    m_zMaxReal = m_maxReal;
//    m_zMinImag = m_minImag;
//    m_zMaxImag = m_maxImag;
    m_minReal = -2.2;
    m_maxReal = 1.2;
    m_minImag = -1.0;
    m_maxImag = 1.0;
    setZoomRect(QRect(QPoint(), QPoint(getWidth(), getHeight())));
}

