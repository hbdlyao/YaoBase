///////////////////////////////////////////////////////////
//  CxbDev3pVSrc.cpp
//  Implementation of the Class CxbDev3pVSrc
//  Created on:      05-4月-2017 18:01:58
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbDev3pVSrc.h"



//马骏鹏

/**
* 3P的等效电导
*/
//double CxbDev3pVSrc::GetYg(){
//
//	return Yg;
//}


/**
* 3P的等效电导
*/
//void CxbDev3pVSrc::SetYg(double newVal){
//
//	Yg = newVal;
//}


/**
* 3P的等效电纳
*/
//double CxbDev3pVSrc::GetYb(){
//
//	return Yb;
//}


/**
* 3P的等效电纳
*/
//void CxbDev3pVSrc::SetYb(double newVal){
//
//	Yb = newVal;
//}

//马骏鹏
/**
 * 马骏鹏
 */
void CxbDev3pVSrc::SetL(double newVal) {
	L = newVal;
}
/*
*3P的电压实部
*/
double CxbDev3pVSrc::GetUre(int vhOrder) {
	return UhVect[vhOrder] * cos(PhhVect[vhOrder]);
}
/*
*3P的电压虚部
*/
double CxbDev3pVSrc::GetUim(int vhOrder) {
	return UhVect[vhOrder] * sin(PhhVect[vhOrder]);
}
/*
*3P的电导
*/
double CxbDev3pVSrc::GetYg(double vOmega) 
{
	return 0;
}
/*
*3P的电纳
*/
double CxbDev3pVSrc::GetYb(double vOmega) 
{
	return -1.0 /( L * vOmega);
}