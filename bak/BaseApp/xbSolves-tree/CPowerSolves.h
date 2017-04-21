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
	virtual ~CPowerSolves();
	virtual void Clear();

	virtual string TypeToName(int vType);
	virtual void Init(CPowerProfile * vProfile, CPowerGrid * vGrid);

public:
	pPowerCalMap pItems;

	CPowerProfile *pProfile;
	CPowerGrid * pGrid;

	virtual void NewSolves();

	virtual void StationSort();
	virtual void NodeID();
	virtual	void Run();

protected:
	virtual void doNewItem(int vtblType);
	virtual void doNewItem(CDeviceTBL * vTBL);
	virtual void doNewCal(CDeviceBase * vDev, int vIndex);
	virtual void doNewCal_Tree(CDeviceBase* vDev, int vIndex);


	virtual void doPrepare();

};
#endif // !defined(EA_664B9E6A_20C1_4552_B44D_AB338DB234BB__INCLUDED_)
