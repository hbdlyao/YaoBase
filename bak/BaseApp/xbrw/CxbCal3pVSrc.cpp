///////////////////////////////////////////////////////////
//  CxbCal3pVSrc.cpp
//  Implementation of the Class CxbCal3pVSrc
//  Created on:      05-4月-2017 18:32:39
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbCal3pVSrc.h"
#include "CxbDev3pVSrc.h"

void CxbCal3pVSrc::Prepare()
{
	//CxbDev3pVSrc * vDev;

	//vDev = dynamic_cast<CxbDev3pVSrc *>(pDevice);

}

void CxbCal3pVSrc::UpdateY()
{
	//马俊鹏
	int iNode, jNode;
	double vYg, vYb;

	CxbDev3pVSrc * vDev;

	vDev = dynamic_cast<CxbDev3pVSrc *>(pDevice);

	iNode = vDev->GetNodeID(0);
	jNode = vDev->GetNodeID(1);

	//马俊鹏:根据谐波次数得到对应的Yg,Yb ,pxbProfile->xbOrder ,pxbProfile->xbFreq
	double vOmega = pxbProfile->Omega();
	vYg = vDev->GetYg(vOmega);
	vYb = vDev->GetYb(vOmega);


	//数组从0开始,Yao 需考虑接地
	pxbProfile->UpdateY(iNode, jNode, vYg, vYb);

}


void CxbCal3pVSrc::UpdateI()
{
	//马俊鹏
	int iNode, jNode;
	int vStaIndex;
	double vIr, vIm;

	CxbDev3pVSrc * vDev;

	vDev = dynamic_cast<CxbDev3pVSrc *>(pDevice);

	vStaIndex = StationIndex;

	//马骏鹏,yao
	//int vNode = pxbProfile->GetYdim() * pxbProfile->StationMap.find(vDev->GetStationName())->second;

	int vNode = pxbProfile->GetYdim() * vStaIndex;

	//to-do
	iNode = vNode + vDev->GetNodeID(0);
	jNode = vNode + vDev->GetNodeID(1);

	//马俊鹏:根据谐波次数得到对应的Yg,Yb ,pxbProfile->xbOrder ,pxbProfile->xbFreq
	int vhOrder = pxbProfile->xbHOrder;
	double vOmega = vOmega = pxbProfile->Omega();

	vIr = vDev->GetIre(vhOrder, vOmega); //
	vIm = vDev->GetIim(vhOrder, vOmega); //

	//vIr = vDev->GetYg(vOmega) * vDev->GetUre(vhOrder) - vDev->GetYb(vOmega) * vDev->GetUim(vhOrder);
	//vIm = vDev->GetYb(vOmega) * vDev->GetUre(vhOrder) + vDev->GetYg(vOmega) * vDev->GetUim(vhOrder);


	//数组从0开始
	pxbProfile->UpdateI(iNode, jNode, vIr, vIm);

}