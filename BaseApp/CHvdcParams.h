#pragma once

#include <string>

using namespace std;

class CHvdcParams
{
protected:
	CHvdcParams(const CHvdcParams& theInstance) {};

	CHvdcParams() {};
	~CHvdcParams() {}

public:
	static void Init();
	//
	static int ProjectID;
	static string ProjectName;
	static int mcStationCount;
	static int xbStationCount;
};




