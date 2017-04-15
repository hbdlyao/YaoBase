///////////////////////////////////////////////////////////
//  CmcHvdcGrid.h
//  Implementation of the Class CmcHvdcGrid
//  Created on:      08-4ÔÂ-2017 10:32:17
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_1B2F5D6E_1478_43f9_9224_BC5F2BA48903__INCLUDED_)
#define EA_1B2F5D6E_1478_43f9_9224_BC5F2BA48903__INCLUDED_

#include "CHvdcGrid.h"

class CmcHvdcGrid : public CHvdcGrid
{

public:
	virtual void Init();
	virtual string TypeToName(int vType);
	virtual CDeviceTBL * NewDeviceTBL(int vType);

protected:

};
#endif // !defined(EA_1B2F5D6E_1478_43f9_9224_BC5F2BA48903__INCLUDED_)
