#ifndef ASSEMBLY_PATERN_H
#define ASSEMBLY_PATERN_H

#include "../ITry.h"

class CAssemblyPattern : public CITry
{
public:
	CAssemblyPattern(void){}
	virtual ~CAssemblyPattern(void){}
	virtual emJRet Run();
};

#endif
