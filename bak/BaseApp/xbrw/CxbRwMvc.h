///////////////////////////////////////////////////////////
//  CxbRwMvc.h
//  Implementation of the Class CxbRwMvc
//  Created on:      18-4ÔÂ-2017 18:50:05
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_BAA67435_F767_45ec_87D4_4B36E3085597__INCLUDED_)
#define EA_BAA67435_F767_45ec_87D4_4B36E3085597__INCLUDED_

#include "CxbHvdcGrid.h"
#include "CRwMvc.h"

class CxbRwMvc : public CRwMvc
{

public:
	void InitGrid(CxbHvdcGrid* vHvdc);
	void InitAdo(string vDbf) override;

protected:
	CxbHvdcGrid* pHvdc;

	virtual void doLoad();
	virtual void doSave();

protected:
	void doLoad_xb3pVSrc();
	void doLoad_xbPbDKQ();
	void doLoad_xbDcF();
	void doLoad_xbDcLine();
	void doLoad_xbGroundLine();
	void doLoad_xbMetalLine();
	void doLoad_xbGround();
	void doLoad_xbXfC();
	void doLoad_xbCoupleC();
	void doLoad_xbPulseC();
	void doLoad_xbShunt();
	void doLoad_xbBranch();
	void doLoad_xbMonitor();

	void doSave_xb3pVSrc();
	void doSave_xbPbDKQ();
	void doSave_xbDcF();
	void doSave_xbDcLine();
	void doSave_xbGroundLine();
	void doSave_xbMetalLine();
	void doSave_xbGround();
	void doSave_xbXfC();
	void doSave_xbCoupleC();
	void doSave_xbPulseC();
	void doSave_xbShunt();
	void doSave_xbBranch();
	void doSave_xbMonitor();

};
#endif // !defined(EA_BAA67435_F767_45ec_87D4_4B36E3085597__INCLUDED_)
