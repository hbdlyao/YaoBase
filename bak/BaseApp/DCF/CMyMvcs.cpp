///////////////////////////////////////////////////////////
//  CMyMvcs.cpp
//  Implementation of the Class CMyMvcs
//  Created on:      22-3��-2017 17:20:04
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CMyParams.h"
#include "CMyMvcs.h"

//

CRwDbf CMyMvcs::RwMvc;
//
void CMyMvcs::Release()
{
	//RwMvc.
}


void CMyMvcs::Clear()
{

}


void CMyMvcs::Init()
{
	RwMvc.InitAdo(CMyParams::dbf_mdb);
}


