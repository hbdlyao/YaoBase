///////////////////////////////////////////////////////////
//  CxbRw_Tree1.h
//  Implementation of the Class CxbRw_Tree1
//  Created on:      22-4ÔÂ-2017 7:07:32
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_FB52E26C_340D_4a72_B62E_354BECB97182__INCLUDED_)
#define EA_FB52E26C_340D_4a72_B62E_354BECB97182__INCLUDED_

#include "CxbRwBranch.h"

class CxbRw_Tree1 : public CxbRwBranch
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
#endif // !defined(EA_FB52E26C_340D_4a72_B62E_354BECB97182__INCLUDED_)
