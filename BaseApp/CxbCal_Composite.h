#pragma once

#include "CxbCal_Leaf.h"


class CxbCal_Composite : public CxbCalculate
{

public:
	virtual ~CxbCal_Composite();
	virtual void Init(CPowerProfile* vProfile, CPowerGrid* vGrid) override;


public:
	virtual void Prepare()override;
	virtual void StationSort(StationMap& vStaMap)override;
	virtual void NodeSort(NodeMap& vNodeMap)override;
	virtual void NodeGround(NodeMap& vNodeMap)override;
	virtual void NodeID(NodeMap& vNodeID)override;
	virtual void Init(CDeviceBase* vDev)override;
	virtual void Add(CxbCalculate * vItem) override;
	virtual void Remove(CxbCalculate * vItem) override;

protected:
	virtual void UpdateY() override;
	virtual void UpdateI() override;

private:
	pPowerCalVector pChildren;

};
