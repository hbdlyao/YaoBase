///////////////////////////////////////////////////////////
//  CPowerCal_Tree.h
//  Implementation of the Class CPowerCal_Tree
//  Created on:      21-4ÔÂ-2017 18:10:14
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_F43C5F7E_BE96_4ddf_929E_68F709C2E793__INCLUDED_)
#define EA_F43C5F7E_BE96_4ddf_929E_68F709C2E793__INCLUDED_

#include "CPowerCalculate.h"

class CPowerCal_Tree : public CPowerCalculate
{
protected:
	pPowerCalVector pChildren;

public:
	virtual ~CPowerCal_Tree();

	virtual void Init(CDeviceBase * vDev) override;

	virtual void Init(CPowerProfile * vProfile) override;
	
	void Clear() override;

	void Add(CPowerCalculate * vItem) override;
	void Remove(CPowerCalculate * vItem) override;

	bool IsLeaf() override;

	int ChildCount();
	CPowerCalculate * Child(int vIndex);
	pPowerCalVector Children();

public:
	virtual void NewSolves();
	virtual void doNewItem(int vtblType);
	virtual void doNewItem(CDeviceTBL* vTBL);

	//
	CPowerCalculate *  doNewCal(CDeviceBase* vDev);
	virtual void NewCal_Tree(CDeviceBase * vDev);


public:
	CPowerGrid* pGrid;
	void NodeSort(NodeMap& vNodeMap) override;
	void NodeGround(NodeMap& vNodeMap) override;
	void NodeID(NodeMap& vNodeID) override;

	void StationSort(StationMap& vStaMap) override;

public:
	virtual void Prepare();
	virtual void StationSort();

};
#endif // !defined(EA_F43C5F7E_BE96_4ddf_929E_68F709C2E793__INCLUDED_)
