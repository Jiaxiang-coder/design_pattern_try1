#ifndef FLYWEIGHT_H
#define FLYWEIGHT_H

#include "../ITry.h"

class CFlyweight : public CITry
{
public:
	CFlyweight(void){}
public:
	virtual ~CFlyweight(void){}
	virtual emJRet Run();
};

#endif
