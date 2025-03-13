// canvasitem.cpp
#include "canvasitem.h"
#include "lineshape.h"
#include "rectangleshape.h"

#include <QSGFlatColorMaterial>

CanvasItem::CanvasItem(QQuickItem *parent)
    : QQuickItem(parent)
{
    setFlag(ItemHasContents, true);
    setAcceptedMouseButtons(Qt::LeftButton);
    setAntialiasing(true);
}

bool CanvasItem::editMode()
{
    return m_editMode;
}

void CanvasItem::setEditMode(bool value)
{
    if (m_editMode == value)
        return;

    m_editMode = value;
    emit editModeChanged();
}

void CanvasItem::clear()
{
    m_shapes.clear();
    m_model->clearShape();
    update();
}

void CanvasItem::deleteSelected()
{
    if (!m_selectedShape)
        return;

    m_shapes.removeOne(m_selectedShape);
    delete m_selectedShape;
    m_selectedShape = nullptr;
    update();
}

void CanvasItem::setDrawingColor(QColor color)
{
    if (m_drawingColor == color)
        return;

    m_drawingColor = color;
    emit drawingColorChanged();
}

void CanvasItem::setDrawingType(ShapeType type)
{
    if (m_drawingType == type)
        return;

    m_drawingType = type;
    emit drawingTypeChanged();
}

Shape *CanvasItem::selectedShape() const
{
    return m_selectedShape;
}

QSGNode *CanvasItem::updatePaintNode(QSGNode *oldNode, UpdatePaintNodeData *)
{
    QSGNode *rootNode = oldNode ? oldNode : new QSGNode;

    qDebug() << "After: rootNode" << m_shapes;
    // Удаляем старые узлы
    while (rootNode->childCount() > 0)
        rootNode->removeChildNode(rootNode->firstChild());

    qDebug() << "After: " << m_shapes;
    // Добавляем все фигуры
    for (Shape *shape : m_shapes)
        rootNode->appendChildNode(shape->updateNode(nullptr));
    qDebug() << "Before:" << m_shapes;

    if (m_selectedShape) {
        QSGGeometryNode *borderNode = createSelectionBorder(m_selectedShape);
        rootNode->appendChildNode(borderNode);
    }

    // Добавляем превью
    if (m_previewShape) {
        rootNode->appendChildNode(m_previewShape->updateNode(nullptr));
    }
    qDebug() << "Before: m_previewShape" << m_shapes;

    return rootNode;
}

void CanvasItem::mousePressEvent(QMouseEvent *event)
{
    m_startPos = event->position();
    m_isDrawing = true;

    // Создаем фигуру для превью
    switch (m_drawingType) {
    case ShapeType::Rectangle:
        m_previewShape = new RectangleShape(QRectF(m_startPos, m_startPos), m_drawingColor, this);
        break;
    case ShapeType::Line:
        m_previewShape = new LineShape(QLineF(m_startPos, m_startPos), m_drawingColor, this);
        break;
    case ShapeType::None: {
        Shape *clickedShape = findShapeAt(event->position());
        if (!clickedShape)
            break;

        if (m_selectedShape)
            m_selectedShape->setSelected(false);

        m_selectedShape = clickedShape;
        m_selectedShape->setSelected(true);
        m_lastMousePos = event->position();
        m_editMode = true;
    }
    }

    update();
}

void CanvasItem::mouseMoveEvent(QMouseEvent *event)
{
    if (m_isDrawing && m_previewShape) {
        qDebug() << "drawPreview";
        updatePreviewShape(event->position());
        update();
    } else if (m_editMode && m_selectedShape) {
        qDebug() << "editMode ";
        QPointF delta = event->position() - m_lastMousePos;
        m_selectedShape->moveBy(delta);
        m_lastMousePos = event->position();
        update();
    }
}

void CanvasItem::mouseReleaseEvent(QMouseEvent *event)
{
    if (!m_isDrawing)
        return;

    if (!m_previewShape)
        return;

    updatePreviewShape(event->position());
    m_shapes.append(m_previewShape);
    m_model->addShape(m_previewShape);
    m_previewShape = nullptr;
    m_isDrawing = false;
    update();
}

void CanvasItem::updatePreviewShape(const QPointF &endPos)
{
    if (!m_previewShape)
        return;

    switch (m_drawingType) {
    case ShapeType::Rectangle: {
        auto *rect = static_cast<RectangleShape *>(m_previewShape);
        rect->setRect(QRectF(m_startPos, endPos).normalized());
        break;
    }
    case ShapeType::Line: {
        auto *line = static_cast<LineShape *>(m_previewShape);
        line->setLine(QLineF(m_startPos, endPos));
        break;
    }
    case ShapeType::None: {
        break;
    }
    }
}

Shape *CanvasItem::findShapeAt(const QPointF &pos) const
{
    for (Shape *shape : m_shapes) {
        if (shape->contains(pos))
            return shape;
    }
    return nullptr;
}

QSGGeometryNode *CanvasItem::createSelectionBorder(Shape *shape)
{
    QSGGeometryNode *node = new QSGGeometryNode();
    QSGGeometry *geometry = new QSGGeometry(QSGGeometry::defaultAttributes_Point2D(), 5);

    geometry->setLineWidth(2);
    geometry->setDrawingMode(QSGGeometry::DrawLineLoop);

    QRectF rect;
    if (shape->type() == Shape::Rectangle) {
        rect = static_cast<RectangleShape *>(shape)->rect();
    }
    // ... обработка других типов фигур ...

    QSGGeometry::Point2D *vertices = geometry->vertexDataAsPoint2D();
    vertices[0].set(rect.left(), rect.top());
    vertices[1].set(rect.right(), rect.top());
    vertices[2].set(rect.right(), rect.bottom());
    vertices[3].set(rect.left(), rect.bottom());
    vertices[4].set(rect.left(), rect.top());

    QSGFlatColorMaterial *material = new QSGFlatColorMaterial;
    material->setColor(Qt::red);

    node->setGeometry(geometry);
    node->setMaterial(material);
    node->setFlags(QSGNode::OwnsGeometry | QSGNode::OwnsMaterial);

    return node;
}

void CanvasItem::setSelectedShape(Shape *shape)
{
    if (m_selectedShape == shape)
        return;

    if (m_selectedShape)
        m_selectedShape->setSelected(false);

    m_selectedShape = shape;

    if (m_selectedShape)
        m_selectedShape->setSelected(true);

    emit selectedShapeChanged();
    update();
}
