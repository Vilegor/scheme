#pragma once
#include "Exceptions.h"
#include "HEAD.h"

class FileExceptions : public Exception
{
public:
	FileExceptions(void){};
	virtual ~FileExceptions(void){};
	virtual void print() = 0;
};

