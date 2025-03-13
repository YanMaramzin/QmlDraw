#pragma once

#include "shapenode.h"

class RectangleNode : public ShapeNode {
public:
    RectangleNode(QRectF rect, QColor color)
        : ShapeNode(color)
    {
        geometry->allocate(4);
        geometry->setDrawingMode(QSGGeometry::DrawTriangleStrip);
        updateGeometry(rect);
    }

    void updateGeometry(QRectF rect) {
        QSGGeometry::Point2D* vertices = geometry->vertexDataAsPoint2D();
        vertices[0].set(rect.left(), rect.top());
        vertices[1].set(rect.right(), rect.top());
        vertices[2].set(rect.left(), rect.bottom());
        vertices[3].set(rect.right(), rect.bottom());

        qDebug() << "Rect:" << rect << "Vertices:"
                 << vertices[0].x << vertices[0].y
                 << vertices[1].x << vertices[1].y
                 << vertices[2].x << vertices[2].y
                 << vertices[3].x << vertices[3].y;
        markDirty(QSGNode::DirtyGeometry);
    }
};

