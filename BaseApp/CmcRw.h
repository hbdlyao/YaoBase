#pragma once

#include "CMyRw.h"
#include "gbHead_mcDevice.h"

class CmcRw : public CRwDbf
{
public:
	void OnLoad_Order();
	void OnSave_Order();

	void OnLoad_Result();
	void OnSave_Result();


	virtual void InitAdo(string vDbf);

	void doLoad_One(CDeviceBase * vDev);
	void doLoad_Shunt(CmcDevShunt * vDev);
	void doLoad_Two(CDeviceBase * vDev);
	
protected:
	virtual void doLoad();
	virtual void doSave();

	void doLoad_Order();
	void doSave_Order();

	void doLoad_Result();
	void doSave_Result();


	/**
	 * void
	 */
	void doLoad_AcSys();
	void doLoad_AcFilter();
	void doLoad_Xf2();
	void doLoad_Convertor();
	void doLoad_DcLine();
	/**
	 * void
	 */
	void doLoad_MetalLine();
	void doLoad_GroundLine();
	void doLoad_Ground();

	void doSave_One(CDeviceBase * vDev);
	void doSave_Two(CDeviceBase * vDev);

	/**
	 * void
	 */
	void doSave_AcSys();
	void doSave_AcFilter();
	void doSave_Xf2();
	void doSave_Convertor();
	void doSave_DcLine();
	void doSave_MetalLine();
	void doSave_GroundLine();
	void doSave_Ground();

	void doSave_Shunt(CmcDevShunt * vDev);


	/**
	 * void
	 */
	void doLoad_Branch(CmcDevDcLine * vDev);
	void doSave_Branch(CmcDevDcLine * vDev);

};
