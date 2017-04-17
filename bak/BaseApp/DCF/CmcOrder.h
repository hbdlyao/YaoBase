#pragma once

#include <string>
#include <stdlib.h>
#include <vector>
#include "CHvdcDefs.h"
using namespace std;
//************************************
// *南方电网主回路及谐波计算软件*
// 改动对象:  CmcOrder
// 改动者:    崔康生
// 改动类型:  修改
// 改动内容:  1.重新设计了数据成员
//            2.
// 改动时间:  2017/04/12
//************************************
class CmcOrder
{
public:
	virtual ~CmcOrder();

	void Init();
	void InitNormal();

	void Clear();

public:
	int StaCount = 0;

	//"DFBFH22" : 双阀，正向，双极，全压，高阻，两侧交流电压为额定


	//要计算的全部工况，来自输入
	int nValNum = 1;   //阀组数
	string Flag_Ground = "1111";  //单极大地/金属回线/双极/双极并联
	string Flag_Ud = "111";  //全压/80%/70%
	string Flag_Rd = "11";   //高阻/低阻（额定）
	string Flag_Uac = "1111";  //额定/最大/最小/极小
	bool IsUdCustom = false;//直流电压预设情况，如预设则使用UdCustom作为电压指令，否则使用UdLevel
	bool IsUacSwap  = false;//是否交流电压交叉
	bool IsUdToGround = false;//直流电压对地或对中性线
							  //string Flag_IsPdSingle = "0";//是否单功率水平，该成员可以不要，当成员BdSize取值为1时即为但功率水平
	double PdStartPer = 10;//起始功率水平
	double PdIncrePer = 5;//功率水平增量
	int PdSize = 29;//功率水平数

					//从全部工况中选取的某一确定工况
					/**
					* 接地形式：单极大地/单极金属/双极
					*/
	int GroundType;
	/**
	* 直流电压：全压/80%/70%
	*/
	int UdLevel;
	/**
	* 直流线路：高阻/低阻
	*/
	int RdLevel;
	/**
	* 各站交流系统电压：额定/最大/最小/极小
	*/
	vector<int> UacLevel;
	/**
	* 直流电压预设值
	*/
	double UdCustom;
	/**
	* 功率水平
	*/
	double PdPer;

public:
	void UpdatePdPercent(int & vPdSize);
	int CaseCount();

	//************************************
	// *南方电网主回路及谐波计算软件*
	// 改动对象:  InitMatrix
	// 改动者:    崔康生
	// 改动类型:  新增
	// 改动内容:  1.用于初始化UacLevel
	// 改动时间:  2017/04/13
	//************************************
	void InitMatrix(int vStaDim);
	//************************************
	// *南方电网主回路及谐波计算软件*
	// 改动对象:  CreateCaseID
	// 改动者:    崔康生
	// 改动类型:  新增
	// 改动内容:  1.根据Order里保存的单工况生成工况代码
	// 改动时间:  2017/04/13
	//************************************
	string CreateCaseID();
};