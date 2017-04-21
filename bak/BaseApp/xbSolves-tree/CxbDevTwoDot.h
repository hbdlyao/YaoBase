///////////////////////////////////////////////////////////
//  CxbDevTwoDot.h
//  Implementation of the Class CxbDevTwoDot
//  Created on:      12-4��-2017 12:00:20
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_8E88760C_D6CE_419f_A916_6E2E357A1B1E__INCLUDED_)
#define EA_8E88760C_D6CE_419f_A916_6E2E357A1B1E__INCLUDED_

#include "CxbDevBase.h"

/**
 * ˫�˵��豸
 */
class CxbDevTwoDot : public CxbDevBase
{
public:

	string StationName1;
	string StationName2;


protected:
	virtual void Init();


public:

	virtual string GetStationName1();
	virtual string GetStationName2();
	
	virtual void SetStationName1(string newVal);
	virtual void SetStationName2(string newVal);

	virtual string GetStationName() override;
	virtual void SetStationName(string newVal) override;
};
#endif // !defined(EA_8E88760C_D6CE_419f_A916_6E2E357A1B1E__INCLUDED_)
