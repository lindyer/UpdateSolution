#include "UpdaterServer.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	UpdaterServer w;
	w.show();
	return a.exec();
}
