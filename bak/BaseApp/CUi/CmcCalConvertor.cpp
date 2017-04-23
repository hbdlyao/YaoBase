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
	//2017-4-22,yao 修改
	delete[] MeasureNodeIndex;
	
	// ?
	//delete MeasureNodeIndex;
	//delete (MeasureNodeIndex + 1);

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

	//
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

void CmcCalConvertor::CalStation_N()//++--
{
	int vK = 0;
	vK = StationIndex;

	if (pmcProfile->pmcStaData[vK].ConvertorType == Hvdc_Rectify)
		pmcProfile->UpdateConvertor_N(vK, true);
	else
		pmcProfile->UpdateConvertor_N(vK, false);
	pmcProfile->UpdateXf2_N(vK);//++--
}

void CmcCalConvertor::CalStation()//++--
{
	int vK = 0;
	vK = StationIndex;

	switch (pmcProfile->pmcStaData[vK].TapCtrlType)
	{
	case xfCtrl_FixedAngle:
		CalAngleStation();
		break;
	case xfCtrl_ConstantUv:
		CalUvStation();
		break;
	default:
		break;
	}

	if (!pmcProfile->LimitOK)
		ChangeStationCtrlType();
}

void CmcCalConvertor::CalAngleStation()//++--
{
	int vK = 0;
	vK = StationIndex;

	double vAngle;
	double vAngleRangeMax, vAngleRangeMin, vAngleMin;

	vAngleRangeMax = pmcProfile->pmcStaData[vK].AngCtrl_Max;
	vAngleRangeMin = pmcProfile->pmcStaData[vK].AngCtrl_Min;
	vAngleMin = pmcProfile->pmcStaData[vK].Ang_Min;

	pmcProfile->UpdateXf2_l(vK);
	while (true)
	{
		pmcProfile->UpdateConvertor_Port(vK, pmcProfile->pmcStaData[vK].ConvertorType == Hvdc_Rectify);
		vAngle = pmcProfile->pmcStaData[vK].alphaOrgamma;
		if (vAngle - vAngleRangeMax > Epsilon&&pmcProfile->IsTapUpAble(vK))
		{
			pmcProfile->UpdateXf2_UpShift(vK);
			continue;
		}
		if (vAngleRangeMin - vAngle > Epsilon&&pmcProfile->IsTapDownAble(vK))
		{
			pmcProfile->UpdateXf2_DownShift(vK);
			continue;
		}
		if (vAngleMin - vAngle > Epsilon)
		{
			pmcProfile->pmcStaData[vK].alphaOrgamma = vAngleMin;
			pmcProfile->UpdateConvertor_AC(vK, pmcProfile->pmcStaData[vK].ConvertorType == Hvdc_Rectify);
			pmcProfile->LimitOK = false;
			break;
		}
		break;
	}
}
void CmcCalConvertor::CalUvStation()//++--
{
	int vK = 0;
	vK = StationIndex;

	double vAngle;
	double vAngleMin;

	pmcProfile->UpdateXf2_Port(vK);
	pmcProfile->UpdateConvertor_Port(vK, pmcProfile->pmcStaData[vK].ConvertorType == Hvdc_Rectify);

	vAngle = pmcProfile->pmcStaData[vK].alphaOrgamma;
	vAngleMin = pmcProfile->pmcStaData[vK].Ang_Min;
	if (vAngleMin - vAngle > Epsilon)
	{
		pmcProfile->pmcStaData[vK].alphaOrgamma = vAngleMin;
		pmcProfile->UpdateConvertor_AC(vK, pmcProfile->pmcStaData[vK].ConvertorType == Hvdc_Rectify);
		pmcProfile->LimitOK = false;
	}
}

