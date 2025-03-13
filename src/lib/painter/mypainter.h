#pragma once

#include <QQmlEngine>
#include <QtQmlIntegration>  // Обязательно
#include <QQuickPaintedItem>
#include <QPainter>

class MyPainter : public QQuickPaintedItem
{
    Q_OBJECT
    QML_ELEMENT
public:
    explicit MyPainter(QQuickItem *parent = nullptr);
    ~MyPainter() override = default;

    void paint(QPainter *painter) override;

    // Метод для добавления точки в список для рисования
    Q_INVOKABLE void addPoint(const QPointF &point);

private:
    QList<QPointF> points; // Список точек для рисования
};

