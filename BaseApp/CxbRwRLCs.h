///////////////////////////////////////////////////////////
//  CxbRwRLCs.h
//  Implementation of the Class CxbRwRLCs
//  Created on:      18-4ÔÂ-2017 17:11:32
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_7F0DB329_76C5_4ed9_90FB_4C596047DF8D__INCLUDED_)
#define EA_7F0DB329_76C5_4ed9_90FB_4C596047DF8D__INCLUDED_

#include "CxbRw.h"
#include "CxbDevRLCs.h"

class CxbRwRLCs : public CxbRw
{

protected:
	void doLoad(CxbDevBase * vDevice) override;
	void doSave(CxbDevBase * vDevice) override;

	void doLoad_Data_Root(CxbDevBase * vDevice);
	void doLoad_Data_Tree(CxbDevRLCs* vParent, int vIndex);

	void doSave_Data_Root(CxbDevBase * vDevice);
	void doSave_Data_Tree(CxbDevRLCs* vParent, int vIndex);

};
#endif // !defined(EA_7F0DB329_76C5_4ed9_90FB_4C596047DF8D__INCLUDED_)
