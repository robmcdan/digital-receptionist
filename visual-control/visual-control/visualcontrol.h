#ifndef VISUALCONTROL_H
#define VISUALCONTROL_H

#include <qt4/QtGui/qmainwindow.h>
#include <logger.h>
class VisualControl : public QMainWindow
{
	Q_OBJECT

public:
	VisualControl(QWidget *parent = 0, Qt::WFlags flags = 0);
	~VisualControl();

};

#endif // VISUALCONTROL_H
