///////////////////////////////////////////////////////////
//  CmcRwXf2.h
//  Implementation of the Class CmcRwXf2
//  Created on:      18-4��-2017 20:38:23
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_44D30430_7C90_4590_ADD0_F59399A0609F__INCLUDED_)
#define EA_44D30430_7C90_4590_ADD0_F59399A0609F__INCLUDED_

#include "CmcRwTwo.h"

class CmcRwXf2 : public CmcRwTwo
{

protected:
	void doLoad(CmcDevBase* vDevice) override;
	void doSave(CmcDevBase* vDevice) override;

};
#endif // !defined(EA_44D30430_7C90_4590_ADD0_F59399A0609F__INCLUDED_)
