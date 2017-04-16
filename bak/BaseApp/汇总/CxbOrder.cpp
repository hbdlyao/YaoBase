///////////////////////////////////////////////////////////
//  CxbOrder.cpp
//  Implementation of the Class CxbOrder
//  Created on:      05-4��-2017 18:22:10
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CxbOrder.h"
#include "gbHead_Def.h"


void CxbOrder::Init()
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
	PdSize = 1;//����ˮƽ��
}


/**
 * �Ϸ���������·��г���������* �Ķ�����:  CreateCaseID �Ķ���:    �޿��� �Ķ�����:  ���� �Ķ�����:  1.
 * ����Order�ﱣ��ĵ��������ɹ������� �Ķ�ʱ��:  2017/04/13
 */
string CxbOrder::CreateCaseID() {

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
	if (StaCount > 0)
	{	
		for (int i = 0; i < UacLevel.size(); i++)
			CaseID = CaseID + ((char)(UacLevel[i] + 1 + '0'));
	}//if
	//
	return CaseID;
}