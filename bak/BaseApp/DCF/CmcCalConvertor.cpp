///////////////////////////////////////////////////////////
//  CmcCalConvertor.cpp
//  Implementation of the Class CmcCalConvertor
//  Created on:      02-4月-2017 14:42:20
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CmcCalConvertor.h"

CmcCalConvertor::CmcCalConvertor()
{
	MeasureNodeIndex = new int[2];
}
CmcCalConvertor::~CmcCalConvertor()
{
	delete MeasureNodeIndex;
	delete (MeasureNodeIndex + 1);
}

void CmcCalConvertor::StationSort(StationMap& vStaMap)
{
	CmcCalTwoDot::StationSort(vStaMap);

	int vN, vID;
	string vName;

	CmcDevConvertor* vDev = static_cast<CmcDevConvertor*>(pDevice);
	vName = vDev->GetMeasureStation();
	vN = static_cast<int> (vStaMap.count(vName));

	if (vN == 0)
	{//不存在 vName
		vID = static_cast<int> (vStaMap.size());
		vStaMap[vName] = vID;
	}

	MeasureStationIndex = vStaMap[vName];
}

void CmcCalConvertor::RecordMeasureNode(CmcCalConvertor& vCalConvertor)
{
	MeasureNodeIndex[0] = vCalConvertor.GetNodeID(0);
	MeasureNodeIndex[1] = vCalConvertor.GetNodeID(1);
}

int CmcCalConvertor::GetNodeID(int vIndex)
{
	return pDevice->GetNodeID(vIndex);
}

void CmcCalConvertor::CalConvertor_DC()
{
	int vK = 0;

	CmcDevConvertor * vDev;

	vK = StationIndex;

	vDev = dynamic_cast<CmcDevConvertor *>(pDevice);
	if (vDev->GetStationType() == Hvdc_Rectify)
		pmcProfile->UpdateConvertor_DC(vK, true);
	else
		pmcProfile->UpdateConvertor_DC(vK, false);
}
void CmcCalConvertor::CalConvertor_AC()
{
	int vK = 0;

	CmcDevConvertor * vDev;

	vK = StationIndex;

	vDev = dynamic_cast<CmcDevConvertor *>(pDevice);
	if (vDev->GetStationType() == Hvdc_Rectify)
		pmcProfile->UpdateConvertor_AC(vK, true);
	else
		pmcProfile->UpdateConvertor_AC(vK, false);
}
void CmcCalConvertor::CalConvertor_Port()
{
	int vK = 0;

	CmcDevConvertor * vDev;

	vK = StationIndex;

	vDev = dynamic_cast<CmcDevConvertor *>(pDevice);
	if (vDev->GetStationType() == Hvdc_Rectify)
		pmcProfile->UpdateConvertor_Port(vK, true);
	else
		pmcProfile->UpdateConvertor_Port(vK, false);
}

//************************************
// *南方电网主回路及谐波计算软件*
// 改动对象:  Prepare
// 改动者:    崔康生
// 改动类型:  修改
// 改动内容:  1.完成了函数功能(数据填充)
// 改动时间:  2017/04/17
//************************************
void CmcCalConvertor::Prepare()
{
	int vK = 0;
	CmcDevConvertor * vDev;

	vDev = dynamic_cast<CmcDevConvertor *>(pDevice);
	StaionCtrlType = vDev->GetStationCtrlType();


	vK = StationIndex;

	vDev = dynamic_cast<CmcDevConvertor *>(pDevice);

	//参数
	pmcProfile->pmcStaData[vK].Pconv = 0;
	pmcProfile->pmcStaData[vK].Udio = 0;
	pmcProfile->pmcStaData[vK].miu = 0;
	pmcProfile->pmcStaData[vK].Qf_max = 0;
	pmcProfile->pmcStaData[vK].Qf_min = 0;
	pmcProfile->pmcStaData[vK].StationName = vDev->GetStationName();
	pmcProfile->pmcStaData[vK].Uv = 0;
	pmcProfile->pmcStaData[vK].UT = vDev->GetUT();
	pmcProfile->pmcStaData[vK].Ang_Min = vDev->GetAngleMin();

	if (vDev->GetUdN() > pmcProfile->pmcStaData[vK].Ud_Max)
		pmcProfile->pmcStaData[vK].Ud_Max = vDev->GetUdN();

	if (vDev->GetStationCtrlType() == StaCtrl_ConstantAngle)
		pmcProfile->pmcStaData[vK].alphaOrgamma = vDev->GetAngleRef();
	else
		pmcProfile->pmcStaData[vK].alphaOrgamma = vDev->GetAlpha_gamaN();

	//指令相关
	pmcProfile->pmcStaData[vK].PdPer = pmcProfile->pmcOrder->PdPer;
	pmcProfile->pmcStaData[vK].nT = 2 * pmcProfile->pmcOrder->nValNum;
	if (pmcProfile->pmcOrder->GroundType == mc_Ground20 || pmcProfile->pmcOrder->GroundType == mc_Ground21)
		pmcProfile->pmcStaData[vK].nPoleNum = 2;
	else
		pmcProfile->pmcStaData[vK].nPoleNum = 1;

	//指令相关(冗余)
	switch (pmcProfile->pmcOrder->UdLevel)
	{
	case  Ud_Per80:
		pmcProfile->pmcStaData[vK].Ud = vDev->GetUdN()*0.8;
		pmcProfile->pmcStaData[vK].UdL = vDev->GetUdN()*0.8;
		break;
	case  Ud_Per70:
		pmcProfile->pmcStaData[vK].Ud = vDev->GetUdN()*0.7;
		pmcProfile->pmcStaData[vK].UdL = vDev->GetUdN()*0.7;
		break;
	default:
		pmcProfile->pmcStaData[vK].Ud = vDev->GetUdN();
		pmcProfile->pmcStaData[vK].UdL = vDev->GetUdN();
		break;
	}


	pmcProfile->pmcStaData[vK].Id = vDev->GetPdN() / vDev->GetUdN()*pmcProfile->pmcOrder->PdPer / 100.0;
	pmcProfile->pmcStaData[vK].Pd = vDev->GetPdN()*pmcProfile->pmcOrder->PdPer / 100.0;


}



