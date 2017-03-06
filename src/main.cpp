#include "gui/digitalreceptionist_gui.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	gui::DigitalReceptionist w;
	w.show();
	return a.exec();
}
