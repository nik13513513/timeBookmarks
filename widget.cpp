#include <QGraphicsRectItem>

#include "widget.h"
#include "ui_widget.h"
#include "RulerView.h"

Widget::Widget(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::Form),
	m_scene(new QGraphicsScene(this))
{
	ui->setupUi(this);

	ui->graphicsView->setScene(m_scene);
	m_scene->setSceneRect(0, 0, 1000, 1000);

	ui->graphicsView->installEventFilter(this);
	ui->graphicsView->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
	ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);

	auto item = m_scene->addRect(5, 5, 50, 50);
	item->setToolTip("233");
}

Widget::~Widget()
{
	delete ui;
}

bool Widget::eventFilter(QObject* obj, QEvent* event)
{
	if (event->type() == QEvent::Resize)
	{
		auto size = ui->graphicsView->viewport()->size();
		m_scene->setSceneRect(0, 0, size.width(), size.height());
		//m_ruler->setSize(size);
	}

	// standard event processing
	return QObject::eventFilter(obj, event);
}
