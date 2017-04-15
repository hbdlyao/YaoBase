

#include "gbHead_SysVar.h"

#include "gbHead_Var.h"
#include "gbHead_Def.h"

#include "CmcSolveMvc.h"
#include "CPowerSolveMvc.h"

#include <iostream>


void PowerCalculate()
{ 
	CPowerSolveMvc * vMvc;

	vMvc = new CPowerSolveMvc();
	vMvc->Init();
	vMvc->Init(CHvdcVars::pmcHvdcGrid);

	vMvc->NodeID();

	delete vMvc;

}

void mcCalculate()
{
	CmcSolveMvc * vMvc;

	//
	vMvc = new CmcSolveMvc();
	vMvc->Init();
	vMvc->Init(CHvdcVars::pmcHvdcGrid);

	vMvc->Run();

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
	CxbSolveMvc * vMvc;

	//
	vMvc = new CxbSolveMvc();
	vMvc->Init();
	vMvc->Init(CHvdcVars::pxbHvdcGrid);

	vMvc->Run();

	delete vMvc;

}

int main()
{
	//CMyInitApp::->Init();

	CHvdcInitApp::Init();
	CHvdcInitApp::Open();

	//
	//mcCalculateNormal();

	//mcCalculate();

	xbCalculate();

	//
	CHvdcInitApp::Exit();
        
	//
	cout << "End" << endl;

	system("pause"); 

}

