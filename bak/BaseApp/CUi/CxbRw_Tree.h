///////////////////////////////////////////////////////////
//  CxbRw_Tree.h
//  Implementation of the Class CxbRw_Tree
//  Created on:      20-4ÔÂ-2017 22:28:49
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_3A6B0157_4527_4b7e_8FEA_84A410359E17__INCLUDED_)
#define EA_3A6B0157_4527_4b7e_8FEA_84A410359E17__INCLUDED_

#include "CxbRwBranch.h"
#include "CxbDev_Tree.h"

class CxbRw_Tree : public CxbRwBranch
{

public:
	void OnLoad() override;
	void OnSave() override;

protected:
	void doLoad(CxbDevBase* vDevice) override;
	void doSave(CxbDevBase* vDevice) override;

	/**
	 * void CxbRw_Tree::OnSave() { doSave_Root();  doSave_Tree(); }
	 */
	virtual void doLoad_Root();
	virtual void doSave_Root();

	virtual void doLoad_Tree();
	virtual void doSave_Tree();

	virtual void doLoad_Root(CxbDevBase* vRoot);
	virtual void doSave_Root(CxbDevBase* vRoot);

	virtual void doLoad_Node(CxbDev_Tree* vNode, int vIndex);
	virtual void doSave_Node(CxbDev_Tree* vNode, int vIndex);

	virtual void doLoad_Leaf(CxbDevBase* vLeaf, int vIndex);
	virtual void doSave_Leaf(CxbDevBase* vLeaf, int vIndex);

};
#endif // !defined(EA_3A6B0157_4527_4b7e_8FEA_84A410359E17__INCLUDED_)
