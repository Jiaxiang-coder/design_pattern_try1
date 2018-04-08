#ifndef CHAIN_OF_RESPONSIBILITY_H
#define CHAIN_OF_RESPONSIBILITY_H

#include "../ITry.h"

class CChainOfResponsibility : public CITry
{
public:
	CChainOfResponsibility(void){}
public:
	virtual ~CChainOfResponsibility(void){}
	virtual emJRet Run();
};


#endif
