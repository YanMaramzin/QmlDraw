// rectangleshape.h
#include "shape.h"

class RectangleShape : public Shape
{
    Q_OBJECT
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

private:
    QRectF m_rect;
};
