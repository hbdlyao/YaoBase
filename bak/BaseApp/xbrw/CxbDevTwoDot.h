///////////////////////////////////////////////////////////
//  CxbDevTwoDot.h
//  Implementation of the Class CxbDevTwoDot
//  Created on:      12-4月-2017 12:00:20
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_8E88760C_D6CE_419f_A916_6E2E357A1B1E__INCLUDED_)
#define EA_8E88760C_D6CE_419f_A916_6E2E357A1B1E__INCLUDED_

#include "CxbDevBase.h"

/**
 * 双端点设备
 */
class CxbDevTwoDot : public CxbDevBase
{
public:
	/**
	 * 马骏鹏
	 */
	string StationName1;
	string StationName2;


protected:
	virtual void Init();


public:
	/**
	 * 马骏鹏
	 */
	string GetStationName1();
	string GetStationName2();
	/**
	 * 马骏鹏
	 */
	void SetStationName1(string newVal);
	void SetStationName2(string newVal);
};
#endif // !defined(EA_8E88760C_D6CE_419f_A916_6E2E357A1B1E__INCLUDED_)
