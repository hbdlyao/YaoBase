///////////////////////////////////////////////////////////
//  CxbDev3pVSrc.cpp
//  Implementation of the Class CxbDev3pVSrc
//  Created on:      05-4��-2017 18:01:58
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbDev3pVSrc.h"



//����

/**
* 3P�ĵ�Ч�絼
*/
//double CxbDev3pVSrc::GetYg(){
//
//	return Yg;
//}


/**
* 3P�ĵ�Ч�絼
*/
//void CxbDev3pVSrc::SetYg(double newVal){
//
//	Yg = newVal;
//}


/**
* 3P�ĵ�Ч����
*/
//double CxbDev3pVSrc::GetYb(){
//
//	return Yb;
//}


/**
* 3P�ĵ�Ч����
*/
//void CxbDev3pVSrc::SetYb(double newVal){
//
//	Yb = newVal;
//}

//����

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
*3P�ĵ�ѹʵ��
*/
double CxbDev3pVSrc::GetUre(int vhOrder) {
	return Data->Voltage[vhOrder] * cos(Data->Phase[vhOrder]);
}
/*
*3P�ĵ�ѹ�鲿
*/
double CxbDev3pVSrc::GetUim(int vhOrder) {
	return Data->Voltage[vhOrder] * sin(Data->Phase[vhOrder]);
}

/*
*3P�ĵ���ʵ��
*/
double CxbDev3pVSrc::GetIre(int vhOrder, double vOmega) {
	return Data->Voltage[vhOrder] * sin(Data->Phase[vhOrder]) / (Data->Z_L*vOmega);
}
/*
*3P�ĵ����鲿
*/
double CxbDev3pVSrc::GetIim(int vhOrder, double vOmega) {
	return -Data->Voltage[vhOrder] * cos(Data->Phase[vhOrder]) / (Data->Z_L*vOmega);
}

/*
*3P�ĵ絼
*/
double CxbDev3pVSrc::GetYg(double vOmega)
{
	return 0;
}
/*
*3P�ĵ���
*/
double CxbDev3pVSrc::GetYb(double vOmega)
{
	return -1.0 / (Data->Z_L * vOmega);
}