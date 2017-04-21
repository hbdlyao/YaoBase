///////////////////////////////////////////////////////////
//  CxbRwMonitor.h
//  Implementation of the Class CxbRwMonitor
//  Created on:      18-4ÔÂ-2017 23:39:58
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_9E4D5D2D_58F4_4450_8EC1_0BAB6C7DDBB6__INCLUDED_)
#define EA_9E4D5D2D_58F4_4450_8EC1_0BAB6C7DDBB6__INCLUDED_

#include "CxbRw_Tree.h"

class CxbRwMonitor : public CxbRw_Tree
{

protected:
	void doLoad_Leaf(CxbDevBase* vLeaf, int vIndex) override;
	void doSave_Leaf(CxbDevBase* vLeaf, int vIndex) override;
};
#endif // !defined(EA_9E4D5D2D_58F4_4450_8EC1_0BAB6C7DDBB6__INCLUDED_)
