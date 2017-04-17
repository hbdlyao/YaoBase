#pragma once
#include "CxbCalRLC.h"

class CxbCalRLC_N : public CxbCalRLC
{
private:
	pVector_xbCalRLC pChildren;

public:
	virtual ~CxbCalRLC_N();
	void Clear();
	void Add(CxbCalRLC * vItem) override;
	void Remove(CxbCalRLC * vItem) override;

	virtual void Init(CPowerProfile* vProfile, CPowerGrid* vGrid) override;

public:
	virtual void Prepare();
	virtual void StationSort(StationMap& vStaMap);
	virtual void NodeSort(NodeMap& vNodeMap);
	virtual void NodeGround(NodeMap& vNodeMap);
	virtual void NodeID(NodeMap& vNodeID);


protected:
	void UpdateY() override;
	void UpdateI() override;

};
