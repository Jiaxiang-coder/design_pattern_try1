#ifndef STRATEGY_H
#define STRATEGY_H

#include "../ITry.h"
class CStrategy : public CITry
{
public:
	CStrategy(void){}
public:
	virtual ~CStrategy(void){}
	virtual emJRet Run();
};

#endif
