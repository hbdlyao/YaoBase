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

//void CxbDev3pVSrc::PrepareData(string vCondition, string vPowPre)
//{
//	pxbU3PData_Map * vDataMap;
//	if (PowPreMap.count(vCondition))
//		vDataMap = PowPreMap.find(vCondition)->second;
//	if (vDataMap->count(vCondition))
//		Data = vDataMap->find(vCondition)->second;
//}
void CxbDev3pVSrc::PrepareData(string vCondition)
{
	if (DataMap.count(vCondition))
		Data = DataMap.find(vCondition)->second;
}
/*
*3P的电压实部
*/
double CxbDev3pVSrc::GetUre(int vhOrder) {
	return Data->Voltage[vhOrder] * cos(Data->Phase[vhOrder]);
}
/*
*3P的电压虚部
*/
double CxbDev3pVSrc::GetUim(int vhOrder) {
	return Data->Voltage[vhOrder] * sin(Data->Phase[vhOrder]);
}

/*
*3P的电流实部
*/
double CxbDev3pVSrc::GetIre(int vhOrder, double vOmega) {
	return Data->Voltage[vhOrder] * sin(Data->Phase[vhOrder]) / (Data->Z_L*vOmega);
}
/*
*3P的电流虚部
*/
double CxbDev3pVSrc::GetIim(int vhOrder, double vOmega) {
	return -Data->Voltage[vhOrder] * cos(Data->Phase[vhOrder]) / (Data->Z_L*vOmega);
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
	return -1.0 / (Data->Z_L * vOmega);
}