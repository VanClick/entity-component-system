#pragma once

#include "Component.h"

class Com_A: public Component
{
public:
	static int IID;

private:
	int a = 1;

public:
	Com_A();
	virtual ~Com_A();

	static void ReflectPropertys();

	int getAValue()
	{
		return a;
	}

};

