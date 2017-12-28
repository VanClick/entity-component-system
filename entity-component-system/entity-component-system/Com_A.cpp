#include "Com_A.h"
#include "Property.h"
#include "PropertyType.h"
#include "ComponentInfoT.h"

static ComponentInfoT<Com_A>* _sInfo = new ComponentInfoT<Com_A>("Com_A");
int Com_A::IID = _sInfo->GetIndex();

Com_A::Com_A()
{
	a = 5;
}


Com_A::~Com_A()
{
}

void Com_A::ReflectPropertys()
{
	Property * prop = new Property(PropertyType::INT, sizeof(a), "a", 1);
	_sInfo->AddProperty(prop);
}
