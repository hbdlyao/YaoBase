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
	virtual ~CxbSolveMvc();

	virtual void Init();
	virtual void Init(CPowerGrid* vGrid);
	virtual void Clear();

public:
	virtual void NodeID(int vGNDType);
	virtual void Run();

protected:
	virtual void doNewSolves(int vGNDType);

protected:
	int StaCount();

	void doDCF();

	void selectU3P(string vCondition);

	void doInitRun();
	void doInitMatrix();

	
	virtual void doRecordResult();
	virtual void doRun();
	
	void doRun_Ground(string vFlag);
	void doRun_Rd(string vFlag);
	void doRun_Ud(string vFlag);
	void doRun_UdCustom();
	void doRun_Uac(string vFlag);
	void doRun_UacSwap(string vFlag, int vIndex, int vStaCount);
	void doRun_Pd();


};
