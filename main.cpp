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

	QObject::connect(&w, SIGNAL(SignalHideMorzeWindow()), &morzeWind, SLOT(HideMorze()));
	QObject::connect(&w, SIGNAL(SignalShowMorzeWindow()), &morzeWind, SLOT(ShowMorze()));

	QObject::connect(&w, SIGNAL(exiting()), &a, SLOT(quit()));
	morzeWind.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
	morzeWind.showFullScreen();
	w.showFullScreen();

    return a.exec();
}