void CmcCalConvertor::LimitUd()//++--
{
	int vK = 0;
	vK = StationIndex;

	if (pmcProfile->pmcStaData[vK].Ud > pmcProfile->Ud_Max)
	{
		if (StationCtrlType != StaCtrl_ConstantAngle || pmcProfile->pmcStaData[vK].TapCtrlType == xfCtrl_ConstantUv || !pmcProfile->IsTapUpAble(vK))
		{
			pmcProfile->pmcStaData[vK].Ud = pmcProfile->Ud_Max;
			StationCtrlType = StaCtrl_ConstantUd;
			MeasureStationIndex = StationIndex;
			MeasureNodeIndex[0] = GetNodeID(0);
			MeasureNodeIndex[1] = GetNodeID(1);
			pmcProfile->LimitOK = false;
			return;
		}
		if (pmcProfile->pmcStaData[vK].TapCtrlType == xfCtrl_FixedAngle)
		{
			pmcProfile->UpdateXf2_UpShift(vK);
			pmcProfile->UpdateUdio(vK);
			pmcProfile->LimitOK = false;
			return;
		}
	}
}
void CmcCalConvertor::ChangeStationCtrlType()//++--
{
	int vK = 0;
	vK = StationIndex;

	//没有定电流控制?
	//哪两种类型间的转换?
	switch (StationCtrlType)
	{
	case StaCtrl_ConstantUd:
		MeasureStationIndex = StationIndex;
		MeasureNodeIndex[0] = GetNodeID(0);
		MeasureNodeIndex[1] = GetNodeID(1);
		break;

	case StaCtrl_ConstantPd:
		pmcProfile->URefStation = StationIndex;
		pmcProfile->URefNode[0] = GetNodeID(0);
		pmcProfile->URefNode[1] = GetNodeID(1);
		break;

	default:
		StationCtrlType = StaCtrl_ConstantAngle;
		MeasureStationIndex = StationIndex;
		MeasureNodeIndex[0] = GetNodeID(0);
		MeasureNodeIndex[1] = GetNodeID(1);
		break;
	}
}
void CmcCalConvertor::SetUdStation()//++--
{
	int vK = 0;
	vK = StationIndex;

	if (StationCtrlType == StaCtrl_ConstantUd)
	{
		MeasureStationIndex = pmcProfile->URefStation;
		MeasureNodeIndex[0] = pmcProfile->URefNode[0];
		MeasureNodeIndex[1] = pmcProfile->URefNode[1];
		pmcProfile->URefStation = -1;
	}
}
//void CmcCalConvertor::CalConvertor_DC()
//{
//	int vK = 0;
//
//	CmcDevConvertor * vDev;
//
//	vK = StationIndex;
//
//	vDev = dynamic_cast<CmcDevConvertor *>(pDevice);
//	if (vDev->GetStationType() == Hvdc_Rectify)
//		pmcProfile->UpdateConvertor_DC(vK, true);
//	else
//		pmcProfile->UpdateConvertor_DC(vK, false);
//}
//void CmcCalConvertor::CalConvertor_AC()
//{
//	int vK = 0;
//
//	CmcDevConvertor * vDev;
//
//	vK = StationIndex;
//
//	vDev = dynamic_cast<CmcDevConvertor *>(pDevice);
//	if (vDev->GetStationType() == Hvdc_Rectify)
//		pmcProfile->UpdateConvertor_AC(vK, true);
//	else
//		pmcProfile->UpdateConvertor_AC(vK, false);
//}
//void CmcCalConvertor::CalConvertor_Port()
//{
//	int vK = 0;
//
//	CmcDevConvertor * vDev;
//
//	vK = StationIndex;
//
//	vDev = dynamic_cast<CmcDevConvertor *>(pDevice);
//	if (vDev->GetStationType() == Hvdc_Rectify)
//		pmcProfile->UpdateConvertor_Port(vK, true);
//	else
//		pmcProfile->UpdateConvertor_Port(vK, false);
//}

//************************************
// *南方电网主回路及谐波计算软件*
// 改动对象:  Prepare
// 改动者:    崔康生
// 改动类型:  修改
// 改动内容:  1.角度转弧度
//			  2.准备StationCtrlType参量
//			  3.整理参数
// 改动时间:  2017/04/21
//************************************
void CmcCalConvertor::Prepare()
{

	int vK = 0;
	CmcDevConvertor * vDev;

	vK = StationIndex;

	vDev = dynamic_cast<CmcDevConvertor *>(pDevice);

	StationCtrlType = vDev->GetStationCtrlType();

	//参数
	pmcProfile->pmcStaData[vK].StationName = vDev->GetStationName();
	pmcProfile->pmcStaData[vK].Pconv = vDev->GetPconvN();
	pmcProfile->pmcStaData[vK].Qconv = vDev->GetQconvN();
	pmcProfile->pmcStaData[vK].miu = D2R(vDev->GetmiuN());
	pmcProfile->pmcStaData[vK].Ang_Min = D2R(vDev->GetAngleMin());
	pmcProfile->pmcStaData[vK].Udio = vDev->GetUdioN();
	pmcProfile->pmcStaData[vK].UT = vDev->GetUT();

	if (vDev->GetUdN() > pmcProfile->Ud_Max)//++--	// ?
		pmcProfile->Ud_Max = vDev->GetUdN();

	if (vDev->GetStationCtrlType() == StaCtrl_ConstantAngle)
		pmcProfile->pmcStaData[vK].alphaOrgamma = D2R(vDev->GetAngleRef());
	else
		pmcProfile->pmcStaData[vK].alphaOrgamma = D2R(vDev->GetAlpha_gamaN());

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

	pmcProfile->pmcStaData[vK].ConvertorType = vDev->GetStationType();
}


