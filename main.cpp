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

	morzeWind.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
	morzeWind.resize(morzeWind.GetSizeX(), morzeWind.GetSizeY());
	morzeWind.MoveToConer();
	QPalette palMorze = morzeWind.palette();
	palMorze.setColor(QPalette::Base, palMorze.color(QPalette::Window));
	morzeWind.setPalette(palMorze);
	morzeWind.setPalette(QPalette(Qt::black));
	morzeWind.show();

	w.showFullScreen();

    return a.exec();
}

