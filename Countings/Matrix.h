#pragma once
#include <iomanip> /////for consoleOutput only!!!
#include "SCHEME_H.h"
#include "Exceptions/MatrixException.h"
#include "Exceptions/MatrixSizeException.h"
#include "Exceptions/MatrixIndexException.h"
#include "Exceptions/MatrixSingularException.h"

template<class Type>
class Matrix
{
public:
	Matrix(void);
	Matrix(size_t scaleX, size_t scaleY);
	Matrix(size_t scaleXY);        /* creates square matrix */
	Matrix(const Matrix& nativeMatrix);
	~Matrix(void);
	void resize(size_t newScaleX, size_t newScaleY);
	size_t getHeight(void);
	size_t getWidth(void);
	void initialize();
	void initialize(Type** baseArray, size_t arraySizeX, size_t arraySizeY);
	_testing void consoleOutput();
	Matrix<Type>& operator = (const Matrix& baseMatrix);
	Matrix<Type>& operator = (Type value);    /* returns matrix which contains value in its diagonal*/
	Matrix<Type> operator + (const Matrix& baseMatrix);
	Matrix<Type> operator - (const Matrix& baseMatrix);
	Matrix<Type> operator - (void);
	Matrix<Type> operator * (const Matrix& baseMatrix);
	Matrix<Type> operator * (Type coefficient);
	Matrix<Type> operator / (Type coefficient);
	Matrix<Type> operator ^ (int power);
	Type* operator [] (_index i);
        Matrix<Type> diag(void);        /* returns matrix which contains diagonal elements of the base matrix*/
	Matrix<Type> inverseValues(void);   /* returns matrix which consists of the inverse elements of the base matrix */
	                                    /* this is an equivalent of 1/baseMatrix */
	Matrix<Type> transposition(void);   /* returns transposed base matrix */
	Matrix<Type> cofactor(_index i0, _index j0);   /* returns cofactor of the selected element */
	Type det();    /* returns determinant of the base matrix */
private:
	Type** _data;        /* matrix of values */
	size_t _scaleX;      /* number of columns of the matrix */
	size_t _scaleY;      /* number of strings of the matrix */
};

template<class Type>
Type Matrix<Type>::det()
{
	if(_scaleX != _scaleY)
	{
		MatrixSizeException* e = new MatrixSizeException(L"Matrix must be square!");
		throw e;
	}

	Type determinant;
	if (_scaleX == MIN_MATRIX_SIZE)   /* для матрицы состоящей только из одного числа(т.е. явл. числом)
						              определитель равен этому числу */
	{
		determinant = _data[0][0];
		return determinant;
	}
	if(_scaleX == MIN_SQUARE_MATRIX_SIZE)
	{
		determinant = _data[0][0] * _data[1][1] - _data[0][1] * _data[1][0];
	}
	else
	{
		determinant = 0;
		for (_index curPos = 0; curPos < _scaleX; curPos++)  /* определение детерминанта по элементам первой строки */
		{
			Matrix<Type> A = this->cofactor(FIRST_STRING_INDEX, curPos);
			if (( (curPos+1) + (FIRST_STRING_INDEX+1) ) % 2 == 0)
			{
				determinant += _data[FIRST_STRING_INDEX][curPos] * A.det(); /*рекурсивный вызов функции 
				                                     нахождения определителя алгебраического дополнения*/
			}
			else
			{
				determinant -= _data[FIRST_STRING_INDEX][curPos] * A.det();
			}
		}
	}
	return determinant;
}


template<class Type>
Matrix<Type> Matrix<Type>::cofactor( _index i0, _index j0 )
{
	Matrix<Type> A(_scaleX - 1, _scaleY - 1);
	for (_index i = 0; i < _scaleY; i++)
	{
		if (i == i0)
		{
			continue;
		}
		for (_index j = 0; j < _scaleX; j++)
		{
			if (j < j0)
			{
				if (i < i0)
				{
					A._data[i][j] = _data[i][j];
				} 
				else
				{
					A._data[i-1][j] = _data[i][j];
				}
			}
			if (j > j0)
			{
				if (i < i0)
				{
					A._data[i][j-1] = _data[i][j];
				} 
				else
				{
					A._data[i-1][j-1] = _data[i][j];
				}
			}
		}
	}
	return A;
}


