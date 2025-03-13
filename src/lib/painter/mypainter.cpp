#include "mypainter.h"

MyPainter::MyPainter(QQuickItem *parent) :
    QQuickPaintedItem(parent)
{
    setAcceptedMouseButtons(Qt::AllButtons); // Принимаем все события мыши
}

void MyPainter::paint(QPainter *painter)
{
    painter->setRenderHint(QPainter::Antialiasing, true); // Включаем сглаживание

    // Рисуем линии между точками
    if (points.size() > 1) {
        painter->setPen(QPen(Qt::black, 2));
        for (int i = 1; i < points.size(); ++i) {
            painter->drawLine(points[i-1], points[i]);
        }
    }
}

void MyPainter::addPoint(const QPointF &point)
{
    points.append(point);
    update(); // Обновляем отрисовку
}
