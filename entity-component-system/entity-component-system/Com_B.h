#pragma once

#include "Component.h"

class Com_B : public Component
{
public:
	static int IID;

private:
	int b = 2;

public:
	Com_B();
	virtual ~Com_B();

	static void ReflectPropertys();

	int getBValue()
	{
		return b;
	}
};

