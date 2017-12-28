#include "EntityInfo.h"
#include "Component.h"
#include "ComponentInfo.h"
#include "EntityHeader.h"

map<string, EntityInfo*> EntityInfo::_entityInfoMap;

EntityInfo::EntityInfo()
{
	offset = sizeof(EntityHeader);
}

EntityInfo::~EntityInfo()
{
}

EntityInfo * EntityInfo::Create(string name)
{
	EntityInfo* entityInfo = new EntityInfo();
	entityInfo->_name = name;
	entityInfo->_entitySize = sizeof(EntityHeader);
	entityInfo->_componentOffset = new int[ComponentInfo::GetIndexCount()];
	memset(entityInfo->_componentOffset, 0, sizeof(ComponentInfo::GetIndexCount() * sizeof(int)));

	_entityInfoMap[name] = entityInfo;

	return entityInfo;
}

bool EntityInfo::AddComponent(string name)
{
	ComponentInfo* componentInfo = ComponentInfo::GetComponentInfo(name);
	if (componentInfo != NULL)
	{
		_entitySize += componentInfo->GetSize();
		_componentInfos.push_back(componentInfo);
		_componentOffset[componentInfo->GetIndex()] = offset;
		offset += componentInfo->GetSize();
		return true;
	}
	return false;
}

int EntityInfo::GetSize()
{
	return _entitySize;
}

IInterface * EntityInfo::CreateEntity(string name)
{
	EntityInfo* entityInfo = _entityInfoMap[name];
	if (entityInfo != NULL)
	{
		return entityInfo->_CreateEntity(name);
	}

	return nullptr;
}

IInterface* EntityInfo::_CreateEntity(string name)
{
	char* entity = (char*)malloc(_entitySize);
	if (entity != NULL)
	{
		memset(entity, 0, _entitySize);

		EntityHeader * header = new(entity) EntityHeader();
		header->entityInfo = this;

		entity += sizeof(EntityHeader);

		for (int i = 0, offset = 0; i < _componentInfos.size(); i++)
		{
			Component* com = (Component*)(entity + offset);
			_componentInfos[i]->ConstructComponent((Component*)(entity + offset));
			com->entityHeader = header;
			offset += _componentInfos[i]->GetSize();
		}

		return (IInterface*)entity;
	}

	return nullptr;
}
