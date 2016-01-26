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

	widthFirstScreen = 0;
	heightFirstScreen = 0;
	widthSecondScreen = 0;
	heightSecondScreen = 0;
	CountScreens = 0;

	CountScreens = windowMorze->numScreens();
	widthFirstScreen = windowMorze->screenGeometry(0).width();
	heightFirstScreen = windowMorze->screenGeometry(0).height();


	if(windowMorze->numScreens()>1)
	{

		widthSecondScreen = windowMorze->screenGeometry(1).width();
		heightSecondScreen = windowMorze->screenGeometry(1).height();
		QRect screenres = QApplication::desktop()->screenGeometry(1);
		//windowMorze->setGeometry(screenres.x(), screenres.y(), widthSecondScreen, heightSecondScreen);

		//windowMorze->resize(screenres.width(), screenres.height());
		//windowMorze->showFullScreen();
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

//void morzewindow::MoveToConer()
//{
//	if(windowMorze->numScreens()>1)
//	{
//		QRect rect = QApplication::desktop()->screenGeometry(1);
//		QPoint Coner = rect.center(); //координаты центра экрана
//		Coner.setX(1920);
//		Coner.setY(0);
//		move(Coner);
//	}
//	else
//	{
//		QRect rect = QApplication::desktop()->screenGeometry(0);
//		QPoint Coner = rect.center(); //координаты центра экрана
//		Coner.setX(widthFirstScreen/3);
//		Coner.setY(heightFirstScreen/3);
//		move(Coner);
//	}
//}

//int morzewindow::GetSizeX()
//{
//	if(windowMorze->numScreens()>1)
//	{
//		return widthSecondScreen;
//	}
//	return widthFirstScreen/3;
//}

//int morzewindow::GetSizeY()
//{
//	if(windowMorze->numScreens()>1)
//	{
//		return heightSecondScreen;
//	}
//	return heightFirstScreen/3;
//}



