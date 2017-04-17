#pragma once

#include "CxbCalculate.h"
#include "CPowerSolves.h"
#include "CxbHvdcGrid.h"

class CxbSolves : public CPowerSolves
{
protected:
	int GroundType;

	CxbProfile* pxbProfile;
	CxbHvdcGrid * pxbHvdc;

public:
	virtual void Init(CPowerProfile* vProfile, CPowerGrid* vGrid);

	virtual string TypeToName(int vType);

	virtual void NewSolves(int vGndType);
	virtual void Run();

protected:
	virtual void doPrepare();

	virtual void doNewItem(int vtblType);
	virtual void doNewCal(CDeviceBase * vDev, int vIndex);


	void doNewXbSolvers10();
	void doNewXbSolvers11();
	void doNewXbSolvers20();
	void doNewXbSolvers21();


	//
	void doSovle();
	//
	void doSolveU();
	void doUpdateI();
	void doUpdateY();



};
