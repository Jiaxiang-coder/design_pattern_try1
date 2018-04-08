#ifndef FACTORY_H
#define FACTORY_H
#include "../ITry.h"
class CFactory : public CITry
{
public:
	CFactory(void){}
public:
	virtual ~CFactory(void){}
	virtual emJRet Run();
};


#endif
