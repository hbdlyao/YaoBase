///////////////////////////////////////////////////////////
//  CmcSolveMvc.cpp
//  Implementation of the Class CmcSolveMvc
//  Created on:      09-4月-2017 23:54:44
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CmcSolveMvc.h"

void CmcSolveMvc::Init()
{
	pSolves = new CmcSolves();
	pmcSolves= dynamic_cast<CmcSolves *> (pSolves);
	//

}

void CmcSolveMvc::Init(CPowerProfile * vProfile, CPowerGrid * vGrid)
{
	pProfile = vProfile;
	pGrid = vGrid;

	pmcProfile = dynamic_cast<CmcProfile *> (pProfile);
	pmcHvdc = dynamic_cast<CmcHvdcGrid *> (pGrid);

}

void CmcSolveMvc::doNewSolves(int vGNDType)
{
	pmcSolves->Clear();
	pmcSolves->NewSolves(vGNDType);
}


void CmcSolveMvc::Run(int vGNDType)
{
	pmcProfile->pmcOrder->GroundType = vGNDType;

	//
	pmcSolves->Init(pProfile, pGrid);
	//
	doNewSolves(vGNDType);

	//节点编号
	doNodeID();
	
	//变电站排序
	doStationSort();

	//
	doRun();

}


void CmcSolveMvc::NodeID(int vGNDType)
{
	pmcProfile->pmcOrder->GroundType = vGNDType;

	//
	pmcSolves->Init(pProfile, pGrid);
	//
	doNewSolves(vGNDType);

	//节点编号
	doNodeID();
	
}


void CmcSolveMvc::doRun()
{
	//
	pmcProfile->Clear();
	//
	pmcSolves->Run();
}

////////////////////////////////
void CmcSolvesMvcNormal::Init()
{

	pSolves = new CmcSolvesNormal();
	pmcSolves = dynamic_cast<CmcSolves *> (pSolves);

}