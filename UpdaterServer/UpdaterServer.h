#pragma once

#include <QtWidgets/QWidget>
#include "ui_UpdaterServer.h"
#include <QWebSocket>
#include <list>
#include "../Common/BaseType.h"
class QWebSocketServer;
class QWebSocket;
class UpdaterServer : public QWidget
{
	Q_OBJECT

public:
	UpdaterServer(QWidget *parent = nullptr);

private:
	void onNewConnection();
	void onDisconnect();
	void onBinaryFrameReceived(const QByteArray& frame, bool isLastFrame);
	void onBytesWritten(qint64 bytes);
	void onMessageReceived(const QString& message);

private:
	Ui::UpdaterServerClass ui;
	QWebSocketServer* _wss = nullptr;
	std::list<QWebSocket*> _wsList;
	IgnoredPathList _ignoredPathList;
};
