#pragma once 

#include <QGraphicsRectItem>

class BookmarkItem : public QGraphicsRectItem
{
	QString m_name;

public:
	BookmarkItem(QGraphicsItem *parent = Q_NULLPTR);
	~BookmarkItem();

	void setName(const QString& name);

protected:
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR) Q_DECL_FINAL;
};

