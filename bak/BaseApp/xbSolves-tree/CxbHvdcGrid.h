///////////////////////////////////////////////////////////
//  CxbHvdcGrid.h
//  Implementation of the Class CxbDeviceTBL
//  Created on:      13-4月-2017 15:39:07
//  Original author: Administrator
///////////////////////////////////////////////////////////

#if !defined(EA_5F53B9B8_946F_4870_BD12_E3D539C4E2BC__INCLUDED_)
#define EA_5F53B9B8_946F_4870_BD12_E3D539C4E2BC__INCLUDED_

#include "CDeviceTBL.h"
#include "CPowerGrid.h"

/**
 * xb直流设备表
 */
class CxbDeviceTBL : public CDeviceTBL
{
protected:
	virtual CDeviceBase * doNewDevice(int vDevType);

public:
	virtual string TypeToName(int vDevType);

	static CDeviceBase * xbNewDevice(int vDevType);

public:
	void Prepare_hRLC();

};

class CxbHvdcGrid : public CPowerGrid
{
public:
	virtual void Init();
	virtual string TypeToName(int vType);
	virtual CDeviceTBL * NewDeviceTBL(int vType);
	
public:
	void Prepare_hRLC();



};
#endif // !defined(EA_5F53B9B8_946F_4870_BD12_E3D539C4E2BC__INCLUDED_)
