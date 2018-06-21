#pragma once 

#include <QWidget>

class QGraphicsScene;
class Ruler;

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
	Ruler*			m_ruler;

	bool eventFilter(QObject *obj, QEvent *event);


};