//************************************
// *南方电网主回路及谐波计算软件*
// 改动对象:  InitX
// 改动者:    崔康生
// 改动类型:  修改
// 改动内容:  1.排除定电流的站
// 改动时间:  2017/04/20
//************************************
void CmcCalConvertor::InitX()
{
	int vK = 0;
	CmcDevConvertor * vDev;

	vK = StationIndex;

	vDev = dynamic_cast<CmcDevConvertor *>(pDevice);

	if (vDev->GetStationType() == Hvdc_Invertor)
	{
		pmcProfile->pmcStaData[vK].Id *= -1;
		pmcProfile->pmcStaData[vK].Pd *= -1;
		pmcProfile->pmcStaDataN[vK].Id *= -1;
		pmcProfile->pmcStaDataN[vK].Pd *= -1;
	}

	if (vDev->GetNodeID(0) != -1)
		pmcProfile->InitX_Y(vDev->GetNodeID(0), vDev->GetUdN());
	if (vDev->GetNodeID(1) != -1)
		pmcProfile->InitX_Y(vDev->GetNodeID(1), 0);
	if (Offset != -1)
		pmcProfile->InitX_I(Offset, 3);

}

//************************************
// *南方电网主回路及谐波计算软件*
// 改动对象:  SaveX
// 改动者:    崔康生
// 改动类型:  新增
// 改动内容:  1.保存doSovleDcNet的计算结果
//			  2.继承自CmcCalculate
// 改动时间:  2017/04/20
//************************************
void CmcCalConvertor::SaveX()
{
	int vK = 0;
	CmcDevConvertor * vDev;

	vK = StationIndex;

	vDev = dynamic_cast<CmcDevConvertor *>(pDevice);

	pmcProfile->SaveX(Offset, vK, vDev->GetNodeID(0), vDev->GetNodeID(1));

	if (vDev->GetStationType() == Hvdc_Invertor)
	{
		pmcProfile->pmcStaData[vK].Id *= -1;
		pmcProfile->pmcStaData[vK].Pd *= -1;
		pmcProfile->pmcStaDataN[vK].Id *= -1;
		pmcProfile->pmcStaDataN[vK].Pd *= -1;
	}
}
//************************************
// *南方电网主回路及谐波计算软件*
// 改动对象:  PrepareNormal
// 改动者:    崔康生
// 改动类型:  修改
// 改动内容:  1.角度转弧度
//			  2.整理参数
// 改动时间:  2017/04/21
//************************************
void CmcCalConvertor::PrepareNormal()//++--
{
	int vK = 0;
	CmcDevConvertor * vDev;

	vK = StationIndex;

	vDev = dynamic_cast<CmcDevConvertor *>(pDevice);

	//额定值
	pmcProfile->pmcStaDataN[vK].StationName = vDev->GetStationName();
	pmcProfile->pmcStaDataN[vK].Pconv = vDev->GetPconvN();
	pmcProfile->pmcStaDataN[vK].Qconv = vDev->GetQconvN();
	pmcProfile->pmcStaDataN[vK].miu = D2R(vDev->GetmiuN());
	pmcProfile->pmcStaDataN[vK].alphaOrgamma = D2R(vDev->GetAlpha_gamaN());
	pmcProfile->pmcStaDataN[vK].Ang_Min = D2R(vDev->GetAngleMin());
	pmcProfile->pmcStaDataN[vK].Pd = vDev->GetPdN();
	pmcProfile->pmcStaDataN[vK].Ud = vDev->GetUdN();
	pmcProfile->pmcStaDataN[vK].UdL = vDev->GetUdN();
	pmcProfile->pmcStaDataN[vK].UT = vDev->GetUT();
	pmcProfile->pmcStaDataN[vK].nT = 2 * vDev->GetValvor12Count();
	pmcProfile->pmcStaDataN[vK].Udio = vDev->GetUdioN();
	pmcProfile->pmcStaDataN[vK].Id = vDev->GetIdN();
	pmcProfile->pmcStaDataN[vK].nPoleNum = 2;
	pmcProfile->pmcStaDataN[vK].PdPer = 100;
	pmcProfile->pmcStaDataN[vK].ConvertorType = vDev->GetStationType();
}
//************************************
// *南方电网主回路及谐波计算软件*
// 改动对象:  SaveNormal
// 改动者:    崔康生
// 改动类型:  修改
// 改动内容:  1.弧度转角度
//			  2.整理参数
// 改动时间:  2017/04/21
//************************************
void CmcCalConvertor::SaveNormal()
{
	int vK = 0;
	CmcDevConvertor * vDev;

	vDev = dynamic_cast<CmcDevConvertor *>(pDevice);
	vK = StationIndex;

	vDev->SetPconvN(pmcProfile->pmcStaData[vK].Pconv);
	vDev->SetQconvN(pmcProfile->pmcStaData[vK].Qconv);
	vDev->SetmiuN(R2D(pmcProfile->pmcStaData[vK].miu));
	vDev->SetAlpha_gamaN(R2D(pmcProfile->pmcStaData[vK].alphaOrgamma));
	vDev->SetPdN(pmcProfile->pmcStaData[vK].Pd);
	vDev->SetUdN(pmcProfile->pmcStaData[vK].Ud);
	vDev->SetUdioN(pmcProfile->pmcStaData[vK].Udio);
	vDev->SetUvN(pmcProfile->pmcStaData[vK].Uv);
	vDev->SetIdN(pmcProfile->pmcStaData[vK].Id);
}

