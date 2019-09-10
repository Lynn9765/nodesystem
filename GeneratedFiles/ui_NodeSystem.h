/********************************************************************************
** Form generated from reading UI file 'NodeSystem.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NODESYSTEM_H
#define UI_NODESYSTEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NodeSystemClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *NodeSystemClass)
    {
        if (NodeSystemClass->objectName().isEmpty())
            NodeSystemClass->setObjectName(QStringLiteral("NodeSystemClass"));
        NodeSystemClass->resize(600, 400);
        menuBar = new QMenuBar(NodeSystemClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        NodeSystemClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(NodeSystemClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        NodeSystemClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(NodeSystemClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        NodeSystemClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(NodeSystemClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        NodeSystemClass->setStatusBar(statusBar);

        retranslateUi(NodeSystemClass);

        QMetaObject::connectSlotsByName(NodeSystemClass);
    } // setupUi

    void retranslateUi(QMainWindow *NodeSystemClass)
    {
        NodeSystemClass->setWindowTitle(QApplication::translate("NodeSystemClass", "NodeSystem", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class NodeSystemClass: public Ui_NodeSystemClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NODESYSTEM_H
