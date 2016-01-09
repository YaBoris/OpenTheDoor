#include "mainwindow.h"
#include "ui_mainwindow.h"


Etalon EtalonMorzeCode;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{    
	ui->setupUi(this);
	QDesktopWidget* qdw = QApplication::desktop();
	congratulationsString = "<FONT COLOR = GREEN><CENTER>ПРАВИЛЬНО!</CENTER><FONT>";
	errorString = "<FONT COLOR = RED><CENTER>НЕПРАВИЛЬНО!</CENTER><FONT>";
	enterString = "Введите код";
	extraQuitString = "11111";
	widthFirstScreen=0;
	heightFirstScreen=0;
	int CountScreens=0;
	NumberLine=1;
	allLabelAnswered=0;
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

	le_gray_palette.setColor(QPalette::Text, Qt::gray);
	le_black_palette.setColor(QPalette::Text, Qt::black);
	ui->lineEdit_1->setPalette(le_gray_palette);

	ui->pushButton_1->move(xButton, y);
	ui->pushButton_1->setStyleSheet("QPushButton {  border-radius: 10px; } ");
	ui->lineEdit_1->move(x, y);

	y+=70;
	ui->lineEdit_2->size().setHeight(y);
	ui->lineEdit_2->setStyleSheet("QLineEdit {  border-radius: 10px; } ");
	ui->lineEdit_2->setPalette(le_gray_palette);
	ui->pushButton_2->move(xButton, y);
	ui->pushButton_2->setStyleSheet("QPushButton {  border-radius: 10px; } ");
	ui->lineEdit_2->move(x, y);

	y+=70;
	ui->lineEdit_3->size().setHeight(y);
	ui->lineEdit_3->setStyleSheet("QLineEdit {  border-radius: 10px; } ");
	ui->lineEdit_3->setPalette(le_gray_palette);

	ui->pushButton_3->move(xButton, y);
	ui->pushButton_3->setStyleSheet("QPushButton {  border-radius: 10px; } ");
	ui->lineEdit_3->move(x, y);

	x = (widthFirstScreen-600)/2;
	y=60;

	ui->lineEdit_1->setText(enterString);
	ui->lineEdit_2->setText(enterString);
	ui->lineEdit_3->setText(enterString);

	ui->lineEdit_1->installEventFilter(this);
	ui->lineEdit_2->installEventFilter(this);
	ui->lineEdit_3->installEventFilter(this);

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
	if (ControlCode(String1, 5))
	{
		emit exiting();
	}
	if(ControlCode(String1, NumberLine))
	{
		allLabelAnswered+=1;
		if(allLabelAnswered == 7)
		{
			lbl->setText(congratulationsString);
			lbl->show();
			lbl->move((widthFirstScreen-lbl->width())/2,(heightFirstScreen-lbl->height())/2);
			timerMessage.startShow(1500);

			emit startVideo();

			allLabelAnswered = 0;
			ui->lineEdit_1->setPalette(le_gray_palette);
			ui->lineEdit_1->setText(enterString);

			ui->lineEdit_2->show();
			ui->pushButton_2->show();
			ui->lineEdit_2->setPalette(le_gray_palette);
			ui->lineEdit_2->setText(enterString);

			ui->lineEdit_3->show();
			ui->pushButton_3->show();
			ui->lineEdit_3->setPalette(le_gray_palette);
			ui->lineEdit_3->setText(enterString);
		}
		else
		{
			ui->lineEdit_1->hide();
			ui->pushButton_1->hide();

			lbl->setText(congratulationsString);
			lbl->show();
			lbl->move((widthFirstScreen-lbl->width())/2,(heightFirstScreen-lbl->height())/2);
			timerMessage.startShow(1500);
		}
	}
	else
	{
		//если неправильное слово
		lbl->setText(errorString);
		lbl->show();
		lbl->move((widthFirstScreen-lbl->width())/2,(heightFirstScreen-lbl->height())/2);
		timerMessage.startShow(1500);
		ui->lineEdit_1->setText("");
	}
}

void MainWindow::on_pushButton_2_clicked()
{
	NumberLine = 2;
	QString String2 = ui->lineEdit_2->text();
	if (ControlCode(String2, 5))
	{
		emit exiting();
	}
	if(ControlCode(String2, NumberLine))
	{
		allLabelAnswered+=2;
		if(allLabelAnswered == 7)
		{
			lbl->setText(congratulationsString);
			lbl->show();
			lbl->move((widthFirstScreen-lbl->width())/2,(heightFirstScreen-lbl->height())/2);
			timerMessage.startShow(1500);

			emit startVideo();

			allLabelAnswered = 0;
			ui->lineEdit_2->setPalette(le_gray_palette);
			ui->lineEdit_2->setText(enterString);

			ui->lineEdit_1->show();
			ui->pushButton_1->show();
			ui->lineEdit_1->setPalette(le_gray_palette);
			ui->lineEdit_1->setText(enterString);

			ui->lineEdit_3->show();
			ui->pushButton_3->show();
			ui->lineEdit_3->setPalette(le_gray_palette);
			ui->lineEdit_3->setText(enterString);
		}
		else
		{
			ui->lineEdit_2->hide();
			ui->pushButton_2->hide();

			lbl->setText(congratulationsString);
			lbl->show();
			lbl->move((widthFirstScreen-lbl->width())/2,(heightFirstScreen-lbl->height())/2);
			timerMessage.startShow(1500);
		}
	}
	else
	{
		//если неправильное слово
		lbl->setText(errorString);
		lbl->show();
		lbl->move((widthFirstScreen-lbl->width())/2,(heightFirstScreen-lbl->height())/2);
		timerMessage.startShow(1500);
		ui->lineEdit_2->setText("");
	}
}

