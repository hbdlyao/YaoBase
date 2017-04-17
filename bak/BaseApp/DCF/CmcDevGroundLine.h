#pragma once

#include "CmcDevShunt.h"

/**
 * ����· �ӵؼ�
 */
class CmcDevGroundLine : public CmcDevShunt
{

protected:	/**
	 * �������ֵ
	 */
	double ZrMax;
	/**
	 * �ӵ����ͣ��������/��������/˫����
	 */
	double ZrMin;


public:
	/**
	 * �������ֵ
	 */
	double GetZrMax();
	/**
	 * �ӵ����ͣ��������/��������/˫����
	 */
	double GetZrMin();
	/**
	 * �������ֵ
	 */
	void SetZrMax(double newVal);
	/**
	 * �ӵ����ͣ��������/��������/˫����
	 */
	void SetZrMin(double newVal);
};

