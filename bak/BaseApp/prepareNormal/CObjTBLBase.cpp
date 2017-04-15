///////////////////////////////////////////////////////////
//  CObjTBLBase.cpp
//  Implementation of the Class CObjTBLBase
//  Created on:      02-4ÔÂ-2017 15:15:25
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CObjTBLBase.h"


CObjTBLBase::CObjTBLBase()
{
	Init();
}


CObjTBLBase::~CObjTBLBase()
{
	Release();
}

void CObjTBLBase::Init()
{
	tblName = "CObjTBLBase.tblname";
	tblType = -1;
}

void CObjTBLBase::Release()
{
	Clear();
}

void CObjTBLBase::Clear()
{

	//ItemsVect
	for each (CObjBase * vObj in ItemsVect)
	{
		delete vObj;

		vObj = nullptr;

	}

	ItemsVect.clear();
	ItemsMap.clear();

	/*
	for each (pObj_Pair vPair in ItemsMap)
	{
	delete vPair.second;

	vPair.second = nullptr;
	}

	ItemsMap.clear();
	*/
}



void CObjTBLBase::ItemAdd(string vID,CObjBase* vItem)
{
	ItemsVect.push_back(vItem);
	ItemsMap[vID] = vItem;
}


void CObjTBLBase::ItemRemove(CObjBase* vItem){

	//pItems.erase(vItem.GetObjName());
}


void CObjTBLBase::ItemRemove(int vItem){

	//pItems.erase(vItem.GetObjName());
}


void CObjTBLBase::ItemRemove(string vName){

	//pItems.erase(vItem.GetObjName());
}


string CObjTBLBase::TypeToName(){

	return  TypeToName(tblType);
}


int CObjTBLBase::GetItemCount(){

	return static_cast<int > (ItemsVect.size());
	
	///ItemCount;
}


pObjMap CObjTBLBase::GetItems(){

	return ItemsMap;
}


string CObjTBLBase::GetTblName(){

	return tblName;
}


void CObjTBLBase::SetTblName(string newVal){

	tblName = newVal;
}


int CObjTBLBase::GetTblType(){

	return tblType;
}


void CObjTBLBase::SetTblType(int newVal){

	tblType = newVal;
}


CObjBase * CObjTBLBase::Item(int vIndex)
{
	return ItemsVect[vIndex];
}


CObjBase * CObjTBLBase::Item(string vName){

	return ItemsMap[vName];
}

