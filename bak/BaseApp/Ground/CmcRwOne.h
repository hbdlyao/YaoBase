///////////////////////////////////////////////////////////
//  CmcRwOne.h
//  Implementation of the Class CmcRwOne
//  Created on:      18-4��-2017 20:24:49
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_185F6457_4B96_447d_B7E2_A4149C4CD98F__INCLUDED_)
#define EA_185F6457_4B96_447d_B7E2_A4149C4CD98F__INCLUDED_

#include "CmcRw.h"

class CmcRwOne : public CmcRw
{

protected:
	void doLoad(CmcDevBase* vDevice) override;
	void doSave(CmcDevBase* vDevice) override;

};
#endif // !defined(EA_185F6457_4B96_447d_B7E2_A4149C4CD98F__INCLUDED_)
