///////////////////////////////////////////////////////////
//  CDevBase_Tree.h
//  Implementation of the Class CDevBase_Tree
//  Created on:      21-4ÔÂ-2017 19:40:47
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_67DDBE4D_0C79_4875_BABA_E91623C21F32__INCLUDED_)
#define EA_67DDBE4D_0C79_4875_BABA_E91623C21F32__INCLUDED_

#include "CDeviceBase.h"
#include "CxbDevBranch.h"

class CDevBase_Tree : public CDeviceBase
{

public:
	virtual ~CDevBase_Tree();
	void Add(CDeviceBase* vItem) override;
	void Remove(CDeviceBase* vItem) override;
	virtual bool IsLeaf() override;
	int ChildCount();
	CDeviceBase * Child(int vIndex);
	pObjVector Children();
	virtual void ClearNodeID() override;
	virtual void NodeSort(NodeMap& vNodeMap) override;
	virtual void NodeGround(NodeMap& vNodeMap) override;
	virtual void NodeID(NodeMap& vNodeID) override;

protected:
	pObjVector pChildren;

};
#endif // !defined(EA_67DDBE4D_0C79_4875_BABA_E91623C21F32__INCLUDED_)
