#include "morzecode.h"

morzeCode::morzeCode()
{
	//а
	morzeCodeLine.push_back(1072);//1072,0,1,2,2,2,2
	morzeCodeLine.push_back(0);
	morzeCodeLine.push_back(1);
	morzeCodeLine.push_back(2);
	morzeCodeLine.push_back(2);
	morzeCodeLine.push_back(2);
	morzeCodeLine.push_back(2);
	morzeCodeArr.push_back(morzeCodeLine);

	//б
	morzeCodeLine[0]=1073;//1073,1,0,0,0,2,2
	morzeCodeLine[1]=1;
	morzeCodeLine[2]=0;
	morzeCodeLine[3]=0;
	morzeCodeLine[4]=0;
	morzeCodeLine[5]=2;
	morzeCodeLine[6]=2;
	morzeCodeArr.push_back(morzeCodeLine);

	//в
	morzeCodeLine[0]=1074;//1074,0,1,1,2,2,2
	morzeCodeLine[1]=0;
	morzeCodeLine[2]=1;
	morzeCodeLine[3]=1;
	morzeCodeLine[4]=2;
	morzeCodeLine[5]=2;
	morzeCodeLine[6]=2;
	morzeCodeArr.push_back(morzeCodeLine);

	//г
	morzeCodeLine[0]=1075;//1075,1,1,0,2,2,2
	morzeCodeLine[1]=1;
	morzeCodeLine[2]=1;
	morzeCodeLine[3]=0;
	morzeCodeLine[4]=2;
	morzeCodeLine[5]=2;
	morzeCodeLine[6]=2;
	morzeCodeArr.push_back(morzeCodeLine);

	//д
	morzeCodeLine[0]=1076;//1076,1,0,0,2,2,2
	morzeCodeLine[1]=1;
	morzeCodeLine[2]=0;
	morzeCodeLine[3]=0;
	morzeCodeLine[4]=2;
	morzeCodeLine[5]=2;
	morzeCodeLine[6]=2;
	morzeCodeArr.push_back(morzeCodeLine);

	//е
	morzeCodeLine[0]=1077;//1077,0,2,2,2,2,2
	morzeCodeLine[1]=0;
	morzeCodeLine[2]=2;
	morzeCodeLine[3]=2;
	morzeCodeLine[4]=2;
	morzeCodeLine[5]=2;
	morzeCodeLine[6]=2;
	morzeCodeArr.push_back(morzeCodeLine);

	//ж
	morzeCodeLine[0]=1078;//1078,0,0,0,1,2,2
	morzeCodeLine[1]=0;
	morzeCodeLine[2]=0;
	morzeCodeLine[3]=0;
	morzeCodeLine[4]=1;
	morzeCodeLine[5]=2;
	morzeCodeLine[6]=2;
	morzeCodeArr.push_back(morzeCodeLine);

	//з
	morzeCodeLine[0]=1079;//1079,1,1,0,0,2,2
	morzeCodeLine[1]=1;
	morzeCodeLine[2]=1;
	morzeCodeLine[3]=0;
	morzeCodeLine[4]=0;
	morzeCodeLine[5]=2;
	morzeCodeLine[6]=2;
	morzeCodeArr.push_back(morzeCodeLine);

	//и
	morzeCodeLine[0]=1080;//1080,0,0,2,2,2,2
	morzeCodeLine[1]=0;
	morzeCodeLine[2]=0;
	morzeCodeLine[3]=2;
	morzeCodeLine[4]=2;
	morzeCodeLine[5]=2;
	morzeCodeLine[6]=2;
	morzeCodeArr.push_back(morzeCodeLine);

	//й
	morzeCodeLine[0]=1081;//1081,0,1,1,1,2,2
	morzeCodeLine[1]=0;
	morzeCodeLine[2]=1;
	morzeCodeLine[3]=1;
	morzeCodeLine[4]=1;
	morzeCodeLine[5]=2;
	morzeCodeLine[6]=2;
	morzeCodeArr.push_back(morzeCodeLine);

	//к
	morzeCodeLine[0]=1082;//1082,1,0,1,2,2,2
	morzeCodeLine[1]=1;
	morzeCodeLine[2]=0;
	morzeCodeLine[3]=1;
	morzeCodeLine[4]=2;
	morzeCodeLine[5]=2;
	morzeCodeLine[6]=2;
	morzeCodeArr.push_back(morzeCodeLine);

	//л
	morzeCodeLine[0]=1083;//1083,0,1,0,0,2,2
	morzeCodeLine[1]=0;
	morzeCodeLine[2]=1;
	morzeCodeLine[3]=0;
	morzeCodeLine[4]=0;
	morzeCodeLine[5]=2;
	morzeCodeLine[6]=2;
	morzeCodeArr.push_back(morzeCodeLine);

	//м
	morzeCodeLine[0]=1084;//1084,1,1,2,2,2,2
	morzeCodeLine[1]=1;
	morzeCodeLine[2]=1;
	morzeCodeLine[3]=2;
	morzeCodeLine[4]=2;
	morzeCodeLine[5]=2;
	morzeCodeLine[6]=2;
	morzeCodeArr.push_back(morzeCodeLine);

	//н
	morzeCodeLine[0]=1085;//1085,1,0,2,2,2,2
	morzeCodeLine[1]=1;
	morzeCodeLine[2]=0;
	morzeCodeLine[3]=2;
	morzeCodeLine[4]=2;
	morzeCodeLine[5]=2;
	morzeCodeLine[6]=2;
	morzeCodeArr.push_back(morzeCodeLine);

	//о
	morzeCodeLine[0]=1086;//1086,1,1,1,2,2,2
	morzeCodeLine[1]=1;
	morzeCodeLine[2]=1;
	morzeCodeLine[3]=1;
	morzeCodeLine[4]=2;
	morzeCodeLine[5]=2;
	morzeCodeLine[6]=2;
	morzeCodeArr.push_back(morzeCodeLine);

	//п
	morzeCodeLine[0]=1087;//1087,0,1,1,0,2,2
	morzeCodeLine[1]=0;
	morzeCodeLine[2]=1;
	morzeCodeLine[3]=1;
	morzeCodeLine[4]=0;
	morzeCodeLine[5]=2;
	morzeCodeLine[6]=2;
	morzeCodeArr.push_back(morzeCodeLine);

	//р
	morzeCodeLine[0]=1088;//1088,0,1,0,2,2,2
	morzeCodeLine[1]=0;
	morzeCodeLine[2]=1;
	morzeCodeLine[3]=0;
	morzeCodeLine[4]=2;
	morzeCodeLine[5]=2;
	morzeCodeLine[6]=2;
	morzeCodeArr.push_back(morzeCodeLine);

	//с
	morzeCodeLine[0]=1089;//1089,0,0,0,2,2,2
	morzeCodeLine[1]=0;
	morzeCodeLine[2]=0;
	morzeCodeLine[3]=0;
	morzeCodeLine[4]=2;
	morzeCodeLine[5]=2;
	morzeCodeLine[6]=2;
	morzeCodeArr.push_back(morzeCodeLine);

	//т
	morzeCodeLine[0]=1090;//1090,1,2,2,2,2,2
	morzeCodeLine[1]=1;
	morzeCodeLine[2]=2;
	morzeCodeLine[3]=2;
	morzeCodeLine[4]=2;
	morzeCodeLine[5]=2;
	morzeCodeLine[6]=2;
	morzeCodeArr.push_back(morzeCodeLine);

	//у
	morzeCodeLine[0]=1091;//1091,0,0,1,2,2,2
	morzeCodeLine[1]=0;
	morzeCodeLine[2]=0;
	morzeCodeLine[3]=1;
	morzeCodeLine[4]=2;
	morzeCodeLine[5]=2;
	morzeCodeLine[6]=2;
	morzeCodeArr.push_back(morzeCodeLine);

	//ф
	morzeCodeLine[0]=1092;//1092,0,0,1,0,2,2
	morzeCodeLine[1]=0;
	morzeCodeLine[2]=0;
	morzeCodeLine[3]=1;
	morzeCodeLine[4]=0;
	morzeCodeLine[5]=2;
	morzeCodeLine[6]=2;
	morzeCodeArr.push_back(morzeCodeLine);

	//х
	morzeCodeLine[0]=1093;//1093,0,0,0,0,2,2
	morzeCodeLine[1]=0;
	morzeCodeLine[2]=0;
	morzeCodeLine[3]=0;
	morzeCodeLine[4]=0;
	morzeCodeLine[5]=2;
	morzeCodeLine[6]=2;
	morzeCodeArr.push_back(morzeCodeLine);

	//ц
	morzeCodeLine[0]=1094;//1094,1,0,1,0,2,2
	morzeCodeLine[1]=1;
	morzeCodeLine[2]=0;
	morzeCodeLine[3]=1;
	morzeCodeLine[4]=0;
	morzeCodeLine[5]=2;
	morzeCodeLine[6]=2;
	morzeCodeArr.push_back(morzeCodeLine);

	//ч
	morzeCodeLine[0]=1095;//1095,1,1,1,0,2,2,
	morzeCodeLine[1]=1;
	morzeCodeLine[2]=1;
	morzeCodeLine[3]=1;
	morzeCodeLine[4]=0;
	morzeCodeLine[5]=2;
	morzeCodeLine[6]=2;
	morzeCodeArr.push_back(morzeCodeLine);

	//ш
	morzeCodeLine[0]=1096;//1096,1,1,1,1,2,2
	morzeCodeLine[1]=1;
	morzeCodeLine[2]=1;
	morzeCodeLine[3]=1;
	morzeCodeLine[4]=1;
	morzeCodeLine[5]=2;
	morzeCodeLine[6]=2;
	morzeCodeArr.push_back(morzeCodeLine);

	//щ
	morzeCodeLine[0]=1097;//1097,1,1,0,1,2,2
	morzeCodeLine[1]=1;
	morzeCodeLine[2]=1;
	morzeCodeLine[3]=0;
	morzeCodeLine[4]=1;
	morzeCodeLine[5]=2;
	morzeCodeLine[6]=2;
	morzeCodeArr.push_back(morzeCodeLine);

	//ъ
	morzeCodeLine[0]=1098;//1098,1,1,0,1,1,2
	morzeCodeLine[1]=1;
	morzeCodeLine[2]=1;
	morzeCodeLine[3]=0;
	morzeCodeLine[4]=1;
	morzeCodeLine[5]=1;
	morzeCodeLine[6]=2;
	morzeCodeArr.push_back(morzeCodeLine);

	//ы
	morzeCodeLine[0]=1099;//1099,1,0,1,1,2,2
	morzeCodeLine[1]=1;
	morzeCodeLine[2]=0;
	morzeCodeLine[3]=1;
	morzeCodeLine[4]=1;
	morzeCodeLine[5]=2;
	morzeCodeLine[6]=2;
	morzeCodeArr.push_back(morzeCodeLine);

	//ь
	morzeCodeLine[0]=1100;//1100,1,0,0,1,2,2
	morzeCodeLine[1]=1;
	morzeCodeLine[2]=0;
	morzeCodeLine[3]=0;
	morzeCodeLine[4]=1;
	morzeCodeLine[5]=2;
	morzeCodeLine[6]=2;
	morzeCodeArr.push_back(morzeCodeLine);

	//э
	morzeCodeLine[0]=1101;//1101,0,0,1,0,0,2
	morzeCodeLine[1]=0;
	morzeCodeLine[2]=0;
	morzeCodeLine[3]=1;
	morzeCodeLine[4]=0;
	morzeCodeLine[5]=0;
	morzeCodeLine[6]=2;
	morzeCodeArr.push_back(morzeCodeLine);

	//ю
	morzeCodeLine[0]=1102;//1102,0,0,1,1,2,2
	morzeCodeLine[1]=0;
	morzeCodeLine[2]=0;
	morzeCodeLine[3]=1;
	morzeCodeLine[4]=1;
	morzeCodeLine[5]=2;
	morzeCodeLine[6]=2;
	morzeCodeArr.push_back(morzeCodeLine);

	//я
	morzeCodeLine[0]=1103;//1103,0,1,0,1,2,2
	morzeCodeLine[1]=0;
	morzeCodeLine[2]=1;
	morzeCodeLine[3]=0;
	morzeCodeLine[4]=1;
	morzeCodeLine[5]=2;
	morzeCodeLine[6]=2;
	morzeCodeArr.push_back(morzeCodeLine);


	morzeCodeLine[0]=30;//30,1,1,1,1,1,2
	morzeCodeLine[1]=1;
	morzeCodeLine[2]=1;
	morzeCodeLine[3]=1;
	morzeCodeLine[4]=1;
	morzeCodeLine[5]=1;
	morzeCodeLine[6]=2;
	morzeCodeArr.push_back(morzeCodeLine);

	morzeCodeLine[0]=31;//31,0,0,1,1,1,2
	morzeCodeLine[1]=0;
	morzeCodeLine[2]=0;
	morzeCodeLine[3]=1;
	morzeCodeLine[4]=1;
	morzeCodeLine[5]=1;
	morzeCodeLine[6]=2;
	morzeCodeArr.push_back(morzeCodeLine);

	morzeCodeLine[0]=32;//32,0,0,0,1,1,2
	morzeCodeLine[1]=0;
	morzeCodeLine[2]=0;
	morzeCodeLine[3]=0;
	morzeCodeLine[4]=1;
	morzeCodeLine[5]=1;
	morzeCodeLine[6]=2;
	morzeCodeArr.push_back(morzeCodeLine);

	morzeCodeLine[0]=33;//33,0,0,0,0,1,2
	morzeCodeLine[1]=0;
	morzeCodeLine[2]=0;
	morzeCodeLine[3]=0;
	morzeCodeLine[4]=0;
	morzeCodeLine[5]=1;
	morzeCodeLine[6]=2;
	morzeCodeArr.push_back(morzeCodeLine);

	morzeCodeLine[0]=34;//34,0,0,0,0,0,2
	morzeCodeLine[1]=0;
	morzeCodeLine[2]=0;
	morzeCodeLine[3]=0;
	morzeCodeLine[4]=0;
	morzeCodeLine[5]=0;
	morzeCodeLine[6]=2;
	morzeCodeArr.push_back(morzeCodeLine);

	morzeCodeLine[0]=35;//35,1,0,0,0,0,2
	morzeCodeLine[1]=1;
	morzeCodeLine[2]=0;
	morzeCodeLine[3]=0;
	morzeCodeLine[4]=0;
	morzeCodeLine[5]=0;
	morzeCodeLine[6]=2;
	morzeCodeArr.push_back(morzeCodeLine);

	morzeCodeLine[0]=36;//36,1,1,0,0,0,2
	morzeCodeLine[1]=1;
	morzeCodeLine[2]=1;
	morzeCodeLine[3]=0;
	morzeCodeLine[4]=0;
	morzeCodeLine[5]=0;
	morzeCodeLine[6]=2;
	morzeCodeArr.push_back(morzeCodeLine);

	morzeCodeLine[0]=37;//37,1,1,1,0,0,2
	morzeCodeLine[1]=1;
	morzeCodeLine[2]=1;
	morzeCodeLine[3]=1;
	morzeCodeLine[4]=0;
	morzeCodeLine[5]=0;
	morzeCodeLine[6]=2;
	morzeCodeArr.push_back(morzeCodeLine);

	morzeCodeLine[0]=38;//38,1,1,1,1,0,2
	morzeCodeLine[1]=1;
	morzeCodeLine[2]=1;
	morzeCodeLine[3]=1;
	morzeCodeLine[4]=1;
	morzeCodeLine[5]=0;
	morzeCodeLine[6]=2;
	morzeCodeArr.push_back(morzeCodeLine);

	morzeCodeLine[0]=39;//39,0,0,0,0,1,2
	morzeCodeLine[1]=0;
	morzeCodeLine[2]=0;
	morzeCodeLine[3]=0;
	morzeCodeLine[4]=0;
	morzeCodeLine[5]=1;
	morzeCodeLine[6]=2;
	morzeCodeArr.push_back(morzeCodeLine);

}

int morzeCode::GetMorzeCharacter(int indexUtfCharacter, int MorzeCharacterPosition)
{
	return morzeCodeArr[indexUtfCharacter][MorzeCharacterPosition];
}

int morzeCode::GetUtfCode(int index)
{
	return morzeCodeArr[index][0];
}
