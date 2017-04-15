#pragma once

#include "CMatrix.h"
#include "CPowerMath.h"


#include "CxbHvdcGrid.h"
#include "CxbResult.h"
#include "CxbOrder.h"

#include "CPowerProfile.h"


class CxbProfile : public CPowerProfile
{
protected:
	virtual void doInit();
	virtual void doClear();

public:
	string Flag_Case="DFBFH22";

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
	int StationNum=1;
	NodeMap StationMap;

	CMatrix * Ymatrix;
	CMatrix * Ivect;
	CMatrix * Uvect;

public:
	
	
	virtual ~CxbProfile();

	double Omega();

	//
	virtual void Init();
	virtual void Clear();
	virtual void Release();

	virtual	void ClearData();
	virtual void InitMatrix(int vN);

	virtual void Solve();

	void UpdateYLine(int * pNode, CMatrix vY);

	virtual void UpdateI(int iNode, double vIr, double vIm);

	virtual void UpdateI(int iNode, int jNode, double vIr, double vIm);


};

