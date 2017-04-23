///////////////////////////////////////////////////////////
//  CmcRwMvc.cpp
//  Implementation of the Class CmcRwMvc
//  Created on:      18-4ÔÂ-2017 21:32:02
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CmcRwMvc.h"
#include "gbHead_mcRw.h"


void CmcRwMvc::InitGrid(CmcHvdcGrid* vHvdc)
{

	pHvdc = vHvdc;
}



void CmcRwMvc::InitAdo(string vDbf)
{
	dbfName = vDbf;

	RwAdo = new CRwAdo_Access();
	RwAdo->InitDbf(dbfName, "", "", "false");
}

void CmcRwMvc::doLoad()
{

	doLoad_mcAcSys();
	doLoad_mcAcFilter();
	doLoad_mcXf2();
	
	doLoad_mcConvertor();
	
	doLoad_mcDcLine();
	doLoad_mcMetalLine();
	doLoad_mcGroundLine();
	
	//doLoad_mcGround();


}


void CmcRwMvc::doSave()
{

	doSave_mcAcSys();
	doSave_mcAcFilter();
	doSave_mcXf2();
	
	doSave_mcConvertor();
	
	doSave_mcDcLine();
	doSave_mcMetalLine();
	doSave_mcGroundLine();
	
	//doSave_mcGround();
}


/**
* void
*/
void CmcRwMvc::doLoad_mcAcSys()
{
	CmcRwAcSys vRw;

	vRw.InitAdo(RwAdo);
	vRw.InitTable("mcAcSystem", mc_AcSys, mc_AcSys);
	vRw.InitGrid(pHvdc);

	vRw.OnLoad();

}


void CmcRwMvc::doLoad_mcAcFilter()
{
	CmcRwAcfilter vRw;

	vRw.InitAdo(RwAdo);
	vRw.InitTable("mcAcFilter", mc_AcF, mc_AcF);
	vRw.InitGrid(pHvdc);

	vRw.OnLoad();

}




/**
 * void
 */
void CmcRwMvc::doLoad_mcXf2()
{
	CmcRwXf2 vRw;

	vRw.InitAdo(RwAdo);
	vRw.InitTable("mcTransformer", mc_Xf2, mc_Xf2);
	vRw.InitGrid(pHvdc);

	vRw.OnLoad();
}


void CmcRwMvc::doLoad_mcConvertor() 
{
	CmcRwConvertor vRw;

	vRw.InitAdo(RwAdo);
	vRw.InitTable("mcConvertor", mc_Convertor, mc_Convertor);
	vRw.InitGrid(pHvdc);

	vRw.OnLoad();
}

/**
 * void
 */
void CmcRwMvc::doLoad_mcDcLine()
{
	CmcRwDcLine vRw;

	vRw.InitAdo(RwAdo);
	vRw.InitTable("mcDcLine", mc_DcLine, mc_DcLine);
	vRw.InitGrid(pHvdc);

	vRw.OnLoad();
}
/**
 * void
 */
void CmcRwMvc::doLoad_mcMetalLine()
{
	CmcRwMetalLine vRw;

	vRw.InitAdo(RwAdo);
	vRw.InitTable("mcMetalLine", mc_MetalLine, mc_MetalLine);
	vRw.InitGrid(pHvdc);

	vRw.OnLoad();
}


/**
 * void
 */
void CmcRwMvc::doLoad_mcGroundLine() 
{
	CmcRwGroundLine vRw;

	vRw.InitAdo(RwAdo);
	vRw.InitTable("mcGroundLine", mc_GroundLine, mc_GroundLine);
	vRw.InitGrid(pHvdc);

	vRw.OnLoad();
}


void CmcRwMvc::doLoad_mcGround()
{
	CmcRwGround vRw;

	vRw.InitAdo(RwAdo);
	vRw.InitTable("mcGround", mc_Ground, mc_Ground);
	vRw.InitGrid(pHvdc);

	vRw.OnLoad();
}


/**
* void
*/
void CmcRwMvc::doSave_mcAcSys()
{
	CmcRwAcSys vRw;

	vRw.InitAdo(RwAdo);
	vRw.InitTable("mcAcSystem", mc_AcSys, mc_AcSys);
	vRw.InitGrid(pHvdc);

	vRw.OnSave();

}


void CmcRwMvc::doSave_mcAcFilter()
{
	CmcRwAcfilter vRw;

	vRw.InitAdo(RwAdo);
	vRw.InitTable("mcAcFilter", mc_AcF, mc_AcF);
	vRw.InitGrid(pHvdc);

	vRw.OnSave();

}



/**
* void
*/
void CmcRwMvc::doSave_mcXf2()
{
	CmcRwXf2 vRw;

	vRw.InitAdo(RwAdo);
	vRw.InitTable("mcTransformer", mc_Xf2, mc_Xf2);
	vRw.InitGrid(pHvdc);

	vRw.OnSave();
}


void CmcRwMvc::doSave_mcConvertor()
{
	CmcRwConvertor vRw;

	vRw.InitAdo(RwAdo);
	vRw.InitTable("mcConvertor", mc_Convertor, mc_Convertor);
	vRw.InitGrid(pHvdc);

	vRw.OnSave();
}

/**
* void
*/
void CmcRwMvc::doSave_mcDcLine()
{
	CmcRwDcLine vRw;

	vRw.InitAdo(RwAdo);
	vRw.InitTable("mcDcLine", mc_DcLine, mc_DcLine);
	vRw.InitGrid(pHvdc);

	vRw.OnSave();
}
/**
* void
*/
void CmcRwMvc::doSave_mcMetalLine()
{
	CmcRwMetalLine vRw;

	vRw.InitAdo(RwAdo);
	vRw.InitTable("mcMetalLine", mc_MetalLine, mc_MetalLine);
	vRw.InitGrid(pHvdc);

	vRw.OnSave();
}


/**
* void
*/
void CmcRwMvc::doSave_mcGroundLine()
{
	CmcRwGroundLine vRw;

	vRw.InitAdo(RwAdo);
	vRw.InitTable("mcGroundLine", mc_GroundLine, mc_GroundLine);
	vRw.InitGrid(pHvdc);

	vRw.OnSave();
}


void CmcRwMvc::doSave_mcGround()
{
	CmcRwGround vRw;

	vRw.InitAdo(RwAdo);
	vRw.InitTable("mcGround", mc_Ground, mc_Ground);
	vRw.InitGrid(pHvdc);

	vRw.OnSave();
}
