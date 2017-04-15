///////////////////////////////////////////////////////////
//  CxbDevBase.h
//  Implementation of the Class CxbDevBase
//  Created on:      12-4月-2017 14:00:36
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_14923168_F51E_4cf5_A176_85172044F6D2__INCLUDED_)
#define EA_14923168_F51E_4cf5_A176_85172044F6D2__INCLUDED_

#include "CDeviceBase.h"

class CxbDevBase : public CDeviceBase
{
protected:	/**
	 * 所属拓扑类型  单极大地 单极金属 双极
	 */
	int PosOrNeg;



public:
	/**
	 * 所属拓扑类型  单极大地 单极金属 双极
	 */
	int GetPosOrNeg();
	/**
	 * 所属拓扑类型  单极大地 单极金属 双极
	 */
	void SetPosOrNeg(int newVal);
};
#endif // !defined(EA_14923168_F51E_4cf5_A176_85172044F6D2__INCLUDED_)
