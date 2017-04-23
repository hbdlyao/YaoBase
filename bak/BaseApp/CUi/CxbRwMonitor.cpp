///////////////////////////////////////////////////////////
//  CxbRwMonitor.cpp
//  Implementation of the Class CxbRwMonitor
//  Created on:      18-4ÔÂ-2017 23:39:58
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbRwMonitor.h"

void CxbRwMonitor::doLoad_Leaf(CxbDevBase* vLeaf, int vIndex)
{

	CxbRwBranch::doLoad(vLeaf);
}


void CxbRwMonitor::doSave_Leaf(CxbDevBase* vLeaf, int vIndex)
{

	CxbRwBranch::doSave(vLeaf);
}