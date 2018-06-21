#pragma once 

#include <QString>
#include <QTime>
#include <list>

class QGraphicsScene;
class QGraphicsRectItem;

struct Bookmark
{
	QString		name;	
	QTime		time;
	quint32		duration;

	bool operator < (const Bookmark& rv) const
	{
		return (time < rv.time);
	}
};

struct BookmarkHandler
{
	Bookmark			bookmark;
	QGraphicsRectItem*	graphicItem;

	BookmarkHandler(const Bookmark& bookmark, QGraphicsRectItem* item = nullptr)
	{
		this->bookmark = bookmark;
		graphicItem = item;
	}

	bool operator < (const BookmarkHandler& rv) const
	{
		return (bookmark < rv.bookmark);
	}
};

class BookmarkManager
{
	QGraphicsScene*				m_scene;
	std::map<QTime,BookmarkHandler>	m_bookmarks;

public:
	BookmarkManager(QGraphicsScene* scene);
	void generateBookmarks(int count);

	void recalcItems(int width);

	void removeBookmarks();
};



