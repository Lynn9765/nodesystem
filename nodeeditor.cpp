#include "nodeeditor.h"
#include <QVBoxLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QLabel>
#include <QPushButton>

NodeEditor::NodeEditor()
{
	QVBoxLayout *vLayout = new QVBoxLayout;
	QHBoxLayout *hLayout1 = new QHBoxLayout;
	QHBoxLayout *hLayout2 = new QHBoxLayout;
	QHBoxLayout *hLayout3 = new QHBoxLayout;
	QHBoxLayout *hLayout4 = new QHBoxLayout;

	QLabel *label1 = new QLabel("Leader");
	QLabel *label2 = new QLabel("Teammate1");
	QLabel *label3 = new QLabel("Teammate2");
	QLabel *label4 = new QLabel("Description");
	QLabel *label5 = new QLabel("Color");
	
	QLineEdit *lineEdit1 = new QLineEdit;
	QLineEdit *lineEdit2 = new QLineEdit;
	QLineEdit *lineEdit3 = new QLineEdit;
	QTextEdit *textEdit = new QTextEdit;

	QPushButton *button = new QPushButton("save");


}