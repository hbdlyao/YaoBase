#pragma once

#include <string>
#include <stdlib.h>
#include <vector>
#include "CHvdcDefs.h"
using namespace std;
//************************************
// *�Ϸ���������·��г���������*
// �Ķ�����:  CmcOrder
// �Ķ���:    �޿���
// �Ķ�����:  �޸�
// �Ķ�����:  1.������������ݳ�Ա
//            2.
// �Ķ�ʱ��:  2017/04/12
//************************************
class CmcOrder
{
public:
	virtual ~CmcOrder();

	void Init();
	void InitNormal();

	void Clear();

public:
	int StaCount = 0;

	//"DFBFH22" : ˫��������˫����ȫѹ�����裬���ཻ����ѹΪ�


	//Ҫ�����ȫ����������������
	int nValNum = 1;   //������
	string Flag_Ground = "1111";  //�������/��������/˫��/˫������
	string Flag_Ud = "111";  //ȫѹ/80%/70%
	string Flag_Rd = "11";    //����/����
	string Flag_Uac = "1111";  //�/���/��С/��С
	bool IsUdCustom = false;//ֱ����ѹԤ���������Ԥ����ʹ��UdCustom��Ϊ��ѹָ�����ʹ��UdLevel
	bool IsUacSwap  = false;//�Ƿ�����ѹ����
	bool IsUdToGround = false;//ֱ����ѹ�Եػ��������
							  //string Flag_IsPdSingle = "0";//�Ƿ񵥹���ˮƽ���ó�Ա���Բ�Ҫ������ԱBdSizeȡֵΪ1ʱ��Ϊ������ˮƽ
	double PdStartPer = 10;//��ʼ����ˮƽ
	double PdIncrePer = 5;//����ˮƽ����
	int PdSize = 29;//����ˮƽ��

					//��ȫ��������ѡȡ��ĳһȷ������
					/**
					* �ӵ���ʽ���������/��������/˫��
					*/
	int GroundType;
	/**
	* ֱ����ѹ��ȫѹ/80%/70%
	*/
	int UdLevel;
	/**
	* ֱ����·������/����
	*/
	int RdLevel;
	/**
	* ��վ����ϵͳ��ѹ���/���/��С/��С
	*/
	vector<int> UacLevel;
	/**
	* ֱ����ѹԤ��ֵ
	*/
	double UdCustom;
	/**
	* ����ˮƽ
	*/
	double PdPer;

public:
	void UpdatePdPercent(int & vPdSize);
	int CaseCount();

	//************************************
	// *�Ϸ���������·��г���������*
	// �Ķ�����:  InitMatrix
	// �Ķ���:    �޿���
	// �Ķ�����:  ����
	// �Ķ�����:  1.���ڳ�ʼ��UacLevel
	// �Ķ�ʱ��:  2017/04/13
	//************************************
	void InitMatrix(int vStaDim);
	//************************************
	// *�Ϸ���������·��г���������*
	// �Ķ�����:  CreateCaseID
	// �Ķ���:    �޿���
	// �Ķ�����:  ����
	// �Ķ�����:  1.����Order�ﱣ��ĵ��������ɹ�������
	// �Ķ�ʱ��:  2017/04/13
	//************************************
	string CreateCaseID();
};