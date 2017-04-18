///////////////////////////////////////////////////////////
//  CxbRwMvc.cpp
//  Implementation of the Class CxbRwMvc
//  Created on:      18-4ÔÂ-2017 18:50:05
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbRwMvc.h"
#include "gbHead_xbRw.h"


void CxbRwMvc::InitGrid(CxbHvdcGrid* vHvdc)
{

	pHvdc = vHvdc;
}


void CxbRwMvc::InitAdo(string vDbf)
{
	dbfName = vDbf;
	
	RwAdo = new CRwAdo_Access();
	RwAdo->InitDbf(dbfName, "", "", "false");
}


void CxbRwMvc::doLoad()
{

	doLoad_xb3pVSrc();
	
	doLoad_xbPbDKQ();
	doLoad_xbDcF();
	
	doLoad_xbDcLine();
	doLoad_xbGroundLine();
	doLoad_xbMetalLine();
	
	doLoad_xbGround();
	doLoad_xbXfC();
	doLoad_xbCoupleC();
	doLoad_xbPulseC();
	doLoad_xbShunt();
	doLoad_xbBranch();
	
	//
	doLoad_xbMonitor();
	
}


void CxbRwMvc::doSave()
{

	doSave_xb3pVSrc();
	
	doSave_xbPbDKQ();
	doSave_xbDcF();
	
	doSave_xbDcLine();
	doSave_xbGroundLine();
	doSave_xbMetalLine();
	
	doSave_xbGround();
	
	doSave_xbXfC();
	doSave_xbCoupleC();
	doSave_xbPulseC();
	
	doSave_xbShunt();
	doSave_xbBranch();
	
	doSave_xbMonitor();
	
}


void CxbRwMvc::doLoad_xb3pVSrc()
{
	CxbRw3pVSrc vRw;

	vRw.InitAdo(RwAdo);
	vRw.InitTable("xb3pVsrc",xb_3pVSrc,xb_3pVSrc);
	vRw.InitGrid(pHvdc);

	vRw.OnLoad();

}


void CxbRwMvc::doLoad_xbPbDKQ()
{
	CxbRwBranch vRw;

	vRw.InitAdo(RwAdo);
	vRw.InitTable("xbPbDKQ", xb_PbDKQ, xb_PbDKQ);
	vRw.InitGrid(pHvdc);

	vRw.OnLoad();
	
}


void CxbRwMvc::doLoad_xbDcF()
{


}


void CxbRwMvc::doLoad_xbDcLine()
{

}


void CxbRwMvc::doLoad_xbGroundLine()
{

}


void CxbRwMvc::doLoad_xbMetalLine()
{

}


void CxbRwMvc::doLoad_xbGround()
{
	CxbRwShunt vRw;

	vRw.InitAdo(RwAdo);
	vRw.InitTable("xbGround", xb_Ground, xb_Ground);
	vRw.InitGrid(pHvdc);

	vRw.OnLoad();
}


void CxbRwMvc::doLoad_xbXfC()
{
	CxbRwShunt vRw;

	vRw.InitAdo(RwAdo);
	vRw.InitTable("xbXf_C", xb_XfC, xb_XfC);
	vRw.InitGrid(pHvdc);

	vRw.OnLoad();
}


void CxbRwMvc::doLoad_xbCoupleC()
{
	CxbRwShunt vRw;

	vRw.InitAdo(RwAdo);
	vRw.InitTable("xbCouple_C", xb_CoupleC, xb_CoupleC);
	vRw.InitGrid(pHvdc);

	vRw.OnLoad();
}


void CxbRwMvc::doLoad_xbPulseC()
{
	CxbRwShunt vRw;

	vRw.InitAdo(RwAdo);
	vRw.InitTable("xbPulse_C", xb_PulseC, xb_PulseC);
	vRw.InitGrid(pHvdc);

	vRw.OnLoad();

}


void CxbRwMvc::doLoad_xbShunt()
{
	CxbRwShunt vRw;

	vRw.InitAdo(RwAdo);
	vRw.InitTable("xbShunt", xb_Shunt, xb_Shunt);
	vRw.InitGrid(pHvdc);

	vRw.OnLoad();

}


void CxbRwMvc::doLoad_xbBranch()
{
	CxbRwBranch vRw;

	vRw.InitAdo(RwAdo);
	vRw.InitTable("xbBranch", xb_Branch, xb_Branch);
	vRw.InitGrid(pHvdc);

	vRw.OnLoad();
}


void CxbRwMvc::doLoad_xbMonitor(){

}


void CxbRwMvc::doSave_xb3pVSrc()
{

}


void CxbRwMvc::doSave_xbPbDKQ() {

}


void CxbRwMvc::doSave_xbDcF() {

}


void CxbRwMvc::doSave_xbDcLine() {

}


void CxbRwMvc::doSave_xbGroundLine() {

}


void CxbRwMvc::doSave_xbMetalLine() {

}


void CxbRwMvc::doSave_xbGround() {

}


void CxbRwMvc::doSave_xbXfC() {

}


void CxbRwMvc::doSave_xbCoupleC() {

}


void CxbRwMvc::doSave_xbPulseC() {

}


void CxbRwMvc::doSave_xbShunt() {

}


void CxbRwMvc::doSave_xbBranch() {

}


void CxbRwMvc::doSave_xbMonitor() {

}