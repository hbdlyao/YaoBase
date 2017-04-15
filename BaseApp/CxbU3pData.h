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
struct CxbU3PData
{
public:
	string ConMethod;

	string PowLevel;

	double * Voltage;

	double * Phase;

	double Z_L;

};

typedef map<string, CxbU3PData *> pxbU3PData_Map;
typedef map<string, pxbU3PData_Map *> pxbU3PPowPre_Map;

