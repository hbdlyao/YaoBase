#pragma once


#include "CDeviceBase.h"

class CmcDevBase : public CDeviceBase
{
protected:
	/**
	 * ������������
	 * 
	 * �������
	 * ��������
	 * ˫��
	 */
	string tpFlag;



public:
	/**
	 * ������������
	 * 
	 * �������
	 * ��������
	 * ˫��
	 */
	string GettpFlag();
	/**
	 * ������������
	 * 
	 * �������
	 * ��������
	 * ˫��
	 */
	void SettpFlag(string newVal);
};
