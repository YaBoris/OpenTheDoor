#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "mousefilter.h"
#include "congra.h"
#include "opendoortimer.h"
#include <QMainWindow>
#include <QtDebug>
#include <QTime>
#include "etalon.h"
#include <QDesktopWidget>
#include <QString>
#include <QIODevice>
#include <QFile>
#include <windows.h>
#include <QtWidgets>
#include <QWidget>
#include <QLabel>
#include <QMessageBox>
#include <QDialog>
#include <QImage>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
	int allLabelAnswered;
	QLabel* lbl;
	QString congratulationsString;
	QString errorString;
	QString StandartString;
	QString clearString;
	QString enterString;
	QString extraQuitString;
	QString pathToVideoBat;
	QPalette le_gray_palette;
	QPalette le_black_palette;
	QProcess* procVideo;
	QImage* imageMainWindow;

	Congra timerMessage;
	Congra timerOpenDoor;

	opendoortimer timerChangeTxtOpenDoor;
	QThread* timerChangeTxtOpenDoorThread;

	MyThread messageThread;
	int widthFirstScreen;
	int heightFirstScreen;
	bool bBlink;
	int NumberLine;
	void timeEvent(QTimerEvent*);
	bool ControlCode(QString code, int NumberLineEdit);
	bool eventFilter(QObject *obj, QEvent *ev);
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
	void exiting();

private slots:
    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

	//void startVideo();

	//void changeStateTxtFile();

private:
	Ui::MainWindow *ui;

public slots:
	void HideWindow()
	{
		lbl->hide();
	}


};

#endif // MAINWINDOW_H
