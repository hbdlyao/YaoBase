///////////////////////////////////////////////////////////
//  CDeviceBase.cpp
//  Implementation of the Class CDeviceBase
//  Created on:      19-4月-2017 18:00:43
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CDeviceBase.h"




CDeviceBase::CDeviceBase(){

	Init();
}


CDeviceBase::CDeviceBase(const CDeviceBase& theCDeviceBaseVo){

	Init();
}


CDeviceBase::~CDeviceBase(){

	delete[] NodeIDs;  //删除数组类型的指针
	delete[] NodeNames;//删除数组类型的指针
}


void CDeviceBase::Init(){

}


bool CDeviceBase::IsLeaf(){

	return true;
}


void CDeviceBase::Add(CDeviceBase* vItem){

}


void CDeviceBase::Remove(CDeviceBase* vItem){

}


string CDeviceBase::GetDeviceID(){

	return DeviceID;
}


void CDeviceBase::SetDeviceID(string newVal){

	DeviceID = newVal;
	
	//objGUID = newVal; ?
}


string CDeviceBase::GetDeviceName(){

	return DeviceName;
}


void CDeviceBase::SetDeviceName(string newVal){

	DeviceName = newVal;
	
	//objName = newVal;
}


int CDeviceBase::GetDeviceType(){

	return DeviceType;
}


void CDeviceBase::SetDeviceType(int newVal){

	DeviceType = newVal;
	
	//objType = newVal;
}


int CDeviceBase::GetDotCount(){

	return dotCount;
}


void CDeviceBase::SetDotCount(int newVal){

	dotCount = newVal;
	
	NodeIDs   = new int[newVal];
	NodeNames = new string[newVal];
	
	for (int i = 0; i < dotCount; i++)
	{
		NodeIDs[i] = -2;
		NodeNames[i] = "NodeNames";
	
	}
}


string CDeviceBase::GetNodeName(int vIndex){

	return  NodeNames[vIndex];
}


void CDeviceBase::SetNodeName(int vIndex, string vName){

	NodeNames[vIndex] = vName;
}


int CDeviceBase::GetNodeID(int vIndex){

	return  NodeIDs[vIndex];
}


void CDeviceBase::SetNodeID(int vIndex, int vID)
{
	NodeIDs[vIndex] = vID;
}

string CDeviceBase::BusName(int vIndex)
{	
	string vBus;

	//vBus = DeviceName + "--" + GetNodeName(vIndex);

	vBus =GetNodeName(vIndex);

	return vBus;

}


string CDeviceBase::GetStationName(){

	return StationName;
}


void CDeviceBase::SetStationName(string newVal){

	StationName = newVal;
}


void CDeviceBase::ClearNodeID(){

	for (int i = 0; i < GetDotCount(); i++)
	{
		SetNodeID(i, -2);
	}//for i
}

void CDeviceBase::NodeSort(NodeMap& vNodeMap)
{

	int i, vN, vID;
	string vBus;
	
	for (i = 0; i < GetDotCount(); i++)
	{
		vBus = BusName(i);
		vN = static_cast<int > (vNodeMap.count(vBus));
	
		if (vN == 0)
		{//不存在 vName
			vID = static_cast<int> (vNodeMap.size());
			vNodeMap[vBus] = vID;
		}
	
	}//for i
}


void CDeviceBase::NodeGround(NodeMap& vNodeMap)
{
	int i;
	string vBus;

	for (i = 0; i < GetDotCount(); i++)
	{
		vBus = BusName(i);
		if (vBus == "-1")//-1表示接地
			vNodeMap[vBus] = -1;

	}//for i
}


void CDeviceBase::NodeID(NodeMap& vNodeID)
{

	int i, vID;
	string vBus;
	
	for (i = 0; i < GetDotCount(); i++)
	{
		vBus = BusName(i);
		vID = vNodeID[vBus];
	
		SetNodeID(i, vID);
	
	}//for i
}