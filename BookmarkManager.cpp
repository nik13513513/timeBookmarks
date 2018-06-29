

#include <QDebug>
#include <QFuture>
#include <QtConcurrent/QtConcurrent>

#include <QGraphicsScene>

#include "BookmarkManager.h"
#include "BookmarkItem.h"
#include "setStorage.h"


BookmarkItem* BookmarkManager::getGraphicsItem(int index)
{
	if (index >= 0 && index < m_bookmarksGui.size())
		return m_bookmarksGui.at(index);

	return nullptr;
}

BookmarkItem* BookmarkManager::createGraphicsItem(const QString& name)
{
	auto item = new BookmarkItem();
	item->setRect(0, 0, 30, 30);
	item->setName(name);

	m_scene->addItem(item);
	m_bookmarksGui.push_back(item);
	
	return item;
}

void BookmarkManager::redraw()
{
	auto calc_res = m_watcher.result();

	for (int i = 0; i < calc_res.size(); ++i)
	{
		auto gi = getGraphicsItem(i);

		if (!gi)
			gi = createGraphicsItem(calc_res.at(i).name);

		gi->setPos(calc_res.at(i).pos1, 50);
		gi->setRect(0, 0, calc_res.at(i).pos2 - calc_res.at(i).pos1, 30);

		gi->setToolTip(calc_res.at(i).toolTip);
	}
}


BookmarkManager::BookmarkManager(QGraphicsScene* scene, QObject* parent):
	QObject(parent),
	m_scene(scene),
	m_storage(new SetStorage())
{

	connect(&m_watcher, SIGNAL(finished()), this, SLOT(redraw()));
}

BookmarkManager::~BookmarkManager()
{
	delete m_storage;
}

void BookmarkManager::generateBookmarks(int count)
{
	qDeleteAll(m_scene->items());
	m_bookmarksGui.clear();

	m_storage->generateBookmarks(count);

	recalcItems(m_scene->width());
}

void BookmarkManager::recalcItems(int width)
{
	auto dx = width / double(timeMax);
	//auto calc_res = m_storage->getCalculation(dx);

	auto future =  QtConcurrent::run(m_storage, &IStorage::getCalculation, dx);
	m_watcher.setFuture(future);
}