void CmcCalConvertor::InitX()
{
	//崔康生2014-4-15

	int vK = 0;
	CmcDevConvertor * vDev;

	vK = StationIndex;

	vDev = dynamic_cast<CmcDevConvertor *>(pDevice);

	pmcProfile->InitX_Y(vDev->GetNodeID(0), vDev->GetUdN());
	if (vDev->GetNodeID(1) != -1)
		pmcProfile->InitX_Y(vDev->GetNodeID(1), 0);
	pmcProfile->InitX_I(vK, 3);

}


//************************************
// *南方电网主回路及谐波计算软件*
// 改动对象:  PrepareNormal
// 改动者:    崔康生
// 改动类型:  修改
// 改动内容:  1.完成了数据填充功能
// 改动时间:  2017/04/17
//************************************
void CmcCalConvertor::PrepareNormal()
{
	int vK = 0;
	CmcDevConvertor * vDev;

	vK = StationIndex;

	vDev = dynamic_cast<CmcDevConvertor *>(pDevice);

	//额定值
	pmcProfile->pmcStaDataN[vK].alphaOrgamma = vDev->GetAlpha_gamaN();
	pmcProfile->pmcStaDataN[vK].Ang_Min = vDev->GetAngleMin();
	pmcProfile->pmcStaDataN[vK].Id = vDev->GetIdN();
	pmcProfile->pmcStaDataN[vK].Pd = vDev->GetPdN();
	pmcProfile->pmcStaDataN[vK].StationName = vDev->GetStationName();
	pmcProfile->pmcStaDataN[vK].Udio = vDev->GetUdioN();
	pmcProfile->pmcStaDataN[vK].Ud = vDev->GetUdN();
	pmcProfile->pmcStaDataN[vK].UdL = vDev->GetUdN();
	pmcProfile->pmcStaDataN[vK].UT = vDev->GetUT();
	pmcProfile->pmcStaDataN[vK].Uv = vDev->GetUvN();
	pmcProfile->pmcStaDataN[vK].nT = 2 * vDev->GetValvor12Count();
	pmcProfile->pmcStaDataN[vK].nPoleNum = 2;
	if (vDev->GetUdN() > pmcProfile->pmcStaDataN[vK].Ud_Max)
		pmcProfile->pmcStaDataN[vK].Ud_Max = vDev->GetUdN();
	pmcProfile->pmcStaDataN[vK].PdPer = 100;
	//崔康生：以下应该从Hvdc中取值？
	pmcProfile->pmcStaDataN[vK].Pconv = 0;
	pmcProfile->pmcStaDataN[vK].miu = 0;
	pmcProfile->pmcStaDataN[vK].Qf_max = 0;
	pmcProfile->pmcStaDataN[vK].Qf_min = 0;
}
void CmcCalConvertor::SaveNormal()
{
	int vK = 0;
	CmcDevConvertor * vDev;

	vDev = dynamic_cast<CmcDevConvertor *>(pDevice);
	vK = StationIndex;

	vDev->SetAlpha_gamaN(pmcProfile->pmcStaData[vK].alphaOrgamma);
	vDev->SetIdN(pmcProfile->pmcStaData[vK].Id);
	vDev->SetPdN(pmcProfile->pmcStaData[vK].Pd);
	vDev->SetUdioN(pmcProfile->pmcStaData[vK].Udio);
	vDev->SetUdN(pmcProfile->pmcStaData[vK].Ud);
	vDev->SetUvN(pmcProfile->pmcStaData[vK].Uv);
	//vDev->setp(pmcProfile->pmcStaData[vK].Pconv);
	//vDev->setmiu(pmcProfile->pmcStaData[vK].miu);
	//vDev->setq(pmcProfile->pmcStaData[vK].Qf_max);
	//vDev->SetQacN(pmcProfile->pmcStaData[vK].Qf_min);
}



