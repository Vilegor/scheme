#pragma once
#include "Element.h"
#include "HEAD.h"

class Capacity : public Element
{
public:
	Capacity(void);
	Capacity(capacity_t capacity);
	~Capacity(void);
	int getType();
	int getValue();
private:
	capacity_t _capacity;
};

