#include "mainwidget.h"
#include <QtWidgets/QApplication>
#include "SparseTableModel.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	mainwidget w;
	w.show();

	return a.exec();
}
