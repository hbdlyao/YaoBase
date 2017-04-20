#pragma once


#include "CmcDevOneDot.h"

/**
 * ����· ����ϵͳ
 */
class CmcDevAcSys : public CmcDevOneDot
{

public:
	/**
	 * ����ϵͳ�޹�����
	 */
	double GetQac();
	/**
	 * ����ϵͳ��޹�����
	 */
	double GetQacN();
	/**
	 * ����ϵͳ��������޹�
	 */
	double GetQinMax();
	/**
	 * ����ϵͳ��������޹�
	 */
	double GetQoutMax();
	/**
	 * �������ѹ
	 */
	double GetUac();
	/**
	 * ������ѹ��Сֵ
	 */
	double GetUacExMin();
	/**
	 * ������ѹ���ֵ
	 */
	double GetUacMax();
	/**
	 * ������ѹ��Сֵ
	 */
	double GetUacMin();
	/**
	 * ��������ѹ
	 */
	double GetUacN();
	/**
	 * ����ϵͳ�޹�����
	 */
	void SetQac(double newVal);
	/**
	 * ����ϵͳ��޹�����
	 */
	void SetQacN(double newVal);
	/**
	 * ����ϵͳ��������޹�
	 */
	void SetQinMax(double newVal);
	/**
	 * ����ϵͳ��������޹�
	 */
	void SetQoutMax(double newVal);
	/**
	 * �������ѹ
	 */
	void SetUac(double newVal);
	/**
	 * ������ѹ��Сֵ
	 */
	void SetUacExMin(double newVal);
	/**
	 * ������ѹ���ֵ
	 */
	void SetUacMax(double newVal);
	/**
	 * ������ѹ��Сֵ
	 */
	void SetUacMin(double newVal);
	/**
	 * ��������ѹ
	 */
	void SetUacN(double newVal);
	/**
	 * ����Ƶ��
	 */
	double GetFreq();
	/**
	 * ����Ƶ��
	 */
	void SetFreq(int newVal);

protected:
	/**
	 * ����ϵͳ�޹�����
	 */
	double Qac;
	/**
	 * ����ϵͳ��޹�����
	 */
	double QacN;
	/**
	 * ����ϵͳ��������޹�
	 */
	double QinMax;
	/**
	 * ����ϵͳ��������޹�
	 */
	double QoutMax;
	/**
	 * �������ߵ�ѹ
	 */
	double Uac;
	/**
	 * ������ѹ��Сֵ
	 */
	double UacExMin;
	/**
	 * ������ѹ���ֵ
	 */
	double UacMax;
	/**
	 * ������ѹ��Сֵ
	 */
	double UacMin;
	/**
	 * �������ߵ�ѹ
	 */
	double UacN;
	/**
	 * ����Ƶ��
	 */
	double Freq;

};
