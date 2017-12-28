#include "ComponentInfo.h"
#include "Component.h"

map<string, ComponentInfo*> ComponentInfo::_componentInfoMap;
int ComponentInfo::_sIndex = 0;

ComponentInfo::ComponentInfo(string name, int size)
{
	this->_index = _sIndex++;
	this->size = size;
	_componentInfoMap[name] = this;
}


ComponentInfo::~ComponentInfo()
{
}

ComponentInfo * ComponentInfo::Create()
{
	return nullptr;
}

ComponentInfo * ComponentInfo::GetComponentInfo(string name)
{
	return _componentInfoMap[name];
}

bool ComponentInfo::AddProperty(Property * prop)
{
	_propertys.push_back(prop);
	return false;
}

int ComponentInfo::GetSize()
{
	return size;
}

int ComponentInfo::GetIndex()
{
	return _index;
}
