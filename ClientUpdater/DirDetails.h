#pragma once
#include "BaseType.h"
#include <QObject>
#include <QDir>

class DirDetails : public QObject {
	Q_OBJECT

public:
	explicit DirDetails(const QString& dirPath, const IgnoredPathList& ignoredPathList, QObject* parent = nullptr);

	explicit DirDetails(const QDir& dir, const IgnoredPathList& ignoredPathList, QObject* parent = nullptr);

	explicit DirDetails(const IgnoredPathList& ignoredPathList, QObject* parent = nullptr);

	~DirDetails();
	//添加过滤路径
	void addIgnoredPath(const QString& path);
	//设置过滤
	void setIgnoredPathList(const IgnoredPathList& list);
	//返回一个Json字符串，格式如{"Paths":Array1,"Timestamp":Array2}, Array1.count == Array2.count
	QString scan();

private:
	//当前目录
	QDir _dir;
	//被忽略的目录
	IgnoredPathList _ignoredPathList;
	//文件信息
	QFileInfoList _fileInfoList;
};
