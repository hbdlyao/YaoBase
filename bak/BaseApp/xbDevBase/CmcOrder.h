#pragma once

#include <string>

using namespace std;

class CmcOrder
{

public:
	//DFBFH22 : 

	string Flag_Pulse = "11";   //双阀/单阀
	string Flag_Ground= "1111";  //双极/金属回线/单极大地/双极并联
	string Flag_Ud    = "1111";  //全压/80%/70%/预设
	string Flag_Rd    = "11";    //高阻/低阻
	string Flag_Uac   = "1111";  //额定/最大/最小/极小

	/**
	 * 接地形式：单极大地/单极金属/双极
	 */
	int GroundType;
	/**
	 * 直流电压：全压/80%/70%/预设
	 */
	int UdLevel;
	/**
	 * 直流线路：高阻/低阻
	 */
	int RdLevel;
	/**
	 * 交流系统电压：额定/最大/最小/极小
	 */
	int UacLevel;
	/**
	 * 交流系统电压：是否交叉
	 */
	int UacSwap;
	/**
	 * 不平衡工况
	 */
	int Unbalance;
	/**
	 * 每极12脉动换流器数：1/2
	 */
	int Nof12pulse;

	~CmcOrder();

	void Init();
	void Clear();
	void Release();

};
