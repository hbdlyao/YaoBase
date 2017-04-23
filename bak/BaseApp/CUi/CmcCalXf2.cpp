///////////////////////////////////////////////////////////
//  CmcCalXf2.cpp
//  Implementation of the Class CmcCalXf2
//  Created on:      02-4月-2017 14:41:57
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CmcCalXf2.h"
#include "CmcDevXf2.h"

/**
 * 网侧不变，下调一及分接头 virtual void CalTap(); virtual void CalTapNormal();
 */
void CmcCalXf2::Prepare()
{
	int vK = 0;
	CmcDevXf2 * vDev;

	vK = StationIndex;
	vDev = dynamic_cast<CmcDevXf2 *>(pDevice);

	//实际值
	//参数
	pmcProfile->pmcStaData[vK].AngCtrl_Max = vDev->GetAngleMax();
	pmcProfile->pmcStaData[vK].AngCtrl_Min = vDev->GetAngleMin();
	pmcProfile->pmcStaData[vK].Uv = vDev->GetFixedURef()*vDev->GetUvN();
	pmcProfile->pmcStaData[vK].Tap_Max = vDev->GetTapMax();
	pmcProfile->pmcStaData[vK].Tap_Min = vDev->GetTapMin();
	pmcProfile->pmcStaData[vK].deltaK = vDev->GetTapSetup();
	pmcProfile->pmcStaData[vK].Uv_Max = vDev->GetUvMax()*vDev->GetUvN();
	pmcProfile->pmcStaData[vK].dx = vDev->GetUkp() / 2.0;
	pmcProfile->pmcStaData[vK].dr = vDev->GetUrp();
	pmcProfile->pmcStaData[vK].Nnom = vDev->GetTkN();
	pmcProfile->pmcStaData[vK].TC = vDev->GetTapN();
}


//************************************
// *南方电网主回路及谐波计算软件*
// 改动对象:  PrepareNormal
// 改动者:    崔康生
// 改动类型:  修改
// 改动内容:  1.完成了数据填充功能
// 改动时间:  2017/04/17
//************************************
void CmcCalXf2::PrepareNormal()
{
	int vK = 0;
	CmcDevXf2 * vDev;

	vK = StationIndex;
	vDev = dynamic_cast<CmcDevXf2 *>(pDevice);

	//额定值
	pmcProfile->pmcStaDataN[vK].AngCtrl_Max = vDev->GetAngleMax();
	pmcProfile->pmcStaDataN[vK].AngCtrl_Min = vDev->GetAngleMin();
	pmcProfile->pmcStaDataN[vK].Tap_Max = vDev->GetTapMax();
	pmcProfile->pmcStaDataN[vK].Tap_Min = vDev->GetTapMin();
	pmcProfile->pmcStaDataN[vK].TC = vDev->GetTapN();
	pmcProfile->pmcStaDataN[vK].deltaK = vDev->GetTapSetup();
	pmcProfile->pmcStaDataN[vK].Nnom = vDev->GetTkN();
	pmcProfile->pmcStaDataN[vK].dx = vDev->GetUkp() / 2.0;
	pmcProfile->pmcStaDataN[vK].dr = vDev->GetUrp();
	pmcProfile->pmcStaDataN[vK].Uv = vDev->GetUvN();
	pmcProfile->pmcStaDataN[vK].Uv_Max = 10000;

}
/**
 * 南方电网主回路及谐波计算软件* 改动对象:  PrepareNormal 改动者:    崔康生 改动类型:  新增 改动内容:  1.
 * 存储额定值到Device中 改动时间:  2017/04/18
 */
void CmcCalXf2::SaveNormal()
{
	int vK = 0;
	CmcDevXf2 * vDev;

	vDev = dynamic_cast<CmcDevXf2 *>(pDevice);
	vK = StationIndex;

	vDev->SetTapN(pmcProfile->pmcStaData[vK].TC);
	vDev->SetTkN(pmcProfile->pmcStaData[vK].Nnom);
	vDev->SetUvN(pmcProfile->pmcStaData[vK].Uv);
}

/**
 * 南方电网主回路及谐波计算软件* 改动对象: 改动者:    崔康生 改动类型:  修改 改动内容:  1.
 * CalXf2_l至CalXf2_DownShift新增 2.CalTap至CalTapNormal删除 改动时间:  2017/04/18
 */
void CmcCalXf2::CalXf2_l()
{
	pmcProfile->UpdateXf2_l(StationIndex);
}
/**
 * 网侧及变比已知（Uv、Nnorm、Tc）
 */
void CmcCalXf2::CalXf2_v()
{
	pmcProfile->UpdateXf2_v(StationIndex);
}
/**
 * 阀侧及变比已知（Ul、Nnorm、TC）
 */
void CmcCalXf2::CalXf2_Port()
{
	pmcProfile->UpdateXf2_Port(StationIndex);
}
/**
 * 两侧端口及分接头已知（Ul、Uv、TC）
 */
void CmcCalXf2::CalXf2_UpShift()
{
	pmcProfile->UpdateXf2_UpShift(StationIndex);
}
/**
 * 网侧不变，上调一及分接头
 */
void CmcCalXf2::CalXf2_DownShift()
{
	pmcProfile->UpdateXf2_DownShift(StationIndex);
}



void CmcCalXf2::NodeSort(NodeMap& vNodeMap)
{
	//不参与节点编号
}


void CmcCalXf2::NodeID(NodeMap& vNodeID)
{
	//不参与节点编号
}




void CmcCalXf2::NodeGround(NodeMap& vNodeMap){

	//不参与节点编号
}