#pragma once 

#include <vector>
#include <QObject>
#include <QTime>

/// <summary>
/// мсек в сутках
/// </summary>
static auto timeMax = 60 * 60 * 24 * 1000;

/// <summary>
/// максимальная длительность в мсек
/// </summary>
static auto durationMax = 60 * 60 * 3 * 1000;

/// <summary>
/// Данные закладки
/// </summary>
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

/// <summary>
/// данные "объединенной" закладки
/// </summary>
struct mergedBookmark
{
	int pos1;				//начальная позиция в пикселах по оси x
	int pos2;				//конечная позиция в пикселах по оси x
	QString name;			//имя
	QString toolTip;		//подсказка
	bool isMerged{ false };	//объединенная или нет
};

/// <summary>
/// Абстрактный класс хранилища
/// для хранения 100000000 элементов скорее всего потребуется хранилище с бд
/// </summary>
class IStorage : public QObject
{
	Q_OBJECT

protected:
	virtual void clear();
	virtual void storeBookmark(const Bookmark& bm);

public:
	explicit IStorage(QObject* parent = Q_NULLPTR);
	virtual ~IStorage();

	/// <summary>
	/// Генерация случайных вкладок
	/// </summary>
	void generateBookmarks(int count);

	/// <summary>
	/// Расчет объединения вкладок
	/// </summary>
	virtual std::vector<mergedBookmark> getCalculation(double dx);
};