//************************************
// *南方电网主回路及谐波计算软件*
// 改动对象:  UpdateJ
// 改动者:    崔康生
// 改动类型:  修改
// 改动内容:  1.排除定电流的站
//			  2.对于每个站，增加参数：Offset
// 改动时间:  2017/04/20
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
		break;

	case StaCtrl_ConstantPd:
		pmcProfile->UpdateJ_PdCtrl(Offset, vK_s, iNode_s, jNode_s);
		break;

	case StaCtrl_ConstantUd:
		pmcProfile->UpdateJ_UdCtrl(Offset, vK_s, iNode_s, jNode_s, vK_m, iNode_m, jNode_m);
		break;

	case StaCtrl_ConstantAngle:
		if (vDev->GetStationType() == Hvdc_Rectify)
			pmcProfile->UpdateJ_AngCtrl(Offset, vK_s, iNode_s, jNode_s, true);
		else
			pmcProfile->UpdateJ_AngCtrl(Offset, vK_s, iNode_s, jNode_s, false);
		break;
	default:
		break;
	}// switch

}

//************************************
// *南方电网主回路及谐波计算软件*
// 改动对象:  UpdateF_J
// 改动者:    崔康生
// 改动类型:  修改
// 改动内容:  1.对于每个站，增加参数：Offset
// 改动时间:  2017/04/20
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
		pmcProfile->UpdateF_PdCtrl(Offset, vK_s, iNode_s, jNode_s);
		break;

	case StaCtrl_ConstantUd:
		pmcProfile->UpdateF_UdCtrl(Offset, vK_s, iNode_s, jNode_s, vK_m, iNode_m, jNode_m);
		break;

	case StaCtrl_ConstantAngle:
		if (vDev->GetStationType() == Hvdc_Rectify)
			pmcProfile->UpdateF_AngCtrl(Offset, vK_s, iNode_s, jNode_s, true);
		else
			pmcProfile->UpdateF_AngCtrl(Offset, vK_s, iNode_s, jNode_s, false);
		break;
	default:
		break;
	}// switch

}


void CmcCalConvertor::NodeGround(NodeMap & vNodeMap)
{

	pDevice->NodeGround(vNodeMap);

///////////////////////////////////////////
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


//************************************
// *南方电网主回路及谐波计算软件*
// 改动对象:  OffsetSort
// 改动者:    崔康生
// 改动类型:  新增
// 改动内容:  1.非定电流站：记录offset并使offset++
// 改动时间:  2017/04/20
//************************************
void CmcCalConvertor::OffsetSort(int& vCurrentOffset)
{
	CmcCalTwoDot::OffsetSort(vCurrentOffset);
	if (StationCtrlType != StaCtrl_ConstantId&&StationCtrlType != StaCtrl_TrackId)
	{
		Offset = vCurrentOffset;
		vCurrentOffset++;
	}
}