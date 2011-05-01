#pragma once
#include "SCHEME_H.h"
#include "MatrixException.h"

class MatrixSingularException : public MatrixException
{
public:
	MatrixSingularException(_TCHAR* cause);
	~MatrixSingularException(void){};
	void print(void);
private:
	_TCHAR _what[MAX_MESSAGE_LENGTH];
	_TCHAR _cause[MAX_MESSAGE_LENGTH];
};

