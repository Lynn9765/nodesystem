#ifndef DIAGRAMITEM_H
#define DIAGRAMITEM_H

#include <QGraphicsPixmapItem>
#include <QList>

QT_BEGIN_NAMESPACE
class QPixmap;
class QGraphicsItem;
class QGraphicsScene;
class QTextEdit;
class QGraphicsSceneMouseEvent;
class QMenu;
class QGraphicsSceneContextMenuEvent;
class QPainter;
class QStyleOptionGraphicsItem;
class QWidget;
class QPolygonF;
QT_END_NAMESPACE

class Arrow;

class DiagramItem : public QGraphicsPolygonItem
{
public:
	enum { Type = UserType + 15 };
	enum DiagramType { Step, Conditional, StartEnd, Io };

	DiagramItem(DiagramType diagramType, QMenu *contextMenu, QGraphicsItem *parent = 0);

	void removeArrow(Arrow *arrow);
	void removeArrows();
	DiagramType diagramType() const { return myDiagramType; }
	QPolygonF polygon() const { return myPolygon; }
	void addArrow(Arrow *arrow);
	int type() const override { return Type; }

protected:
	QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;

private:
	DiagramType myDiagramType;
	QPolygonF myPolygon;
	QMenu *myContextMenu;
	QList<Arrow *> arrows;
};

#endif // DIAGRAMITEM_H