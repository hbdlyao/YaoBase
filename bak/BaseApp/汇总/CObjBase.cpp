///////////////////////////////////////////////////////////
//  CObjBase.cpp
//  Implementation of the Class CObjBase
//  Created on:      02-4��-2017 15:16:13
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
	objGUID = CMyFunc::CreateObjID();
	//
}

void CObjBase::Clear()
{

}


string CObjBase::GetObjGUID(){

	return objGUID;
}


void CObjBase::SetObjGUID(string newVal){

	objGUID = newVal;
}


