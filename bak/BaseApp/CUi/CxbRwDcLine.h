///////////////////////////////////////////////////////////
//  CxbRwDcLine.h
//  Implementation of the Class CxbRwDcLine
//  Created on:      18-4ÔÂ-2017 17:11:13
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_3DEF9080_6497_4b20_B08D_02292F8ED324__INCLUDED_)
#define EA_3DEF9080_6497_4b20_B08D_02292F8ED324__INCLUDED_

#include "CxbRwTwo.h"
#include "CxbDevDcLine.h"

class CxbRwDcLine : public CxbRwTwo
{
public:
	void OnLoad() override;
	void OnSave() override;

protected:
	void doLoad();
	void doSave();

	void doLoad(CxbDevBase * vDevice) override;
	void doSave(CxbDevBase * vDevice) override;


	void doLoad_hData();
	void doLoad_hData(CxbDevDcLine * vDevice) ;


	void doSave_hData();
	void doSave_hData(CxbDevDcLine * vDev);
};
#endif // !defined(EA_3DEF9080_6497_4b20_B08D_02292F8ED324__INCLUDED_)
