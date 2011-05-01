#include "HEAD.h"
#include "MatrixSizeException.h"


MatrixSizeException::MatrixSizeException(_TCHAR* cause)
{
	_tcscpy_s(_what, L"An error occurred during the operation. Incorrect matrix size.");
	_tcscpy_s(_cause, cause);
}

void MatrixSizeException::print( void )
{
	cout << _what << _cause;
}
