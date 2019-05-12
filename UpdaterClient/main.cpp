#include "UpdaterClient.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	UpdaterClient w;
	w.show();
	return a.exec();
}
