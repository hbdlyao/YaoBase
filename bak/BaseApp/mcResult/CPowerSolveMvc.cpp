///////////////////////////////////////////////////////////
//  CPowerSolveMvc.cpp
//  Implementation of the Class CPowerSolveMvc
//  Created on:      09-4月-2017 21:45:59
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CPowerSolveMvc.h"


CPowerSolveMvc::~CPowerSolveMvc()
{
	Release();
}


void CPowerSolveMvc::Clear()
{
	pSolves->Clear();

	pProfile->Clear();
}


void CPowerSolveMvc::Release()
{
	Clear();
	//
	delete pSolves;
	pSolves = nullptr;

	//
	delete pProfile;
	pProfile = nullptr;

}


void CPowerSolveMvc::Init()
{
	pSolves = new CPowerSolves();

	pProfile = new CPowerProfile();
	pProfile->Init();

}

void CPowerSolveMvc::Init(CPowerGrid * vGrid)
{
	pGrid = vGrid;

	//
	pSolves->Init(pProfile, pGrid);

}


void CPowerSolveMvc::NodeID()
{
	//
	pSolves->Init(pProfile, pGrid);
	//
	doNewSolves();
	
	//节点编号
	doNodeID();
}


void CPowerSolveMvc::Run()
{
	//
	pSolves->Init(pProfile, pGrid);
	//
	doNewSolves();

	//节点编号
	doNodeID();

	//
	doStationSort();

	//
	doRun();
}


void CPowerSolveMvc::doRun()
{
	//
	pProfile->ClearData();
	//
	pSolves->Run();
}


void CPowerSolveMvc::doNewSolves()
{
	pSolves->Clear();
	pSolves->NewSolves();
}


void CPowerSolveMvc::doNodeID()
{
	pSolves->NodeID();
}


void CPowerSolveMvc::doStationSort()
{
	pSolves->StationSort();
}

