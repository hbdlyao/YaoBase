///////////////////////////////////////////////////////////
//  CxbCal_Tree.h
//  Implementation of the Class CxbCal_Tree
//  Created on:      21-4ÔÂ-2017 20:03:35
///////////////////////////////////////////////////////////

#if !defined(EA_2466365B_8DFB_4d3c_9C09_4309159ED776__INCLUDED_)
#define EA_2466365B_8DFB_4d3c_9C09_4309159ED776__INCLUDED_

#include "CxbCalculate.h"

class CxbCal_Tree : public CxbCalculate
{

protected:
	pxbCalVector pChildren;
	virtual CxbCalculate * doNewCal(CDeviceBase* vDev);

public:

	virtual ~CxbCal_Tree();
	virtual void Init(CPowerProfile* vProfile);
	virtual void Init(CDeviceBase* vDev) override;
	virtual void Add(CxbCalculate* vItem) override;
	void Clear() override;
	virtual void Remove(CxbCalculate* vItem) override;
	virtual bool IsLeaf() override;
	virtual void Prepare() override;
	int ChildCount();
	CxbCalculate * Child(int vIndex);
	pxbCalVector Children();
	void NodeID(NodeMap& vNodeID) override;
	void NodeSort(NodeMap& vNodeMap) override;
	void NodeGround(NodeMap& vNodeMap) override;
	void StationSort(StationMap& vStaMap) override;

public:
	virtual void UpdateY() override;
	virtual void UpdateI() override;
	virtual void NewCal_Tree(CDeviceBase* vDev);



};
#endif // !defined(EA_2466365B_8DFB_4d3c_9C09_4309159ED776__INCLUDED_)
