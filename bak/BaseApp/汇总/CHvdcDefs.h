#pragma once

#include <string>
#include <map>

using namespace std;

struct struct_BGXB
{
public:
	int hOrder;
	double hUrms;
	double hAngle;

};


struct struct_Branch
{

public:
	/**
	* ����
	*/
	double Zr;
	/**
	* �п�
	*/
	double Zx_L;
	/**
	* �ݿ�
	*/
	double Zx_C;
	/**
	* ���
	*/
	double Z_L;
	/**
	* ����
	*/
	double Z_C;

};

struct struct_LineMode
{

public:
	/**
	* ֱ�����߸߶�
	*/
	double CSXGD;
	/**
	* ֱ�����߼��
	*/
	double CSXSPJL;
	/**
	* �������봫���߼�߶�
	*/
	double BLXYCSXGDC;
	/**
	* ��·����
	*/
	double XLCD;
	/**
	* ������ˮƽ����
	*/
	double BLXSPJL;
	/**
	* �����߰뾶
	*/
	double CSXBJ;
	/**
	* �����߰뾶
	*/
	double BLXBJ;
	/**
	* �����ߵ絼��
	*/
	double CSXDDL;
	/**
	* �����ߵ�������
	*/
	double CSXDZLX;
	/**
	* �����ߵ�����
	*/
	double CSXDZL;
	/**
	* ������ֱ������
	*/
	double CSXZZDZ;
	/**
	* �����߻���
	*/
	double CSXHC;
	/**
	* �����߷�����
	*/
	double CSXFLS;
	/**
	* �����߷��Ѽ��
	*/
	double CSXFLJJ;
	/**
	* �����ߵ�������
	*/
	double BLXDZLX;
	/**
	* �����ߵ絼��
	*/
	double BLXDDL;
	/**
	* �����ߵ�����
	*/
	double BLXDZL;
	/**
	* ������ֱ������
	*/
	double BLXZZDZ;
	/**
	* �����߻���
	*/
	double BLXHC;
	/**
	* �����߷�����
	*/
	double BLXFLS;
	/**
	* �����߷��Ѽ��
	*/
	double BLXFLJJ;
	/**
	* ����������
	*/
	double TRDZL;

};
