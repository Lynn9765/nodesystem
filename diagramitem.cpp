#include "diagramitem.h"
#include "arrow.h"

#include <QGraphicsScene>
#include <QGraphicsSceneContextMenuEvent>
#include <QPainter>

DiagramItem::DiagramItem()
	: color(qrand() % 256, qrand() % 256, qrand() % 256)
{
	setFlag(QGraphicsItem::ItemIsMovable, true);
	setFlag(QGraphicsItem::ItemIsSelectable, true);
	setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
}

QRectF DiagramItem::boundingRect() const
{
	return QRectF(0, 0, 200, 100);
}

QPainterPath DiagramItem::shape() const
{
	QPainterPath path;
	path.addRect(0, 0, 200, 100);
	return path;
}

void DiagramItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
	QPainterPath path;
	path.moveTo(50, 0);
	path.arcTo(0, 0, 100, 100, 90, 180);
	path.lineTo(150, 100);
	path.arcTo(100, 0, 100, 100, 270, 180);
	path.lineTo(50, 0);
	myPolygon = path.toFillPolygon();

	painter->setBrush(color);
	painter->drawPath(path);

	painter->setPen(Qt::black);
	painter->drawText(boundingRect(), Qt::AlignCenter, "New Node");

	if (isSelected())
	{
		painter->setPen(QPen(Qt::DashLine));
		painter->setBrush(Qt::NoBrush);
		painter->drawRect(boundingRect());
	}
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
