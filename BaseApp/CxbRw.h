#pragma once

#include "CMyRw.h"
#include "CxbDevBase.h"
#include "CxbHvdcGrid.h"

#include "CxbOrder.h"
#include "CxbResult.h"

class CxbRw : public CRwDbf
{
protected:
	CxbHvdcGrid * pHvdc = nullptr;

public:
	void InitGrid(CxbHvdcGrid * vHvdc);


public:
	virtual void OnLoad() override;
	virtual void OnSave() override;
	

protected:

	virtual void doLoad(CxbDevBase * vDevice);
	virtual void doSave(CxbDevBase * vDevice);


	//

};

