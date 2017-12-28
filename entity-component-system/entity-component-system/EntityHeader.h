#pragma once

#include "EntityInfo.h"

class EntityHeader
{
public:
	EntityHeader();
	virtual ~EntityHeader();

	virtual bool Query(int id, IInterface **result);

	EntityInfo* entityInfo;
};

