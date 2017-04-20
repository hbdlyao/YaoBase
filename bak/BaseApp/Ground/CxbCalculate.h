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
	virtual void Init(CDeviceBase * vDev)override;
	virtual void Init(CPowerProfile* vProfile, CPowerGrid* vGrid) override;

public:
	virtual bool IsLeaf();

	virtual void Add(CxbCalculate * vItem);
	virtual void Remove(CxbCalculate * vItem);

public:
	virtual void UpdateY();
	virtual void UpdateI();
	virtual void StationSort(StationMap& vStaMap) override;
	
};


typedef vector<CxbCalculate*> pxbCalVector;

typedef map<string, CxbCalculate*> pxbCalMap;
typedef pair<string, CxbCalculate*> pxbCalPair;