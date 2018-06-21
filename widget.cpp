#include <QGraphicsRectItem>
#include <QInputDialog>

#include "Widget.h"
#include "ui_widget.h"
#include "RulerView.h"

Widget::Widget(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::Form),
	m_scene(new QGraphicsScene(this)),
	m_manager(new BookmarkManager(m_scene))
{
	ui->setupUi(this);

	ui->graphicsView->setScene(m_scene);
	resizeSceneSizeToScreen();

	ui->graphicsView->installEventFilter(this);
	ui->graphicsView->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
	ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
}

Widget::~Widget()
{
	delete ui;
	delete m_manager;
}

void Widget::on_generateButton_clicked()
{
	bool ok;
	auto count = QInputDialog::getInt(this, tr(u8"Введите количество"),
										tr(u8"Количество:"), 10, 1, 100000000, 10, &ok);
	if (ok)
	{
		ui->countLineEdit->setText(QString::number(count));
		m_manager->generateBookmarks(count);
	}
}

bool Widget::eventFilter(QObject* obj, QEvent* event)
{
	if (event->type() == QEvent::Resize)
	{
		resizeSceneSizeToScreen();

		m_manager->recalcItems(ui->graphicsView->viewport()->size().width());
	}

	// standard event processing
	return QObject::eventFilter(obj, event);
}

void Widget::resizeSceneSizeToScreen()
{
	auto size = ui->graphicsView->viewport()->size();
	m_scene->setSceneRect(0, 0, size.width(),
								size.height());
}
