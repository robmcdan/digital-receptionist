#ifndef VISUALCONTROL_H
#define VISUALCONTROL_H

#include <QMainWindow>

class DigitalReceptionist : public QMainWindow
{
	Q_OBJECT

public:
	DigitalReceptionist(QWidget *parent = 0, Qt::WindowFlags flags = 0);
	~DigitalReceptionist();

};

#endif // VISUALCONTROL_H
