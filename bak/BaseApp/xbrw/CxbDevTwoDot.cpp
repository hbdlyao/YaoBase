///////////////////////////////////////////////////////////
//  CxbDevTwoDot.cpp
//  Implementation of the Class CxbDevTwoDot
//  Created on:      12-4��-2017 12:00:20
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbDevTwoDot.h"




void CxbDevTwoDot::Init(){

	SetDotCount(2);
}


/**
 * ����
 */
string CxbDevTwoDot::GetStationName1(){

	return StationName1;
}


string CxbDevTwoDot::GetStationName2(){

	return StationName2;
}


/**
 * ����
 */
void CxbDevTwoDot::SetStationName1(string newVal){

	StationName1 = newVal;
}


void CxbDevTwoDot::SetStationName2(string newVal){

	StationName2 = newVal;
}