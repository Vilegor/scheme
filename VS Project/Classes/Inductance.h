#pragma once
#include "Element.h"
#include "HEAD.h"
class Inductance : public Element
{
public:
	Inductance(void);
	Inductance(inductance_t inductance);
	~Inductance(void);
	int getType();
	int getValue();
private:
	inductance_t _inductance;
};

