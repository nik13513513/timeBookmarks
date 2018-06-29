#pragma once 

#include <set>
#include "IStorage.h"

/// <summary>
/// хранилище, основанное на std::set
/// </summary>
class SetStorage: public IStorage
{
	std::set<Bookmark> m_set;

protected:
	void storeBookmark(const Bookmark& bm) Q_DECL_FINAL;
	void clear() Q_DECL_FINAL;

public:
	explicit SetStorage(QObject* parent = Q_NULLPTR);

	std::vector<mergedBookmark> getCalculation(double dx) Q_DECL_FINAL;
};