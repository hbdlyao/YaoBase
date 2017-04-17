///////////////////////////////////////////////////////////
//  CxbDevRLCs.h
//  Implementation of the Class CxbDevRLCs
//  Created on:      17-4ÔÂ-2017 17:24:53
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_78534360_4BFE_4d67_9727_29ED50B4B3BE__INCLUDED_)
#define EA_78534360_4BFE_4d67_9727_29ED50B4B3BE__INCLUDED_

#include "CxbDevBranch.h"

class CxbDevRLCs : public CxbDevBranch
{

public:
	virtual ~CxbDevRLCs();

	void Add(CxbDevBase * vItem) override;
	void Remove(CxbDevBase * vItem) override;

private:
	pObjVector pChildren;


};
#endif // !defined(EA_78534360_4BFE_4d67_9727_29ED50B4B3BE__INCLUDED_)
