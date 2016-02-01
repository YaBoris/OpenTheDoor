#include "ui_morzewindow.h"
#include "morzewindow.h"
#include <QDesktopWidget>
#include <QPalette>

morzewindow::morzewindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::morzewindow)
{
    ui->setupUi(this);
	QDesktopWidget* windowMorze = QApplication::desktop();

	MorzeBlinkThread = new BlinkThread;

	CountScreens = windowMorze->numScreens();
	widthFirstScreen = windowMorze->screenGeometry(0).width();
	heightFirstScreen = windowMorze->screenGeometry(0).height();

	if(windowMorze->numScreens()>1)
	{
		widthSecondScreen = windowMorze->screenGeometry(0).width();
		heightSecondScreen = windowMorze->screenGeometry(0).height();
		QRect screenres = QApplication::desktop()->screenGeometry(0);
		move(screenres.x(), screenres.y());
	}
	MorzeBlinkTimer.moveToThread(MorzeBlinkThread);
	QObject::connect(MorzeBlinkThread, SIGNAL(started()), &MorzeBlinkTimer, SLOT(startBlink()));
	QObject::connect(&MorzeBlinkTimer, SIGNAL(latency(bool)), this, SLOT(Blink(bool)));
	MorzeBlinkThread->start();
}

//слот для смены цвета окна морзянки черный/белый
void morzewindow::Blink(bool BlackWhite)
{
	if(BlackWhite)
	{
		this->setPalette(QPalette(Qt::white));
		this->show();
	}
	else
	{
		this->setPalette(QPalette(Qt::black));
		this->show();
	}
}

morzewindow::~morzewindow()
{
    delete ui;
}



