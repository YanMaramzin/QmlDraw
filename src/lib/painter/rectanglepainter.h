// #ifndef RECTANGLEPAINTER_H
// #define RECTANGLEPAINTER_H

// #include <QQmlEngine>
// #include <QQuickPaintedItem>
// #include <QPainter>
// #include <vector>
// #include <QRect>
// #include <rectangle.h>
// #include <memory>

// class RectanglePainter : public QQuickPaintedItem
// {
//     Q_OBJECT
//     QML_ELEMENT
// public:
//     explicit RectanglePainter(QQuickItem *parent = nullptr);
//     ~RectanglePainter() = default;
//     void paint(QPainter *painter);
//     Q_INVOKABLE void setBegin(const QPoint &point);
//     Q_INVOKABLE void setEnd(const QPointF &point);
//     Q_INVOKABLE void preUpdate(const QPoint &point);
//     Q_INVOKABLE void setColor(const QColor &color);
// private:
//     QPointF pointBeg;
//     QPointF pointEnd;
//     std::vector<std::unique_ptr<Shape>> m_shape;
//     std::unique_ptr<Shape> m_currentShape;
//     QColor m_color {"black"};
// };

// #endif // RECTANGLEPAINTER_H
