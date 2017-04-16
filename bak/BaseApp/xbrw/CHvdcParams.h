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
	static string tbl_AcSys;
	static string tbl_AcF;
	static string tbl_Xf2;
	static string tbl_Convertor;
	static string tbl_DcLine;
	static string tbl_MetalLine;
	static string tbl_GroundLine;
	static string tbl_Ground;

	//
	static int ProjectID;
	static string ProjectName;
	static int StationCount;
		
};




