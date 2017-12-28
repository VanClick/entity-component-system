#include <iostream>
#include "Com_A.h"
#include "Com_B.h"
#include "EntityInfo.h"

using namespace std;

int main()
{
	// init entity info
	EntityInfo* entityInfo = EntityInfo::Create("MyEntity");
	entityInfo->AddComponent("Com_A");
	entityInfo->AddComponent("Com_B");

	// create entity
	IInterface* entity = EntityInfo::CreateEntity("MyEntity");

	// query components
	Com_A* com_A = NULL;
	entity->Query(&com_A);

	Com_B* com_B = NULL;
	com_A->Query(&com_B);

	cout << com_A->getAValue() << " " << com_B->getBValue() << endl;

	int end;
	cin >> end;
}

