#include "abb.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	abb w;
	w.show();
	return a.exec();
}
