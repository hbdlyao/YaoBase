#pragma once


#include "CPowerGrid.h"
#include "gbHead_mcDevice.h"

using namespace std;


/**
 * 直流设备表
 */
class CHvdcDeviceTBL : public CDeviceTBL
{

public:

	virtual string TypeToName(int vDevType);


protected:
	virtual CDeviceBase * doNewDevice(int vDevType);
};

class CHvdcGrid : public CPowerGrid
{
public:
	int StaCount();
	
	virtual void Init();
	virtual string TypeToName(int vType);
	virtual CDeviceTBL * NewDeviceTBL(int vType);

};


//typedef unique_ptr<CHvdcGrid> UP_HvdcGrid;


