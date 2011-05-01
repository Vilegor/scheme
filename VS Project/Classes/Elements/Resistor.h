#pragma once
#include "Element.h"
#include "HEAD.h"
class Resistor : public Element
{
public:
	Resistor(void);
	Resistor(resistance_t resistance);
	~Resistor(void);
	int getType();
	int getValue();
private:
	resistance_t _resistance;	
};

