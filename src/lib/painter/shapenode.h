#pragma once

#include <QSGGeometryNode>
#include <QSGFlatColorMaterial>

class ShapeNode : public QSGGeometryNode {
public:
    ShapeNode(QColor color) {
        geometry = new QSGGeometry(QSGGeometry::defaultAttributes_Point2D(), 0);
        material = new QSGFlatColorMaterial;
        material->setColor(color);
        setGeometry(geometry);
        setMaterial(material);
        setFlags(QSGNode::OwnsGeometry | QSGNode::OwnsMaterial);
    }

protected:
    QSGGeometry* geometry;
    QSGFlatColorMaterial* material;
};

