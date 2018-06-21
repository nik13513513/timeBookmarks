#pragma once 

#include <QGraphicsItem>

class Ruler : public QGraphicsItem
{
	QSizeF m_size{10,10};

public:
	Ruler(QGraphicsItem *parent = Q_NULLPTR);
	~Ruler();

	void setSize(const QSize& size);

protected:
	QRectF boundingRect() const Q_DECL_FINAL;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR) Q_DECL_FINAL;

};

