#include "Property.h"

Property::Property(PropertyType type, int length, string name, int arraySize)
{
	this->type = type;
	this->length = length;
	this->name = name;
	this->arraySize = arraySize;
}


Property::~Property()
{
}

Property * Property::Create(PropertyType type, int length, string name, int arraySize)
{
	return nullptr;
}
