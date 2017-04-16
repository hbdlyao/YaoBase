#pragma once

#include "CmcHvdcGrid.h"
#include "CmcProfile.h"
#include "CmcSolves.h"
#include "CPowerSolveMvc.h"

class CmcSolveMvc : public CPowerSolveMvc
{

protected:
	CmcProfile* pmcProfile;
	CmcSolves* pmcSolves;
	CmcHvdcGrid * pmcHvdc;
	CmcResult* pmcResult;

public:
	virtual ~CmcSolveMvc();

	virtual void Init();
	virtual void Init(CPowerGrid* vGrid);
	virtual void Clear();

public:
	virtual void NodeID(int vGNDType);

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
	virtual void doRecordResult();

protected:

	virtual void doNewSolves(int vGNDType);
	virtual void doRun();

	void doInitRun();

	void doInitMatrix();


	void doRun_Ground(string vFlag);
	void doRun_Rd(string vFlag);
	void doRun_Ud(string vFlag);
	void doRun_UdCustom();
	void doRun_Uac(string vFlag);
	void doRun_UacSwap(string vFlag, int vIndex, int vStaCount);
	void doRun_Pd();
	virtual void doPrepareNormal();
	int StaCount();



};

class CmcSolveMvcNormal : public CmcSolveMvc
{

public:
	virtual void Init();
	/**
	 * 南方电网主回路及谐波计算软件* 改动对象:  Run 改动者:    崔康生 改动类型:  修改 改动内容:  1.
	 * 修改方法功能的定义：用于求解Order中所有工况 2.取消入参int vGNDType 改动时间:  2017/04/12
	 */
	virtual void Run();

	virtual void doRecordResult();

};
