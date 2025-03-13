#pragma once

#include <QAbstractListModel>
#include "shape.h"

class ShapesModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum Roles { TypeRole = Qt::UserRole + 1, ColorRole, ShapePtrRole };

    explicit ShapesModel(QObject *parent = nullptr);
    ~ShapesModel() override = default;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

    void addShape(Shape *shape);
    void removeShape(int index);
    void clearShape();
    Shape *getShape(int index) const;

private:
    QList<Shape *> m_shapes;
};
