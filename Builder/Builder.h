#ifndef BUILDER_H
#define BUILDER_H

#include "../ITry.h"

class CBuilder : public CITry
{
public:
	CBuilder(void){}
	virtual ~CBuilder(void){}
	virtual emJRet Run();
};


#endif
