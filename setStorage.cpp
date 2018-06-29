#include "setStorage.h"


SetStorage::SetStorage(QObject* parent) :
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


	int i = 0;

	Bookmark prev;
	mergedBookmark merged;
	int mergedStartPos{ 0 };
	bool mergeStarted{ false };
	QString mergedTooltip;

	for (auto& bm : m_set)
	{
		if (i == 0) {
			prev = bm;
			i++;
			continue;
		}

		auto prevX = prev.time.msecsSinceStartOfDay()* dx;
		auto currentX = bm.time.msecsSinceStartOfDay()* dx;

		if (currentX  - prevX < 10 && !mergeStarted)
		{
			mergeStarted = true;
			mergedStartPos = prevX;
		}else
		{
			if (mergeStarted)//in merge
			{
				if (currentX - prevX < 10) //continue
				{
					continue;	
				}
				else {
					merged.pos1 = mergedStartPos;
					merged.pos2 = currentX + bm.duration*dx;
					merged.isMerged = true;
					merged.name = "merged";


					mergeStarted = false;
				}
			}else//single
			{
				merged.pos1 = currentX;
				merged.pos2 = currentX + bm.duration*dx;
				merged.name = bm.name;
				merged.toolTip = QString("name:%1 \n time:%2 \n duration:%3").arg(bm.name)
										.arg(bm.time.toString("hh:mm:ss"))
										.arg(QTime::fromMSecsSinceStartOfDay(bm.duration).toString("hh:mm:ss"));
			}

			retValue.push_back(merged);
		}

		prev = bm;

		i++;
	}

	return retValue;
}

