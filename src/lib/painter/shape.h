#pragma once

#include <QColor>
#include <QObject>
#include <QSGNode>

class Shape : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool selected READ selected WRITE setSelected NOTIFY selectedChanged)
public:
    enum Type { Rectangle, Line };
    Q_ENUM(Type)

    Shape(Type type, QColor color, QObject *parent = nullptr)
        : QObject(parent)
        , m_type(type)
        , m_color(color)
    {}

    virtual QSGNode *updateNode(QSGNode *oldNode) = 0;
    virtual void updateGeometry(const QPointF &startPos, const QPointF &endPos) = 0;
    virtual bool contains(const QPointF &point) const = 0;
    virtual void moveBy(const QPointF &delta) = 0;

    Type type() const { return m_type; }
    QColor color() const { return m_color; }
    void setColor(QColor color) { m_color = color; }
    bool selected() const;
    void setSelected(bool value);

signals:
    void selectedChanged();
    void needsUpdate();

protected:
    Type m_type;
    QColor m_color;
    bool m_selected{false};
};
