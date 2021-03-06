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
	virtual void InitOrder();


public:
	virtual void NodeID(int vGNDType);
	virtual void Run();

protected:
	virtual void doNewSolves(int vGNDType);

protected:
	int StaCount();


	//马骏鹏
	//形成各器件导纳参数
	void InitDevY();

	void doPrepare_U3p(string vCondition);
	void doPrepare_Line();
	void doPrepare_DCF();

	//
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

	//
	void doRun_DCF();


};
