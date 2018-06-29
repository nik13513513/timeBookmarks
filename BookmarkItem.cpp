#include <QPainter>
#include <QGuiApplication>

#include "BookmarkItem.h"


BookmarkItem::BookmarkItem(QGraphicsItem* parent)
{
	setOpacity(0.9);
	setPen(QPen(Qt::darkBlue));
	setBrush(QBrush(Qt::blue));
}

BookmarkItem::~BookmarkItem()
{
}

void BookmarkItem::setName(const QString& name)
{
	m_name = name;
}

void BookmarkItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	QGraphicsRectItem::paint(painter,option, widget);

	painter->setRenderHint(QPainter::TextAntialiasing);
	painter->setPen(Qt::white);

	QFontMetrics metrics(painter->font());
	QString elidedText = metrics.elidedText(m_name, Qt::ElideRight, rect().width());
	painter->drawText(rect(), Qt::AlignLeft | Qt::AlignVCenter | Qt::TextWordWrap, elidedText);
}
