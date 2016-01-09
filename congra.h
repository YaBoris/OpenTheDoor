#ifndef CONGRA_H
#define CONGRA_H


#pragma once

#include <QtWidgets>

class Congra : public QObject {
Q_OBJECT

signals:
	//void finished();
	void hiding();

public:
	QTimer m_timer;
	Congra(QObject* pobj = 0) : QObject(pobj)
	{
		connect(&m_timer, SIGNAL(timeout()), SLOT(hideSignal()));
	}
	void startShow(int seconds)
	{
		qDebug() << "show timer";
		m_timer.start(seconds);
	}
	public slots:
	void hideSignal()
	{
		emit hiding();
	}
};


// ======================================================================
class MyThread : public QThread {
Q_OBJECT
public:
	MyThread(){}

	void run()
	{
		exec();
	}
};



#endif // CONGRA_H
