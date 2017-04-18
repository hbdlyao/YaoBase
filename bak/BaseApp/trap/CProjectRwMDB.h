///////////////////////////////////////////////////////////
//  CProjectRwMDB.h
//  Implementation of the Class CProjectRwMDB
//  Created on:      16-4ÔÂ-2017 11:10:21
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_210C0F30_69F3_43be_8D05_D68D9E9C32B4__INCLUDED_)
#define EA_210C0F30_69F3_43be_8D05_D68D9E9C32B4__INCLUDED_

#include "CMyRw.h"

/**
 * ¹¤³Ì¶ÁÐ´
 */
class CProjectRwMDB : public CRwDbf
{

protected:
	virtual void doLoad();
	virtual void doSave();


public:
	virtual void InitAdo(string vDbf);
};
#endif // !defined(EA_210C0F30_69F3_43be_8D05_D68D9E9C32B4__INCLUDED_)
