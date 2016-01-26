#include "mainwindow.h"
#include "morzewindow.h"
#include "congra.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QtWidgets>
#include <QDebug>
#include <etalon.h>
#include <thread>
#include <chrono>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
	morzewindow morzeWind;

	QObject::connect(&w, SIGNAL(exiting()), &a, SLOT(quit()));
	morzeWind.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
	morzeWind.showFullScreen();

	//w.showFullScreen();
	w.show();

    return a.exec();
}

