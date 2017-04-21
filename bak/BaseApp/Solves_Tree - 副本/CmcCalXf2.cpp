///////////////////////////////////////////////////////////
//  CmcCalXf2.cpp
//  Implementation of the Class CmcCalXf2
//  Created on:      02-4��-2017 14:41:57
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CmcCalXf2.h"
#include "CmcDevXf2.h"

//************************************
// *�Ϸ���������·��г���������*
// �Ķ�����:  Prepare
// �Ķ���:    �޿���
// �Ķ�����:  �޸�
// �Ķ�����:  1.�����������书��
// �Ķ�ʱ��:  2017/04/17
//************************************
void CmcCalXf2::Prepare()
{
	int vK = 0;
	CmcDevXf2 * vDev;

	vK = StationIndex;
	vDev = dynamic_cast<CmcDevXf2 *>(pDevice);

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
	pmcProfile->pmcStaData[vK].Nnom = vDev->GetTkN();
	pmcProfile->pmcStaData[vK].TC = vDev->GetTapN();
}


//************************************
// *�Ϸ���������·��г���������*
// �Ķ�����:  PrepareNormal
// �Ķ���:    �޿���
// �Ķ�����:  �޸�
// �Ķ�����:  1.�����������书��
// �Ķ�ʱ��:  2017/04/17
//************************************
void CmcCalXf2::PrepareNormal()
{
	int vK = 0;
	CmcDevXf2 * vDev;

	vK = StationIndex;
	vDev = dynamic_cast<CmcDevXf2 *>(pDevice);

	//�ֵ
	pmcProfile->pmcStaDataN[vK].AngCtrl_Max = vDev->GetAngleMax();
	pmcProfile->pmcStaDataN[vK].AngCtrl_Min = vDev->GetAngleMin();
	pmcProfile->pmcStaDataN[vK].Tap_Max = vDev->GetTapMax();
	pmcProfile->pmcStaDataN[vK].Tap_Min = vDev->GetTapMin();
	pmcProfile->pmcStaDataN[vK].TC = vDev->GetTapN();
	pmcProfile->pmcStaDataN[vK].deltaK = vDev->GetTapSetup();
	pmcProfile->pmcStaDataN[vK].Nnom = vDev->GetTkN();
	pmcProfile->pmcStaDataN[vK].dx = vDev->GetUkp() / 2.0;
	pmcProfile->pmcStaDataN[vK].dr = vDev->GetUrp();
	pmcProfile->pmcStaDataN[vK].Uv = vDev->GetUvN();
	pmcProfile->pmcStaDataN[vK].Uv_Max = 10000;

}
void CmcCalXf2::SaveNormal()
{
	int vK = 0;
	CmcDevXf2 * vDev;

	vDev = dynamic_cast<CmcDevXf2 *>(pDevice);
	vK = StationIndex;

	vDev->SetTapN(pmcProfile->pmcStaData[vK].TC);
	vDev->SetTkN(pmcProfile->pmcStaData[vK].Nnom);
	vDev->SetUvN(pmcProfile->pmcStaData[vK].Uv);
}

void CmcCalXf2::CalXf2_l()
{
	pmcProfile->UpdateXf2_l(StationIndex);
}
void CmcCalXf2::CalXf2_v()
{
	pmcProfile->UpdateXf2_v(StationIndex);
}
void CmcCalXf2::CalXf2_Port()
{
	pmcProfile->UpdateXf2_Port(StationIndex);
}
void CmcCalXf2::CalXf2_UpShift()
{
	pmcProfile->UpdateXf2_UpShift(StationIndex);
}
void CmcCalXf2::CalXf2_DownShift()
{
	pmcProfile->UpdateXf2_DownShift(StationIndex);
}



void CmcCalXf2::NodeSort(NodeMap& vNodeMap)
{
	//������ڵ���
}


void CmcCalXf2::NodeID(NodeMap& vNodeID)
{
	//������ڵ���
}

