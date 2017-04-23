#pragma once

#include "CmcCalTwoDot.h"
#include "CmcDevConvertor.h"

/**
* 换流器
*/
class CmcCalConvertor : public CmcCalTwoDot
{

public:
	virtual void Prepare();
	~CmcCalConvertor();
	CmcCalConvertor();
	virtual void StationSort(StationMap& vStaMap);
	void RecordMeasureNode(CmcCalConvertor& vCalConvertor);
	int GetNodeID(int vIndex);

	virtual void UpdateF_J();
	virtual void NodeGround(NodeMap & vNodeMap);
	void InitX();
	//************************************
	// *南方电网主回路及谐波计算软件*
	// 改动对象:  SaveX
	// 改动者:    崔康生
	// 改动类型:  新增
	// 改动内容:  1.保存doSovleDcNet的计算结果
	//			  2.继承自CmcCalculate
	// 改动时间:  2017/04/20
	//************************************
	virtual void SaveX();
	virtual void PrepareNormal();
	virtual void SaveNormal();
	//************************************
	// *南方电网主回路及谐波计算软件*
	// 改动对象:  CalStation_N至CalStation
	// 改动者:    崔康生
	// 改动类型:  新增
	// 改动内容:  1.站计算用
	//			  2.继承自CmcCalculate
	// 改动时间:  2017/04/20
	//************************************
	virtual void CalStation_N();
	virtual void CalStation();
	void CalAngleStation();//++--
	void CalUvStation();//++--
	void LimitUd();//++--
	void ChangeStationCtrlType();//++--
	void SetUdStation();//++--
						//************************************
						// *南方电网主回路及谐波计算软件*
						// 改动对象:  CalConvertor_DC至CalConvertor_Port
						// 改动者:    崔康生
						// 改动类型:  删除
						// 改动内容:  1.
						// 改动时间:  2017/04/21
						//************************************
						//virtual void CalConvertor_AC();//交流侧及角度已知（Uv、alpha/gamma、Id）,Id为补充变量
						//virtual void CalConvertor_Port();//交、直流端口已知（Uv、Ud、Id）
	int  MeasureStationIndex;

	//************************************
	// *南方电网主回路及谐波计算软件*
	// 改动对象:  StationCtrlType至OffsetSort
	// 改动者:    崔康生
	// 改动类型:  新增
	// 改动内容:  1.记录换流站控制类型，并根据类型记录其在矩阵中的位置
	//            2.继承自CmcCalculate
	// 改动时间:  2017/04/20
	//************************************
	int StationCtrlType;
	virtual void OffsetSort(int& vCurrentOffset);

protected:
	int * MeasureNodeIndex;

	virtual void UpdateJ();

};
