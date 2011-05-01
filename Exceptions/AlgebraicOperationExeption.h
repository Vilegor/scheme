#pragma once
#include "SCHEME_H.h"
#include "Exception.h"

class AlgebraicOperationExeption : public Exception
{
public:
	AlgebraicOperationExeption(_TCHAR* cause);
	~AlgebraicOperationExeption(void){};
	void print(void);
private:
	_TCHAR _what[MAX_MESSAGE_LENGTH];
	_TCHAR _cause[MAX_MESSAGE_LENGTH];
};

