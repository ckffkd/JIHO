#include "Object.h"
#include "ObjectpoolManager.h"
#include "PrototypeManager.h"


int main(void)
{
	PrototypeManager::GetInstance()->Initialize();
	
	ULONGLONG Time = GetTickCount64();

	while (true)
	{
		if (Time + 80 < GetTickCount64())
		{
			Time = GetTickCount64();
			system("cls");

			ObjectpoolManager::GetInstance()->Update();
			ObjectpoolManager::GetInstance()->Render();
		}
	}

	return 0;
}