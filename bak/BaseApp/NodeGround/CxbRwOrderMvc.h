///////////////////////////////////////////////////////////
//  CxbRwOrderMvc.h
//  Implementation of the Class CxbRwOrderMvc
//  Created on:      18-4��-2017 22:56:16
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_84B118E1_A96D_43ea_8EBB_D569FEF43149__INCLUDED_)
#define EA_84B118E1_A96D_43ea_8EBB_D569FEF43149__INCLUDED_

#include "CRwMvc.h"
#include "CxbOrder.h"


class CxbRwOrderMvc : public CRwMvcAccess
{

public:
	void Init(CxbOrder* vOrder);
	void doLoad();
	void doSave();

protected:
	CxbOrder* pOrder;

};
#endif // !defined(EA_84B118E1_A96D_43ea_8EBB_D569FEF43149__INCLUDED_)
