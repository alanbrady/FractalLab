#ifndef ABSTRACTFRACTAL_H
#define ABSTRACTFRACTAL_H

class AbstractFractal
{
public:
    AbstractFractal(int ix, int iy, int width, int height)
        : m_ix(ix), m_iy(iy), m_width(width), m_height(height) {}

    virtual ~AbstractFractal() {}

    virtual void drawMe(QPainter* painter) = 0;

    int getIX() const { return m_ix; }
    int getIY() const { return m_iy; }
    int getWidth() const { return m_width; }
    int getHeight() const { return m_height; }

    void setWidth(int width) { m_width = width; }
    void setHeight(int height) { m_height = height; }

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

};

#endif // ABSTRACTFRACTAL_H
