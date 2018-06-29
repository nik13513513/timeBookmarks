#pragma once 

#include <QFutureWatcher>
#include "IStorage.h"

class QGraphicsScene;
class BookmarkGraphicItem;
class IStorage;

/// <summary>
/// результаты обсчета объединения
/// </summary>
typedef std::vector<mergedBookmark> calcRes;

/// <summary>
/// Менеджер закладок, управляет перерисовкой графических элементов
/// </summary>
class BookmarkManager: public QObject
{
	Q_OBJECT
	QGraphicsScene*				m_scene;
	std::vector<BookmarkGraphicItem*>	m_guiItems;
	IStorage*					m_storage;
	QFutureWatcher<calcRes>		m_watcher;

	BookmarkGraphicItem* getGraphicsItem(int index);
	BookmarkGraphicItem* createGraphicsItem(const QString& name);

private slots:
	/// <summary>
	/// перерисовать item-ы в соответствии с calcRes
	/// </summary>
	void redraw();

public:
	BookmarkManager(QGraphicsScene* scene, QObject* parent = Q_NULLPTR);
	~BookmarkManager();

	/// <summary>
	/// 
	/// </summary>
	void generateBookmarks(int count);

	/// <summary>
	/// 
	/// </summary>
	void recalcItems(int width);
};



