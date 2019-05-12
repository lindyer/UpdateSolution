#include "UpdaterServer.h"
#include <QWebSocketServer>
#include <QtNetwork/QNetworkProxy>
#include <QHostAddress>


UpdaterServer::UpdaterServer(QWidget* parent)
	: QWidget(parent) {
	ui.setupUi(this);
	_wss = new QWebSocketServer("Updater Server", QWebSocketServer::NonSecureMode, this);
	_wss->setProxy(QNetworkProxy::NoProxy);
	connect(_wss, &QWebSocketServer::newConnection, this, &UpdaterServer::onNewConnection);
	qDebug() << "listen:" << _wss->listen(QHostAddress::Any, 9999);
}


void UpdaterServer::onDisconnect() {
	qDebug() << "disconnected";
	auto ws = qobject_cast<QWebSocket*>(sender());
	_wsList.remove(ws);
	qDebug() << "Current Connection Count:" << _wsList.size();
}


void UpdaterServer::onBinaryFrameReceived(const QByteArray& frame, bool isLastFrame) {
	qDebug() << "binaryFrameReceived" << frame << isLastFrame;
	auto ws = qobject_cast<QWebSocket*>(sender());
}


void UpdaterServer::onBytesWritten(qint64 bytes) {
	qDebug() << "bytesWritten" << bytes;
	auto ws = qobject_cast<QWebSocket*>(sender());
}


void UpdaterServer::onMessageReceived(const QString& message) {
	qDebug() << "textMessageReceived" << message;
	auto ws = qobject_cast<QWebSocket*>(sender());
}


void UpdaterServer::onNewConnection() {
	auto ws = _wss->nextPendingConnection();
	_wsList.push_back(ws);
	connect(ws, &QWebSocket::disconnected, this, &UpdaterServer::onDisconnect);
	connect(ws, &QWebSocket::binaryFrameReceived, this, &UpdaterServer::onBinaryFrameReceived);
	connect(ws, &QWebSocket::bytesWritten, this, &UpdaterServer::onBytesWritten);
	connect(ws, &QWebSocket::textMessageReceived, this, &UpdaterServer::onMessageReceived);
	ws->sendTextMessage("Hello Client");
}
