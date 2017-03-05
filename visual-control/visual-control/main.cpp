#include "gui/visualcontrol.h"
#include <qt4/QtGui/qapplication.h>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	gui::VisualControl w;
	w.show();
	return a.exec();
}
