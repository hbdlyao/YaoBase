///////////////////////////////////////////////////////////
//  CmcRwMvc.h
//  Implementation of the Class CmcRwMvc
//  Created on:      18-4��-2017 21:32:02
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_4402847C_542D_415f_B379_AE32A06E9F95__INCLUDED_)
#define EA_4402847C_542D_415f_B379_AE32A06E9F95__INCLUDED_

#include "CRwMvc.h"
#include "CmcHvdcGrid.h"

class CmcRwMvc : public CRwMvc
{

public:
	void InitGrid(CmcHvdcGrid* vHvdc);
	void InitAdo(string vDbf) override;

protected:
	CmcHvdcGrid* pHvdc;


	virtual void doLoad();
	virtual void doSave();
	/**
	 * void
	 */
	void doLoad_mcAcSys();
	void doLoad_mcAcFilter();
	/**
	 * void
	 */
	void doLoad_mcXf2();
	void doLoad_mcConvertor();
	/**
	 * void
	 */
	void doLoad_mcDcLine();
	/**
	 * void
	 */
	void doLoad_mcMetalLine();
	/**
	 * void
	 */
	void doLoad_mcGroundLine();
	void doLoad_mcGround();
	/**
	 * void
	 */
	void doSave_mcAcSys();
	void doSave_mcAcFilter();
	void doSave_mcXf2();
	void doSave_mcConvertor();
	void doSave_mcDcLine();
	void doSave_mcMetalLine();
	void doSave_mcGroundLine();
	void doSave_mcGround();

};
#endif // !defined(EA_4402847C_542D_415f_B379_AE32A06E9F95__INCLUDED_)