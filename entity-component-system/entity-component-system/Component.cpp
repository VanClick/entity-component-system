#include "Component.h"

Component::Component()
{
}

Component::~Component()
{
}

bool Component::Query(int id, IInterface ** result)
{
	return entityHeader->Query(id, result);
}
