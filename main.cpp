#include <QApplication>
#include "widget.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	app.setFont(QFont("Tahoma", 11));

	Widget mainWidget;
	mainWidget.setWindowTitle(QObject::tr("Bookmarks"));
	mainWidget.show();
	mainWidget.resizeSceneSizeToScreen();

	return app.exec();
}
