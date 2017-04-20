///////////////////////////////////////////////////////////
//  CxbRwRLCs.h
//  Implementation of the Class CxbRwRLCs
//  Created on:      18-4ÔÂ-2017 17:11:32
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_7F0DB329_76C5_4ed9_90FB_4C596047DF8D__INCLUDED_)
#define EA_7F0DB329_76C5_4ed9_90FB_4C596047DF8D__INCLUDED_

#include "CxbRwBranch.h"

#include "CxbDevRLCs.h"

class CxbRwRLCs : public CxbRwBranch
{
public:
	void OnLoad() override;
	void OnSave() override;

protected:
	void doLoad(CxbDevBase * vDevice) override;
	void doSave(CxbDevBase * vDevice) override;

	virtual void doLoad_Root();
	virtual void doSave_Root();	
	
	virtual void doLoad_Tree();
	virtual void doSave_Tree();	
	
	virtual void doLoad_Root(CxbDevBase * vRoot);
	virtual void doSave_Root(CxbDevBase * vRoot);

	virtual void doLoad_Node(CxbDevRLCs* vNode, int vIndex);
	virtual void doSave_Node(CxbDevRLCs* vNode, int vIndex);

	virtual void doLoad_Leaf(CxbDevBase * vLeaf, int vIndex);
	virtual void doSave_Leaf(CxbDevBase * vLeaf, int vIndex);


};
#endif // !defined(EA_7F0DB329_76C5_4ed9_90FB_4C596047DF8D__INCLUDED_)
