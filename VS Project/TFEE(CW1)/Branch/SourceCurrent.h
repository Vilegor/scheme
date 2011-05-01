#pragma once
#include "Element.h"
#include "HEAD.h"
class SourceCurrent : public Element
{
public:
	SourceCurrent(void);
	SourceCurrent(amperage_t amperage);
	~SourceCurrent(void);
	int getType();
	int getValue();
private:
	amperage_t _amperage;
};

