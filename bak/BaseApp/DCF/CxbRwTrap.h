///////////////////////////////////////////////////////////
//  CxbRwTrap.h
//  Implementation of the Class CxbRwTrap
//  Created on:      18-4��-2017 23:41:01
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_329292BB_5B26_4364_AF85_BD1139BC3598__INCLUDED_)
#define EA_329292BB_5B26_4364_AF85_BD1139BC3598__INCLUDED_

#include "CxbRw_Tree.h"

class CxbRwTrap : public CxbRw_Tree
{

protected:
	 void doLoad_Leaf(CxbDevBase* vLeaf, int vIndex) override;
	 void doSave_Leaf(CxbDevBase* vLeaf, int vIndex) override;
};
#endif // !defined(EA_329292BB_5B26_4364_AF85_BD1139BC3598__INCLUDED_)
