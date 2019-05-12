#include "ClientUpdater.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ClientUpdater w;
	w.show();
	return a.exec();
}
