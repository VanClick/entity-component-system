#pragma once

#include <vector>
#include <map>
#include <string>
#include "IInterface.h"

using namespace std;

class ComponentInfo;

class EntityInfo
{
public:
	static EntityInfo* Create(string name);
	bool AddComponent(string name);
	int GetSize();
	static IInterface* CreateEntity(string name);

	int getComponentOffset(int index)
	{
		return _componentOffset[index];
	}

private:
	EntityInfo();
	virtual ~EntityInfo();
	IInterface* _CreateEntity(string name);

private:
	static map<string, EntityInfo*> _entityInfoMap;

	string _name;
	vector<ComponentInfo*> _componentInfos;
	int* _componentOffset;

	int offset;
	int _entitySize;
};
