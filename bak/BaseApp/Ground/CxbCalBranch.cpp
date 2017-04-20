///////////////////////////////////////////////////////////
//  CxbCalBranch.cpp
//  Implementation of the Class CxbCalBranch
//  Created on:      05-4月-2017 18:32:16
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbCalBranch.h"
#include "CxbDevBranch.h"


void CxbCalBranch::UpdateY()
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
	if ((iNode != -1) && (jNode != -1)) //接地
		pxbProfile->UpdateI(iNode, jNode, vYg, vYb);

	if (iNode == -1)
		pxbProfile->UpdateI0(jNode, vYg, vYb);

	if (jNode == -1)
		pxbProfile->UpdateI0(iNode, vYg, vYb);

}