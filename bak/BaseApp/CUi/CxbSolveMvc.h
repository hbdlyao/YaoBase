#pragma once

#include "CxbHvdcGrid.h"
#include "CxbSolves.h"

#include "CxbSolves.h"

class CxbSolveMvc 
{

protected:
	CxbProfile* pxbProfile;
	CxbSolves * pxbSolves;
	
	CxbHvdcGrid * pxbHvdc;

	CxbResult* pxbResult;

public:
	virtual ~CxbSolveMvc();

	virtual void Init();
	virtual void Init(CxbHvdcGrid* vGrid);
	virtual void Clear();
	virtual void InitOrder();


public:
	virtual void Test(int vGNDType);
	virtual void Run();
protected:
	void doNodeID() ;
	void doStationSort() ;

	virtual void doNewSolves(int vGNDType);

protected:
	int StaCount();
	double hMax();
	double Frequence();


	void doPrepare_U3p(string vCondition);
	void doPrepare_hRLC();

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
