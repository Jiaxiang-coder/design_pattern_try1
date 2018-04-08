#ifndef PROXY_H
#define PROXY_H

#include "../ITry.h"

class CProxy : public CITry
{
public:
	CProxy(void){}
public:
	virtual ~CProxy(void){}
	virtual emJRet Run();
};


#endif
