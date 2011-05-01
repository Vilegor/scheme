#pragma once
#include "Exceptions.h"
class MatrixException : public Exception
{
public:
	MatrixException(void){};
	virtual ~MatrixException(void){};
	virtual void print(void) = 0;
};

