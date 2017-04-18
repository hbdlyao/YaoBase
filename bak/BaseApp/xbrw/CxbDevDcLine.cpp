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


void CxbDevDcLine::SetYm12re(double newVal){

	Ym12re = newVal;
}


double CxbDevDcLine::GetYm11re(){

	return Ym11re;
}


double CxbDevDcLine::GetYs11im(){

	return Ys11im;
}


void CxbDevDcLine::SetYm11re(double newVal){

	Ym11re = newVal;
}


void CxbDevDcLine::SetYs11im(double newVal){

	Ys11im = newVal;
}


double CxbDevDcLine::GetYs12im(){

	return Ys12im;
}


void CxbDevDcLine::SetYs12im(double newVal){

	Ys12im = newVal;
}


double CxbDevDcLine::GetYm11im(){

	return Ym11im;
}


double CxbDevDcLine::GetYs11re(){

	return Ys11re;
}


void CxbDevDcLine::SetYm11im(double newVal){

	Ym11im = newVal;
}


void CxbDevDcLine::SetYs11re(double newVal){

	Ys11re = newVal;
}


double CxbDevDcLine::GetYm12im(){

	return Ym12im;
}


double CxbDevDcLine::GetYs12re(){

	return Ys12re;
}


void CxbDevDcLine::SetYm12im(double newVal){

	Ym12im = newVal;
}


void CxbDevDcLine::SetYs12re(double newVal){

	Ys12re = newVal;
}


double CxbDevDcLine::GetYm12re(){

	return Ym12re;
}