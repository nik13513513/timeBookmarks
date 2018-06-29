#include <ctime>
#include <iostream>
#include <cstdlib>
#include <random>

#include "IStorage.h"


static std::random_device rd; // obtain a random number from hardware
static std::mt19937 eng(rd()); // seed the generator



quint32 generateRand(quint32 start, quint32 end)
{
	std::uniform_int_distribution<> distr(start, end);

	return distr(eng);
}

IStorage::IStorage(QObject* parent):
QObject(parent)
{
}

IStorage::~IStorage()
{
}

void IStorage::generateBookmarks(int count)
{
	clear();

	for (int i = 0; i < count; i++) {
		Bookmark bm;
		bm.name = QString("Bookmark %1").arg(i);
		bm.time = QTime::fromMSecsSinceStartOfDay(generateRand(0, timeMax));
		bm.duration = generateRand(0, durationMax);

		storeBookmark(bm);
	}
}

void IStorage::storeBookmark(const Bookmark& bm)
{

}

void IStorage::clear()
{

}

std::vector<mergedBookmark> IStorage::getCalculation(double dx)
{
	return std::vector<mergedBookmark>();
}
