///////////////////////////////////////////////////////////
//  CmcRwDcLine.h
//  Implementation of the Class CmcRwDcLine
//  Created on:      18-4ÔÂ-2017 21:41:07
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_FBC24368_6B4E_4372_824D_09690713EC17__INCLUDED_)
#define EA_FBC24368_6B4E_4372_824D_09690713EC17__INCLUDED_

#include "CmcRwTwo.h"

class CmcRwDcLine : public CmcRwTwo
{

protected:
	virtual void doLoad(CmcDevBase* vDevice);
	virtual void doSave(CmcDevBase* vDevice);

};
#endif // !defined(EA_FBC24368_6B4E_4372_824D_09690713EC17__INCLUDED_)
