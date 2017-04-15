#pragma once


#include "CmcCalOneDot.h"

/**
 * 主回路 交流系统
 */
class CmcCalAcSys : public CmcCalOneDot
{

public:
	virtual void Prepare();

	virtual void NodeSort(NodeMap& vNodeMap);
	virtual void NodeID(NodeMap& vNodeID);
};
