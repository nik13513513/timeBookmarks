#pragma once 
#include <set>
#include "IStorage.h"

class SetStorage: public IStorage
{
	std::set<Bookmark> m_set;

public:
	explicit SetStorage(QObject* parent = Q_NULLPTR);

protected:
	void storeBookmark(const Bookmark& bm) Q_DECL_FINAL; 
	void clear() Q_DECL_FINAL;
	std::vector<mergedBookmark> getCalculation(double dx) Q_DECL_FINAL;
};