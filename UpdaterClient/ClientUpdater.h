#pragma once

#include <QtWidgets/QWidget>
#include "ui_UpdaterClient.h"
#include "Downloader.h"

class ClientUpdater : public QWidget
{
	Q_OBJECT

public:
	explicit ClientUpdater(QWidget *parent = nullptr);

private:
	Ui::UpdaterClientClass ui;
	Downloader* _dl;
};
