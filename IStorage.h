#pragma once 

#include <vector>
#include <QObject>
#include <QTime>


static auto timeMax = 60 * 60 * 24 * 1000;
static auto durationMax = 60 * 60 * 3 * 1000;


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

struct mergedBookmark
{
	int pos1;
	int pos2;
	QString name;
	QString toolTip;
};

class IStorage: public QObject
{
	Q_OBJECT
public:
	explicit IStorage(QObject* parent=Q_NULLPTR);
	virtual ~IStorage();

	void generateBookmarks(int count);

	virtual void storeBookmark(const Bookmark& bm);
	virtual void clear();
	virtual std::vector<mergedBookmark> getCalculation(double dx);
};