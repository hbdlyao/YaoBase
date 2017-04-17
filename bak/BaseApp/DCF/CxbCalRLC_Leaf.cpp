///////////////////////////////////////////////////////////
//  CxbCalRLC_Leaf.cpp
//  Implementation of the Class CxbCalRLC_Leaf
//  Created on:      17-4��-2017 14:31:19
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
	
	
	//����:����г�������õ���Ӧ��Yg,Yb ,pxbProfile->xbOrder ,pxbProfile->xbFreq
	
	int vhOrder = pxbProfile->xbHOrder;
	vYg = vDev->GetYg(vhOrder);
	vYb = vDev->GetYb(vhOrder);
	
	
	//�����0��ʼ
	if (jNode == -1) //�ӵ�
		pxbProfile->UpdateY0(iNode, vYg, vYb);
	else
		pxbProfile->UpdateY(iNode, jNode, vYg, vYb);

}