#include <iostream>
#include "Com_A.h"
#include "Com_B.h"
#include "EntityInfo.h"
#include "EntityCreater.h"

using namespace std;

int main()
{
	EntityInfo* entityInfo = EntityInfo::Create("MyEntity");
	entityInfo->AddComponent("Com_A");
	entityInfo->AddComponent("Com_B");

	IInterface* entity = EntityInfo::CreateEntity("MyEntity");

	Com_A* com_A;
	entity->Query((IInterface*&)com_A);

	Com_B* com_B;
	com_A->Query((IInterface*&)com_B);

	cout << com_A->getAValue() << " " << com_B->getBValue() << endl;

	int end;
	cin >> end;
}

