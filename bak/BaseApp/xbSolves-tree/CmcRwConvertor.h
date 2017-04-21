///////////////////////////////////////////////////////////
//  CmcRwConvertor.h
//  Implementation of the Class CmcRwConvertor
//  Created on:      18-4ÔÂ-2017 20:38:18
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_5BE99274_E652_4837_8521_16FD54C4E6DB__INCLUDED_)
#define EA_5BE99274_E652_4837_8521_16FD54C4E6DB__INCLUDED_

#include "CmcRwTwo.h"

class CmcRwConvertor : public CmcRwTwo
{

protected:
	void doLoad(CmcDevBase* vDevice) override;
	void doSave(CmcDevBase* vDevice) override;

};
#endif // !defined(EA_5BE99274_E652_4837_8521_16FD54C4E6DB__INCLUDED_)
