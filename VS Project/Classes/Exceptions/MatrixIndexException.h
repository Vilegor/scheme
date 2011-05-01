#pragma once
#include "HEAD.h"
#include "MatrixException.h"

class MatrixIndexException : public MatrixException
{
public:
	MatrixIndexException(_index wrongIndex);
	~MatrixIndexException(void){};
	void print(void);
private:
	_TCHAR _what[MAX_MESSAGE_LENGTH];
	_index _wrongIndex;
};

