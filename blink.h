#ifndef BLINK
#define BLINK

#pragma once

#include <QtWidgets>
#include "etalon.h"

class Blink : public QObject {
Q_OBJECT


signals:
	void latency(bool BlackWhite);

private:
	Etalon ReadyMorze;
	static int const iDot = 500;
	static int const iDash = 2000;
	static int const iPauseSymbol = 500;
	static int const iPauseLetter = 1500;
	static int const iPauseWord = 4000;
	static int const iPauseBeforeOpenDoor = 40000;

public:
	Blink(QObject* pobj = 0) : QObject(pobj){}

public slots:
	void startBlink()
	{
		int* morze = ReadyMorze.GetReadyCodeMorzeForBlink();
		for(int i = 0; i < 50; i++)
		{
			//qDebug() << "index i: " << i;
			switch(morze[i])
			{
			case 0:
				emit latency(true);
				//qDebug() << "iDot";
				QThread::msleep(iDot);
				emit latency(false);
				QThread::msleep(iPauseSymbol);
				//qDebug() << "iPauseSymbol";
				break;
			case 1:
				emit latency(true);
				//qDebug() << "iDash";
				QThread::msleep(iDash);
				emit latency(false);
				QThread::msleep(iPauseSymbol);
				//qDebug() << "iPauseSymbol";
				break;
			case 2:
				emit latency(false);
				QThread::msleep(iPauseLetter);
				//qDebug() << "iPauseLetter";
				break;
			case 3:
				emit latency(false);
				QThread::msleep(iPauseWord);
				//qDebug() << "iPauseWord";
				i = -1;
				break;
			}
		}
	}
};


// ======================================================================
class BlinkThread : public QThread {
Q_OBJECT
public:
	BlinkThread(){}

	void run()
	{
		exec();
	}
};



#endif // BLINK

