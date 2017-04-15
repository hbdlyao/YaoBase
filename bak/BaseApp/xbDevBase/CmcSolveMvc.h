#pragma once

#include "CmcHvdcGrid.h"
#include "CPowerSolveMvc.h"
#include "CmcSolves.h"

class CmcSolveMvc : public CPowerSolveMvc
{
public:
	virtual void Init();
	virtual void Init(CPowerProfile * vProfile, CPowerGrid * vGrid);

	virtual void Run(int vGNDType);
	virtual void NodeID(int vGNDType);

protected:
	CmcProfile * pmcProfile;
	CmcHvdcGrid * pmcHvdc;
	CmcSolves * pmcSolves;

	virtual void doNewSolves(int vGNDType);
	virtual	void doRun();

};

class CmcSolvesMvcNormal : public CmcSolveMvc
{

public:
	virtual void Init();

};
