#pragma once

#include "CmcHvdcGrid.h"
#include "CmcProfile.h"
#include "CmcSolves.h"
#include "CPowerSolveMvc.h"

class CmcSolveMvc : public CPowerSolveMvc
{
public:
	//************************************
	// *南方电网主回路及谐波计算软件*
	// 改动对象:  Run
	// 改动者:    崔康生
	// 改动类型:  修改
	// 改动内容:  1.修改方法功能的定义：用于求解Order中所有工况
	//            2.取消入参int vGNDType
	// 改动时间:  2017/04/12
	//************************************
	virtual void Run();

protected:

	//************************************
	// *南方电网主回路及谐波计算软件*
	// 改动对象:  RecordResult
	// 改动者:    崔康生
	// 改动类型:  新增
	// 改动内容:  1.在一次单功率水平计算结束后将结果保存在Result里
	// 改动时间:  2017/04/13
	//************************************
	virtual void RecordResult();

protected:
	CmcProfile* pmcProfile;
	CmcHvdcGrid* pmcHvdc;
	CmcSolves* pmcSolves;

	virtual void doNewSolves(int vGNDType);

	void doInitRun();
	virtual void doRun();

	void doRun_Ground(string vFlag);
	void doRun_Rd(string vFlag);
	void doRun_Ud(string vFlag);
	void doRun_UdCustom();
	void doRun_Uac(string vFlag);
	void doRun_UacSwap(string vFlag, int vIndex, int vStaCount);
	void doRun_Pd();


public:
	CmcResult* pmcResult;
	virtual void Init();
	virtual void Init(CPowerGrid* vGrid);
	virtual void NodeID(int vGNDType);

public:
	~CmcSolveMvc() ;

	virtual void Clear();
	virtual void Release();

};

class CmcSolvesMvcNormal : public CmcSolveMvc
{

public:
	virtual void Init();

};
