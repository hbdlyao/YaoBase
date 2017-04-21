///////////////////////////////////////////////////////////
//  CxbU3PData.h
//  
//  Created on:      12-4ÔÂ-2017 17:56:23
//  Original author: Âí¿¥Åô
///////////////////////////////////////////////////////////

#pragma once

#include <string>
#include <map>
#include "CMydefs.h"
using namespace std;

struct struct_xbU3PData
{
public:
	string CaseID;

	string PowLevel;

	double * Urms =nullptr;
	double * Angle = nullptr;

	double * Ire = nullptr;
	double * Iim = nullptr;

	double * Yb = nullptr;

};


typedef map<string, struct_xbU3PData *> pxbU3PData_Map;
typedef map<string, pxbU3PData_Map *> pxbU3PPowPre_Map;

