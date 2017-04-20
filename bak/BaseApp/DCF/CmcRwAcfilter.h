///////////////////////////////////////////////////////////
//  CmcRwAcfilter.h
//  Implementation of the Class CmcRwAcfilter
//  Created on:      18-4ÔÂ-2017 20:38:13
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_3B603797_104C_49dc_B742_4BAB6A789431__INCLUDED_)
#define EA_3B603797_104C_49dc_B742_4BAB6A789431__INCLUDED_

#include "CmcRwOne.h"

class CmcRwAcfilter : public CmcRwOne
{

protected:
	void doLoad(CmcDevBase * vDevice);
	void doSave(CmcDevBase * vDevice);

};
#endif // !defined(EA_3B603797_104C_49dc_B742_4BAB6A789431__INCLUDED_)
