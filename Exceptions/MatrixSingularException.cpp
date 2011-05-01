#include "MatrixSingularException.h"

MatrixSingularException::MatrixSingularException( _TCHAR* cause )
{
//	_tcscpy_s(_what, L"Division by zero: ");
//	_tcscpy_s(_cause, cause);
}

void MatrixSingularException::print( void )
{
	cout << _what << _cause;
}
