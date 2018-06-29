#pragma once 

#include <QGraphicsRectItem>

/// <summary>
/// Графическое представление
/// </summary>
class BookmarkGraphicItem : public QGraphicsRectItem
{
	QString m_name;
	bool m_merged {false};

public:
	BookmarkGraphicItem(QGraphicsItem *parent = Q_NULLPTR);
	~BookmarkGraphicItem();

	/// <summary>
	/// Отображаемое имя
	/// </summary>
	/// <param name="name"></param>
	void setName(const QString& name);

	void setMerged(bool merged);

protected:
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR) Q_DECL_FINAL;
};

