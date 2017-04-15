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
	virtual void Run();

protected:
	virtual void doPrepare();

	
	virtual void doNewCal(CDeviceBase * vDev, int vIndex);

	void doNewMcSolvers10();
	void doNewMcSolvers11();
	void doNewMcSolvers20();
	void doNewMcSolvers21();



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

};

class CmcSolvesNormal : public CmcSolves
{

public:
	virtual void Run(CmcProfile* vProfile);

protected:
	void doCalConvertor();
	void doCalTap();

};
