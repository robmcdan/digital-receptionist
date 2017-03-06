#ifndef VISUALCONTROL_H
#define VISUALCONTROL_H

#include <QMainWindow>

class VisualControl : public QMainWindow
{
	Q_OBJECT

public:
	VisualControl(QWidget *parent = 0, Qt::WindowFlags flags = 0);
	~VisualControl();

};

#endif // VISUALCONTROL_H
