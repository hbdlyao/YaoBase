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

protected:
	virtual void doNewCal(CDeviceBase * vDev, int vIndex);

	void doNewMcSolvers10();
	void doNewMcSolvers11();
	void doNewMcSolvers20();
	void doNewMcSolvers21();


public:	
	virtual void Run();
	virtual void PrepareNormal();
	int StaCount();
	void StationSort() override;
	//************************************
	// *南方电网主回路及谐波计算软件*
	// 改动对象:  RecordMeasureNode
	// 改动者:    重要：崔康生
	// 改动类型:  新增
	// 改动内容:  1.记录各站测量点的节点编号
	// 改动时间:  2017/04/17
	//************************************
	void RecordMeasureNode();
	//************************************
	// *南方电网主回路及谐波计算软件*
	// 改动对象:  doGetMaxdX
	// 改动者:    重要：崔康生
	// 改动类型:  新增
	// 改动内容:  1.调用CmcProfile->GetMaxdX()
	// 改动时间:  2017/04/18
	//************************************
	double doGetMaxdX();

protected:
	virtual void doPrepare();


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


	//************************************
	// *南方电网主回路及谐波计算软件*
	// 改动对象:  doCalConvertor和doCalTap
	// 改动者:    崔康生
	// 改动类型:  删除
	// 改动内容:  1.调节分接头按照端进行
	// 改动时间:  2017/04/18
	//************************************
	//void doCalConvertor();
	//void doCalTap();
	//************************************
	// *南方电网主回路及谐波计算软件*
	// 改动对象:  doCalStation
	// 改动者:    崔康生
	// 改动类型:  新增
	// 改动内容:  1.调节分接头按照端进行
	// 改动时间:  2017/04/18
	//************************************
	void doCalStation();

};


class CmcSolvesNormal : public CmcSolves
{

public:
	//************************************
	// *南方电网主回路及谐波计算软件*
	// 改动对象:  Run
	// 改动者:    崔康生
	// 改动类型:  修改
	// 改动内容:  1.取消参数CmcProfile* vProfile
	//            2.
	// 改动时间:  2017/04/18
	//************************************
	virtual void Run();

	//************************************
	// *南方电网主回路及谐波计算软件*
	// 改动对象:  doSaveNorml
	// 改动者:    崔康生
	// 改动类型:  新增
	// 改动内容:  1.将计算结果记录在各个Device里
	// 改动时间:  2017/04/18
	//************************************
	void doSaveNorml();
protected:

	//************************************
	// *南方电网主回路及谐波计算软件*
	// 改动对象:  doCalConvertor和doCalTap
	// 改动者:    崔康生
	// 改动类型:  删除
	// 改动内容:  1.调节分接头按照端进行
	// 改动时间:  2017/04/18
	//************************************
	//void doCalConvertor();
	//void doCalTap();
	//************************************
	// *南方电网主回路及谐波计算软件*
	// 改动对象:  doCalStation
	// 改动者:    崔康生
	// 改动类型:  新增
	// 改动内容:  1.调节分接头按照端进行
	// 改动时间:  2017/04/18
	//************************************
	void doCalStation();
};
