///////////////////////////////////////////////////////////
//  CxbCal3pVSrc.cpp
//  Implementation of the Class CxbCal3pVSrc
//  Created on:      05-4��-2017 18:32:39
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbCal3pVSrc.h"
#include "CxbDev3pVSrc.h"

void CxbCal3pVSrc::Prepare()
{

}

void CxbCal3pVSrc::UpdateY()
{
	//����
	int iNode, jNode;
	double vYg, vYb;

	CxbDev3pVSrc * vDev;

	vDev = dynamic_cast<CxbDev3pVSrc *>(pDevice);

	iNode = vDev->GetNodeID(0);
	jNode = vDev->GetNodeID(1);

	//����:����г�������õ���Ӧ��Yg,Yb ,pxbProfile->xbOrder ,pxbProfile->xbFreq
	double vOmega = pxbProfile->Omega();
	vYg = vDev->GetYg(vOmega);
	vYb = vDev->GetYb(vOmega);


	//�����0��ʼ,Yao �迼�ǽӵ�
	pxbProfile->UpdateY(iNode, jNode, vYg, vYb);

}


void CxbCal3pVSrc::UpdateI()
{
	//����
	int iNode, jNode;
	int vStaIndex;
	double vIr, vIm;

	CxbDev3pVSrc * vDev;

	vDev = dynamic_cast<CxbDev3pVSrc *>(pDevice);

	vStaIndex = StationIndex;

	//����,yao
	//int vNode = pxbProfile->GetYdim() * pxbProfile->StationMap.find(vDev->GetStationName())->second;

	int vNode = pxbProfile->GetYdim() * vStaIndex;

	//to-do
	iNode = vNode + vDev->GetNodeID(0);
	jNode = vNode + vDev->GetNodeID(1);

	//����:����г�������õ���Ӧ��Yg,Yb ,pxbProfile->xbOrder ,pxbProfile->xbFreq
	int vhOrder = pxbProfile->xbHOrder;
	double vOmega = vOmega = pxbProfile->Omega();

	vIr = vDev->GetIre(vhOrder, vOmega); //
	vIm = vDev->GetIim(vhOrder, vOmega); //

	//vIr = vDev->GetYg(vOmega) * vDev->GetUre(vhOrder) - vDev->GetYb(vOmega) * vDev->GetUim(vhOrder);
	//vIm = vDev->GetYb(vOmega) * vDev->GetUre(vhOrder) + vDev->GetYg(vOmega) * vDev->GetUim(vhOrder);


	//�����0��ʼ
	pxbProfile->UpdateI(iNode, jNode, vIr, vIm);

}