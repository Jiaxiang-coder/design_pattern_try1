#ifndef OBSERVER_H
#define OBSERVER_H

#include "../ITry.h"

class CObserver : public CITry
{
public:
	CObserver(void){}
public:
	virtual ~CObserver(void){}
	virtual emJRet Run();
};


#endif