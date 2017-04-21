#pragma once

#include "CmcCalTwoDot.h"

/**
* 主回路换流变压器
*/
class CmcCalXf2 : public CmcCalTwoDot
{

public:
	//************************************
	// *南方电网主回路及谐波计算软件*
	// 改动对象:  
	// 改动者:    崔康生
	// 改动类型:  修改
	// 改动内容:  1.CalXf2_l至CalXf2_DownShift新增
	//            2.CalTap至CalTapNormal删除
	// 改动时间:  2017/04/18
	//************************************
	virtual void CalXf2_l();//网侧及变比已知（Uv、Nnorm、Tc）
	virtual void CalXf2_v();//阀侧及变比已知（Ul、Nnorm、TC）
	virtual void CalXf2_Port();//两侧端口及分接头已知（Ul、Uv、TC）
	virtual void CalXf2_UpShift();//网侧不变，上调一及分接头
	virtual void CalXf2_DownShift();//网侧不变，下调一及分接头
									//virtual void CalTap();
									//virtual void CalTapNormal();

	virtual void Prepare();
	virtual void PrepareNormal();
	//************************************
	// *南方电网主回路及谐波计算软件*
	// 改动对象:  PrepareNormal
	// 改动者:    崔康生
	// 改动类型:  新增
	// 改动内容:  1.存储额定值到Device中
	// 改动时间:  2017/04/18
	//************************************
	virtual void SaveNormal();

	virtual void NodeSort(NodeMap& vNodeMap);
	virtual void NodeID(NodeMap& vNodeID);
};
