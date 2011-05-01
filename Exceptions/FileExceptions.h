#pragma once
#include "Exceptions.h"
#include "SCHEME_H.h"

class FileExceptions : public Exception
{
public:
	FileExceptions(void){};
	virtual ~FileExceptions(void){};
	virtual void print() = 0;
};

