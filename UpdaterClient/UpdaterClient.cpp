#include "UpdaterClient.h"
#include "DirDetails.h"


UpdaterClient::UpdaterClient(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	DirDetails dd(QDir::current(),IgnoredPathList() << "logs" << "UpdaterClient");
	QString json = dd.scan();

	_dl = new Downloader();
}
