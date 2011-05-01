#pragma once
#include "FileExceptions.h"
#include "SCHEME_H.h"

class OpenFileException : public FileExceptions
{
public:
        OpenFileException(_TCHAR *filename);
	~OpenFileException(void);
	void print();
private:
        _TCHAR _what[MAX_MESSAGE_LENGTH];
        _TCHAR _filename[MAX_FILENAME_LENGTH];
};

