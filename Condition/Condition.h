#ifndef CONDITION_H
#define CONDITION_H

#include "../ITry.h"

class CCondition : public CITry
{
public:
	CCondition(void){}
public:
	virtual ~CCondition(void){}
	virtual emJRet Run();
};



#endif