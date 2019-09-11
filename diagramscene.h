#ifndef DIAGRAMSCENE_H
#define DIAGRAMSCENE_H

#include "diagramitem.h"

#include <QGraphicsScene>

QT_BEGIN_NAMESPACE
class QGraphicsSceneMouseEvent;
class QMenu;
class QPointF;
class QGraphicsLineItem;
class QFont;
class QGraphicsTextItem;
class QColor;
QT_END_NAMESPACE

class DiagramScene : public QGraphicsScene
{
	Q_OBJECT

public:
	enum Mode { InsertItem, InsertLine, InsertText, MoveItem };

	explicit DiagramScene(QObject *parent = 0);
	QFont font() const { return myFont; }
	QColor textColor() const { return myTextColor; }
	QColor itemColor() const { return myItemColor; }
	QColor lineColor() const { return myLineColor; }

	public slots:
	void setMode(Mode mode);

signals:
	void itemInserted(DiagramItem *item);

protected:
	void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
	void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
	void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent) override;

private:
	Mode myMode;
	bool leftButtonDown;
	QPointF startPoint;
	QGraphicsLineItem *line;
	QFont myFont;
	QColor myTextColor;
	QColor myItemColor;
	QColor myLineColor;
};

#endif // DIAGRAMSCENE_H