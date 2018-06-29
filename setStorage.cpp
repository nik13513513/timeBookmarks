#include "setStorage.h"


SetStorage::SetStorage(QObject* parent):
IStorage(parent)
{
}

void SetStorage::storeBookmark(const Bookmark& bm)
{
	m_set.emplace(bm);
}

void SetStorage::clear()
{
	m_set.clear();
}

std::vector<mergedBookmark> SetStorage::getCalculation(double dx)
{
	std::vector<mergedBookmark> retValue;

	for(auto& bm: m_set)
	{
		mergedBookmark merged;

		merged.pos1 = dx * bm.time.msecsSinceStartOfDay();
		merged.pos2 = merged.pos1 + dx*bm.duration;
		merged.name = bm.name;
		merged.toolTip  = QString("name:%1 \n time:%2 \n duration:%3").arg(bm.name)
												.arg(bm.time.toString("hh:mm:ss"))
									.arg(QTime::fromMSecsSinceStartOfDay(bm.duration).toString("hh:mm:ss"));

		retValue.push_back(merged);
	}

	return retValue;
}

