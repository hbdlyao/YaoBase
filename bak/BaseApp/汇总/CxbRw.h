#pragma once

#include "CMyRw.h"

class CxbRw : public CRwDbf
{

public:
	virtual void InitAdo(string vDbf);

protected:
	virtual void doLoad();
	virtual void doSave();

};

