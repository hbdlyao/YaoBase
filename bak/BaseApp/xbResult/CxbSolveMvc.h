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
	CxbResult* pxbResult;

public:
	~CxbSolveMvc();

	virtual void Init();
	virtual void Init(CPowerGrid* vGrid);
	virtual void Clear();
	virtual void Release();

public:
	virtual void Run(int vGNDType);
	virtual void NodeID(int vGNDType);

protected:
	virtual void doNewSolves(int vGNDType);

	virtual	void doRun();

protected:
	void doDCF();


};