void MainWindow::on_pushButton_3_clicked()
{
	NumberLine = 4;
	QString String3 = ui->lineEdit_3->text();
	if (ControlCode(String3, 5))
	{
		emit exiting();
	}
	if(ControlCode(String3, NumberLine))
	{
		allLabelAnswered+=4;
		if(allLabelAnswered == 7)
		{
			lbl->setText(congratulationsString);
			lbl->show();
			lbl->move((widthFirstScreen-lbl->width())/2,(heightFirstScreen-lbl->height())/2);
			timerMessage.startShow(1500);

			emit startVideo();

			allLabelAnswered = 0;
			ui->lineEdit_3->setPalette(le_gray_palette);
			ui->lineEdit_3->setText(enterString);

			ui->lineEdit_2->show();
			ui->pushButton_2->show();
			ui->lineEdit_2->setPalette(le_gray_palette);
			ui->lineEdit_2->setText(enterString);

			ui->lineEdit_1->show();
			ui->pushButton_1->show();
			ui->lineEdit_1->setPalette(le_gray_palette);
			ui->lineEdit_1->setText(enterString);
		}
		else
		{
			ui->lineEdit_3->hide();
			ui->pushButton_3->hide();

			lbl->setText(congratulationsString);
			lbl->show();
			lbl->move((widthFirstScreen-lbl->width())/2,(heightFirstScreen-lbl->height())/2);
			timerMessage.startShow(1500);
		}
	}
	else
	{
		//если неправильное слово
		lbl->setText(errorString);
		lbl->show();
		lbl->move((widthFirstScreen-lbl->width())/2,(heightFirstScreen-lbl->height())/2);
		timerMessage.startShow(1500);
		ui->lineEdit_3->setText("");
	}
}

bool MainWindow::eventFilter(QObject *obj, QEvent *ev)
{
	if (obj == ui->lineEdit_1 && ev->type() == QEvent::FocusIn)
	{
		if (ui->lineEdit_1->text() == enterString)
		{
			ui->lineEdit_1->setText("");
			ui->lineEdit_1->setPalette(le_black_palette);
			if(ui->lineEdit_2->text() == clearString)
			{
				ui->lineEdit_2->setPalette(le_gray_palette);
				ui->lineEdit_2->setText(enterString);
			}
			if(ui->lineEdit_3->text() == clearString)
			{
				ui->lineEdit_3->setPalette(le_gray_palette);
				ui->lineEdit_3->setText(enterString);
			}
			return false;
		}
		else
		{
			return false;
		}
	}
	else if (obj == ui->lineEdit_2 && ev->type() == QEvent::FocusIn)
	{
		if (ui->lineEdit_2->text() == enterString)
		{
			ui->lineEdit_2->setText("");
			ui->lineEdit_2->setPalette(le_black_palette);
			if(ui->lineEdit_1->text() == clearString)
			{
				ui->lineEdit_1->setPalette(le_gray_palette);
				ui->lineEdit_1->setText(enterString);
			}
			if(ui->lineEdit_3->text() == clearString)
			{
				ui->lineEdit_3->setPalette(le_gray_palette);
				ui->lineEdit_3->setText(enterString);
			}
			return false;
		}
		else
		{
			return false;
		}
	}
	else if(obj == ui->lineEdit_3 && ev->type() == QEvent::FocusIn)
	{

		if (ui->lineEdit_3->text() == enterString)
		{
			ui->lineEdit_3->setText("");
			ui->lineEdit_3->setPalette(le_black_palette);
			if(ui->lineEdit_1->text() == clearString)
			{
				ui->lineEdit_1->setPalette(le_gray_palette);
				ui->lineEdit_1->setText(enterString);
			}
			if(ui->lineEdit_2->text() == clearString)
			{
				ui->lineEdit_2->setPalette(le_gray_palette);
				ui->lineEdit_2->setText(enterString);
			}
			return false;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
	return MainWindow::eventFilter(obj, ev);
}

void MainWindow::startVideo()
{
	QProcess* proc=new QProcess(this);
	proc->start("explorer d:\\__DOCS_PROJECTS\\Qt\\OpenTheDoor\\MP709\\startvideo.bat");
}
