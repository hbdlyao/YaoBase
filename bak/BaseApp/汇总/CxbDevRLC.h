///////////////////////////////////////////////////////////
//  CxbDevRLC.h
//  Implementation of the Class CxbDevRLC
//  Created on:      13-4ÔÂ-2017 13:54:52
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_BA92B014_9589_4def_A7B9_4EA49CBC4C93__INCLUDED_)
#define EA_BA92B014_9589_4def_A7B9_4EA49CBC4C93__INCLUDED_

#include "CmcDevBranch.h"

class CxbDevRLC : public CmcDevBranch
{

public:
	virtual void Add(Component component);
	virtual void Remove(Component component);

};

/**
 * This class (a) represents leaf objects in the composition, and (b) defines
 * behaviour for primitive objects in the composition.
 */
class CxbDevRLC_Leaf : public CxbDevRLC
{

public:
	void Add(Component component) override;
	void Remove(Component component) override;

};

class CxbDevRLC_Composite : public CxbDevRLC
{

public:
	void Add(Component component) override;
	void Remove(Component component) override;

private:
	CxbDevRLC* Children;

};
#endif // !defined(EA_BA92B014_9589_4def_A7B9_4EA49CBC4C93__INCLUDED_)
