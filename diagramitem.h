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

struct nodeMsg
{
	QString name;
	QString leader;
	QString teammate1;
	QString teammate2;
	QString teammate3;
	QString description;
};

class DiagramItem : public QGraphicsPolygonItem
{
public:
	enum { Type = UserType + 15 };
	DiagramItem();

	QRectF boundingRect() const override;
	QPainterPath shape() const override;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
	QPolygonF polygon() const { return myPolygon; }
	void removeArrow(Arrow *arrow);
	void removeArrows();
	void addArrow(Arrow *arrow);
	int type() const override { return Type; }

protected:
	QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;

private:
	nodeMsg *msg;
	QColor color;
	QPolygonF myPolygon;
	QList<Arrow *> arrows;
};

#endif // DIAGRAMITEM_H