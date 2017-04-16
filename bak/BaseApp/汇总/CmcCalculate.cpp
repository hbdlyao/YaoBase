///////////////////////////////////////////////////////////
//  CmcCalculate.cpp
//  Implementation of the Class CmcCalculate
//  Created on:      02-4ÔÂ-2017 14:40:28
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CmcCalculate.h"


void CmcCalculate::Init(CPowerProfile * vProfile, CPowerGrid * vGrid)
{
	pProfile = vProfile;
	//pGrid = vGrid;

	pmcProfile = dynamic_cast<CmcProfile *> (pProfile);
	//pmcHvdc = dynamic_cast<CmcHvdcGrid *> (pGrid);

}


void CmcCalculate::CalConvertor()
{


}


void CmcCalculate::CalTap()
{


}


void CmcCalculate::CalConvertorNormal()
{

}


void CmcCalculate::CalTapNormal()
{

}


void CmcCalculate::InitX()
{


}


void CmcCalculate::UpdateY(){

}


void CmcCalculate::Prepare()
{

}


void CmcCalculate::UpdateJ(){

	//
}


void CmcCalculate::UpdateF_J(){

	//
}




void CmcCalculate::PrepareNormal(){

}