template<class Type>
Matrix<Type> Matrix<Type>::transposition( void )
{
	Matrix<Type> result(_scaleY, _scaleX);
	for (_index i = 0; i < _scaleX; i++)
	{
		for (_index j = 0; j < _scaleY; j++)
		{
			result._data[i][j] = _data[j][i];
		}
	}
	return result;
}


template<class Type>
Matrix<Type> Matrix<Type>::inverseValues( void )
{
	Matrix<Type> result(*this);
	for (_index i = 0; i < _scaleY; i++)
	{
		for (_index j = 0; j < _scaleX; j++)
		{
			if (result._data[i][j] != 0)
			{
				result._data[i][j] = 1 / result._data[i][j];
			}
		}
	}
	return result;
}


template<class Type>
Matrix<Type> Matrix<Type>::diag( void )
{
	if (_scaleX == 1)
	{
		Matrix<Type> result(_scaleY, _scaleY);
		for (_index i = 0; i < result._scaleY; i++)
		{
			for (_index j = 0; j < result._scaleX; j++)
			{
				if (i == j)
				{
					result._data[i][j] = _data[i][0];
				}
				else 
				{
					result._data[i][j] = NULL;
				}
			}
		}
		return result;
	} 
	if (_scaleY == 1)
	{
		Matrix<Type> result(_scaleX, _scaleX);
		for (_index i = 0; i < result._scaleX; i++)
		{
			for (_index j = 0; j < result._scaleY; j++)
			{
				if (i == j)
				{
					result._data[i][j] = _data[0][i];
				}
				else 
				{
					result._data[i][j] = NULL;
				}
			}
		}
		return result;
	}

	if (_scaleX != _scaleY)
	{
		MatrixSizeException* e = new MatrixSizeException(L"Matrix must be square!");
		throw e;
	}
	Matrix<Type> result(1, _scaleY);
	for (_index i = 0; i < _scaleY; i++)
	{
		result._data[i][0] = _data[i][i];
	}
	return result;
}


template<class Type>
Type* Matrix<Type>::operator[]( _index i )
{
	if (i < 0 || i > _scaleY-1)
	{
		MatrixIndexException *e = new MatrixIndexException(i);
		throw e;
	}
	return _data[i];
}


template<class Type>
Matrix<Type> Matrix<Type>::operator^( int power )
{
	if (_scaleX != _scaleY)
	{
		MatrixSizeException* e = new MatrixSizeException(L"Matrix must be square!");
		throw e;
	}

	Matrix<Type> result(_scaleX, _scaleY);
	if (power == 0)
	{
		result = 1;     /* создание единичной матрицы */
		return result;
	}

	Matrix<Type> nativeMatrix(*this);
	if (power < 0)   /* получение обратной матрицы */
	{
		if (this->det() == 0)
		{
			MatrixSingularException* e = new MatrixSingularException(L"Determinant must be non-nil!");
			throw e;
		}
		Matrix<Type> CofactorMatrix(_scaleX, _scaleY);
		for (_index i = 0; i < _scaleY; i++)
		{
			for (_index j = 0; j < _scaleX; j++)
			{
				if ((i+1 + j+1) % 2 == 0)
				{
					CofactorMatrix[j][i] = this->cofactor(i, j).det();
				}
				else
				{
					CofactorMatrix[j][i] = -this->cofactor(i, j).det();
				}
			}
		}
		result = CofactorMatrix * ( 1/(this->det()) );
		nativeMatrix = result;
		power *= -1;
	}
	else
	{
		result.initialize(_data, _scaleX, _scaleY);
	}
	for (int curPower = power; curPower > 1; curPower--)
	{
		result = result * nativeMatrix;
	}
	return result;
}


template<class Type>
Matrix<Type> Matrix<Type>::operator/( Type coefficient )
{
	if (coefficient == 0)
	{
		AlgebraicOperationExeption* e = new AlgebraicOperationExeption(L"You cannot divide by zero!");
		throw e;
	}
	Matrix<Type> result(*this);

	for (_index i = 0; i < result._scaleY; i++)
	{
		for (_index j = 0; j < result._scaleX; j++)
		{
			result._data[i][j] /= coefficient;
		}
	}
	return result;
}



