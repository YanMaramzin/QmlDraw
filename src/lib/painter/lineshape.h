#pragma once
#include <QLineF>
#include <shape.h>

class LineShape : public Shape
{
    Q_OBJECT
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

private:
    QLineF m_line;
};
