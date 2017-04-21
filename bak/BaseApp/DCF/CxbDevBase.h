#pragma once

#include "CDeviceBase.h"

class CxbDevBase : public CDeviceBase
{
public:
	virtual void InitData() ;

protected:	/**
	 * ������������  ������� �������� ˫��
	 */
	int PosOrNeg;

public:
	/**
	 * ������������  ������� �������� ˫��
	 */
	int GetPosOrNeg();
	/**
	 * ������������  ������� �������� ˫��
	 */
	void SetPosOrNeg(int newVal);
	virtual void Prepare_hRLC();
	/**
	 * ���г������
	 */
	int hMax();
	/**
	 * ����Ƶ��
	 */
	double FreqRef();
	double Omega();
	
};
