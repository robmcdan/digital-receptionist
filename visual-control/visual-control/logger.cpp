#include "logger.h"
#include <qt4/QtGui/qlistwidget.h>

Logger Logger::instance;

Logger::Logger(void)
	:logWidget(0)
{
}


void Logger::log(const std::string &msg)
{
	if(logWidget != 0)
		logWidget->insertItem(0,QString(msg.c_str()));
}

Logger& Logger::getInstance()
{
	return Logger::instance;
}

void Logger::setLogWidget(QListWidget *logWidget)
{
	this->logWidget = logWidget;
}
