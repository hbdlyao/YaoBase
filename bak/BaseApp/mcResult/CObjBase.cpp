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
	Release();
}


void CObjBase::Init()
{
	objGUID = CMyFunc::CreateObjID();
	//
}


void CObjBase::Release()
{
	Clear();
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


