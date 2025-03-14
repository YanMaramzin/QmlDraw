// rectangleshape.h
#include "shape.h"

class RectangleShape : public Shape
{
    Q_OBJECT
    Q_PROPERTY(qreal width READ width WRITE setWidth NOTIFY geometryChanged)
    Q_PROPERTY(qreal height READ height WRITE setHeight NOTIFY geometryChanged)
public:
    RectangleShape(QRectF rect, QColor color, QObject *parent = nullptr)
        : Shape(Shape::Rectangle, color, parent)
        , m_rect(rect)
    {}

    QSGNode *updateNode(QSGNode *oldNode) override;
    void updateGeometry(const QPointF &startPos, const QPointF &endPos) override;
    QRectF rect() const;
    void setRect(QRectF rect);
    bool contains(const QPointF &point) const override;
    void moveBy(const QPointF &delta) override;

    qreal x() const override { return m_rect.x(); }
    qreal y() const override { return m_rect.y(); }
    qreal width() const { return m_rect.width(); }
    qreal height() const { return m_rect.height(); }

    void setX(qreal x) override;

    void setY(qreal y) override;

    void setWidth(qreal w);

    void setHeight(qreal h);

private:
    QRectF m_rect;
};
