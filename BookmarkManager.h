#pragma once 

#include <QFutureWatcher>
#include "IStorage.h"

class QGraphicsScene;
class BookmarkItem;
class IStorage;

typedef std::vector< mergedBookmark > calcRes;

class BookmarkManager:public QObject
{
	Q_OBJECT
	QGraphicsScene*				m_scene;
	std::vector<BookmarkItem*>	m_bookmarksGui;
	IStorage*					m_storage;
	QFutureWatcher<calcRes>		m_watcher;

	BookmarkItem* getGraphicsItem(int index);
	BookmarkItem* createGraphicsItem(const QString& name);

private slots:
	void redraw();

public:
	BookmarkManager(QGraphicsScene* scene, QObject* parent = Q_NULLPTR);
	~BookmarkManager();

	void generateBookmarks(int count);
	void recalcItems(int width);
};