template<class Type>
Matrix<Type> Matrix<Type>::operator*( const Matrix& baseMatrix )
{
	if (_scaleX != baseMatrix._scaleY)
	{
		MatrixSizeException* e = new MatrixSizeException(L"Width of the first matrix and height of the second matrix doesn't match!");
		throw e;
	}

	Matrix<Type> result(baseMatrix._scaleX, _scaleY);
	for (_index i = 0; i < result._scaleY; i++)
	{
		for (_index j = 0; j < result._scaleX; j++)
		{
			result._data[i][j] = NULL;
			for (_index r = 0; r < _scaleX; r++)
			{
				result._data[i][j] += _data[i][r]*baseMatrix._data[r][j];
			}
		}
	}
	return result;
}


template<class Type>
Matrix<Type> Matrix<Type>::operator*( Type coefficient )
{
	Matrix<Type> result(*this);

	for (_index i = 0; i < result._scaleY; i++)
	{
		for (_index j = 0; j < result._scaleX; j++)
		{
			result._data[i][j] *= coefficient;
		}
	}
	return result;
}


template<class Type>
Matrix<Type> Matrix<Type>::operator+( const Matrix& baseMatrix )
{
	if (_scaleX != baseMatrix._scaleX && _scaleY != baseMatrix._scaleY)
	{
		MatrixSizeException* e = new MatrixSizeException(L"Sizes of the matrices don't match!");
		throw e;
	}

	Matrix<Type> result(*this);
	for (_index i = 0; i < result._scaleY; i++)
	{
		for (_index j = 0; j < result._scaleX; j++)
		{
			result._data[i][j] += baseMatrix._data[i][j];
		}
	}
	return result;
}


template<class Type>
Matrix<Type> Matrix<Type>::operator-( const Matrix& baseMatrix )
{
	if (_scaleX != baseMatrix._scaleX && _scaleY != baseMatrix._scaleY)
	{
		MatrixSizeException* e = new MatrixSizeException(L"Sizes of the matrices don't match!");
		throw e;
	}

	Matrix<Type> result(*this);
	for (_index i = 0; i < result._scaleY; i++)
	{
		for (_index j = 0; j < result._scaleX; j++)
		{
			result._data[i][j] -= baseMatrix._data[i][j];
		}
	}
	return result;
}


template<class Type>
Matrix<Type> Matrix<Type>::operator-( void )
{
	Matrix<Type> result(*this);
	for (_index i = 0; i < result._scaleY; i++)
	{
		for (_index j = 0; j < result._scaleX; j++)
		{
			result._data[i][j] = -result._data[i][j];
		}
	}
	return result;
}


template<class Type>
Matrix<Type>& Matrix<Type>::operator=( Type value )
{
	if (_scaleX != _scaleY)
	{
		MatrixSizeException* e = new MatrixSizeException(L"Matrix must be square!");
		throw e;
	}
	for (_index i = 0; i < _scaleY; i++)
	{
		for (_index j = 0; j < _scaleX; j++)
		{
			if (i == j)
			{
				_data[i][j] = value;
			} 
			else
			{
				_data[i][j] = NULL;
			}
		}
	}
	return *this;
}


template<class Type>
Matrix<Type>& Matrix<Type>::operator=( const Matrix& baseMatrix )
{
	if (_scaleX != baseMatrix._scaleX && _scaleY != baseMatrix._scaleY)
	{
		for (_index i = 0; i < _scaleY; i++)
		{
			delete []_data[i];
		}
		_scaleX = baseMatrix._scaleX;
		_scaleY = baseMatrix._scaleY;
		
		_data = new Type*[_scaleY];
		for ( _index i = 0; i < _scaleY; i++)
		{
			_data[i] = new Type[_scaleX];
		}
		initialize(baseMatrix._data, baseMatrix._scaleX, baseMatrix._scaleY);
	}
	else
	{
		for (_index i = 0; i < _scaleY; i++)
		{
			for (_index j = 0; j < _scaleX; j++)
			{
				_data[i][j] = baseMatrix._data[i][j];
			}
		}
	}
	return *this;
}


