///////////////////////////////////////////////////////////
//  CxbRwDCF.h
//  Implementation of the Class CxbRwDCF
//  Created on:      18-4ÔÂ-2017 23:40:50
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_4E5E2E7C_3AAF_4c70_8173_4C8BCA4BB81C__INCLUDED_)
#define EA_4E5E2E7C_3AAF_4c70_8173_4C8BCA4BB81C__INCLUDED_

#include "CxbRwRLCs.h"

class CxbRwDCF : public CxbRwRLCs
{

protected:
	void doLoad_Data_Root(CxbDevBase* vDevice) override;
	void doSave_Data_Root(CxbDevBase* vDevice) override;
};
#endif // !defined(EA_4E5E2E7C_3AAF_4c70_8173_4C8BCA4BB81C__INCLUDED_)
