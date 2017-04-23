///////////////////////////////////////////////////////////
//  CxbRwTrap.cpp
//  Implementation of the Class CxbRwTrap
//  Created on:      18-4ÔÂ-2017 23:41:01
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbRwTrap.h"



void CxbRwTrap::doLoad_Leaf(CxbDevBase* vLeaf, int vIndex)
{

	CxbRwBranch::doLoad(vLeaf);
}


void CxbRwTrap::doSave_Leaf(CxbDevBase* vLeaf, int vIndex)
{

	CxbRwBranch::doSave(vLeaf);
}