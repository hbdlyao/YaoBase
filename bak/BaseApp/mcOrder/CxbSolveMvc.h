#pragma once

#include "CxbHvdcGrid.h"
#include "CPowerSolveMvc.h"
#include "CxbSolves.h"

class CxbSolveMvc : public CPowerSolveMvc
{
protected:
	CxbProfile* pxbProfile;
	CxbSolves* pxbSolves;
	CxbHvdcGrid * pxbHvdc;

public:
	CxbHvdcGrid *pHvdc;
	virtual void Init();
	virtual void Init(CPowerGrid* vGrid);

	virtual void Run(int vGNDType);
	virtual void NodeID(int vGNDType);

protected:
	virtual void doNewSolves(int vGNDType);
	virtual void doDCF();
	virtual	void doRun();


};
