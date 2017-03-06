#include "gui/visualcontrol_gui.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	gui::VisualControl w;
	w.show();
	return a.exec();
}
