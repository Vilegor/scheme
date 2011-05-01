#include "AlgebraicOperationExeption.h"

AlgebraicOperationExeption::AlgebraicOperationExeption(_TCHAR* cause)
{
	_tcscpy_s(_what, L"An error occurred during the execution of algebraic operation:");
	_tcscpy_s(_cause, cause);
}

void AlgebraicOperationExeption::print( void )
{
	cout << _what << _cause;
}
