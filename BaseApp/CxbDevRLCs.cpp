///////////////////////////////////////////////////////////
//  CxbDevRLCs.cpp
//  Implementation of the Class CxbDevRLCs
//  Created on:      17-4ÔÂ-2017 17:24:53
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbDevRLCs.h"

CxbDevRLCs::~CxbDevRLCs()
{

	for each (CxbDevRLCs * vCal in pChildren)
	{
		delete vCal;
		vCal = nullptr;
	}

	pChildren.clear();
}

void CxbDevRLCs::Add(CxbDevBase * vItem)
{

	pChildren.push_back(vItem);
}


void CxbDevRLCs::Remove(CxbDevBase * vItem)
{

	//children.removeElement( component );

}


