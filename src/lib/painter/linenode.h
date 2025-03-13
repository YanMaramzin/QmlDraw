#pragma once

#include "shapenode.h"

class LineNode : public ShapeNode {
public:
    LineNode(QPointF start, QPointF end, QColor color)
        : ShapeNode(color)
    {
        geometry->allocate(2);
        QSGGeometry::Point2D* vertices = geometry->vertexDataAsPoint2D();
        vertices[0].set(start.x(), start.y());
        vertices[1].set(end.x(), end.y());
        geometry->setDrawingMode(QSGGeometry::DrawLines);
    }
    void updateGeometry(QPointF start, QPointF end) {
        QSGGeometry::Point2D* vertices = geometry->vertexDataAsPoint2D();
        vertices[0].set(start.x(), start.y());
        vertices[1].set(end.x(), end.y());
        markDirty(QSGNode::DirtyGeometry);
    }
};
