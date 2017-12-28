#include "EntityHeader.h"



EntityHeader::EntityHeader()
{
}


EntityHeader::~EntityHeader()
{
}

bool EntityHeader::Query(int id, IInterface ** result)
{
	int offset = entityInfo->getComponentOffset(id);
	if (offset == 0)
	{
		return false;
	}
	*result = (IInterface *)((char*)this + offset);
	return true;
}
