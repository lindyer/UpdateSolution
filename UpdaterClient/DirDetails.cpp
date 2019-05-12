#include "DirDetails.h"
#include <QDir>
#include <QDebug>
#include <functional>
#include <QDateTime>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>


DirDetails::DirDetails(const QString& dirPath, const IgnoredPathList& ignoredPathList, QObject* parent)
	: DirDetails(ignoredPathList, parent) {
	_dir = dirPath;
}


DirDetails::DirDetails(const QDir& dir, const IgnoredPathList& ignoredPathList, QObject* parent)
	: DirDetails(ignoredPathList, parent) {
	_dir = dir;
}


DirDetails::DirDetails(const IgnoredPathList& ignoredPathList, QObject* parent)
	: QObject(parent), _ignoredPathList(ignoredPathList) {
}


DirDetails::~DirDetails() {
}


void DirDetails::addIgnoredPath(const QString& path) {
	_ignoredPathList << path;
}


void DirDetails::setIgnoredPathList(const IgnoredPathList& list) {
	_ignoredPathList = list;
}


QString DirDetails::scan() {
	std::function<void(const QDir&)> expandFn;
	QJsonArray pathArray;
	QJsonArray timestampArray;
	expandFn = [&expandFn, &pathArray, &timestampArray, this](const QDir& dir) {
		for (auto& entry : dir.entryInfoList(QDir::NoDotAndDotDot | QDir::AllEntries)) {
			if (_ignoredPathList.contains(entry.fileName())) {
				continue;
			}
			if (entry.isDir()) {
				expandFn(QDir(entry.filePath()));
			} else {
				pathArray << entry.filePath();
				timestampArray << entry.fileTime(QFile::FileModificationTime).toMSecsSinceEpoch();
				_fileInfoList.append(entry);
			}
		}
	};
	expandFn(_dir);
	QJsonObject obj;
	obj.insert("Paths", pathArray);
	obj.insert("Timestamps", timestampArray);
	QJsonDocument doc(obj);
	return doc.toJson(QJsonDocument::Compact);
}
