///////////////////////////////////////////////////////////
//  CxbDev_Tree.h
//  Implementation of the Class CxbDev_Tree
//  Created on:      17-4ÔÂ-2017 17:24:53
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_78534360_4BFE_4d67_9727_29ED50B4B3BE__INCLUDED_)
#define EA_78534360_4BFE_4d67_9727_29ED50B4B3BE__INCLUDED_

#include "CxbDevBranch.h"

class CxbDev_Tree : public CxbDevBranch
{
public:
	virtual ~CxbDev_Tree();

	void Add(CDeviceBase * vItem) override;
	void Remove(CDeviceBase * vItem) override;

	virtual bool IsLeaf()override;

protected:
	pObjVector pChildren;

public:
	int ChildCount();
	CDeviceBase * Child(int vIndex);
	pObjVector  Children();

public:
	virtual void ClearNodeID() override;

	virtual void NodeSort(NodeMap & vNodeMap) override;
	virtual void NodeGround(NodeMap & vNodeMap) override;
	virtual void NodeID(NodeMap & vNodeID) override;



};
#endif // !defined(EA_78534360_4BFE_4d67_9727_29ED50B4B3BE__INCLUDED_)
