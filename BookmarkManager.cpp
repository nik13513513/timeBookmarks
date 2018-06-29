

#include <QDebug>
#include <QFuture>
#include <QtConcurrent/QtConcurrent>

#include <QGraphicsScene>

#include "BookmarkManager.h"
#include "BookmarkGraphicItem.h"
#include "setStorage.h"


BookmarkGraphicItem* BookmarkManager::getGraphicsItem(int index)
{
	if (index >= 0 && index < m_guiItems.size())
		return m_guiItems.at(index);

	return nullptr;
}

BookmarkGraphicItem* BookmarkManager::createGraphicsItem(const QString& name)
{
	auto item = new BookmarkGraphicItem();
	item->setRect(0, 0, 30, 30);
	item->setName(name);

	m_scene->addItem(item);
	m_guiItems.push_back(item);

	return item;
}

void BookmarkManager::redraw()
{
	auto calc_res = m_watcher.result();

	for (int i = 0; i < calc_res.size(); ++i)
	{
		auto gi = getGraphicsItem(i);
		auto currentResult = calc_res.at(i);

		if (!gi)
			gi = createGraphicsItem(currentResult.name);

		gi->setMerged(currentResult.isMerged);
		gi->setPos(currentResult.pos1, 50);
		gi->setRect(0, 0, currentResult.pos2 - currentResult.pos1, 30);

		gi->setToolTip(currentResult.toolTip);
	}
}


BookmarkManager::BookmarkManager(QGraphicsScene* scene, QObject* parent) :
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
	m_guiItems.clear();

	m_storage->generateBookmarks(count);

	recalcItems(m_scene->width());
}

void BookmarkManager::recalcItems(int width)
{
	auto dx = width / double(timeMax);

	auto future = QtConcurrent::run(m_storage, &IStorage::getCalculation, dx);
	m_watcher.setFuture(future);
}


