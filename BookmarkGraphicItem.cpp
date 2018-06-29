#include <QPainter>
#include <QGuiApplication>

#include "BookmarkGraphicItem.h"


BookmarkGraphicItem::BookmarkGraphicItem(QGraphicsItem* parent) :
	QGraphicsRectItem(parent)
{
	setOpacity(0.9);
	setPen(QPen(Qt::darkBlue));
	setBrush(QBrush(Qt::blue));
}

BookmarkGraphicItem::~BookmarkGraphicItem()
{
}

void BookmarkGraphicItem::setName(const QString& name)
{
	m_name = name;
}

void BookmarkGraphicItem::setMerged(bool merged)
{
	if (m_merged != merged) {
		m_merged = merged;

		if (m_merged)
		{
			setPen(QPen(Qt::darkGreen));
			setBrush(QBrush(Qt::green));
		}
		else
		{
			setPen(QPen(Qt::darkBlue));
			setBrush(QBrush(Qt::blue));
		}

		update();
	}
}

void BookmarkGraphicItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	QGraphicsRectItem::paint(painter, option, widget);

	painter->setRenderHint(QPainter::TextAntialiasing);
	painter->setPen(Qt::white);

	QFontMetrics metrics(painter->font());
	auto elidedText = metrics.elidedText(m_name, Qt::ElideRight, rect().width());
	painter->drawText(rect(), Qt::AlignLeft | Qt::AlignVCenter | Qt::TextWordWrap, elidedText);
}
