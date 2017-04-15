///////////////////////////////////////////////////////////
//  CmcDevBase.cpp
//  Implementation of the Class CmcDevBase
//  Created on:      13-4月-2017 13:15:15
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CmcDevBase.h"



/**
 * 所属拓扑类型
 * 
 * 单极大地
 * 单极金属
 * 双极
 */
string CmcDevBase::GettpFlag(){

	return tpFlag;
}


/**
 * 所属拓扑类型
 * 
 * 单极大地
 * 单极金属
 * 双极
 */
void CmcDevBase::SettpFlag(string newVal){

	tpFlag = newVal;
}