///////////////////////////////////////////////////////////
//  CxbCalDcLine.h
//  Implementation of the Class CxbCalDcLine
//  Created on:      05-4��-2017 18:32:32
//  Original author: Administrator
///////////////////////////////////////////////////////////

#if !defined(EA_3A0DCF80_8780_4abc_9525_28CDE31950EE__INCLUDED_)
#define EA_3A0DCF80_8780_4abc_9525_28CDE31950EE__INCLUDED_

#include "CxbCalculate.h"

/**
 * ����· ֱ������
 */
class CxbCalDcLine : public CxbCalculate
{
public:
	virtual void StationSort(StationMap& vStaMap);
	virtual void NodeGround(NodeMap & vNodeMap) ;

protected:
	virtual void UpdateY();


};
#endif // !defined(EA_3A0DCF80_8780_4abc_9525_28CDE31950EE__INCLUDED_)
