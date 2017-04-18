///////////////////////////////////////////////////////////
//  CmcCalXf2.cpp
//  Implementation of the Class CmcCalXf2
//  Created on:      02-4��-2017 14:41:57
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CmcCalXf2.h"
#include "CmcDevXf2.h"

void CmcCalXf2::Prepare()
{
	int vK = 0;
	CmcDevXf2 * vDev;

	vK = StationIndex;
	vDev = dynamic_cast<CmcDevXf2 *>(pDevice);

	//�޿���
	//ʵ��ֵ
	//����
	pmcProfile->pmcStaData[vK].AngCtrl_Max = vDev->GetAngleMax();
	pmcProfile->pmcStaData[vK].AngCtrl_Min = vDev->GetAngleMin();
	pmcProfile->pmcStaData[vK].Uv = vDev->GetFixedURef()*vDev->GetUvN();
	pmcProfile->pmcStaData[vK].Tap_Max = vDev->GetTapMax();
	pmcProfile->pmcStaData[vK].Tap_Min = vDev->GetTapMin();
	pmcProfile->pmcStaData[vK].deltaK = vDev->GetTapSetup();
	pmcProfile->pmcStaData[vK].Uv_Max = vDev->GetUvMax()*vDev->GetUvN();
	pmcProfile->pmcStaData[vK].dx = vDev->GetUkp() / 2.0;
	pmcProfile->pmcStaData[vK].dr = vDev->GetUrp();

	pmcProfile->pmcStaData[vK].TC = vDev->GetTapN();

}


void CmcCalXf2::PrepareNormal() 
{
	int vK = 0;
	CmcDevXf2 * vDev;

	vK = StationIndex;
	vDev = dynamic_cast<CmcDevXf2 *>(pDevice);

	//�޿���
	//�ֵ
	pmcProfile->pmcStaDataN[vK].TC = vDev->GetTapN();

}

void CmcCalXf2::CalTap()
{

}

void CmcCalXf2::CalTapNormal()
{
	int vK = 0;
	double vX;

	CmcDevXf2 * vDev;

	//�޿���
	vK = StationIndex;

	vDev = dynamic_cast<CmcDevXf2 *>(pDevice);
		
	//TapN=0 ?
	pmcProfile->UpdateTapN(vK);

	vX = pmcProfile->pmcStaDataN[vK].TC;

	vDev->SetTapN(ceil(vX)); //ȡ��

}



void CmcCalXf2::NodeSort(NodeMap& vNodeMap)
{
	//������ڵ���
}


void CmcCalXf2::NodeID(NodeMap& vNodeID)
{
	//������ڵ���
}

