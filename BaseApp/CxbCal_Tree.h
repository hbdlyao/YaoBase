///////////////////////////////////////////////////////////
//  CxbCal_Composite.h
//  Implementation of the Class CxbCal_Tree
//  Created on:      20-4ÔÂ-2017 22:17:30
///////////////////////////////////////////////////////////

#if !defined(EA_DE7A03AC_DB87_4702_BA5F_A66B317759E7__INCLUDED_)
#define EA_DE7A03AC_DB87_4702_BA5F_A66B317759E7__INCLUDED_

#include "CxbCalculate.h"

class CxbCal_Tree : public CxbCalculate
{

public:
	virtual ~CxbCal_Tree();
	virtual void Init(CPowerProfile* vProfile, CPowerGrid* vGrid) override;
	virtual void Init(CDeviceBase* vDev) override;
	virtual void Add(CxbCalculate* vItem) override;
	virtual void Remove(CxbCalculate* vItem) override;
	virtual bool IsLeaf() override;
	virtual void Prepare() override;
	virtual void StationSort(StationMap& vStaMap) override;
	virtual void NodeSort(NodeMap& vNodeMap) override;
	virtual void NodeGround(NodeMap& vNodeMap) override;
	virtual void NodeID(NodeMap& vNodeID) override;

protected:
	virtual void UpdateY() override;
	virtual void UpdateI() override;

private:
	pxbCalVector pChildren;

};
#endif // !defined(EA_DE7A03AC_DB87_4702_BA5F_A66B317759E7__INCLUDED_)
