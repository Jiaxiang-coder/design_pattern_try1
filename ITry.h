#pragma once
#include <iostream>
enum emJRet{
	emJOk,
	emJFailed
};

class CITry
{
public:
	CITry(void);
public:
	virtual ~CITry(void);
	virtual emJRet Run();
};
