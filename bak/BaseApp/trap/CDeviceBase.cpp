///////////////////////////////////////////////////////////
//  CDeviceBase.cpp
//  Implementation of the Class CDeviceBase
//  Created on:      04-4��-2017 7:59:49
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CDeviceBase.h"


CDeviceBase::CDeviceBase()
{
	Init();
}


CDeviceBase::CDeviceBase(const CDeviceBase & theCDeviceBaseVo)
{

	Init();
}


CDeviceBase::~CDeviceBase()
{

	delete[] NodeIDs;  //ɾ���������͵�ָ��
	delete[] NodeNames;//ɾ���������͵�ָ��
}


string CDeviceBase::GetDeviceID()
{

	return DeviceID;
}


void CDeviceBase::SetDeviceID(string newVal)
{
	DeviceID = newVal;
	
	//objGUID = newVal; ?
}


string CDeviceBase::GetDeviceName()
{

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


void CDeviceBase::SetNodeID(int vIndex, int vID){

	NodeIDs[vIndex] = vID;
}


string CDeviceBase::GetStationName(){

	return StationName;
}


void CDeviceBase::SetStationName(string newVal){

	StationName = newVal;
}


void CDeviceBase::Init(){

}


int CDeviceBase::GetdotCount(){

	return dotCount;
}


void CDeviceBase::SetdotCount(int newVal){

	dotCount = newVal;
}


void CDeviceBase::ClearNodeID()
{
	for (int i = 0; i < GetDotCount(); i++)
	{
		SetNodeID(i, -2);
	}//for i

}


void CDeviceBase::NodeSort(NodeMap& vNodeMap)
{
	int i, vN, vID;
	string vName;

	for (i = 0; i < GetDotCount(); i++)
	{
		vName = GetNodeName(i);
		vN = static_cast<int > (vNodeMap.count(vName));

		if (vN == 0)
		{//������ vName
			vID = static_cast<int> (vNodeMap.size());
			vNodeMap[vName] = vID;
		}

	}//for i

}


void CDeviceBase::NodeGround(NodeMap& vNodeMap)
{

}

void CDeviceBase::NodeID(NodeMap & vNodeID)
{
	int i, vID;
	string vName;

	for (i = 0; i < GetDotCount(); i++)
	{
		vName = GetNodeName(i);
		vID = vNodeID[vName];

		SetNodeID(i, vID);

	}//for i

}

