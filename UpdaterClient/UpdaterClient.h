#pragma once

#include <QtWidgets/QWidget>
#include "ui_UpdaterClient.h"
#include "Downloader.h"

class UpdaterClient : public QWidget
{
	Q_OBJECT

public:
	explicit UpdaterClient(QWidget *parent = nullptr);

private:
	Ui::UpdaterClientClass ui;
	Downloader* _dl;
};
