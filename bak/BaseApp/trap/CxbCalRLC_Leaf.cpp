///////////////////////////////////////////////////////////
//  CxbCalRLC_Leaf.cpp
//  Implementation of the Class CxbCalRLC_Leaf
//  Created on:      17-4月-2017 14:31:19
///////////////////////////////////////////////////////////

#include "CxbCalRLC_Leaf.h"
#include "CxbDevBranch.h"


void CxbCalRLC_Leaf::Add(CxbCalRLC * vItem)
{
	//// cannot add to a leaf
}


void CxbCalRLC_Leaf::Remove(CxbCalRLC * vItem)
{

	//// cannot remove from a leaf

}


void CxbCalRLC_Leaf::UpdateY()
{

	int iNode, jNode;
	double vYg, vYb;
	
	
	CxbDevBranch * vDev;
	
	vDev = dynamic_cast<CxbDevBranch *>(pDevice);
	
	iNode = vDev->GetNodeID(0);
	jNode = vDev->GetNodeID(1);
	
	
	//马俊鹏:根据谐波次数得到对应的Yg,Yb ,pxbProfile->xbOrder ,pxbProfile->xbFreq
	
	int vhOrder = pxbProfile->xbHOrder;
	vYg = vDev->GetYg(vhOrder);
	vYb = vDev->GetYb(vhOrder);
	
	
	//数组从0开始
	if (jNode == -1) //接地
		pxbProfile->UpdateY0(iNode, vYg, vYb);
	else
		pxbProfile->UpdateY(iNode, jNode, vYg, vYb);

}