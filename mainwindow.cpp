#include "mainwindow.h"
#include "ui_mainwindow.h"


Etalon EtalonMorzeCode;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{    
	ui->setupUi(this);
	StandartString = "Введите код";
	QDesktopWidget* qdw = QApplication::desktop();
	congratulationsString = "<FONT COLOR = GREEN><CENTER>ПРАВИЛЬНО!</CENTER><FONT>";
	errorString = "<FONT COLOR = RED><CENTER>НЕПРАВИЛЬНО!</CENTER><FONT>";
	widthFirstScreen=0;
	heightFirstScreen=0;
	int CountScreens=0;
	NumberLine=1;

	timerMessage.moveToThread(&messageThread);

	QObject::connect(&timerMessage, SIGNAL(hiding()), SLOT(HideWindow()));
	QObject::connect(&timerMessage, SIGNAL(finished()), &messageThread, SLOT(quit()));

	lbl = new QLabel();
	QFont f("Helvetica", 80, QFont::Bold);
	lbl->setFont(f);
	lbl->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

	CountScreens=qdw->numScreens();
	widthFirstScreen=qdw->screenGeometry().width();
	heightFirstScreen=qdw->screenGeometry().height();

	int y = (heightFirstScreen-190)/2;
	int x = (widthFirstScreen-580)/2;
	int xButton=x+460;

	ui->lineEdit_1->size().setWidth(x);
	ui->lineEdit_1->size().setHeight(y);
	ui->lineEdit_1->setStyleSheet("QLineEdit {  border-radius: 10px; } ");
	//ui->lineEdit_1->installEventFilter(new MouseFilter(ui->lineEdit_1));
	ui->pushButton_1->move(xButton, y);
	ui->pushButton_1->setStyleSheet("QPushButton {  border-radius: 10px; } ");
	ui->lineEdit_1->move(x, y);

	y+=70;
	ui->lineEdit_2->size().setHeight(y);
	ui->lineEdit_2->setStyleSheet("QLineEdit {  border-radius: 10px; } ");
	//ui->lineEdit_2->installEventFilter(new MouseFilter (ui->lineEdit_2));
	ui->pushButton_2->move(xButton, y);
	ui->pushButton_2->setStyleSheet("QPushButton {  border-radius: 10px; } ");
	ui->lineEdit_2->move(x, y);

	y+=70;
	ui->lineEdit_3->size().setHeight(y);
	ui->lineEdit_3->setStyleSheet("QLineEdit {  border-radius: 10px; } ");
	//ui->lineEdit_3->installEventFilter(new MouseFilter (ui->lineEdit_3));
	ui->pushButton_3->move(xButton, y);
	ui->pushButton_3->setStyleSheet("QPushButton {  border-radius: 10px; } ");
	ui->lineEdit_3->move(x, y);

	x = (widthFirstScreen-600)/2;
	y=60;

	ui->lineEdit_1->setText(StandartString);
	ui->lineEdit_2->setText(StandartString);
	ui->lineEdit_3->setText(StandartString);

	messageThread.start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::ControlCode(QString code, int NumberLineEdit)
{
	if(!QString::compare(code, EtalonMorzeCode.getStrings(NumberLineEdit), Qt::CaseInsensitive))
	{
		return true;
	}
	return false;
}

void MainWindow::on_pushButton_1_clicked()
{
	NumberLine = 1;
	QString String1 = ui->lineEdit_1->text();
	if(ControlCode(String1, NumberLine))
	{
		lbl->setText(congratulationsString);
		lbl->show();
		lbl->move((widthFirstScreen-lbl->width())/2,(heightFirstScreen-lbl->height())/2);

		timerMessage.startShow(1500);

		ui->lineEdit_1->hide();
		ui->pushButton_1->hide();
	}
	else
	{
		//если неправильное слово
		lbl->setText(errorString);
		lbl->show();
		lbl->move((widthFirstScreen-lbl->width())/2,(heightFirstScreen-lbl->height())/2);

		//messageThread.start();
		timerMessage.startShow(1500);

		ui->lineEdit_1->setText("");
	}
}

void MainWindow::on_pushButton_2_clicked()
{
	NumberLine = 2;
	QString String2 = ui->lineEdit_2->text();
	if(ControlCode(String2, NumberLine))
	{
		lbl->setText(congratulationsString);
		lbl->show();
		lbl->move((widthFirstScreen-lbl->width())/2,(heightFirstScreen-lbl->height())/2);

		timerMessage.startShow(1500);

		ui->lineEdit_2->hide();
		ui->pushButton_2->hide();
	}
	else
	{
		//если неправильное слово
		lbl->setText(errorString);
		lbl->show();
		lbl->move((widthFirstScreen-lbl->width())/2,(heightFirstScreen-lbl->height())/2);

		//messageThread.start();
		timerMessage.startShow(1500);

		ui->lineEdit_2->setText("");
	}
}

void MainWindow::on_pushButton_3_clicked()
{
	NumberLine = 3;
	QString String3 = ui->lineEdit_3->text();
	if(ControlCode(String3, NumberLine))
	{
		lbl->setText(congratulationsString);
		lbl->show();
		lbl->move((widthFirstScreen-lbl->width())/2,(heightFirstScreen-lbl->height())/2);

		timerMessage.startShow(1500);

		ui->lineEdit_3->hide();
		ui->pushButton_3->hide();
	}
	else
	{
		//если неправильное слово
		lbl->setText(errorString);
		lbl->show();
		lbl->move((widthFirstScreen-lbl->width())/2,(heightFirstScreen-lbl->height())/2);

		//messageThread.start();
		timerMessage.startShow(1500);

		ui->lineEdit_3->setText("");
	}
}

