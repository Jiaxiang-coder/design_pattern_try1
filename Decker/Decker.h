#ifndef DOCKER_H
#define DOCKER_H
#include "../ITry.h"

class CDecker : public CITry
{
public:
	CDecker(void){}
public:
	virtual ~CDecker(void){}
	virtual emJRet Run();
};


#endif
