#include "etalon.h"
#include <QFile>
#include <QByteArray>
#include <QString>
#include <windows.h>
#include <QIODevice>
#include <QByteArray>
#include <QChar>

int ReadyCodeMorzeForBlink[50];

Etalon::Etalon()
{
    QChar ch;
	int ex = 0;
    string1Etalon = "";
    string2Etalon = "";
    string3Etalon = "";
    string4Etalon = "";
	string5Etalon = "11111";

	//QFile codesFile("d:\\Downloads\\Qt\\Projects\\OpenTheDoor\\data.txt");
	//QFile codesFile("d:\\__DOCS_PROJECTS\\Qt\\OpenTheDoor\\data.txt");
	QFile codesFile("C:\\Users\\Public\\Downloads\\MP709\\data.txt");


	for(int i = 0; i < 50; i++) ReadyCodeMorzeForBlink[i] = 3;

    do
    {
        if (!codesFile.open(QIODevice::ReadOnly))
        {
            ex = 1;
            Sleep(100);
			//qDebug() << "Ошибка открытия для записи";
        }
        else
        {
            ex = 0;
            int i = 0;
            fullString = (codesFile.readAll());
			for(QString::iterator it = fullString.begin(); it != fullString.end(); it++)
            {
                if(*it == '|')
                {
                    i++;
                    continue;
                }
                switch (i)
                {
                    case 0:
                        ch = *it;
                        string1Etalon.push_back(ch);
                    break;
                    case 1:
                        ch = *it;
                        string2Etalon.push_back(ch);
                    break;
                    case 2:
                        ch = *it;
                        string3Etalon.push_back(ch);
                    break;
                    case 3:
                        ch = *it;
						//qDebug() << "ch " << ch;
                        string4Etalon.push_back(ch);
                    break;
                }
            }
        }
    }while(ex);

	//собираем строку морзянки для мигающего окна
	int indexArrayMorzeCode = 0;

	QChar charSearch;

	for(QString::iterator it = string4Etalon.begin(); it != string4Etalon.end(); it++)
	{
		charSearch = *it;

		for(int i = 0; i < 42; i++)
		{
			//qDebug() << "TableCode.GetMorzeCodeReady(i)" << TableCode.GetMorzeCodeReady(i);

			if(TableCode.GetUtfCode(i) != charSearch.unicode())
			{
				continue;
			}
			else
			{
				for(int j = 1; j < 7; j++)
				{
					ReadyCodeMorzeForBlink[indexArrayMorzeCode]=TableCode.GetMorzeCharacter(i, j);
					//qDebug() << "ReadyCodeMorzeForBlink[" << indexArrayMorzeCode << "]" << ReadyCodeMorzeForBlink[indexArrayMorzeCode];

					indexArrayMorzeCode++;

					if(ReadyCodeMorzeForBlink[indexArrayMorzeCode-1] == 2)
						break;

				}
			}
		}
		ReadyCodeMorzeForBlink[indexArrayMorzeCode] = 3;
		//qDebug() << "\n\n";
		for(int k = 0; k <= indexArrayMorzeCode; k++)
		{

			//qDebug() << "ReadyCodeMorzeForBlink[ " << k << "]" << ReadyCodeMorzeForBlink[k];
		}
	}

}

QString Etalon::getStrings(int InstString)
{
	switch (InstString)
	{
    case 1:
        return string1Etalon;
        break;
    case 2:
        return string2Etalon;
        break;
    case 3:
        return string3Etalon;
        break;
    case 4:
        return string4Etalon;
		break;
	case 5:
		return string5Etalon;
    }
    QString err = "Error";
    return err;
}

int* Etalon::GetReadyCodeMorzeForBlink()
{
	return ReadyCodeMorzeForBlink;
}

Etalon::~Etalon(){}
