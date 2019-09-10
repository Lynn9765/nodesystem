#include "NodeSystem.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	NodeSystem w;
	w.setGeometry(100, 100, 800, 500);
	w.show();
	return a.exec();
}
