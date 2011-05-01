#pragma once
class Exception
{
public:
	Exception(void){};
	virtual ~Exception(void){};
	virtual void print() = 0;
};

