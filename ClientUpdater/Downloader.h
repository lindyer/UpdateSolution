#pragma once

#include <QObject>
#include <QWebSocket>

class Downloader : public QObject
{
	Q_OBJECT

public:
	explicit Downloader(QObject *parent = nullptr);
	~Downloader();

private slots:
	void onDisconnect();
	void onBinaryFrameReceived(const QByteArray& frame, bool isLastFrame);
	void onBytesWritten(qint64 bytes);
	void onMessageReceived(const QString& message);

private:
	QWebSocket* _ws = nullptr;
};