//************************************
// *南方电网主回路及谐波计算软件*
// 改动对象:  UpdateJ
// 改动者:    崔康生
// 改动类型:  修改
// 改动内容:  1.所有控制类型都参加UpdateJ，J矩阵为StaCount+NodeCount维
// 改动时间:  2017/04/17
//************************************
void CmcCalConvertor::UpdateJ()
{//需考虑有接地情况：双极中性点
	int vK_s, iNode_s, jNode_s;
	int vK_m, iNode_m, jNode_m;
	CmcDevConvertor * vDev;

	vDev = dynamic_cast<CmcDevConvertor *>(pDevice);

	vK_s = StationIndex;
	iNode_s = vDev->GetNodeID(0);
	jNode_s = vDev->GetNodeID(1);

	vK_m = MeasureStationIndex;
	iNode_m = MeasureNodeIndex[0];
	jNode_m = MeasureNodeIndex[1];

	switch (vDev->GetStationCtrlType())
	{
	case StaCtrl_ConstantId:

	case StaCtrl_TrackId:
		pmcProfile->UpdateJ_IdCtrl(vK_s, iNode_s, jNode_s);
		break;

	case StaCtrl_ConstantPd:
		pmcProfile->UpdateJ_PdCtrl(vK_s, iNode_s, jNode_s);
		break;

	case StaCtrl_ConstantUd:
		pmcProfile->UpdateJ_UdCtrl(vK_s, iNode_s, jNode_s, vK_m, iNode_m, jNode_m);
		break;

	case StaCtrl_ConstantAngle:
		if (vDev->GetStationType() == Hvdc_Rectify)
			pmcProfile->UpdateJ_AngCtrl(vK_s, iNode_s, jNode_s, true);
		else
			pmcProfile->UpdateJ_AngCtrl(vK_s, iNode_s, jNode_s, false);
		break;
	default:
		break;
	}// switch

}

//************************************
// *南方电网主回路及谐波计算软件*
// 改动对象:  doUpdateJ_PdCtrl至doUpdateJ_AngCtrl
// 改动者:    崔康生
// 改动类型:  删除
// 改动内容:  1.函数功能完全一样，判断是否-1将引起4种重载
// 改动时间:  2017/04/17
//************************************
//
//void CmcCalConvertor::doUpdateJ_PdCtrl(int vK, CmcDevConvertor* vDev)
//{
//
//	int iNode, jNode;
//	iNode = vDev->GetNodeID(0);
//	jNode = vDev->GetNodeID(1);
//
//	if (jNode == -1) //不接地
//		pmcProfile->UpdateJ_PdCtrl0(vK, iNode);
//	else
//		pmcProfile->UpdateJ_PdCtrl(vK, iNode, jNode);
//
//}
//
//void CmcCalConvertor::doUpdateJ_UdCtrl(int vK, CmcDevConvertor* vDev)
//{
//
//	int iNode, jNode;
//	iNode = vDev->GetNodeID(0);
//	jNode = vDev->GetNodeID(1);
//
//	if (jNode == -1) //接地
//		pmcProfile->UpdateJ_UdCtrl0(vK, iNode);
//	else
//		pmcProfile->UpdateJ_UdCtrl(vK, iNode, jNode);
//}
//
//void CmcCalConvertor::doUpdateJ_AngCtrl(int vK, CmcDevConvertor* vDev)
//{
//
//	int iNode, jNode;
//	iNode = vDev->GetNodeID(0);
//	jNode = vDev->GetNodeID(1);
//
//	if (jNode == -1) //接地
//		pmcProfile->UpdateJ_AngCtrl0(vK, iNode);
//	else
//		pmcProfile->UpdateJ_AngCtrl(vK, iNode, jNode);
//}


