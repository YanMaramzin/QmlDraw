// rectangleshape.cpp
#include <QSGFlatColorMaterial>
#include <QSGGeometryNode>
#include <rectangleshape.h>

QSGNode *RectangleShape::updateNode(QSGNode *oldNode)
{
    QSGGeometryNode *node = static_cast<QSGGeometryNode *>(oldNode);
    if (!node) {
        node = new QSGGeometryNode;
        node->setGeometry(new QSGGeometry(QSGGeometry::defaultAttributes_Point2D(), 4));
        node->setMaterial(new QSGFlatColorMaterial);
        node->geometry()->setDrawingMode(QSGGeometry::DrawTriangleStrip);
    }

    QSGGeometry::Point2D *vertices = node->geometry()->vertexDataAsPoint2D();
    vertices[0].set(m_rect.left(), m_rect.top());
    vertices[1].set(m_rect.right(), m_rect.top());
    vertices[2].set(m_rect.left(), m_rect.bottom());
    vertices[3].set(m_rect.right(), m_rect.bottom());

    static_cast<QSGFlatColorMaterial *>(node->material())->setColor(m_color);

    return node;
}

void RectangleShape::updateGeometry(const QPointF &startPos, const QPointF &endPos)
{
    m_rect = QRectF(startPos, endPos).normalized();
    emit needsUpdate();
}

QRectF RectangleShape::rect() const
{
    return m_rect;
}

void RectangleShape::setRect(QRectF rect)
{
    m_rect = rect.normalized();
    emit needsUpdate();
}

bool RectangleShape::contains(const QPointF &point) const
{
    return m_rect.contains(point);
}

void RectangleShape::moveBy(const QPointF &delta)
{
    m_rect.translate(delta);
    emit needsUpdate();
}
