#ifndef ABSTRACTFRACTAL_H
#define ABSTRACTFRACTAL_H

#include <QPainter>
#include <QRect>

class AbstractFractal
{
public:
    AbstractFractal(int ix, int iy, int width, int height)
        : m_ix(ix), m_iy(iy), m_width(width), m_height(height) {
        zoomRect = QRect(0, 0, width, height);
    }

    virtual ~AbstractFractal() {}

    virtual void drawMe(QPainter* painter) = 0;

    int getIX() const { return m_ix; }
    int getIY() const { return m_iy; }
    int getWidth() const { return m_width; }
    int getHeight() const { return m_height; }

    const QRect& getZoomRect() { return zoomRect; }
    virtual void setZoomRect(QRect rect) { zoomRect = rect; }

    virtual void setWidth(int width) { m_width = width; }
    virtual void setHeight(int height) { m_height = height; }

    void setDimensions(int ix, int iy, int width, int height) {
        m_ix = ix;
        m_iy = iy;
        m_width = width;
        m_height = height;
    }

private:
    int m_ix;
    int m_iy;
    int m_width;
    int m_height;
    QRect zoomRect;

};

#endif // ABSTRACTFRACTAL_H
