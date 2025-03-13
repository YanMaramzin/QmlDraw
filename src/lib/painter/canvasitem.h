#pragma once

// canvasitem.h
#include <QList>
#include <QQuickItem>
#include "shape.h"
#include "shapesmodel.h"

class CanvasItem : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QColor drawingColor READ drawingColor WRITE setDrawingColor NOTIFY drawingColorChanged)
    Q_PROPERTY(ShapeType drawingType READ drawingType WRITE setDrawingType NOTIFY drawingTypeChanged)
    Q_PROPERTY(bool editMode READ editMode WRITE setEditMode NOTIFY editModeChanged FINAL)
    Q_PROPERTY(ShapesModel *shapesModel READ shapesModel CONSTANT)
    Q_PROPERTY(
        Shape *selectedShape READ selectedShape WRITE setSelectedShape NOTIFY selectedShapeChanged)
    QML_ELEMENT
public:
    enum ShapeType { None, Rectangle, Line };
    Q_ENUM(ShapeType)

    explicit CanvasItem(QQuickItem *parent = nullptr);

    QColor drawingColor() const { return m_drawingColor; }
    ShapeType drawingType() const { return m_drawingType; }
    bool editMode();
    void setEditMode(bool value);

    Q_INVOKABLE void clear();
    Q_INVOKABLE void deleteSelected();
    ShapesModel *shapesModel() const { return m_model; }

    void setDrawingColor(QColor color);
    void setDrawingType(ShapeType type);
    Shape *selectedShape() const;
    void setSelectedShape(Shape *shape);

signals:
    void drawingColorChanged();
    void drawingTypeChanged();
    void editModeChanged();
    void selectedShapeChanged();

protected:
    QSGNode *updatePaintNode(QSGNode *oldNode, UpdatePaintNodeData *) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    void updatePreviewShape(const QPointF &endPos);
    Shape *findShapeAt(const QPointF &pos) const;
    void updateSelectionIndicator();
    QSGGeometryNode *createSelectionBorder(Shape *shape);

    QColor m_drawingColor = Qt::blue;
    ShapeType m_drawingType = ShapeType::Line;
    QList<Shape *> m_shapes;
    Shape *m_previewShape = nullptr;
    Shape *m_selectedShape = nullptr;
    QPointF m_lastMousePos;
    bool m_editMode = false;
    QPointF m_startPos;
    bool m_isDrawing = false;
    ShapesModel *m_model = new ShapesModel(this);
};

// // canvasitem.h
// #include <QQuickItem>
// #include <QList>
// #include <QSGNode>

// class CanvasItem : public QQuickItem {
//     Q_OBJECT
//     Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)
//     Q_PROPERTY(int shapeType READ shapeType WRITE setShapeType NOTIFY shapeTypeChanged)
//     Q_PROPERTY(int selectedIndex READ selectedIndex WRITE setSelectedIndex NOTIFY selectedIndexChanged)
//     QML_ELEMENT

// public:
//     enum ShapeType
//     {
//         Line,
//         Rectangle,
//         Edit
//     };
//     Q_ENUM(ShapeType)

//     CanvasItem(QQuickItem* parent = nullptr);

//     QColor color() const;
//     void setColor(QColor color);

//     int shapeType() const;
//     void setShapeType(int type);

//     int selectedIndex() const;
//     void setSelectedIndex(int index);

//     Q_INVOKABLE void clear();
//     Q_INVOKABLE void deleteSelected();

// signals:
//     void colorChanged();
//     void shapeTypeChanged();
//     void selectedIndexChanged();

// protected:
//     QSGNode* updatePaintNode(QSGNode* oldNode, UpdatePaintNodeData*) override;
//     void mousePressEvent(QMouseEvent* event) override;
//     void mouseMoveEvent(QMouseEvent* event) override;
//     void mouseReleaseEvent(QMouseEvent* event) override;
//     void updatePreview();
//     void updateShape();

// private:
//     struct ShapeData {
//         QRectF rect;
//         QColor color;
//         bool isSelected = false;
//     };

//     void updatePreviewGeometry();
//     void finalizeShape();
//     int findShapeAt(QPointF pos) const;

//     QColor m_color = Qt::blue;
//     ShapeType m_shapeType = Line;
//     QSGNode* m_previewNode = nullptr;
//     QPointF m_currentPos;
//     QList<QSGNode*> m_shapes;
//     QPointF m_startPos;
//     int m_selectedIndex = -1;
// };

// canvasitem.h
// #include <QQuickItem>
// #include <QSGGeometryNode>
// #include <QList>

// class CanvasItem : public QQuickItem {
//     Q_OBJECT
//     Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)
//     Q_PROPERTY(int shapeType READ shapeType WRITE setShapeType NOTIFY shapeTypeChanged)
//     Q_PROPERTY(int selectedIndex READ selectedIndex WRITE setSelectedIndex NOTIFY selectedIndexChanged)
//     QML_ELEMENT

// public:
//     enum ShapeType { Line, Rectangle, Edit };
//     Q_ENUM(ShapeType)

//     enum ShapeKind { LineShape, RectangleShape };
//     Q_ENUM(ShapeKind)

//     explicit CanvasItem(QQuickItem* parent = nullptr);

//     QColor color() const;
//     void setColor(QColor color);

//     int shapeType() const;
//     void setShapeType(int type);

//     int selectedIndex() const { return m_selectedIndex; }
//     void setSelectedIndex(int index);

//     Q_INVOKABLE void clear();
//     Q_INVOKABLE void deleteSelected();
//     Q_INVOKABLE void updateSelectedGeometry(qreal x1, qreal y1, qreal x2, qreal y2);

// signals:
//     void colorChanged();
//     void shapeTypeChanged();
//     void selectedIndexChanged();

// protected:
//     QSGNode* updatePaintNode(QSGNode* oldNode, UpdatePaintNodeData*) override;
//     void mousePressEvent(QMouseEvent* event) override;
//     void mouseMoveEvent(QMouseEvent* event) override;
//     void mouseReleaseEvent(QMouseEvent* event) override;

// private:
//     struct ShapeData {
//         ShapeKind type;
//         QColor color;
//         bool isSelected = false;
//         QVector<QPointF> points;
//     };

//     void updatePreviewGeometry();
//     void finalizeShape();
//     int findShapeAt(QPointF pos) const;
//     bool isPointNearLine(const QPointF& point, const QPointF& p1, const QPointF& p2) const;

//     QColor m_color = Qt::blue;
//     ShapeType m_shapeType = Line;
//     int m_selectedIndex = -1;
//     QPointF m_startPos;
//     QPointF m_currentPos;
//     QList<ShapeData> m_shapes;
//     QSGGeometryNode* m_previewNode = nullptr;
//     QSGGeometryNode* m_selectionNode = nullptr;
// };
