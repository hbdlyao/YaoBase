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

	virtual void Add(CxbCalculate * vItem);
	virtual void Remove(CxbCalculate * vItem);

public:
	virtual void UpdateY();
	virtual void UpdateI();

	virtual void Init(CPowerProfile* vProfile, CPowerGrid* vGrid);
	virtual void StationSort(StationMap& vStaMap) override;
	
};


