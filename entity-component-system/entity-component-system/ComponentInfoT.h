#pragma once

#include "ComponentInfo.h"

class Component;

template<typename T>
class ComponentInfoT :public ComponentInfo
{
public:
	ComponentInfoT(string name)
		:ComponentInfo(name, sizeof(T))
	{
	}
	virtual ~ComponentInfoT() {}

	virtual bool ConstructComponent(Component* com)
	{
		com = new(com) T();
		return true;
	}
};
