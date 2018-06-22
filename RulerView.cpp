#include <QPainter>

#include "RulerView.h"

RulerView::RulerView(QWidget *parent):
	QGraphicsView(parent)
{

}

RulerView::~RulerView()
{
}

void RulerView::paintEvent(QPaintEvent* event)
{
	QGraphicsView::paintEvent(event);


	QPainter painter(viewport());
	painter.setPen(Qt::blue);

	QPen pen;
	int lineWidth = 5;
	pen.setWidth(lineWidth);
	pen.setColor(QColor(Qt::blue));
	painter.setPen(pen);

	painter.drawRect(lineWidth/2, lineWidth/2, viewport()->width()- lineWidth,
							viewport()->height()- lineWidth);
}
