#include <QPainter>
#include <QGuiApplication>

#include "RulerView.h"


RulerView::RulerView(QWidget *parent) :
	QGraphicsView(parent)
{

}

RulerView::~RulerView()
{
}

void RulerView::paintEvent(QPaintEvent* event)
{
	//default implementation
	QGraphicsView::paintEvent(event);

	QPainter painter(viewport());
	painter.setPen(Qt::black);

	QPen pen;
	auto lineWidth = 3;
	pen.setWidth(lineWidth);
	pen.setColor(QColor(Qt::black));
	painter.setPen(pen);
	painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);

	auto width = viewport()->width();
	auto height = viewport()->height();

	//draw outline
	painter.drawRect(lineWidth / 2, lineWidth / 2, width - lineWidth,
		height - lineWidth);

	//draw ticks
	auto step = width / 24.0;//24 hour

	for (int i = 0; i < 25; ++i)
	{
		auto text = QString("%1h").arg(i);
		QFontMetrics fm(qApp->font());

		QPoint p1(step*i, 0);
		QPoint p2(step*i, fm.height());
		painter.drawLine(QLine(p1, p2));


		auto margin = 5;//ticks margin

		painter.drawText(p1.x() - fm.width(text) / 2.0,
			p2.y() + fm.height() + margin, text);
	}
}
