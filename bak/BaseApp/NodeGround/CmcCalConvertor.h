#pragma once

#include "CmcCalTwoDot.h"
#include "CmcDevConvertor.h"

/**
 * 换流器
 */
class CmcCalConvertor : public CmcCalTwoDot
{

public:
	CmcCalConvertor();
	virtual ~CmcCalConvertor();
	int GetStaionCtrlType();
	void SetStaionCtrlType(int newVal);
	int GetNodeID(int vIndex);
	virtual void NodeGround(NodeMap& vNodeMap);
	virtual void StationSort(StationMap& vStaMap);
	void RecordMeasureNode(CmcCalConvertor& vCalConvertor);
	virtual bool IsFixed_I();
	virtual void Prepare();
	virtual void PrepareNormal();
	void InitX();
	virtual void UpdateJ();
	virtual void UpdateF_J();
	virtual void CalConvertor_DC();
	/**
	 * 直流侧及角度已知（Ud、Id、alpha/gamma）
	 */
	virtual void CalConvertor_AC();
	/**
	 * 交流侧及角度已知（Uv、alpha/gamma、Id）,Id为补充变量
	 */
	virtual void CalConvertor_Port();
	virtual void SaveNormal();

protected:
	int* MeasureNodeIndex;
	int StaionCtrlType;

public:
	int MeasureStationIndex;

};
