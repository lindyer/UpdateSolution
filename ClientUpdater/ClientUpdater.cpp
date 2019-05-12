#include "ClientUpdater.h"
#include "DirDetails.h"


ClientUpdater::ClientUpdater(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	DirDetails dd(QDir::current(),IgnoredPathList() << "logs" << "ClientUpdater");
	QString json = dd.scan();

	_dl = new Downloader();
}
