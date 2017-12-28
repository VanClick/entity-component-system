#pragma once

#include "IInterface.h"
#include "Property.h"
#include "EntityHeader.h"

class EntityInfo;

class Component : public IInterface
{
public:
	friend class EntityInfo;

	Component();
	virtual ~Component();

	template<typename T>
	bool Query(T **result)
	{
		return Query(T::IID, (IInterface **)result);
	}

	virtual bool Query(int id, IInterface **result);

private:
	EntityHeader* entityHeader;
};
