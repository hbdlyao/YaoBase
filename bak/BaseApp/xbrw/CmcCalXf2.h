#pragma once

#include "CmcCalTwoDot.h"

/**
 * 主回路换流变压器
 */
class CmcCalXf2 : public CmcCalTwoDot
{

public:
	virtual void CalTap();
	virtual void CalTapNormal();
	virtual void Prepare();

	virtual void NodeSort(NodeMap& vNodeMap);
	virtual void NodeID(NodeMap& vNodeID);
	virtual void PrepareNormal();
};
