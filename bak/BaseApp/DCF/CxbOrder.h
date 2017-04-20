///////////////////////////////////////////////////////////
//  CxbOrder.h
//  Implementation of the Class CxbOrder
//  Created on:      05-4月-2017 18:22:10
//  Original author: Administrator
///////////////////////////////////////////////////////////

#if !defined(EA_06889A3F_2BCF_4c6b_8051_6C5BCC4067F9__INCLUDED_)
#define EA_06889A3F_2BCF_4c6b_8051_6C5BCC4067F9__INCLUDED_

#include "CmcOrder.h"

#include <string>

using namespace std;

class CxbOrder : public CmcOrder
{
public:
	//马骏鹏
	string GroundStaiton;
	//马骏鹏
	//滤波器偏差类型
	int DCFDevType;
	int DCFRandTimes;
	void Init();
	/**
	 * 南方电网主回路及谐波计算软件* 改动对象:  CreateCaseID 改动者:    崔康生 改动类型:  新增 改动内容:  1.
	 * 根据Order里保存的单工况生成工况代码 改动时间:  2017/04/13
	 */
	string CreateCaseID();


};
#endif // !defined(EA_06889A3F_2BCF_4c6b_8051_6C5BCC4067F9__INCLUDED_)
