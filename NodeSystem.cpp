#include "arrow.h"
#include "diagramitem.h"
#include "diagramscene.h"
#include "NodeSystem.h"

#include <QtWidgets>

const int InsertTextButton = 10;

NodeSystem::NodeSystem()
{
	createActions();

	scene = new DiagramScene(itemMenu, this);
	scene->setSceneRect(QRectF(0, 0, 5000, 5000));
	connect(scene, SIGNAL(itemInserted(DiagramItem*)),
		this, SLOT(itemInserted(DiagramItem*)));
	connect(scene, SIGNAL(textInserted(QGraphicsTextItem*)),
		this, SLOT(textInserted(QGraphicsTextItem*)));
	connect(scene, SIGNAL(itemSelected(QGraphicsItem*)),
		this, SLOT(itemSelected(QGraphicsItem*)));
	createToolbars();

	//QHBoxLayout *layout = new QHBoxLayout;
	//layout->addWidget(toolBox);
	view = new QGraphicsView(scene);
	//layout->addWidget(view);

	//QWidget *widget = new QWidget;
	//widget->setLayout(layout);

	QSplitter* m_mainSplitter = new QSplitter(Qt::Horizontal, this);
	QWidget *nodeWidget = new QWidget;
	m_mainSplitter->addWidget(nodeWidget);
	m_mainSplitter->addWidget(view);
	m_mainSplitter->setSizes({ 200, 800 });

	setCentralWidget(m_mainSplitter);
	setWindowTitle(tr("Node System"));
	setUnifiedTitleAndToolBarOnMac(true);
}

void NodeSystem::addNodeItem()
{
	scene->setMode(DiagramScene::InsertItem);
}

void NodeSystem::deleteItem()
{
	foreach(QGraphicsItem *item, scene->selectedItems()) {
		if (item->type() == Arrow::Type) {
			scene->removeItem(item);
			Arrow *arrow = qgraphicsitem_cast<Arrow *>(item);
			arrow->startItem()->removeArrow(arrow);
			arrow->endItem()->removeArrow(arrow);
			delete item;
		}
	}

	foreach(QGraphicsItem *item, scene->selectedItems()) {
		if (item->type() == DiagramItem::Type)
			qgraphicsitem_cast<DiagramItem *>(item)->removeArrows();
		scene->removeItem(item);
		delete item;
	}
}

void NodeSystem::pointerGroupClicked(int)
{
	scene->setMode(DiagramScene::Mode(pointerTypeGroup->checkedId()));
}

void NodeSystem::itemInserted(DiagramItem *item)
{
	pointerTypeGroup->button(int(DiagramScene::MoveItem))->setChecked(true);
	scene->setMode(DiagramScene::Mode(pointerTypeGroup->checkedId()));
}

void NodeSystem::sceneScaleChanged(const QString &scale)
{
	double newScale = scale.left(scale.indexOf(tr("%"))).toDouble() / 100.0;
	QMatrix oldMatrix = view->matrix();
	view->resetMatrix();
	view->translate(oldMatrix.dx(), oldMatrix.dy());
	view->scale(newScale, newScale);
}

void NodeSystem::createActions()
{
	addAction = new QAction(QIcon(":/images/add-node"), tr("&Add"), this);
	addAction->setStatusTip(tr("Add a node"));
	connect(addAction, SIGNAL(triggered()), this, SLOT(addNodeItem()));

	deleteAction = new QAction(QIcon(":/images/del-node"), tr("&Delete"), this);
	deleteAction->setShortcut(tr("Delete"));
	deleteAction->setStatusTip(tr("Delete item from diagram"));
	connect(deleteAction, SIGNAL(triggered()), this, SLOT(deleteItem()));

	exitAction = new QAction(tr("E&xit"), this);
	exitAction->setShortcuts(QKeySequence::Quit);
	exitAction->setStatusTip(tr("Quit Scenediagram example"));
	connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));
}

void NodeSystem::createToolbars()
{
	editToolBar = addToolBar(tr("Edit"));
	editToolBar->addAction(addAction);
	editToolBar->addAction(deleteAction);

	QToolButton *pointerButton = new QToolButton;
	pointerButton->setCheckable(true);
	pointerButton->setChecked(true);
	pointerButton->setIcon(QIcon(":/images/pointer"));
	QToolButton *linePointerButton = new QToolButton;
	linePointerButton->setCheckable(true);
	linePointerButton->setIcon(QIcon(":/images/linepointer"));

	pointerTypeGroup = new QButtonGroup(this);
	pointerTypeGroup->addButton(pointerButton, int(DiagramScene::MoveItem));
	pointerTypeGroup->addButton(linePointerButton, int(DiagramScene::InsertLine));
	connect(pointerTypeGroup, SIGNAL(buttonClicked(int)),
		this, SLOT(pointerGroupClicked(int)));

	sceneScaleCombo = new QComboBox;
	QStringList scales;
	scales << tr("50%") << tr("75%") << tr("100%") << tr("125%") << tr("150%");
	sceneScaleCombo->addItems(scales);
	sceneScaleCombo->setCurrentIndex(2);
	connect(sceneScaleCombo, SIGNAL(currentIndexChanged(QString)),
		this, SLOT(sceneScaleChanged(QString)));

	pointerToolbar = addToolBar(tr("Pointer type"));
	pointerToolbar->addWidget(pointerButton);
	pointerToolbar->addWidget(linePointerButton);
	pointerToolbar->addWidget(sceneScaleCombo);
}
