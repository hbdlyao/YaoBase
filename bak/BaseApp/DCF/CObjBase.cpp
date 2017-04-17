///////////////////////////////////////////////////////////
//  CObjBase.cpp
//  Implementation of the Class CObjBase
//  Created on:      02-4ÔÂ-2017 15:16:13
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CObjBase.h"

#include "CMyFunc.h"


CObjBase::CObjBase()
{
	Init();
}

CObjBase::~CObjBase()
{
	Clear();
}


void CObjBase::Init()
{
	//objGUID = CMyFunc::CreateObjID();
	//
}

void CObjBase::Clear()
{

}


unsigned long CObjBase::GetObjGUID(){

	return objGUID;
}


void CObjBase::SetObjGUID(unsigned long newVal){

	objGUID = newVal;
}