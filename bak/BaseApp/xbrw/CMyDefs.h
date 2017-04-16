#pragma once

#include <string>
#include <vector>
#include <map>


//Բ����
#define PI 3.141592653589793


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



//���������͵�Vector����
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

