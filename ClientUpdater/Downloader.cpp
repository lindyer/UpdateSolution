#include "Downloader.h"
#include <QSettings>
#include <QDebug>


Downloader::Downloader(QObject* parent)
	: QObject(parent) {
	QSettings settings("UpdaterClient.conf", QSettings::IniFormat);
	QString url = settings.value("url").toString();
	qDebug() << settings.value("url");
	_ws = new QWebSocket();
	connect(_ws, &QWebSocket::disconnected, this, &Downloader::onDisconnect);
	connect(_ws, &QWebSocket::binaryFrameReceived, this, &Downloader::onBinaryFrameReceived);
	connect(_ws, &QWebSocket::bytesWritten, this, &Downloader::onBytesWritten);
	connect(_ws, &QWebSocket::textMessageReceived, this, &Downloader::onMessageReceived);
	_ws->open(QUrl(url));
}


Downloader::~Downloader() {
}


void Downloader::onDisconnect() {
	qDebug() << "Connect Server Failed";
}


void Downloader::onBinaryFrameReceived(const QByteArray& frame, bool isLastFrame) {
	qDebug() << "onBinaryFrameReceived";
}


void Downloader::onBytesWritten(qint64 bytes) {
	qDebug() << "onBytesWritten";
}


void Downloader::onMessageReceived(const QString& message) {
	qDebug() << "onMessageReceived";
}
