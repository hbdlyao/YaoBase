

#include "gbHead_SysVar.h"

#include "gbHead_Var.h"
#include "gbHead_Def.h"

#include "CmcSolveMvc.h"
#include "CPowerSolveMvc.h"

#include <iostream>


void mcNodeID(int vGnd)
{ 
	CmcSolveMvc * vMvc;

	vMvc = new CmcSolveMvc();
	vMvc->Init();
	vMvc->Init(CHvdcVars::pmcHvdcGrid);
	vMvc->InitOrder();

	vMvc->NodeID(vGnd);

	delete vMvc;

}


void xbNodeID(int vGnd)
{
	CxbSolveMvc * vMvc;

	vMvc = new CxbSolveMvc();
	vMvc->Init();
	vMvc->Init(CHvdcVars::pxbHvdcGrid);
	vMvc->InitOrder();

	vMvc->NodeID(vGnd);

	delete vMvc;

}



void mcCalculate()
{
	CmcSolveMvc * vMvc;
	
	//
	vMvc = new CmcSolveMvc();
	vMvc->Init();
	vMvc->Init(CHvdcVars::pmcHvdcGrid);	
	vMvc->InitOrder();

	vMvc->Run();

	//vMvc->NodeID(xb_Ground10);

	delete vMvc;


}

void mcCalculateNormal()
{
	CmcSolveMvc * vMvc;

	//
	vMvc = new CmcSolveMvcNormal();
	vMvc->Init();
	vMvc->Init(CHvdcVars::pmcHvdcGrid);

	vMvc->Run();

	delete vMvc;

}

void xbCalculate()
{	
	//
	CxbSolveMvc * vMvc;

	//
	vMvc = new CxbSolveMvc();
	vMvc->Init();
	vMvc->Init(CHvdcVars::pxbHvdcGrid);
	//vMvc->InitOrder();

	vMvc->Run();

	//
	delete vMvc;


}

int main()
{
	//CMyInitApp::->Init();

	CHvdcInitApp::Init();
	
	CHvdcInitApp::Open();

	
	///////////////////////////////////////////

	//CHvdcMvcs::pmcRwMvc->OnLoad();
	//mcNodeID(mc_Ground11);
	//mcCalculateNormal();
	//mcCalculate();
	//CHvdcMvcs::pmcRwMvc->OnSave();

	///////////////////////////////////////////
	CHvdcMvcs::pxbRwMvc->OnLoad();
	
	xbNodeID(xb_Ground10);

	//xbCalculate();
	
	//CHvdcMvcs::pxbRwMvc->OnSave();

	/////////////////////////
	CHvdcInitApp::Exit();
        
	//
	cout << "End" << endl;

	system("pause"); 

}

