///////////////////////////////////////////////////////////
//  CxbDevDcLine.cpp
//  Implementation of the Class CxbDevDcLine
//  Created on:      05-4ÔÂ-2017 17:00:36
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbDevDcLine.h"


void CxbDevDcLine::Init()
{
	SetDotCount(4);

	//Âí¿¥Åô
	Ys = new CComplex[4 * H_CAL_NUM]; //2x2
	Ym = new CComplex[4 * H_CAL_NUM]; //2x2

}

//Âí¿¥Åô
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
 * ·µ»ØYÕó
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
//·µ»ØYs£¬Ym
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


/**
 * Âí¿¥Åô
 */
string CxbDevDcLine::GetStationName1(){

	return StationName1;
}


string CxbDevDcLine::GetStationName2(){

	return StationName2;
}


/**
 * Âí¿¥Åô
 */
void CxbDevDcLine::SetStationName1(string newVal){

	StationName1 = newVal;
}


void CxbDevDcLine::SetStationName2(string newVal){

	StationName2 = newVal;
}