#pragma once

#include "CMatrix.h"
#include "CPowerMath.h"


#include "CxbHvdcGrid.h"
#include "CxbResult.h"
#include "CxbOrder.h"

#include "CPowerProfile.h"


class CxbProfile : public CPowerProfile
{
public:
	//
	virtual ~CxbProfile();

	virtual void Init();
	virtual void Clear();

protected:
	virtual void doInit();
	virtual void doClear();
	
public:
	virtual void InitMatrix(int vN);

	void ReSetData();

protected:
	void doInitMatrix();
	void doInitData();

public:
	int Flag_DCFOver;

	/**
	 * 计算工况指令
	 */
	CxbOrder* pxbOrder;

	/**
	 * 谐波次数
	 */
	int xbHOrder=1;

	/**
	 * 系统频率
	 */
	double xbFreq=50;

	//马骏鹏
	CMatrix * Ymatrix;
	CMatrix * Ivect;
	CMatrix * Uvect;
	
public:

	
	double Omega();

	virtual void Solve();

	void UpdateYLine(int * pNode, CMatrix vY);

	virtual void UpdateI0(int iNode, double vIr, double vIm);

	virtual void UpdateI(int iNode, int jNode, double vIr, double vIm);


};

