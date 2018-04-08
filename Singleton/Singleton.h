#ifndef SINGLETON_H
#define SINGLETON_H

#include "../ITry.h"

class CSingleton : public CITry
{
public:
	CSingleton(void){}
public:
	virtual ~CSingleton(void){}
	virtual emJRet Run();
};


#endif
