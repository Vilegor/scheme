#pragma once
#include "Element.h"
#include "HEAD.h"

class SourceDC : public Element
{
public:
	SourceDC(void);
	SourceDC(voltage_t voltage);
	~SourceDC(void);
	int getType();
	int getValue();
private:
	voltage_t _voltage;
};

