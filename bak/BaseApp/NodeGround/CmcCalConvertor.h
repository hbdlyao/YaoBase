#pragma once

#include "CmcCalTwoDot.h"
#include "CmcDevConvertor.h"

/**
 * ������
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
	 * ֱ���༰�Ƕ���֪��Ud��Id��alpha/gamma��
	 */
	virtual void CalConvertor_AC();
	/**
	 * �����༰�Ƕ���֪��Uv��alpha/gamma��Id��,IdΪ�������
	 */
	virtual void CalConvertor_Port();
	virtual void SaveNormal();

protected:
	int* MeasureNodeIndex;
	int StaionCtrlType;

public:
	int MeasureStationIndex;

};
