///////////////////////////////////////////////////////////
//  CPowerSolves.h
//  Implementation of the Class CPowerSolves
//  Created on:      09-4ÔÂ-2017 21:38:12
//  Original author: Administrator
///////////////////////////////////////////////////////////

#if !defined(EA_664B9E6A_20C1_4552_B44D_AB338DB234BB__INCLUDED_)
#define EA_664B9E6A_20C1_4552_B44D_AB338DB234BB__INCLUDED_

#include "CPowerProfile.h"
#include "CPowerCalculate.h"

class CPowerSolves
{

public:
	pPowerCalMap pItems;

	CPowerProfile *pProfile;
	CPowerGrid * pGrid;

	virtual ~CPowerSolves();
	virtual string TypeToName(int vType);

	virtual void Init(CPowerProfile * vProfile, CPowerGrid * vGrid);

	virtual void Clear();
	virtual void NewSolves();

	virtual void StationSort();

	virtual void NodeID();
	virtual	void Run();

protected:
	virtual void Release();

	virtual void doNewCal(CDeviceBase * vDev, int vIndex);
	virtual void doNewItem(int vtblType);

	virtual void doPrepare();

};
#endif // !defined(EA_664B9E6A_20C1_4552_B44D_AB338DB234BB__INCLUDED_)
