#include "diagramitem.h"
#include "arrow.h"

#include <QGraphicsScene>
#include <QGraphicsSceneContextMenuEvent>
#include <QMenu>
#include <QPainter>

DiagramItem::DiagramItem(DiagramType diagramType, QMenu *contextMenu,
	QGraphicsItem *parent)
	: QGraphicsPolygonItem(parent)
{
	myDiagramType = diagramType;
	myContextMenu = contextMenu;

	QPainterPath path;
	path.moveTo(50,0);
	path.arcTo(0, 0, 100, 100, 90, 180);
	path.lineTo(150,100);
	path.arcTo(100,0,100,100,270,180);
	path.lineTo(50, 0);
	myPolygon = path.toFillPolygon();

	setPolygon(myPolygon);
	setFlag(QGraphicsItem::ItemIsMovable, true);
	setFlag(QGraphicsItem::ItemIsSelectable, true);
	setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
}

void DiagramItem::removeArrow(Arrow *arrow)
{
	int index = arrows.indexOf(arrow);

	if (index != -1)
		arrows.removeAt(index);
}

void DiagramItem::removeArrows()
{
	foreach(Arrow *arrow, arrows) {
		arrow->startItem()->removeArrow(arrow);
		arrow->endItem()->removeArrow(arrow);
		scene()->removeItem(arrow);
		delete arrow;
	}
}

void DiagramItem::addArrow(Arrow *arrow)
{
	arrows.append(arrow);
}

QVariant DiagramItem::itemChange(GraphicsItemChange change, const QVariant &value)
{
	if (change == QGraphicsItem::ItemPositionChange) {
		foreach(Arrow *arrow, arrows) {
			arrow->updatePosition();
		}
	}

	return value;
}
