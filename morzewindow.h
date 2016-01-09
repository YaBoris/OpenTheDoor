#ifndef MORZEWINDOW_H
#define MORZEWINDOW_H

#include "congra.h"
#include "blink.h"
#include <QMainWindow>
#include <QDesktopWidget>
#include <QtDebug>
#include <QString>

namespace Ui {
class morzewindow;
}

class morzewindow : public QMainWindow
{
    Q_OBJECT

public:

	int widthFirstScreen;
	int heightFirstScreen;
	int widthSecondScreen;
	int heightSecondScreen;
	int CountScreens;
	Blink MorzeBlinkTimer;
	BlinkThread* MorzeBlinkThread;

	QDesktopWidget* windowMorze;
	QRect screenres;

	explicit morzewindow(QWidget *parent = 0);
	~morzewindow();
	void MoveToConer();
	int GetSizeX();
	int GetSizeY();
	void FullMorzeString();



private:
    Ui::morzewindow *ui;

public slots:
	void Blink(bool BlackWhite);


};


#endif // MORZEWINDOW_H
