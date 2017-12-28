#include "Com_B.h"
#include "ComponentInfoT.h"
#include "Property.h"
#include "PropertyType.h"

static ComponentInfoT<Com_B>* _sInfo = new ComponentInfoT<Com_B>("Com_B");
int Com_B::IID = _sInfo->GetIndex();

Com_B::Com_B()
{
	b = 10;
}


Com_B::~Com_B()
{
}

void Com_B::ReflectPropertys()
{
	Property * prop = new Property(PropertyType::INT, sizeof(b), "a", 1);
	_sInfo->AddProperty(prop);

}
