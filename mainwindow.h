#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "mousefilter.h"
#include "congra.h"
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

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
	QLabel* lbl;
	QString congratulationsString;
	QString errorString;
	QString StandartString;
	QString clearString;
	Congra timerMessage;
	MyThread messageThread;
	int widthFirstScreen;
	int heightFirstScreen;
	bool bBlink;
	int NumberLine;
	void timeEvent(QTimerEvent*);
	bool ControlCode(QString code, int NumberLineEdit);
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
	Ui::MainWindow *ui;

public slots:
	void HideWindow()
	{
		lbl->hide();
	}


};

#endif // MAINWINDOW_H