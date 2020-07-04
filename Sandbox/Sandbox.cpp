#include <Qt/qapplication.h>
#include <QtGui/qwidget.h>

#include "MyGlWindow.h"

int main(int argc, char** argv)
{
	// Define Qt applicaion
	QApplication application(argc, argv);

	// Open Qt Window
	MyGlWindow myGlWindow;
	myGlWindow.show();

	return application.exec();
}