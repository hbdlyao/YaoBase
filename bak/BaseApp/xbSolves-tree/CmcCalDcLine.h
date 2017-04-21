#pragma once

#include "CmcCalTwoDot.h"

/**
 * 主回路 直流极线
 */
class CmcCalDcLine : public CmcCalTwoDot
{

public:
	virtual void StationSort(StationMap & vStaMap);

protected:
	virtual void UpdateY();

};


