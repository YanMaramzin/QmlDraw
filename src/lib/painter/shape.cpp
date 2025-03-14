#include "shape.h"

void Shape::setColor(QColor color)
{
    if (m_color == color)
        return;

    m_color = color;
    emit colorChanged();
}

bool Shape::selected() const
{
    return m_selected;
}

void Shape::setSelected(bool selected)
{
    if (m_selected == selected)
        return;

    m_selected = selected;
    emit selectedChanged();
}

// qreal Shape::x() {}

// void Shape::setX(qreal x)
// {
//     Q_UNUSED(x)
// }

// qreal Shape::y() {}

// void Shape::setY(qreal y)
// {
//     Q_UNUSED(y)
// }

// QColor Shape::backgroundColor() const
// {
//     return m_backgroundColor;
// }

// void Shape::setBackgroundColor(const QColor &value)
// {
//     if (m_backgroundColor == value)
//         return;

//     m_backgroundColor = value;
//     emit backgroundColorChanged();
// }


