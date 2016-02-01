#ifndef OPENDOORTIMER
#define OPENDOORTIMER

#pragma once

#include <QtWidgets>

class opendoortimer : public QObject {
Q_OBJECT

signals:
	void quitThread();

public:
	opendoortimer(QObject* pobj = 0) : QObject(pobj){}

public slots:
	void changeTxt()
	{
		QThread::msleep(32000);
		//QFile openDoorFile("d://__DOCS_PROJECTS//Qt//OpenTheDoor//MP709//MP709.local.set");
		QFile openDoorFile("C://Users//Public//Downloads//MP709//MP709.local.set");
		//QFile openDoorFile("d://Downloads//Qt//Projects//OpenTheDoor//MP709//MP709.local.set");
		int ex = 0;
		do
		{
			if (!openDoorFile.open(QIODevice::WriteOnly | QIODevice::Truncate))
			{
				ex = 1;
				QThread::msleep(50);
				//qDebug() << "Ошибка открытия для записи";
			}
			else
			{
				ex = 0;
				openDoorFile.write("SVET=ON");
				openDoorFile.close();
				QThread::msleep(1300);
			}
		}while(ex);
		do
		{
			if (!openDoorFile.open(QIODevice::WriteOnly | QIODevice::Truncate))
			{
				ex = 1;
				QThread::msleep(50);
			}
			else
			{
				ex = 0;
				openDoorFile.write("SVET=OFF");
				openDoorFile.close();
				QThread::msleep(300);
			}
		}while(ex);
		do
		{
			if (!openDoorFile.open(QIODevice::WriteOnly | QIODevice::Truncate))
			{
				ex = 1;
				QThread::msleep(50);
			}
			else
			{
				ex = 0;
				openDoorFile.write("SVET=ON");
				openDoorFile.close();
				QThread::msleep(1300);
			}
		}while(ex);
		do
		{
			if (!openDoorFile.open(QIODevice::WriteOnly | QIODevice::Truncate))
			{
				ex = 1;
				QThread::msleep(60);
			}
			else
			{
				ex = 0;
				openDoorFile.write("SVET=OFF");
				openDoorFile.close();
			}
		}while(ex);
		emit quitThread();
	}
};

#endif // OPENDOORTIMER

