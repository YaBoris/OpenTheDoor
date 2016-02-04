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
	extraQuitString = "11110";
	//pathToVideoBat = "explorer d:\\Downloads\\Qt\\Projects\\OpenTheDoor\\MP709\\startvideo.bat";
	//pathToVideoBat = "explorer d:\\__DOCS_PROJECTS\\Qt\\OpenTheDoor\\MP709\\startvideo.bat";

	pathToVideoBat = "explorer C:\\Users\\Public\\Downloads\\MP709\\startvideo.bat";

	widthFirstScreen=0;
	heightFirstScreen=0;
	CountScreens=0;
	widthSecondScreen = 0;
	heightSecondScreen = 0;
	NumberLine=1;
	allLabelAnswered=0;

	timerMessage.moveToThread(&messageThread);

	CountScreens = qdw->numScreens();
	widthFirstScreen=qdw->screenGeometry(0).width();
	heightFirstScreen=qdw->screenGeometry(0).height();
	int widthIcon = 120;
	int widthButton = 120;
	int widthField = 600;
	int widthSpace = 30;
	int xIcon=0;
	int xField=0;
	int xButton=0;
	int y;

	if(qdw->numScreens()>1)
	{
		widthSecondScreen = qdw->screenGeometry(1).width();
		heightSecondScreen = qdw->screenGeometry(1).height();
		QRect screenres = QApplication::desktop()->screenGeometry(1);
		move(screenres.x(), screenres.y());
		xIcon = (widthSecondScreen-(widthIcon+widthButton+widthSpace*2+widthField))/2;
		xField = xIcon + widthIcon + widthSpace;
		xButton = xField + widthField + widthSpace;
		y = (heightSecondScreen-190)/2;
	}
	else
	{
		xIcon = (widthFirstScreen-(widthIcon+widthButton+widthSpace*2+widthField))/2;
		xField = xIcon + widthIcon + widthSpace;
		xButton = xField + widthField + widthSpace;
		y = (heightFirstScreen-190)/2;
	}

	//процесс для запуска видеоролика
	procVideo=new QProcess(this);

	timerChangeTxtOpenDoorThread = new QThread;
	timerChangeTxtOpenDoor.moveToThread(timerChangeTxtOpenDoorThread);

	//коннект для скрытия окна "ПРАВИЛЬНО/НЕПРАВИЛЬНО"
	QObject::connect(&timerMessage, SIGNAL(hiding()), SLOT(HideWindow()));

	//сокрытие окна морзянки на время показа видео, чтобы не перекрывало
	QObject::connect(&timerChangeTxtOpenDoor, SIGNAL(hideMorzeWindow()), SLOT(hideMWindow()));
	QObject::connect(&timerChangeTxtOpenDoor, SIGNAL(showMorzeWindow()), SLOT(showMWindow()));

	//коннект для запуска функции задержки при просмотре финального видеоролика
	//и последующего изменения состояния текстового файла открытия замка
	QObject::connect(timerChangeTxtOpenDoorThread, SIGNAL(started()), &timerChangeTxtOpenDoor, SLOT(changeTxt()));

	lbl = new QLabel();
	QFont f("Helvetica", 80, QFont::Bold);
	lbl->setFont(f);
	lbl->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

	CountScreens=qdw->numScreens();
	this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
	QPalette palMainWindow;

	//QPixmap pix("d://__DOCS_PROJECTS//Qt//OpenTheDoor//555.png");
	QPixmap pix("C://Users//Public//Downloads//MP709//style//555.png");
	//QPixmap pix("d://Downloads//Qt//Projects//OpenTheDoor//style//555.png");

	palMainWindow.setBrush(this->backgroundRole(), QBrush(pix));
	this->setPalette(palMainWindow);
	this->setAutoFillBackground(true);

	if(qdw->numScreens()>1)
	{
		this->resize(widthSecondScreen, heightSecondScreen);
	}
	else
	{
		this->resize(widthFirstScreen, heightFirstScreen);
	}

	//задаем размещение иконок, полей ввода и кнопок
	ui->lineEdit_1->size().setWidth(widthField);
	ui->lineEdit_1->size().setHeight(y);

	le_gray_palette.setColor(QPalette::Text, Qt::gray);
	le_black_palette.setColor(QPalette::Text, Qt::black);
	ui->lineEdit_1->setPalette(le_gray_palette);

	ui->label_1->move(xIcon, y);
	ui->pushButton_1->move(xButton, y);
	ui->lineEdit_1->move(xField, y);

	y+=70;
	ui->lineEdit_2->size().setHeight(y);
	ui->lineEdit_2->setPalette(le_gray_palette);
	ui->pushButton_2->move(xButton, y);
	ui->lineEdit_2->move(xField, y);
	ui->label_2->move(xIcon, y);

	y+=70;
	ui->lineEdit_3->size().setHeight(y);
	ui->lineEdit_3->setPalette(le_gray_palette);

	ui->pushButton_3->move(xButton, y);
	ui->lineEdit_3->move(xField, y);
	ui->label_3->move(xIcon, y);

	y=60;

	ui->lineEdit_1->setText(enterString);
	ui->lineEdit_2->setText(enterString);
	ui->lineEdit_3->setText(enterString);

	//QFile buttonStyleFile("d://__DOCS_PROJECTS//Qt//OpenTheDoor//style//simple.qss");
	QFile buttonStyleFile("C://Users//Public//Downloads//MP709//style//simple.qss");
	//QFile buttonStyleFile("d://Downloads//Qt//Projects//OpenTheDoor//style//simple.qss");

	buttonStyleFile.open(QFile::ReadOnly);
	QString strCSS = QLatin1String(buttonStyleFile.readAll());
	this->setStyleSheet(strCSS);

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
			lbl->show();
			lbl->setText(congratulationsString);
			if(CountScreens<2)
			{
				lbl->move((widthFirstScreen-lbl->width())/2,(heightFirstScreen-lbl->height())/2);
			}
			else
			{
				lbl->move(0 - lbl->width() - (widthSecondScreen - lbl->width())/2,(heightSecondScreen - lbl->height())/2);
			}
			//если отгаданы все коды, то открываем замок
			timerChangeTxtOpenDoorThread->start();
			procVideo->start(pathToVideoBat);

			allLabelAnswered = 0;
			ui->lineEdit_1->setPalette(le_gray_palette);
			ui->lineEdit_1->setText(enterString);

			ui->lineEdit_2->show();
			ui->pushButton_2->show();
			ui->label_2->show();
			ui->lineEdit_2->setPalette(le_gray_palette);
			ui->lineEdit_2->setText(enterString);

			ui->lineEdit_3->show();
			ui->pushButton_3->show();
			ui->label_3->show();
			ui->lineEdit_3->setPalette(le_gray_palette);
			ui->lineEdit_3->setText(enterString);
		}
		else
		{
			ui->lineEdit_1->hide();
			ui->pushButton_1->hide();
			ui->label_1->hide();
			lbl->setText(congratulationsString);
			lbl->show();
			if(CountScreens<2)
			{
				lbl->move((widthFirstScreen-lbl->width())/2,(heightFirstScreen-lbl->height())/2);
			}
			else
			{
				lbl->move(0 - lbl->width() - (widthSecondScreen - lbl->width())/2,(heightSecondScreen - lbl->height())/2);
			}
			timerMessage.startShow(1500);
		}
	}
	else
	{
		//если неправильное слово
		lbl->setText(errorString);
		lbl->show();
		if(CountScreens<2)
		{
			lbl->move((widthFirstScreen-lbl->width())/2,(heightFirstScreen-lbl->height())/2);
		}
		else
		{
			lbl->move(0 - lbl->width() - (widthSecondScreen - lbl->width())/2,(heightSecondScreen - lbl->height())/2);
		}
		timerMessage.startShow(1500);
		ui->lineEdit_1->setText(enterString);
		ui->lineEdit_1->setFocus();
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
			if(CountScreens<2)
			{
				lbl->move((widthFirstScreen-lbl->width())/2,(heightFirstScreen-lbl->height())/2);
			}
			else
			{
				lbl->move(0 - lbl->width() - (widthSecondScreen - lbl->width())/2,(heightSecondScreen - lbl->height())/2);
			}
			timerMessage.startShow(1500);

			//если отгаданы все коды, то открываеми перезаписываем файл состояния реле на "ВКЛ"
			timerChangeTxtOpenDoorThread->start();
			procVideo->start(pathToVideoBat);

			allLabelAnswered = 0;
			ui->lineEdit_2->setPalette(le_gray_palette);
			ui->lineEdit_2->setText(enterString);

			ui->lineEdit_1->show();
			ui->pushButton_1->show();
			ui->label_1->show();
			ui->lineEdit_1->setPalette(le_gray_palette);
			ui->lineEdit_1->setText(enterString);

			ui->lineEdit_3->show();
			ui->pushButton_3->show();
			ui->label_3->show();
			ui->lineEdit_3->setPalette(le_gray_palette);
			ui->lineEdit_3->setText(enterString);
		}
		else
		{
			ui->lineEdit_2->hide();
			ui->pushButton_2->hide();
			ui->label_2->hide();
			lbl->setText(congratulationsString);
			lbl->show();
			if(CountScreens<2)
			{
				lbl->move((widthFirstScreen-lbl->width())/2,(heightFirstScreen-lbl->height())/2);
			}
			else
			{
				lbl->move(0 - lbl->width() - (widthSecondScreen - lbl->width())/2,(heightSecondScreen - lbl->height())/2);
			}
			timerMessage.startShow(1500);
		}
	}
	else
	{
		//если неправильное слово
		lbl->setText(errorString);
		lbl->show();
		if(CountScreens<2)
		{
			lbl->move((widthFirstScreen-lbl->width())/2,(heightFirstScreen-lbl->height())/2);
		}
		else
		{
			lbl->move(0 - lbl->width() - (widthSecondScreen - lbl->width())/2,(heightSecondScreen - lbl->height())/2);
		}
		timerMessage.startShow(1500);
		ui->lineEdit_2->setText(enterString);
		ui->lineEdit_2->setFocus();
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
			if(CountScreens<2)
			{
				lbl->move((widthFirstScreen-lbl->width())/2,(heightFirstScreen-lbl->height())/2);
			}
			else
			{
				lbl->move(0 - lbl->width() - (widthSecondScreen - lbl->width())/2,(heightSecondScreen - lbl->height())/2);
			}
			timerMessage.startShow(1500);


			//если отгаданы все коды, то открываеми перезаписываем файл состояния реле на "ВКЛ"
			timerChangeTxtOpenDoorThread->start();
			procVideo->start(pathToVideoBat);

			allLabelAnswered = 0;
			ui->lineEdit_3->setPalette(le_gray_palette);
			ui->lineEdit_3->setText(enterString);

			ui->lineEdit_2->show();
			ui->pushButton_2->show();
			ui->label_2->show();
			ui->lineEdit_2->setPalette(le_gray_palette);
			ui->lineEdit_2->setText(enterString);

			ui->lineEdit_1->show();
			ui->pushButton_1->show();
			ui->label_1->show();
			ui->lineEdit_1->setPalette(le_gray_palette);
			ui->lineEdit_1->setText(enterString);
		}
		else
		{
			ui->lineEdit_3->hide();
			ui->pushButton_3->hide();
			ui->label_3->hide();
			lbl->setText(congratulationsString);
			lbl->show();
			if(CountScreens<2)
			{
				lbl->move((widthFirstScreen-lbl->width())/2,(heightFirstScreen-lbl->height())/2);
			}
			else
			{
				lbl->move(0 - lbl->width() - (widthSecondScreen - lbl->width())/2,(heightSecondScreen - lbl->height())/2);
			}
			timerMessage.startShow(1500);
		}
	}
	else
	{
		//если неправильное слово
		lbl->setText(errorString);
		lbl->show();
		if(CountScreens<2)
		{
			lbl->move((widthFirstScreen-lbl->width())/2,(heightFirstScreen-lbl->height())/2);
		}
		else
		{
			lbl->move(0 - lbl->width() - (widthSecondScreen - lbl->width())/2,(heightSecondScreen - lbl->height())/2);
		}
		timerMessage.startShow(1500);
		ui->lineEdit_3->setText(enterString);
		ui->lineEdit_3->setFocus();
	}
}

bool MainWindow::eventFilter(QObject *obj, QEvent *ev)
{
	if (obj == ui->lineEdit_1 && ev->type() == QEvent::FocusIn)
	{
		if(ui->lineEdit_3->text() == "")
		{
			ui->lineEdit_3->setPalette(le_gray_palette);
			ui->lineEdit_3->setText(enterString);
		}
		if(ui->lineEdit_2->text() == "")
		{
			ui->lineEdit_2->setPalette(le_gray_palette);
			ui->lineEdit_2->setText(enterString);
		}

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
		if(ui->lineEdit_1->text() == "")
		{
			ui->lineEdit_1->setPalette(le_gray_palette);
			ui->lineEdit_1->setText(enterString);
		}
		if(ui->lineEdit_3->text() == "")
		{
			ui->lineEdit_3->setPalette(le_gray_palette);
			ui->lineEdit_3->setText(enterString);
		}

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
		if(ui->lineEdit_1->text() == "")
		{
			ui->lineEdit_1->setPalette(le_gray_palette);
			ui->lineEdit_1->setText(enterString);
		}
		if(ui->lineEdit_2->text() == "")
		{
			ui->lineEdit_2->setPalette(le_gray_palette);
			ui->lineEdit_2->setText(enterString);
		}

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

