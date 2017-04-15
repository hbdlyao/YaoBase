///////////////////////////////////////////////////////////
//  CmcResult.cpp
//  Implementation of the Class CmcResult
//  Created on:      03-4ÔÂ-2017 18:54:55
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CmcResult.h"



CmcResult::~CmcResult()
{
	Release();

}

void CmcResult::Release()
{

	Clear();

}

void CmcResult::Init()
{

	StaDim = 0;

	//
	//pmcStaData = nullptr;


}


void CmcResult::Clear()
{
	//delete[] pmcStaData;
	//pmcStaData = nullptr;
}


void CmcResult::InitMatrix()
{

//	int i, j;

	//pmcStaData = new struct_mcStation[StaDim];

}
