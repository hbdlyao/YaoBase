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
	double Zr=0;
	/**
	* �п�
	*/
	double Zx_L=0;
	/**
	* �ݿ�
	*/
	double Zx_C=0;
	/**
	* ���
	*/
	double Z_L=0;
	/**
	* ����
	*/
	double Z_C=0;

};

struct struct_LineParam
{
	double Ys11re;
	double Ys11im;

	double Ys12re;
	double Ys12im;

	double Ym11re;
	double Ym11im;

	double Ym12re;
	double Ym12im;
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
