// #include "rectanglepainter.h"


// RectanglePainter::RectanglePainter(QQuickItem *parent) :
//     QQuickPaintedItem(parent)
// {
// }

// void RectanglePainter::paint(QPainter *painter)
// {
//     // Рисуем все завершенные фигуры
//     // for (const auto& shape : m_shape)
//         // shape->draw(painter);

//     // Рисуем текущую фигуру (если она есть)
//     // if (m_currentShape)
//         // m_currentShape->draw(painter);
// }

// void RectanglePainter::setBegin(const QPoint &point)
// {
//     // rect.push_back(QRect(point, QPoint()));
//     m_currentShape = std::make_unique<Rectangle>();
//     static_cast<Rectangle *>(m_currentShape.get())->m_rect.setTopLeft(point);
//     static_cast<Rectangle *>(m_currentShape.get())->setColor(m_color);
// };

// void RectanglePainter::setEnd(const QPointF &point)
// {
//     Q_UNUSED(point)

//     m_shape.push_back(std::move(m_currentShape));
// }

// void RectanglePainter::preUpdate(const QPoint &point)
// {
//     static_cast<Rectangle *>(m_currentShape.get())->m_rect.setBottomRight(point);
//     update();
// }

// void RectanglePainter::setColor(const QColor &color)
// {
//     m_color = color;
// }


