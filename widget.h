#pragma once 

#include <QWidget>
#include "BookmarkManager.h"

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

	void resizeSceneSizeToScreen();

private slots:
	void on_generateButton_clicked();

private:
	Ui::Form* ui;
	QGraphicsScene* m_scene;
	BookmarkManager* m_manager;

	bool eventFilter(QObject *obj, QEvent *event);
};
