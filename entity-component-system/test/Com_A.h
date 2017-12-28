#pragma once

#include "Component.h"

class Com_A: public Component
{
public:
	Com_A();
	~Com_A();

	int getAValue()
	{
		return 1;
	}
};

