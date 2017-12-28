#pragma once

#include <string>
using namespace std;

enum PropertyType;

class Property
{
public:
	Property(PropertyType type, int length, string name, int arraySize);
	virtual ~Property();

	static Property* Create(PropertyType type, int length, string name, int arraySize);

private:
	PropertyType type;
	int length;
	string name;
	int arraySize;
};
