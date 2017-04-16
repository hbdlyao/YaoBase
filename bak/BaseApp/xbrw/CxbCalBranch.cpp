///////////////////////////////////////////////////////////
//  CxbCalBranch.cpp
//  Implementation of the Class CxbCalBranch
//  Created on:      05-4��-2017 18:32:16
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