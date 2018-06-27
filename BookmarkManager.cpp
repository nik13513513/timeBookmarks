#include <ctime>
#include <iostream>
#include <cstdlib>
#include <random>

#include <QDebug>

#include <QGraphicsScene>
#include <QGraphicsItem>

#include "BookmarkManager.h"

std::random_device rd; // obtain a random number from hardware
std::mt19937 eng(rd()); // seed the generator

auto timeMax = 60 * 60 * 24 * 1000;
auto durationMax = 60 * 60 * 3 * 1000;


quint32 generateRand(quint32 start,quint32 end)
{
	std::uniform_int_distribution<> distr(start, end);

	return distr(eng);
}

BookmarkManager::BookmarkManager(QGraphicsScene* scene):
	m_scene(scene)
{
}

void BookmarkManager::generateBookmarks(int count)
{
	removeBookmarks();

	auto dx = m_scene->width() / double(timeMax);

	for (int i = 0; i < count; i++) {
		Bookmark bm;
		bm.name = QString("Bookmark %1").arg(i);
		bm.time = QTime::fromMSecsSinceStartOfDay(generateRand(0,timeMax));
		bm.duration = generateRand(0,durationMax);

		BookmarkHandler bh(bm);

		//debug item
		auto item = m_scene->addRect(0, 0, 30, 30 , QPen(Qt::darkBlue), QBrush(Qt::blue));
		item->setOpacity(0.9);
		item->setPos(dx * bm.time.msecsSinceStartOfDay(), 50);
		item->setToolTip(QString("%1 \n %2 ").arg(bm.name).arg(bm.time.toString("hh:mm:ss")));


		m_bookmarks.emplace(bm.time, BookmarkHandler(bm,item));
	}
}

void BookmarkManager::recalcItems(int width)
{
	auto dx = width / double(timeMax);

	for (auto& item: m_bookmarks)
	{
		auto pos = item.second.graphicItem->pos();
		item.second.graphicItem->setPos(dx*item.second.bookmark.time.msecsSinceStartOfDay(),
								pos.y());
	}
}

void BookmarkManager::removeBookmarks()
{
	qDeleteAll(m_scene->items());
	m_bookmarks.clear();
}


