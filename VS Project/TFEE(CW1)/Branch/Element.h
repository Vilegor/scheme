#pragma once
#include "HEAD.h"
class Element
{
public:
	Element(void);
	~Element(void);
	virtual int getType() = 0;
	virtual int getValue() = 0;
};

