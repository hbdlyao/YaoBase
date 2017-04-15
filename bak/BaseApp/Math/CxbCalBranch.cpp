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
	double vYg,vYb;
	

	CxbDevBranch * vDev;
	
	vDev = dynamic_cast<CxbDevBranch *>(pDevice);
	
	iNode = vDev->GetNodeID(0);
	jNode = vDev->GetNodeID(1);
	
		
	//马俊鹏:根据谐波次数得到对应的Yg,Yb ,pxbProfile->xbOrder ,pxbProfile->xbFreq
	double vOmega = pxbProfile->Omega();
		
	vYg = vDev->GetYg(vOmega);
	vYb = vDev->GetYb(vOmega);

	
	//数组从0开始
	if (jNode==-1) //接地
		pxbProfile->UpdateY0(iNode,vYg,vYb);
	else
		pxbProfile->UpdateY(iNode, jNode, vYg, vYb);
	
}