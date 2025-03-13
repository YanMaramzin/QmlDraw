#include "shapesmodel.h"

ShapesModel::ShapesModel(QObject *parent)
    : QAbstractListModel(parent)
{}

int ShapesModel::rowCount(const QModelIndex &) const
{
    return m_shapes.size();
}

QVariant ShapesModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    const auto *shape = m_shapes[index.row()];
    switch (role) {
    case TypeRole:
        return shape->type();
    case ColorRole:
        return shape->color();
    case ShapePtrRole:
        return QVariant::fromValue(shape);
    }
    return QVariant();
}

QHash<int, QByteArray> ShapesModel::roleNames() const
{
    return {{TypeRole, "type"}, {ColorRole, "color"}, {ShapePtrRole, "shapePtr"}};
}

void ShapesModel::addShape(Shape *shape)
{
    beginInsertRows(QModelIndex(), m_shapes.size(), m_shapes.size());
    m_shapes.append(shape);
    endInsertRows();
}

void ShapesModel::removeShape(int index)
{
    if (index < 0 || index >= m_shapes.size())
        return;
    beginRemoveRows(QModelIndex(), index, index);
    m_shapes.removeAt(index);
    endRemoveRows();
}

void ShapesModel::clearShape()
{
    beginResetModel();
    m_shapes.clear();
    endResetModel();
}

Shape *ShapesModel::getShape(int index) const
{
    return m_shapes.value(index, nullptr);
}
