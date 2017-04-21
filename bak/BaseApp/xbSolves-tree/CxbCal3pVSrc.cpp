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

	int vhOrder = pxbProfile->xbHOrder;

	vYg = vDev->hYg(vhOrder);
	vYb = vDev->hYb(vhOrder);

	//数组从0开始
	if ((iNode != -1) && (jNode != -1)) //接地
		pxbProfile->UpdateY(iNode, jNode, vYg, vYb);

	if (iNode == -1)
		pxbProfile->UpdateY0(jNode, vYg, vYb);

	if (jNode == -1)
		pxbProfile->UpdateY0(iNode, vYg, vYb);

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

	int vNode = pxbProfile->GetYdim() * vStaIndex;

	//to-do:和接地混淆
	iNode = vNode + vDev->GetNodeID(0);
	jNode = vNode + vDev->GetNodeID(1);

	int vhOrder = pxbProfile->xbHOrder;	
	vIr = vDev->hIre(vhOrder); //
	vIm = vDev->hIim(vhOrder); //

	
	//数组从0开始
	if ((iNode != -1) && (jNode != -1)) //接地
		pxbProfile->UpdateI(iNode, jNode, vIr, vIm);

	if (iNode == -1)
		pxbProfile->UpdateI0(jNode, vIr, vIm);

	if (jNode == -1)
		pxbProfile->UpdateI0(iNode, vIr, vIm);

}