//************************************
// *南方电网主回路及谐波计算软件*
// 改动对象:  UpdateF_J
// 改动者:    崔康生
// 改动类型:  修改
// 改动内容:  1.所有控制类型都参加UpdateJ，J矩阵为StaCount+NodeCount维
// 改动时间:  2017/04/17
//************************************
void CmcCalConvertor::UpdateF_J()
{//需考虑有接地情况：双极中性点
	int vK_s, iNode_s, jNode_s;
	int vK_m, iNode_m, jNode_m;
	CmcDevConvertor * vDev;

	vDev = dynamic_cast<CmcDevConvertor *>(pDevice);

	vK_s = StationIndex;
	iNode_s = vDev->GetNodeID(0);
	jNode_s = vDev->GetNodeID(1);

	vK_m = MeasureStationIndex;
	iNode_m = MeasureNodeIndex[0];
	jNode_m = MeasureNodeIndex[1];

	vDev = dynamic_cast<CmcDevConvertor *>(pDevice);
	switch (vDev->GetStationCtrlType())
	{
	case StaCtrl_ConstantId:
		pmcProfile->UpdateF_IdCtrl(vK_s, iNode_s, jNode_s);
		break;

	case StaCtrl_TrackId:
		pmcProfile->UpdateF_IdCtrl(vK_s, iNode_s, jNode_s, vK_m);
		break;

	case StaCtrl_ConstantPd:
		pmcProfile->UpdateF_PdCtrl(vK_s, iNode_s, jNode_s);
		break;

	case StaCtrl_ConstantUd:
		pmcProfile->UpdateF_UdCtrl(vK_s, iNode_s, jNode_s, vK_m, iNode_m, jNode_m);
		break;

	case StaCtrl_ConstantAngle:
		if (vDev->GetStationType() == Hvdc_Rectify)
			pmcProfile->UpdateF_AngCtrl(vK_s, iNode_s, jNode_s, true);
		else
			pmcProfile->UpdateF_AngCtrl(vK_s, iNode_s, jNode_s, false);
		break;
	default:
		break;
	}// switch

}


//************************************
// *南方电网主回路及谐波计算软件*
// 改动对象:  doUpdateF_PdCtrl至doUpdateF_AngCtrl
// 改动者:    崔康生
// 改动类型:  删除
// 改动内容:  1.函数功能完全一样，判断是否-1将引起4种重载
// 改动时间:  2017/04/17
//************************************
//
//void CmcCalConvertor::doUpdateF_PdCtrl(int vK, CmcDevConvertor* vDev)
//{
//
//	int iNode, jNode;
//	iNode = vDev->GetNodeID(0);
//	jNode = vDev->GetNodeID(1);
//
//
//	if (jNode == -1) //接地
//		pmcProfile->UpdateF_PdCtrl0(vK, iNode);
//	else
//		pmcProfile->UpdateF_PdCtrl(vK, iNode, jNode);
//
//}
//
//void CmcCalConvertor::doUpdateF_UdCtrl(int vK, CmcDevConvertor* vDev)
//{
//
//	int iNode, jNode;
//	iNode = vDev->GetNodeID(0);
//	jNode = vDev->GetNodeID(1);
//
//	if (jNode == -1) //接地
//		pmcProfile->UpdateF_UdCtrl0(vK, iNode);
//	else
//		pmcProfile->UpdateF_UdCtrl(vK, iNode, jNode);
//}
//
//void CmcCalConvertor::doUpdateF_AngCtrl(int vK, CmcDevConvertor* vDev)
//{
//
//	int iNode, jNode;
//	iNode = vDev->GetNodeID(0);
//	jNode = vDev->GetNodeID(1);
//
//	if (jNode == -1) //接地
//		pmcProfile->UpdateF_AngCtrl0(vK, iNode);
//	else
//		pmcProfile->UpdateF_AngCtrl(vK, iNode, jNode);
//}


void CmcCalConvertor::NodeGround(NodeMap & vNodeMap)
{
	bool vGround;
	string vName;
	CmcDevConvertor  * vDev;

	vDev = dynamic_cast<CmcDevConvertor *>(pDevice);
	//双极
	vGround = pmcProfile->IsBiPole();
	if (vGround)
	{
		vName = vDev->BusName(1);
		vNodeMap[vName] = -1; //-1表示接地
	}

	//金属回线
	vGround = pmcProfile->IsMetalLine();
	vGround = vGround && (vDev->GetIsGround() == 1);
	if (vGround)
	{
		vName = vDev->BusName(1);
		vNodeMap[vName] = -1; //-1表示接地
	}

}


bool CmcCalConvertor::IsFixed_I()
{
	CmcDevConvertor  * vDev;

	vDev = dynamic_cast<CmcDevConvertor *>(pDevice);

	return (vDev->GetStationCtrlType()== StaCtrl_ConstantId );

}
