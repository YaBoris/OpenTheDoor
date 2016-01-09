#ifndef ETALON_H
#define ETALON_H

#include <QObject>
#include <QString>
#include <QtDebug>

#include "morzecode.h"

class Etalon
{
public:
	int ReadyCodeMorzeForBlink[50];
    Etalon();
	~Etalon();
	morzeCode TableCode;
    QString getStrings(int InstString);
	int *GetReadyCodeMorzeForBlink();

private:	
	QString fullString;
	QString string1Etalon;
	QString string2Etalon;
	QString string3Etalon;
	QString string4Etalon;
	QString string5Etalon;
};

#endif // ETALON_H
