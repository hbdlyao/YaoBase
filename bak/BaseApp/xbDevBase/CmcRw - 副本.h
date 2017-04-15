#pragma once

#include "CMyRw.h"
#include "gbHead_mcDevice.h"

class CmcRw : public CRwDbf
{

public:
	virtual void doLoad();
	virtual void doSave();
	virtual void InitAdo(string vDbf);

protected:
	void doLoad_AcSys();
	void doLoad_AcFilter();
	void doLoad_Xf2();
	void doLoad_Convertor();
	void doLoad_DcLine();
	void doLoad_MetalLine();
	void doLoad_GroundLine();
	void doLoad_Ground();

	void doSave_AcSys();
	void doSave_AcFilter();
	void doSave_Xf2();
	void doSave_Convertor();
	void doSave_DcLine();
	void doSave_MetalLine();
	void doSave_GroundLine();
	void doSave_Ground();


	void doLoad_Branch(CmcDevDcLine * vDev);
	void doSave_Branch(CmcDevDcLine * vDev);

};
