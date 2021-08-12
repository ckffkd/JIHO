#include "PrototypeManager.h"
#include "Object.h"


//Object* pObjList[3];
list<Object*> pObjList;

void InitObject(string _Key)
{
	//** PrototypeManager ���� ���� ��ü�� ã�ƿ�.
	Object* pObj = PrototypeManager::GetInstance()->FineObject(_Key);

	//** ã������ ��ü�� ���ٸ�...
	if (pObj == nullptr)
	{
		//** ���� �޽����� ����ϰ�...
		COORD Pos = { (SHORT)50, (SHORT)15 };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
		cout << "������ ���� ��ü�� �����ϴ�." << endl;

		// ** �Լ� ����.
		return;
	}


	// ** ������ü�� ���������� �����ߴٸ�...
	else
	{
		int i = 0;

		// ** ������ ���� ��ü�� ���纻�� �Ѱ���
		pObjList.push_back(pObj->Clone());

		for (list<Object*>::iterator iter = pObjList.begin();
			iter != pObjList.end(); ++iter)
		{
			// ** �׸��� ���纻�� �ʱ�ȭ��.
			(*iter)->Initialize();

			// ** ���纻�� �ε������� ����.
			(*iter)->SetIndex(i + 1);
		}
	}
}

int main(void)
{
	//** PrototypeManager �ʱ�ȭ (�ʱ�ȭ�� ����Ǹ� ������ü�� �����Ѵ�.)
	PrototypeManager::GetInstance()->Initialize();

	//** �ʱ�ȭ
	InitObject("Object");


	int i = 0;
	for (list<Object*>::iterator iter = pObjList.begin();
		iter != pObjList.end(); ++iter)
		if ((*iter))
			(*iter)->Render(i);

	//** ����
	for (list<Object*>::iterator iter = pObjList.begin();
		iter != pObjList.end(); ++iter)
	{
		SAFE_DELETE((*iter));
	}
	pObjList.clear();


	return 0;
}


/**********************
 * �ʱ� ����
 * ������׿� ���� ����
 * ��� ����
 * ����
***********************/

