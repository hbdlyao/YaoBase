///////////////////////////////////////////////////////////
//  CmcRwGroundLine.h
//  Implementation of the Class CmcRwGroundLine
//  Created on:      18-4ÔÂ-2017 22:02:19
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_78C54108_B995_4cbf_B6D3_C8C504C0E066__INCLUDED_)
#define EA_78C54108_B995_4cbf_B6D3_C8C504C0E066__INCLUDED_

#include "CmcRwOne.h"

class CmcRwGroundLine : public CmcRwOne
{

protected:
	virtual void doLoad(CmcDevBase* vDevice);
	virtual void doSave(CmcDevBase* vDevice);

};
#endif // !defined(EA_78C54108_B995_4cbf_B6D3_C8C504C0E066__INCLUDED_)
