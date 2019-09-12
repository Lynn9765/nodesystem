#ifndef NODESYSTEM_H
#define NODESYSTEM_H

#include "diagramitem.h"

#include <QMainWindow>

class DiagramScene;

QT_BEGIN_NAMESPACE
class QAction;
class QSpinBox;
class QComboBox;
class QButtonGroup;
class QLineEdit;
class QGraphicsTextItem;
class QFont;
class QToolButton;
class QAbstractButton;
class QGraphicsView;
class QPushButton;
class QColorDialog;
class QColor;
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
	void colorBtnClicked();
	void setColor(QColor);

private:
	void createActions();
	void createToolbars();
	void createNodeEditor();

	DiagramScene *scene;
	QGraphicsView *view;
	QWidget *nodeEditor;
	QAction *exitAction;
	QAction *addAction;
	QAction *deleteAction;

	QToolBar *editToolBar;
	QToolBar *pointerToolbar;
	QComboBox *sceneScaleCombo;
	QButtonGroup *pointerTypeGroup;

	QLineEdit *lineEdit1;
	QLineEdit *lineEdit2;
	QLineEdit *lineEdit3;
	QTextEdit *textEdit;

	QPushButton *colorBtn;
	QPushButton *saveBtn;
};

#endif // NODESYSTEM_H