#pragma once

#include "CmcCalTwoDot.h"
#include "CmcDevConvertor.h"

/**
 * ������
 */
class CmcCalConvertor : public CmcCalTwoDot
{

public:
	virtual void CalConvertor();
	virtual void Prepare();

	virtual void CalConvertorNormal();
	virtual void UpdateF_J();
	virtual void NodeGround(NodeMap & vNodeMap);
	void InitX();
	virtual void PrepareNormal();

protected:

	virtual void UpdateJ();
	virtual void doUpdateJ_PdCtrl(int vK, CmcDevConvertor* vDev);
	virtual void doUpdateJ_UdCtrl(int vK, CmcDevConvertor* vDev);
	virtual void doUpdateJ_AngCtrl(int vK, CmcDevConvertor* vDev);
	virtual void doUpdateF_PdCtrl(int vK, CmcDevConvertor* vDev);
	virtual void doUpdateF_UdCtrl(int vK, CmcDevConvertor* vDev);
	virtual void doUpdateF_AngCtrl(int vK, CmcDevConvertor* vDev);

};
