#ifndef ABSTRACTFRACTAL_H
#define ABSTRACTFRACTAL_H

#include <QPainter>
#include <QRect>

class AbstractFractal
{
public:
    AbstractFractal(int ix, int iy, int width, int height)
        : m_ix(ix), m_iy(iy), m_width(width), m_height(height), m_redraw(false) {
        m_zoomRect = QRect(0, 0, width, height);
    }

    virtual ~AbstractFractal() {}

    virtual void drawMe(QPainter* painter) = 0;

    int getIX() const { return m_ix; }
    int getIY() const { return m_iy; }
    int getWidth() const { return m_width; }
    int getHeight() const { return m_height; }

    const QRect& getZoomRect() { return m_zoomRect; }
    virtual void setZoomRect(QRect rect) { m_zoomRect = rect; }

    virtual void setWidth(int width);
    virtual void setHeight(int height);
    bool needsRedraw() { return m_redraw; }

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
    QRect m_zoomRect;

protected:
    bool m_redraw;

};

#endif // ABSTRACTFRACTAL_H
