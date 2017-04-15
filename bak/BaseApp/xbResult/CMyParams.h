#pragma once

#include <string>

using namespace std;

class CMyParams
{
protected:
	CMyParams(const CMyParams& theInstance) {};

	CMyParams() {};
	~CMyParams() {}
	
	//
	static void getExeFilePath();;
public:
	static void Init();
	//
	static string ExeFilePath;
	static string PRJFile;
	static string dbf_mdb;

};




