#pragma once


#include "CmcCalOneDot.h"

/**
 * ����· ����ϵͳ
 */
class CmcCalAcSys : public CmcCalOneDot
{

public:
	virtual void Prepare();

	virtual void NodeSort(NodeMap& vNodeMap);
	virtual void NodeID(NodeMap& vNodeID);
	virtual void PrepareNormal();
};
