#include <QPainter>

#include "ruler.h"

Ruler::Ruler(QGraphicsItem* parent):
	QGraphicsItem(parent)
{

}

Ruler::~Ruler()
{
}

void Ruler::setSize(const QSize& size)
{
	if (m_size != size) {
		m_size = size;
		prepareGeometryChange();

	}
}

QRectF Ruler::boundingRect() const
{
	return QRectF(QPointF(0,0), m_size);
}

void Ruler::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	QPen pen;
	pen.setWidth(4);
	pen.setColor(QColor(Qt::red));

	painter->setPen(pen);

	painter->drawRoundRect(0,0,20,20,5,5);

	painter->drawLine(QPoint(0,0),QPoint(0,m_size.height()));
}
