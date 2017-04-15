
#include "CHvdcDefs.h"

#include "gbHead_SysVar.h"
#include "gbHead_Var.h"

#include "CmcSolveMvc.h"
#include "CPowerSolveMvc.h"

#include <iostream>

void PowerCalculate()
{ 
	CPowerSolveMvc * vMvc;

	CPowerProfile * vProfile = new CPowerProfile();
	vProfile->Init();
	
	vMvc = new CPowerSolveMvc();
	vMvc->Init(vProfile, CHvdcVars::pmcHvdcGrid);

	vMvc->NodeID();


	delete vProfile;
	delete vMvc;

}

void mcCalculate()
{
	CmcProfile * vProfile;
	CmcSolveMvc * vMvc;

	vProfile = new CmcProfile();
	vProfile->Init();

	//
	vMvc = new CmcSolveMvc();
	vMvc->Init();
	vMvc->Init(vProfile, CHvdcVars::pmcHvdcGrid);

	vMvc->Run(mc_Ground11);


	delete vProfile;
	delete vMvc;

}


void xbCalculate()
{	
	CxbProfile * vProfile;
	CxbSolveMvc * vMvc;

	vProfile = new CxbProfile();
	vProfile->Init();

	//
	vMvc = new CxbSolveMvc();
	vMvc->Init();
	vMvc->Init(vProfile, CHvdcVars::pxbHvdcGrid);

	vMvc->Run(xb_Ground11);

	delete vProfile;
	delete vMvc;

}

int main()
{
	int vx;
	//CMyInitApp::->Init();

	CHvdcInitApp::Init();
	CHvdcInitApp::Open();

	//
	mcCalculate();

	xbCalculate();

	//
	CHvdcInitApp::Exit();
        
	//
	cout << "End" << endl;

	cin >> vx ;

}