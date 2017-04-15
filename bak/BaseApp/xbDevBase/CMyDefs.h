#pragma once

#include <string>
#include <vector>
#include <map>

//圆周率
#define PI 3.141592653589793

//计算谐波次数
#define H_CAL_NUM 60

using namespace std;

enum Enum_appState
{
	app_Start = 0,
	app_Logon   ,
	app_Waiting ,
	app_New  ,
	app_Open ,
	app_Edit, 
	app_Close,
	app_Exit,
	app_Closing

};



//各基本类型的Vector容器
typedef vector<float> floatVector;
typedef vector<double> doubleVector;
typedef vector<int> intVector;
typedef vector<unsigned int> uintVector;

//typedef vector<string> stringVector;

typedef vector<string> StrVector;
typedef vector<StrVector> Str2Array;
typedef vector<StrVector> StrTable;

//
typedef vector<intVector> intMatrix;
typedef vector<doubleVector> dbMatrix;


//map
typedef map<string, int> NodeMap;
typedef map<string, int> StationMap;

