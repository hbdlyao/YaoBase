///////////////////////////////////////////////////////////
//  CPowerSolveMvc.h
//  Implementation of the Class CPowerSolveMvc
//  Created on:      09-4ÔÂ-2017 21:45:59
//  Original author: Administrator
///////////////////////////////////////////////////////////

#if !defined(EA_ED6CD978_DC3B_4776_843F_3EFAAE7D44CD__INCLUDED_)
#define EA_ED6CD978_DC3B_4776_843F_3EFAAE7D44CD__INCLUDED_

#include "CPowerProfile.h"
#include "CPowerSolves.h"
#include "CPowerGrid.h"

class CPowerSolveMvc
{
	
public:
	virtual ~CPowerSolveMvc();

	virtual void Init();
	virtual void Init(CPowerProfile * vProfile, CPowerGrid * vGrid);

	virtual void Clear();
	virtual void Release();
	
	virtual void NodeID();
	virtual void Run();
	
protected:
	CPowerProfile* pProfile;
	CPowerGrid* pGrid;
	CPowerSolves* pSolves;

	virtual void doNewSolves();

	virtual void doNodeID();
	virtual void doStationSort();

	virtual void doRun();


};
#endif // !defined(EA_ED6CD978_DC3B_4776_843F_3EFAAE7D44CD__INCLUDED_)
