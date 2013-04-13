#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <QPointF>
#include <QPolygonF>

class Triangle
{
public:
    Triangle(QPointF top, QPointF left, QPointF right);
//    const Triangle& operator=(const Triangle& other);

    const QPointF& getTop() const { return m_top; }
    const QPointF& getLeft() const { return m_left; }
    const QPointF& getRight() const { return m_right; }

    const QPolygonF& getPolygonF() const { return m_poly; }
private:
    QPointF m_top;
    QPointF m_left;
    QPointF m_right;
    QPolygonF m_poly;

};

#endif // TRIANGLE_H
