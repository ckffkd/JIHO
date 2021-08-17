#include "ObjectpoolManager.h"
#include "PrototypeManager.h"
#include "Object.h"

ObjectpoolManager* ObjectpoolManager::Instance = nullptr;



ObjectpoolManager::ObjectpoolManager()
{

}

ObjectpoolManager::~ObjectpoolManager()
{
	Release();
}

void ObjectpoolManager::Update()
{
	if (GetAsyncKeyState(VK_RETURN))
	{
		//** DesableList �� ������ ������Ʈ�� �ִ��� Ȯ�� �ϰ� ���ٸ�...
		if (DesableList.empty())
		{
			//** 5���� ������Ʈ�� �߰� ������ ��...
			Object* pObj = PrototypeManager::GetInstance()->FineObject("Object");

			for (int i = 0; i < 5; ++i)
				DesableList.push_back(pObj->Clone());
		}

		//** �߰� ������ ������Ʈ �ϳ��� ����.
		list<Object*>::iterator iter = DesableList.begin();

		//** �ʱ�ȭ �� �ʿ��� ���� �ۼ�.
		(*iter)->Initialize();

		//** ����� ����Ʈ�� �߰�.
		EnableList.push_back((*iter));

		//** ���� ����Ʈ���� ����.
		DesableList.pop_front();
	}

	for (list<Object*>::iterator iter = EnableList.begin();
		iter != EnableList.end();)
	{
		int iResult = (*iter)->Update();

		if (iResult == 1)
		{
			//** ���� ����Ʈ���� ����.
			DesableList.push_back((*iter));

			//** ����� ����Ʈ�� �߰�.
			iter = EnableList.erase(iter);
		}
		else
			++iter;
	}
}

void ObjectpoolManager::Render()
{
	for (list<Object*>::iterator iter = EnableList.begin();
		iter != EnableList.end(); ++iter)
		(*iter)->Render();

	{
		//** ���� ����Ʈ�� �����ִ� ������Ʈ�� ���� Ȯ��. (DesableList)
		COORD Pos = { (SHORT)10, (SHORT)5 };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);

		string Buffer = "DesableList : " + to_string(DesableList.size());
		cout << Buffer << endl;
	}

	{
		//** ���� ����Ʈ�� �����ִ� ������Ʈ�� ���� Ȯ��. (EnableList)
		COORD Pos = { (SHORT)10, (SHORT)6 };
		string Buffer = "EnableList : " + to_string(EnableList.size());
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
		cout << Buffer << endl;
	}
}

void ObjectpoolManager::Release()
{
	//** DesableList ���� ����
	for (list<Object*>::iterator iter = DesableList.begin();
		iter != DesableList.end(); ++iter)
	{
		delete (*iter);
		(*iter) = nullptr;
	}
	DesableList.clear();


	//** EnableList ���� ����
	for (list<Object*>::iterator iter = EnableList.begin();
		iter != EnableList.end(); ++iter)
	{
		delete (*iter);
		(*iter) = nullptr;
	}
	EnableList.clear();
}
