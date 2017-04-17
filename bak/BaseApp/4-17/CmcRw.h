#pragma once

#include "CMyRw.h"
#include "gbHead_mcDevice.h"
#include "CmcHvdcGrid.h"

#include "CmcOrder.h"
#include "CmcResult.h"


/**
 * 主回路计算读写
 */
class CmcRw : public CRwDbf
{
public:
	virtual void InitAdo(string vDbf);

public:
	void OnLoad_Order(CmcOrder* vOrder);
	void OnSave_Order(CmcOrder* vOrder);
	
	void OnLoad_Result(CmcResult* vRes);
	void OnSave_Result(CmcResult* vRes);

	void InitGrid(CmcHvdcGrid* vHvdc);

protected:
	void doLoad_Order(CmcOrder* vOrder);
	void doSave_Order(CmcOrder* vOrder);

	void doLoad_Result(CmcResult * vRe);
	void doSave_Result(CmcResult * vRes);

protected:
	void doLoad_One(CDeviceBase * vDev);
	void doLoad_Two(CDeviceBase * vDev);
	void doLoad_Shunt(CmcDevShunt * vDev);
	void doLoad_Branch(CmcDevDcLine * vDev);

	void doSave_One(CDeviceBase * vDev);
	void doSave_Two(CDeviceBase * vDev);
	void doSave_Shunt(CmcDevShunt * vDev);
	void doSave_Branch(CmcDevDcLine * vDev);


protected:	CmcHvdcGrid* pHvdc;
	virtual void doLoad();
	virtual void doSave();


	/**
	 * void
	 */
	void doLoad_mcAcSys();
	void doLoad_mcAcFilter();
	void doLoad_mcXf2();
	void doLoad_mcConvertor();
	void doLoad_mcDcLine();
	void doLoad_mcMetalLine();
	void doLoad_mcGroundLine();
	void doLoad_mcGround();

	/**
	 * void
	 */
	void doSave_mcAcSys();
	void doSave_mcAcFilter();
	void doSave_mcXf2();
	void doSave_mcConvertor();
	void doSave_mcDcLine();
	void doSave_mcMetalLine();
	void doSave_mcGroundLine();
	void doSave_mcGround();


};
