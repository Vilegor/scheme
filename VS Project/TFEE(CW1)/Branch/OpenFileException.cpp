#include "OpenFileException.h"


OpenFileException::OpenFileException(_TCHAR *filename){
	_tcscpy_s(_what,L"An error occurred while opening file:");
	_tcscpy_s(_filename,filename);
}

OpenFileException::~OpenFileException(void){
}

void OpenFileException::print(){
	wcout<<_what<<_filename;
}
