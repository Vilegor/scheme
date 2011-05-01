#pragma once
#include "SCHEME_H.h"
#include "MatrixException.h"

class MatrixSizeException : public MatrixException
{
public:
	MatrixSizeException(_TCHAR* cause);
	~MatrixSizeException(void){};
	void print(void);
private:
	_TCHAR _what[MAX_MESSAGE_LENGTH];
	_TCHAR _cause[MAX_MESSAGE_LENGTH];
};

