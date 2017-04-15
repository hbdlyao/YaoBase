///////////////////////////////////////////////////////////
//  CxbOrder.h
//  Implementation of the Class CxbOrder
//  Created on:      05-4月-2017 18:22:10
//  Original author: Administrator
///////////////////////////////////////////////////////////

#if !defined(EA_06889A3F_2BCF_4c6b_8051_6C5BCC4067F9__INCLUDED_)
#define EA_06889A3F_2BCF_4c6b_8051_6C5BCC4067F9__INCLUDED_
#include <string>
using namespace std;

class CxbOrder
{

public:
	/**
	* 双极/金属回线/单极大地/双极并联
	*/
	string Flag_Ground;

	/**
	* 接地形式：单极大地/单极金属/双极
	*/
	int GroundType;
	//马骏鹏
	string GroundStaiton;
	//马骏鹏
	//滤波器偏差类型
	int DCFDevType;
	int DCFRandTimes;

	~CxbOrder();
	void Init();
	void Clear();
	void Release();

};
#endif // !defined(EA_06889A3F_2BCF_4c6b_8051_6C5BCC4067F9__INCLUDED_)
