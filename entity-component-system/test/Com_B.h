#pragma once

#include "Component.h"

class Com_B : public Component
{
public:
	Com_B();
	~Com_B();

	int getBValue()
	{
		return 2;
	}
};

