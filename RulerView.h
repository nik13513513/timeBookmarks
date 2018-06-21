#pragma once 

#include <QGraphicsView>

class RulerView : public QGraphicsView
{
	Q_OBJECT
public:
	RulerView(QWidget *parent = Q_NULLPTR);
	~RulerView();

protected:
	void paintEvent(QPaintEvent *event) Q_DECL_FINAL;
};

