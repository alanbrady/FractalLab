#include "triangle.h"

Triangle::Triangle(QPointF top, QPointF left, QPointF right)
    : m_top(top), m_left(left), m_right(right) {
    m_poly << top << left << right;
}

//const Triangle &Triangle::operator =(const Triangle &other) {
//    m_top(other.m_top);
//    m_left()
//}

