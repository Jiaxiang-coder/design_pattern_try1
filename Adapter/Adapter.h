#ifndef ADAPTER_H
#define ADAPTER_H

#include "../ITry.h"
class CAdapter : public CITry
{
public:
	CAdapter(void){}
public:
	virtual ~CAdapter(void){}
	virtual emJRet Run();
};







#endif