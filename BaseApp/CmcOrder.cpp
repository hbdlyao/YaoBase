///////////////////////////////////////////////////////////
//  CmcOrder.cpp
//  Implementation of the Class CmcOrder
//  Created on:      03-4��-2017 18:55:02
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CmcOrder.h"
#include "CmcDefs.h"


CmcOrder::~CmcOrder()
{
	Clear();
}

void CmcOrder::Init()
{
	StaCount = 0;

	//
	nValNum = 2;

	Flag_Ground = "1111";  //�������/��������/˫��/˫������
	Flag_Ud = "111";  //ȫѹ/80%/70%
	Flag_Rd = "11";    //����/����
	Flag_Uac = "1111";  //���/�/��С/��С
	
	IsUdCustom = false;//ֱ����ѹԤ���������Ԥ����ʹ��UdCustom��Ϊ��ѹָ�����ʹ��UdLevel
	IsUacSwap = true;// �Ƿ�����ѹ����
	IsUdToGround = false;//ֱ����ѹ�Եػ��������
					 //string Flag_IsPdSingle = "0";//�Ƿ񵥹���ˮƽ���ó�Ա���Բ�Ҫ������ԱBdSizeȡֵΪ1ʱ��Ϊ������ˮƽ
	PdStartPer = 10;//��ʼ����ˮƽ
	PdIncrePer = 5;//����ˮƽ����
	PdSize = 2;//����ˮƽ��

}

void CmcOrder::InitNormal()
{
	StaCount = 0;

	//
	nValNum = 2;

	Flag_Ground = "0010";  //�������/��������/˫��/˫������
	Flag_Ud = "100";  //ȫѹ/80%/70%
	Flag_Rd = "10";    //����/����
	Flag_Uac = "0100";  //���/�/��С/��С

	IsUdCustom = false;//ֱ����ѹԤ���������Ԥ����ʹ��UdCustom��Ϊ��ѹָ�����ʹ��UdLevel
	IsUacSwap = false;// �Ƿ�����ѹ����
	IsUdToGround = false;//ֱ����ѹ�Եػ��������
						 //string Flag_IsPdSingle = "0";//�Ƿ񵥹���ˮƽ���ó�Ա���Բ�Ҫ������ԱBdSizeȡֵΪ1ʱ��Ϊ������ˮƽ
	PdStartPer = 100;//��ʼ����ˮƽ
	PdIncrePer = 0;//����ˮƽ����
	PdSize = 1;//����ˮƽ��

}

void CmcOrder::Clear()
{
	UacLevel = vector<int>(0);
}


void CmcOrder::UpdatePdPercent(int & vPdSize)
{
	PdPer = PdStartPer + PdIncrePer*vPdSize;

}


int CmcOrder::CaseCount()
{
	int vCountGroundType = 0;
	int vCountUd = 0;
	int vCountRd = 0;
	int vCountUac = 0;

	for each (char flag in Flag_Ground)
		if (flag == '1')
			vCountGroundType++;

	for each (char flag in Flag_Ud)
		if (flag == '1')
			vCountUd++;

	if (IsUdCustom)
		vCountUd = 1;

	for each (char flag in Flag_Rd)
		if (flag == '1')
			vCountRd++;

	for each (char flag in Flag_Uac)
		if (flag == '1')
			vCountUac++;

	if (IsUacSwap)
		vCountUac = pow(vCountUac,StaCount );

	//
	int vN = vCountGroundType*vCountUd*vCountRd*vCountUac;

	return vN;

}


/**
 * �Ϸ���������·��г���������* �Ķ�����:  InitMatrix �Ķ���:    �޿��� �Ķ�����:  ���� �Ķ�����:  1.���ڳ�ʼ��UacLevel
 * �Ķ�ʱ��:  2017/04/13
 */
void CmcOrder::InitMatrix(int vStaCount)
{
	StaCount = vStaCount;

	UacLevel = vector<int>(vStaCount);
}

/**
 * �Ϸ���������·��г���������* �Ķ�����:  CreateCaseID �Ķ���:    �޿��� �Ķ�����:  ���� �Ķ�����:  1.
 * ����Order�ﱣ��ĵ��������ɹ������� �Ķ�ʱ��:  2017/04/13
 */
string CmcOrder::CreateCaseID()
{
	//char buff[1];

	string CaseID = "";
	
	//������:
	switch (nValNum)
	{
	case 1:
		CaseID.append("S");
		break;
	case 2:
		CaseID.append("D");
		break;
	}

	//�ӵ�:������أ�����������˫����˫������
	switch (GroundType)
	{
	case mc_Ground20:
		CaseID.append("B");
		break;
	case mc_Ground11:
		CaseID.append("M");
		break;
	case mc_Ground10:
		CaseID.append("G");
		break;
	case mc_Ground21:
		CaseID.append("P");
		break;
	default:
		break;
	}

	//Ud:ȫѹ,80%,70%
	switch (UdLevel)
	{
	case Ud_Full:
		CaseID.append("F");
		break;
	case Ud_Per80:
		CaseID.append("R");
		break;
	case Ud_Per70:
		CaseID.append("S");
		break;

	case Ud_Custom:
		CaseID.append("C");
		break;

	default:
		break;
	}

	//Rd:���衢����
	switch (RdLevel)
	{
	case Rd_High:
		CaseID.append("H");
		break;
	case Rd_Low:
		CaseID.append("L");
		break;
	default:
		break;
	}

	//����Uac
	for (int i = 0; i < UacLevel.size(); i++)
		CaseID = CaseID + ((char)(UacLevel[i] + 1 + '0'));

	//
	return CaseID;
}

