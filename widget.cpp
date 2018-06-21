#include "widget.h"
#include "ui_widget.h"
#include "ruler.h"

Widget::Widget(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::Form),
	m_scene(new QGraphicsScene(this)),
	m_ruler(new Ruler())
{
	ui->setupUi(this);

	m_scene->setSceneRect(0, 0, 1000, 1000);


	ui->graphicsView->setScene(m_scene);
	ui->graphicsView->installEventFilter(this);
	ui->graphicsView->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
	ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);

	m_scene->addItem(m_ruler);
	m_ruler->setToolTip("121212");

	m_scene->addRect(5, 5, 50, 50);
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

		m_ruler->setSize(size);
	}

	// standard event processing
	return QObject::eventFilter(obj, event);
}
