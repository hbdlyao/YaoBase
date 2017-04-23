///////////////////////////////////////////////////////////
//  CxbRwDCF.h
//  Implementation of the Class CxbRwDCF
//  Created on:      18-4ÔÂ-2017 23:40:50
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_4E5E2E7C_3AAF_4c70_8173_4C8BCA4BB81C__INCLUDED_)
#define EA_4E5E2E7C_3AAF_4c70_8173_4C8BCA4BB81C__INCLUDED_

#include "CxbRw_Tree.h"

class CxbRwDCF : public CxbRw_Tree
{

protected:
	void doLoad_Root(CxbDevBase* vRoot) override;
	void doSave_Root(CxbDevBase* vRoot) override;

	void doLoad_Leaf(CxbDevBase * vLeaf, int vIndex)override;
	void doSave_Leaf(CxbDevBase * vLeaf, int vIndex)override;

};
#endif // !defined(EA_4E5E2E7C_3AAF_4c70_8173_4C8BCA4BB81C__INCLUDED_)
