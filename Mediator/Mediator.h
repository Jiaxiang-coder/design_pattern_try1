#ifndef CMEDIATOR_H
#define CMEDIATOR_H

#include "../ITry.h"

class CMediator : public CITry
{
public:
	CMediator(void){}
public:
	virtual ~CMediator(void){}
	virtual emJRet Run();
};


#endif
