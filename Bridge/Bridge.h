#ifndef BRIDGE_H
#define BRIDGE_H
#include "../ITry.h"

class CBridge : public CITry
{
public:
	CBridge(void){}
public:
	virtual ~CBridge(void){}
	virtual emJRet Run();
};

#endif
