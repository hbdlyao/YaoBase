///////////////////////////////////////////////////////////
//  CxbDevBase.cpp
//  Implementation of the Class CxbDevBase
//  Created on:      12-4月-2017 14:00:36
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbDevBase.h"


/**
 * 所属拓扑类型  单极大地 单极金属 双极
 */
int CxbDevBase::GetPosOrNeg()
{
	return PosOrNeg;
}


/**
 * 所属拓扑类型  单极大地 单极金属 双极
 */
void CxbDevBase::SetPosOrNeg(int newVal){

	PosOrNeg = newVal;
}


void CxbDevBase::Add(CxbDevBase * vItem)
{

}


void CxbDevBase::Remove(CxbDevBase * vItem)
{

}