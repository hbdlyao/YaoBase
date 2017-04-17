///////////////////////////////////////////////////////////
//  CxbDevDcLine.cpp
//  Implementation of the Class CxbDevDcLine
//  Created on:      05-4��-2017 17:00:36
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbDevDcLine.h"


void CxbDevDcLine::Init()
{
	SetDotCount(4);

	//������
	Ys = new CComplex[4 * H_CAL_NUM]; //2x2
	Ym = new CComplex[4 * H_CAL_NUM]; //2x2

}

//������
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
 * ����Y��
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
//����Ys��Ym
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
 * ������
 */
string CxbDevDcLine::GetStationName1(){

	return StationName1;
}


string CxbDevDcLine::GetStationName2(){

	return StationName2;
}


/**
 * ������
 */
void CxbDevDcLine::SetStationName1(string newVal){

	StationName1 = newVal;
}


void CxbDevDcLine::SetStationName2(string newVal){

	StationName2 = newVal;
}


double CxbDevDcLine::GetYs11(){

	return Ys11;
}


void CxbDevDcLine::SetYs11(double newVal){

	Ys11 = newVal;
}


double CxbDevDcLine::GetYs12(){

	return Ys12;
}


void CxbDevDcLine::SetYs12(double newVal){

	Ys12 = newVal;
}


double CxbDevDcLine::GetYm11(){

	return Ym11;
}


void CxbDevDcLine::SetYm11(double newVal){

	Ym11 = newVal;
}


double CxbDevDcLine::GetYm12(){

	return Ym12;
}


void CxbDevDcLine::SetYm12(double newVal){

	Ym12 = newVal;
}