template<class Type>
_testing void Matrix<Type>::consoleOutput()
{
	for (_index i = 0; i < _scaleY; i++)
	{
		cout << "| ";
		for (_index j = 0; j < _scaleX; j++)
		{
			cout << std::setw(3) << std::setprecision(3) << _data[i][j];
			cout << " ";
		}
		cout << "|" << endl;
	}

	cout << endl;
}


template<class Type>
size_t Matrix<Type>::getWidth( void )
{
	return _scaleX;
}


template<class Type>
size_t Matrix<Type>::getHeight( void )
{
	return _scaleY;
}


template<class Type>
void Matrix<Type>::resize( size_t newScaleX, size_t newScaleY )
{
	Type** newData;
	newData = new Type*[newScaleY];
	for (_index i = 0; i < newScaleY; i++)
	{
		newData[i] = new Type[newScaleX];
		for (_index j = 0; j < newScaleX; j++)
		{
			newData[i][j] = NULL;
		}
	}
	for(_index i = 0; i < _scaleX && i < newScaleX; i++)
	{
		for (_index j = 0; j < _scaleX && j < newScaleX; j++)
		{
			newData[i][j] = _data[i][j];
		}
	}

	for (_index i = 0; i < _scaleY; i++)
	{
		delete []_data[i];
	}
	delete []_data;
	_data = newData;
	_scaleX = newScaleX;
	_scaleY = newScaleY;
}


template<class Type>
void Matrix<Type>::initialize( Type** initArray, size_t arraySizeX, size_t arraySizeY )
{
	for (_index i = 0; i < _scaleY && i < arraySizeY; i++)
	{
		for ( _index j = 0; j < _scaleX && j < arraySizeX; j++)
		{
			_data[i][j] = initArray[i][j];
		}
	}
}


template<class Type>
void Matrix<Type>::initialize()
{
	for (_index i = 0; i < _scaleY; i++)
	{
		for (_index j = 0; j < _scaleX; j++)
		{
			cout << "M" << i+1 << j+1 <<" = ";
			cin >> _data[i][j];
		}
	}
}


template<class Type>
Matrix<Type>::Matrix( size_t scaleX, size_t scaleY )
{
	if (scaleX == 0 || scaleY == 0)
	{
		MatrixSizeException* e = new MatrixSizeException(L"Matrix can't have zero size!");
		throw e;
	}
	_scaleX = scaleX;
	_scaleY = scaleY;
	_data = new Type*[_scaleY];
	for ( _index i = 0; i < _scaleY; i++)
	{
		_data[i] = new Type[_scaleX];
		for (_index j = 0; j < _scaleX; j++)
		{
			_data[i][j] = NULL;
		}
	}
}


template<class Type>
Matrix<Type>::Matrix( size_t scaleXY )
{
	if (scaleXY == 0)
	{
		MatrixSizeException* e = new MatrixSizeException(L"Matrix can't have zero size!");
		throw e;
	}
	_scaleX = scaleXY;
	_scaleY = scaleXY;
	_data = new Type*[_scaleY];
	for ( _index i = 0; i < _scaleY; i++)
	{
		_data[i] = new Type[_scaleX];
		for (_index j = 0; j < _scaleX; j++)
		{
			_data[i][j] = NULL;
		}
	}
}


template<class Type>
Matrix<Type>::Matrix( const Matrix& nativeMatrix )
{
	_scaleX = nativeMatrix._scaleX;
	_scaleY = nativeMatrix._scaleY;
	_data = new Type*[_scaleY];
	for ( _index i = 0; i < _scaleY; i++)
	{
		_data[i] = new Type[_scaleX];
		for (_index j = 0; j < _scaleX; j++)
		{
			_data[i][j] = nativeMatrix._data[i][j];
		}
	}
}


template<class Type>
Matrix<Type>::Matrix( void )
{
	_scaleX = MIN_MATRIX_SIZE;
	_scaleY = MIN_MATRIX_SIZE;
	_data = new Type*[_scaleY];
	_data[0] = new Type;
	_data[0][0] = NULL;
}


template<class Type>
Matrix<Type>::~Matrix( void )
{
	for (_index i = 0; i < _scaleY; i++)
	{
		delete []_data[i];
	}
	delete []_data;
}
