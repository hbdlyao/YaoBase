#pragma once

#include "CPowerCalculate.h"
#include "CxbProfile.h"
#include "CxbHvdcGrid.h"

class CxbCalculate : public CPowerCalculate
{
private:
	CxbHvdcGrid *pHvdc;

protected:
	CxbProfile * pxbProfile;

public:
	void Init(CPowerProfile* vProfile) override;
	void Init(CDeviceBase * vDev) override;

public:
	virtual void Add(CxbCalculate * vItem);
	virtual void Remove(CxbCalculate * vItem);


public:
	virtual void UpdateY();
	virtual void UpdateI();
	
};


typedef vector<CxbCalculate*> pxbCalVector;

typedef map<string, CxbCalculate*> pxbCalMap;
typedef pair<string, CxbCalculate*> pxbCalPair;