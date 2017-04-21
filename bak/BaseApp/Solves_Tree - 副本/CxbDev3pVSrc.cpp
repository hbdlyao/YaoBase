///////////////////////////////////////////////////////////
//  CxbDev3pVSrc.cpp
//  Implementation of the Class CxbDev3pVSrc
//  Created on:      05-4月-2017 18:01:58
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbDev3pVSrc.h"

CxbDev3pVSrc::~CxbDev3pVSrc()
{
	//Clear();
}

void CxbDev3pVSrc::Clear()
{
	if (pU3pData.Urms !=nullptr)
		delete[] pU3pData.Urms;
	
	if (pU3pData.Angle != nullptr)
		delete[] pU3pData.Angle;

	if (pU3pData.Ire != nullptr)
		delete[] pU3pData.Ire;

	if (pU3pData.Iim != nullptr)
		delete[] pU3pData.Iim;

	if (pU3pData.Yb != nullptr)
		delete[] pU3pData.Yb;
}

void CxbDev3pVSrc::InitData()
{
	//
	pU3pData.Urms = new double[hMax()];
	pU3pData.Angle = new double[hMax()];

	//pU3pData.Ure = new double[hMax()];
	//pU3pData.Uim = new double[hMax()];

	pU3pData.Ire = new double[hMax()];
	pU3pData.Iim = new double[hMax()];

	pU3pData.Yb = new double[hMax()];

}

void CxbDev3pVSrc::Init() 
{
	SetDotCount(2);

	InitData();

}

void CxbDev3pVSrc::Prepare_hRLC()
{
	//Clear();

	//InitData();

	//
	for (int i = 0; i < hMax(); i++)
	{
		pU3pData.Ire[i] =  hUim(i)*Get_hYb(i);
		pU3pData.Iim[i] = -hUre(i)*Get_hYb(i);

		//pU3pData.Yb[i]  = -Get_hYL(i) / Omega();
	}

}

//马骏鹏
void CxbDev3pVSrc::PrepareData(string vCondition)
{
	//if (DataMap.count(vCondition))
	//	pU3pData = DataMap.find(vCondition)->second;
}

/*
*3P的电压实部
*/
double CxbDev3pVSrc::hUre(int vhOrder) 
{
	return  Get_hUrms(vhOrder) * cos(Get_hAngle(vhOrder));
}
/*
*3P的电压虚部
*/
double CxbDev3pVSrc::hUim(int vhOrder) 
{
	return  Get_hUrms(vhOrder) * sin(Get_hAngle(vhOrder));
}

/*
*3P的电流实部
*/
double CxbDev3pVSrc::hIre(int vhOrder)
{//
	return pU3pData.Ire[vhOrder];
}

/*
*3P的电流虚部
*/
double CxbDev3pVSrc::hIim(int vhOrder)
{
	return pU3pData.Iim[vhOrder];
}

double CxbDev3pVSrc::hYg(int vhOrder)
{
	return 0;
}

double CxbDev3pVSrc::hYb(int vhOrder)
{
	return pU3pData.Yb[vhOrder];
}

double CxbDev3pVSrc::Get_hUrms(int vhOrder)
{
	return pU3pData.Urms[vhOrder];
}

void CxbDev3pVSrc::Set_hUrms(int vhOrder, double vX)
{
	pU3pData.Urms[vhOrder] = vX;
}

double CxbDev3pVSrc::Get_hAngle(int vhOrder)
{
	return pU3pData.Angle[vhOrder];
}

void CxbDev3pVSrc::Set_hAngle(int vhOrder, double vX)
{
	pU3pData.Angle[vhOrder] = vX;
}

double CxbDev3pVSrc::Get_hYb(int vhOrder)
{
	return pU3pData.Yb[vhOrder];
}

void CxbDev3pVSrc::Set_hYb(int vhOrder, double vX)
{
	pU3pData.Yb[vhOrder] = vX;
}



