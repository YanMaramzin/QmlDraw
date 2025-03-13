#include "shape.h"

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


