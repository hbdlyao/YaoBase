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
protected:
	CmcHvdcGrid* pHvdc;

public:
	void InitGrid(CmcHvdcGrid* vHvdc);

public:
	virtual void OnLoad() override;
	virtual void OnSave() override;

	void OnLoad_Order(CmcOrder* vOrder);
	void OnSave_Order(CmcOrder* vOrder);
	
	void OnLoad_Result(CmcResult* vRes);
	void OnSave_Result(CmcResult* vRes);


protected:
	virtual void doLoad(CmcDevBase* vDevice);
	virtual void doSave(CmcDevBase* vDevice);




};
