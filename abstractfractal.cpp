#include "abstractfractal.h"

void AbstractFractal::setWidth(int width)
{
    double ratio = (double)m_width/width;
    m_zoomRect.setWidth(m_zoomRect.width()*ratio);
    m_width = width;
}

void AbstractFractal::setHeight(int height)
{
    double ratio = (double)m_height/height;
    m_zoomRect.setHeight(m_zoomRect.height()*ratio);
    m_height = height;
}




