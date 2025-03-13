#include "lineshape.h"
#include <QSGFlatColorMaterial>

QSGNode *LineShape::updateNode(QSGNode *oldNode)
{
    QSGGeometryNode* node = static_cast<QSGGeometryNode*>(oldNode);
    if (!node) {
        node = new QSGGeometryNode;
        node->setGeometry(new QSGGeometry(QSGGeometry::defaultAttributes_Point2D(), 2));
        node->setMaterial(new QSGFlatColorMaterial);
        node->geometry()->setDrawingMode(QSGGeometry::DrawLines);
        node->geometry()->setLineWidth(2.0f);
    }

    QSGGeometry::Point2D* vertices = node->geometry()->vertexDataAsPoint2D();
    vertices[0].set(m_line.x1(), m_line.y1());
    vertices[1].set(m_line.x2(), m_line.y2());

    static_cast<QSGFlatColorMaterial*>(node->material())->setColor(m_color);

    return node;
}

void LineShape::updateGeometry(const QPointF& startPos, const QPointF &endPos)
{
    m_line = QLineF(startPos, endPos);
}

QLineF LineShape::line() const
{
    return m_line;
}

void LineShape::setLine(const QLineF &line)
{
    if (m_line == line)
        return;

    m_line = line;
    emit needsUpdate();
}

bool LineShape::contains(const QPointF &point) const
{
    QLineF l = m_line;
    qreal distance = qAbs((l.y2() - l.y1()) * point.x() - (l.x2() - l.x1()) * point.y()
                          + l.x2() * l.y1() - l.y2() * l.x1())
                     / qSqrt(qPow(l.y2() - l.y1(), 2) + qPow(l.x2() - l.x1(), 2));

    return distance < 5.0; // Порог в пикселях
}

void LineShape::moveBy(const QPointF &delta)
{
    m_line.translate(delta);
    emit needsUpdate();
}
