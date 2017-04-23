#pragma once


#include "CmcCalculate.h"
#include "CPowerSolves.h"
#include "CmcHvdcGrid.h"

class CmcSolves : public CPowerSolves
{

public:
	CmcProfile * pmcProfile;
	CmcHvdcGrid * pmcHvdc;

	virtual string TypeToName(int vType);

	virtual void Init(CPowerProfile * vProfile, CPowerGrid * vGrid);

public:
	virtual void NewSolves(int vGndType);

protected:
	virtual void doNewCal(CDeviceBase * vDev, int vIndex);

	void doNewMcSolvers10();
	void doNewMcSolvers11();
	void doNewMcSolvers20();
	void doNewMcSolvers21();


public:
	virtual void Run();
	virtual void PrepareNormal();
	void RecordMeasureNode();
protected://++--
	double doGetMaxdX();
	//************************************
	// *南方电网主回路及谐波计算软件*
	// 改动对象:  doOffsetSort
	// 改动者:    崔康生
	// 改动类型:  新增
	// 改动内容:  1.调用各个Cal对Offset编号
	// 改动时间:  2017/04/20
	//************************************
	void doOffsetSort();
	void doSaveX();

	virtual void doPrepare();


	void doInit_XVect();
	void doSovleDcNet();
	void doSolve_dX();

	void doUpdateF_Y();
	void doUpdateF_J();


	void doUpdateJ();
	void doUpdateY();
	void doUpdateX();
	void doCalConvertor();
	void doCalTap();


	void doCalStation();

	void doUpdateUdio();//++--
	void doLimitUd();//++--
};


class CmcSolvesNormal : public CmcSolves
{

public:
	virtual void Run();

	void doSaveNorml();
protected:

	void doCalStation();
};
