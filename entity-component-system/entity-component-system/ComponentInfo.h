#pragma once

#include <vector>
#include <map>
#include "IInterface.h"
#include "Property.h"

using namespace std;

class Component;

class ComponentInfo
{
public:
	ComponentInfo(string name, int size);
	virtual ~ComponentInfo();

	static ComponentInfo* Create();
	static ComponentInfo* GetComponentInfo(string name);

	virtual bool ConstructComponent(Component* component) = 0;

	bool AddProperty(Property* prop);
	int GetSize();
	int GetIndex();
	static int GetIndexCount()
	{
		return _sIndex;
	}

private:
	static map<string, ComponentInfo*> _componentInfoMap;
	vector<Property*> _propertys;
	int size;
	static int _sIndex;
	int _index;
};
