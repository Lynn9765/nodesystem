#include "diagramscene.h"
#include "arrow.h"

#include <QTextCursor>
#include <QGraphicsSceneMouseEvent>

DiagramScene::DiagramScene(QMenu *itemMenu, QObject *parent)
	: QGraphicsScene(parent)
{
	myItemMenu = itemMenu;
	myMode = MoveItem;
	myItemType = DiagramItem::Step;
	line = 0;
	myItemColor = Qt::white;
	myTextColor = Qt::black;
	myLineColor = Qt::black;
}

void DiagramScene::setMode(Mode mode)
{
	myMode = mode;
}

void DiagramScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
	if (mouseEvent->button() != Qt::LeftButton)
		return;

	DiagramItem *item;
	switch (myMode) {
	case InsertItem:
		item = new DiagramItem(myItemType, myItemMenu);
		item->setBrush(myItemColor);
		addItem(item);
		item->setPos(mouseEvent->scenePos().x() - 100, mouseEvent->scenePos().y() - 50);
		emit itemInserted(item);
		break;

	case InsertLine:
		line = new QGraphicsLineItem(QLineF(mouseEvent->scenePos(),
			mouseEvent->scenePos()));
		line->setPen(QPen(myLineColor, 2));
		addItem(line);
		break;
	}
	QGraphicsScene::mousePressEvent(mouseEvent);
}

void DiagramScene::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
	if (myMode == InsertLine && line != 0) {
		QLineF newLine(line->line().p1(), mouseEvent->scenePos());
		line->setLine(newLine);
	}
	else if (myMode == MoveItem) {
		QGraphicsScene::mouseMoveEvent(mouseEvent);
	}
}

void DiagramScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
	if (line != 0 && myMode == InsertLine) {
		QList<QGraphicsItem *> startItems = items(line->line().p1());
		if (startItems.count() && startItems.first() == line)
			startItems.removeFirst();
		QList<QGraphicsItem *> endItems = items(line->line().p2());
		if (endItems.count() && endItems.first() == line)
			endItems.removeFirst();

		removeItem(line);
		delete line;

		if (startItems.count() > 0 && endItems.count() > 0 &&
			startItems.first()->type() == DiagramItem::Type &&
			endItems.first()->type() == DiagramItem::Type &&
			startItems.first() != endItems.first()) {
			DiagramItem *startItem = qgraphicsitem_cast<DiagramItem *>(startItems.first());
			DiagramItem *endItem = qgraphicsitem_cast<DiagramItem *>(endItems.first());
			Arrow *arrow = new Arrow(startItem, endItem);
			arrow->setColor(myLineColor);
			startItem->addArrow(arrow);
			endItem->addArrow(arrow);
			arrow->setZValue(-1000.0);
			addItem(arrow);
			arrow->updatePosition();
		}
	}
	line = 0;
	QGraphicsScene::mouseReleaseEvent(mouseEvent);
}
