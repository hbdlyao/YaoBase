#pragma once

#include "CMyRw.h"
#include "CxbHvdcGrid.h"
#include "gbHead_xbDevice.h"

class CxbRw : public CRwDbf
{
protected:
	CxbHvdcGrid * pHvdc = nullptr;

public:
	virtual void InitAdo(string vDbf);

	void InitGrid(CxbHvdcGrid * vHvdc);


public:
	void OnLoad_Order();
	void OnSave_Order();
	void OnLoad_Result();
	void OnSave_Result();

protected:
	void doLoad_One(CxbDevOneDot * vDev);
	void doLoad_Two(CxbDevTwoDot * vDev);

	void doLoad_Shunt(CxbDevShunt * vDev);
	void doLoad_Branch(CxbDevBranch * vDev);

	void doLoad_DcLine(CxbDevDcLine * vDev);


	void doSave_One(CxbDevOneDot* vDev);
	void doSave_Two(CxbDevTwoDot* vDev);
	void doSave_Shunt(CxbDevShunt* vDev);
	void doSave_Branch(CxbDevBranch* vDev);

	void doSave_DcLine(CxbDevDcLine * vDev);


protected:
	virtual void doLoad();
	virtual void doSave();

	void doLoad_xb3pVSrc();
	void doLoad_xbPbDKQ();
	void doLoad_xbDcF();
	void doLoad_xbDcLine();
	void doLoad_xbGroundLine();
	void doLoad_xbMetalLine();
	void doLoad_xbGround();
	void doLoad_xbXfC();
	void doLoad_xbCoupleC();
	void doLoad_xbPulseC();
	void doLoad_xbShunt();
	void doLoad_xbBranch();


	void doSave_xb3pVSrc();
	void doSave_xbPbDKQ();
	void doSave_xbDcF();
	void doSave_xbDcLine();
	void doSave_xbGroundLine();
	void doSave_xbMetalLine();
	void doSave_xbGround();
	void doSave_xbXfC();
	void doSave_xbCoupleC();
	void doSave_xbPulseC();
	void doSave_xbShunt();
	void doSave_xbBranch();


	void doLoad_Order();
	void doSave_Order();
	void doLoad_Result();
	void doSave_Result();


	//

};

