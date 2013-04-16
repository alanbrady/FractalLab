#include "sierpinskifractal.h"

SierpinskiFractal::SierpinskiFractal(int iterations, int ix, int iy,
                                     int width, int height)
    : AbstractFractal(ix, iy, width, height),
      m_iter(iterations) {
}

void SierpinskiFractal::drawMe(QPainter *painter) {
    QList<Triangle> triangles = makeEquilateralTriangles();
    QColor color("blue");

    for (int i = 0; i < triangles.size(); i++) {
        painter->setBrush(QBrush(color));
        painter->drawPolygon(triangles.at(i).getPolygonF());
    }
    m_redraw = false;
}

QList<Triangle> SierpinskiFractal::makeEquilateralTriangles() {
    double minDim = getWidth() > getHeight() ? getHeight() : getWidth();

    QPointF top(minDim/2.0, 0.0);
    QPointF left(0.0, minDim);
    QPointF right(minDim, minDim);
    Triangle root(top, left, right);

    return makeEquilateralTriangles(&root, 0);
}

QList<Triangle> SierpinskiFractal::makeEquilateralTriangles(Triangle *root, int iter) {
    QList<Triangle> triangles;
    if (iter < m_iter) {
        iter++;
        double rootWidth = root->getRight().x()-root->getLeft().x();
        double rootHeight = root->getLeft().y()-root->getTop().y();
        QPointF midLeft(root->getLeft().x()+(rootWidth/4.0),
                        root->getTop().y()+rootHeight/2.0);
        QPointF midRight(root->getRight().x()-(rootWidth/4.0),
                         root->getTop().y()+rootHeight/2.0);
        QPointF midBottom(root->getLeft().x()+rootWidth/2.0,
                          root->getTop().y()+rootHeight);
        Triangle tri1(root->getTop(), midLeft, midRight);
        Triangle tri2(midLeft, root->getLeft(), midBottom);
        Triangle tri3(midRight, midBottom, root->getRight());
        triangles.append(makeEquilateralTriangles(&tri1, iter));
        triangles.append(makeEquilateralTriangles(&tri2, iter));
        triangles.append(makeEquilateralTriangles(&tri3, iter));
    } else {
        triangles.append((*root));
    }
    return triangles;
}


