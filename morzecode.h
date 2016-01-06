#ifndef MORZECODE_H
#define MORZECODE_H
#include <QVector>
#include <QtDebug>

class morzeCode
{
private:

	int tempArray[6];
public:
	QVector< QVector<int> > morzeCodeArr;
	QVector<int> morzeCodeLine;

	morzeCode();
	int GetMorzeCharacter(int utfCharacter, int MorzeCharacterPosition);
	int GetUtfCode(int index);
};

#endif // MORZECODE_H
