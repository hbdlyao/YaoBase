///////////////////////////////////////////////////////////
//  CxbSolves_Tree.h
//  Implementation of the Class CxbSolves_Tree
//  Created on:      21-4ÔÂ-2017 20:29:55
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_469A6E19_8342_4c51_AFFC_903C552DC24F__INCLUDED_)
#define EA_469A6E19_8342_4c51_AFFC_903C552DC24F__INCLUDED_

#include "CxbCal_Tree.h"

class CxbSolves_Tree : public CxbCal_Tree
{
protected:
	CxbHvdcGrid * pHvdc;

	int GroundType();

public:
	void Init(CPowerProfile* vProfile, CxbHvdcGrid * vGrid) ;

protected:
	void doNewItem(int vtblType);
	void doNewItem(CDeviceTBL* vTBL);

public:
	void NewSolves();
	void NewSolves(int vGndType);

public:
	virtual void NodeID();
	virtual void StationSort();

	virtual void Run();

protected:
	void doNewXbSolvers10();
	void doNewXbSolvers11();
	void doNewXbSolvers20();
	void doNewXbSolvers21();

	void doSovle();
	
	void SolveU();

};
#endif // !defined(EA_469A6E19_8342_4c51_AFFC_903C552DC24F__INCLUDED_)
