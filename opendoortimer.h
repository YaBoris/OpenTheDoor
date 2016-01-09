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
		QFile openDoorFile("d:\\__DOCS_PROJECTS\\Qt\\OpenTheDoor\\MP709\\MP709.local.set");
		int ex = 0;
		do
		{
			if (!openDoorFile.open(QIODevice::WriteOnly | QIODevice::Truncate))
			{
				ex = 1;
				Sleep(50);
				//qDebug() << "Ошибка открытия для записи";
			}
			else
			{
				ex = 0;
				openDoorFile.write("SVET=ON");
				openDoorFile.close();
				QThread::msleep(500);
			}
			if (!openDoorFile.open(QIODevice::WriteOnly | QIODevice::Truncate))
			{
				ex = 1;
				Sleep(50);
				//qDebug() << "Ошибка открытия для записи";
			}
			else
			{
				ex = 0;
				openDoorFile.write("SVET=OFF");
				openDoorFile.close();
				QThread::msleep(500);
			}
			if (!openDoorFile.open(QIODevice::WriteOnly | QIODevice::Truncate))
			{
				ex = 1;
				Sleep(50);
				//qDebug() << "Ошибка открытия для записи";
			}
			else
			{
				ex = 0;
				openDoorFile.write("SVET=ON");
				openDoorFile.close();
				QThread::msleep(500);
			}
			if (!openDoorFile.open(QIODevice::WriteOnly | QIODevice::Truncate))
			{
				ex = 1;
				Sleep(50);
				//qDebug() << "Ошибка открытия для записи";
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

