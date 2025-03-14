#pragma once
#include <QLineF>
#include <shape.h>

class LineShape : public Shape
{
    Q_OBJECT
    Q_PROPERTY(qreal x2 READ x2 WRITE setX2 NOTIFY geometryChanged)
    Q_PROPERTY(qreal y2 READ y2 WRITE setY2 NOTIFY geometryChanged)
public:
    LineShape(QLineF line, QColor color, QObject *parent = nullptr)
        : Shape(Shape::Line, color, parent)
    {}

    QSGNode *updateNode(QSGNode *oldNode) override;
    void updateGeometry(const QPointF &startPos, const QPointF &endPos) override;

    QLineF line() const;
    void setLine(const QLineF &line);

    bool contains(const QPointF &point) const override;
    void moveBy(const QPointF &delta) override;

    qreal x() const override { return m_line.x1(); }
    qreal y() const override { return m_line.y1(); }
    qreal x2() const { return m_line.x2(); }
    qreal y2() const { return m_line.y2(); }

    void setX(qreal x) override;

    void setY(qreal y) override;

    void setX2(qreal x2);

    void setY2(qreal y2);

private:
    QLineF m_line;
};
