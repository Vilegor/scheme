#include "MatrixIndexException.h"


MatrixIndexException::MatrixIndexException(_index wrongIndex)
{
	_wrongIndex = wrongIndex;
//	_tcscpy_s(_what, L"Array index out of bounds. index : ");
}

void MatrixIndexException::print( void )
{
	cout << _what << _wrongIndex;
}
