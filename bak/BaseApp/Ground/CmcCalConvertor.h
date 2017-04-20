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
	//************************************
	// *南方电网主回路及谐波计算软件*
	// 改动对象:  StationSort，RecordMeasureNode，GetNodeID，CmcCalConvertor，~CmcCalConvertor
	// 改动者:    崔康生
	// 改动类型:  新增
	// 改动内容:  1.准备MeasureStationIndex和MeasureNodeIndex数据
	//            2.
	// 改动时间:  2017/04/17
	//************************************
	~CmcCalConvertor();
	CmcCalConvertor();
	virtual void StationSort(StationMap& vStaMap);
	void RecordMeasureNode(CmcCalConvertor& vCalConvertor);
	int GetNodeID(int vIndex);

	virtual void UpdateF_J();
	virtual void NodeGround(NodeMap & vNodeMap);
	void InitX();
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

	//************************************
	// *南方电网主回路及谐波计算软件*
	// 改动对象:  
	// 改动者:    崔康生
	// 改动类型:  修改
	// 改动内容:  1.CalConvertor_DC至CalConvertor_Port新增
	//            2.CalConvertor至CalConvertorNormal删除
	// 改动时间:  2017/04/18
	//************************************
	virtual void CalConvertor_DC();//直流侧及角度已知（Ud、Id、alpha/gamma）
	virtual void CalConvertor_AC();//交流侧及角度已知（Uv、alpha/gamma、Id）,Id为补充变量
	virtual void CalConvertor_Port();//交、直流端口已知（Uv、Ud、Id）
									 //virtual void CalConvertor();
									 //virtual void CalConvertorNormal();
									 //************************************
									 // *南方电网主回路及谐波计算软件*
									 // 改动对象:  MeasureStationIndex
									 // 改动者:    重要：崔康生
									 // 改动类型:  新增
									 // 改动内容:  1.测量点站编号
									 // 改动时间:  2017/04/17
									 //************************************
	int  MeasureStationIndex;
protected:
	//************************************
	// *南方电网主回路及谐波计算软件*
	// 改动对象:  MeasureStationIndex
	// 改动者:    重要：崔康生
	// 改动类型:  新增
	// 改动内容:  1.测量点节点编号
	// 改动时间:  2017/04/17
	//************************************
	int * MeasureNodeIndex;

	virtual void UpdateJ();

	//************************************
	// *南方电网主回路及谐波计算软件*
	// 改动对象:  doUpdateJ_PdCtrl至doUpdateJ_AngCtrl
	// 改动者:    崔康生
	// 改动类型:  删除
	// 改动内容:  1.函数功能完全一样，判断是否-1将引起4种重载
	// 改动时间:  2017/04/17
	//************************************
	//virtual void doUpdateJ_IdCtrl(int vK, CmcDevConvertor* vDev);
	//virtual void doUpdateJ_PdCtrl(int vK, CmcDevConvertor* vDev);
	//virtual void doUpdateJ_UdCtrl(int vK, CmcDevConvertor* vDev);
	//virtual void doUpdateJ_AngCtrl(int vK, CmcDevConvertor* vDev);

	//virtual void doUpdateF_PdCtrl(int vK, CmcDevConvertor* vDev);
	//virtual void doUpdateF_UdCtrl(int vK, CmcDevConvertor* vDev);
	//virtual void doUpdateF_AngCtrl(int vK, CmcDevConvertor* vDev);

};
