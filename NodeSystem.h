#ifndef NODESYSTEM_H
#define NODESYSTEM_H

#include "diagramitem.h"

#include <QMainWindow>

class DiagramScene;

QT_BEGIN_NAMESPACE
class QAction;
class QToolBox;
class QSpinBox;
class QComboBox;
class QFontComboBox;
class QButtonGroup;
class QLineEdit;
class QGraphicsTextItem;
class QFont;
class QToolButton;
class QAbstractButton;
class QGraphicsView;
QT_END_NAMESPACE

class NodeSystem : public QMainWindow
{
	Q_OBJECT

public:
	NodeSystem();

private slots:
	void addNodeItem();
	void deleteItem();
	void pointerGroupClicked(int id);
	void itemInserted(DiagramItem *item);
	void sceneScaleChanged(const QString &scale);

private:
	void createActions();
	void createToolbars();

	DiagramScene *scene;
	QGraphicsView *view;

	QAction *exitAction;
	QAction *addAction;
	QAction *deleteAction;

	QAction *toFrontAction;
	QAction *sendBackAction;
	QAction *aboutAction;

	QMenu *fileMenu;
	QMenu *itemMenu;
	QMenu *aboutMenu;

	QToolBar *textToolBar;
	QToolBar *editToolBar;
	QToolBar *colorToolBar;
	QToolBar *pointerToolbar;

	QComboBox *sceneScaleCombo;
	QComboBox *itemColorCombo;
	QComboBox *textColorCombo;
	QComboBox *fontSizeCombo;
	QFontComboBox *fontCombo;

	QToolBox *toolBox;
	QButtonGroup *buttonGroup;
	QButtonGroup *pointerTypeGroup;
	QButtonGroup *backgroundButtonGroup;
	QToolButton *fontColorToolButton;
	QToolButton *fillColorToolButton;
	QToolButton *lineColorToolButton;
	QAction *boldAction;
	QAction *underlineAction;
	QAction *italicAction;
	QAction *textAction;
	QAction *fillAction;
	QAction *lineAction;
};

#endif // NODESYSTEM_H