#pragma once 

#include <QWidget>

class QGraphicsScene;
class RulerView;

namespace Ui {
	class Form;
}

class Widget : public QWidget
{
	Q_OBJECT

public:
	explicit Widget(QWidget *parent = 0);
	~Widget();

private:
	Ui::Form* ui;
	QGraphicsScene* m_scene;

	bool eventFilter(QObject *obj, QEvent *event);
};
