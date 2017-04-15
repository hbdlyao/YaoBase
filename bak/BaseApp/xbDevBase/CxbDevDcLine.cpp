///////////////////////////////////////////////////////////
//  CxbDevDcLine.cpp
//  Implementation of the Class CxbDevDcLine
//  Created on:      05-4月-2017 17:00:36
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbDevDcLine.h"


void CxbDevDcLine::Init()
{
	SetDotCount(4);

	//马骏鹏
	Ys = new CComplex[4 * H_CAL_NUM]; //2x2
	Ym = new CComplex[4 * H_CAL_NUM]; //2x2

}


void CxbDevDcLine::MyFree()
{
	delete Ys;
	delete Ym;

	Ys = nullptr;
	Ym = nullptr;

}

//马骏鹏
void CxbDevDcLine::SetYs(int hOrder, CComplex *newVal) {
	if (hOrder >= H_CAL_NUM) {
		cout << "hOrder out of Range" << endl;
		return;
	}
	for (int i = 0; i < 4; i++)
		*(Ys + (hOrder - 1) * 4 + i) = *(newVal + i);
}
void CxbDevDcLine::SetYm(int hOrder, CComplex *newVal) {
	if (hOrder >= H_CAL_NUM) {
		cout << "hOrder out of Range" << endl;
		return;
	}
	for (int i = 0; i < 4; i++)
		*(Ym + (hOrder - 1) * 4 + i) = *(newVal + i);
}
/**
 * 返回Y阵
 */
CMatrix CxbDevDcLine::GetYMatrix(int hOrder) {
	CMatrix vY(4);
	if (hOrder >= H_CAL_NUM) {
		cout << "hOrder out of Range" << endl;
		return CMatrix(0);
	}
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
		{
			vY._mat[i][j] = *(Ys + (hOrder - 1) * 4 + i * 2 + j);
			vY._mat[i + 2][j] = *(Ym + (hOrder - 1) * 4 + i * 2 + j);
			vY._mat[i][j + 2] = *(Ym + (hOrder - 1) * 4 + i * 2 + j);
			vY._mat[i + 2][j + 2] = *(Ys + (hOrder - 1) * 4 + i * 2 + j);
		}
	return vY;
}
//返回Ys，Ym
CComplex* CxbDevDcLine::GetYs(int hOrder) {
	if (hOrder >= H_CAL_NUM) {
		cout << "hOrder out of Range" << endl;
		return 0;
	}
	return Ys + (hOrder - 1) * 4;
}
CComplex* CxbDevDcLine::GetYm(int hOrder) {
	if (hOrder >= H_CAL_NUM) {
		cout << "hOrder out of Range" << endl;
		return 0;
	}
	return Ym + (hOrder - 1) * 4;
}