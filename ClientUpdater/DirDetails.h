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
	//��ӹ���·��
	void addIgnoredPath(const QString& path);
	//���ù���
	void setIgnoredPathList(const IgnoredPathList& list);
	//����һ��Json�ַ�������ʽ��{"Paths":Array1,"Timestamp":Array2}, Array1.count == Array2.count
	QString scan();

private:
	//��ǰĿ¼
	QDir _dir;
	//�����Ե�Ŀ¼
	IgnoredPathList _ignoredPathList;
	//�ļ���Ϣ
	QFileInfoList _fileInfoList;
};
