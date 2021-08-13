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


	// ** ������ ���� ��ü�� ���纻�� �Ѱ���

	for (int i = 0; i < 3; ++i)
	{
		Object* pTempObj = pObj->Clone();
		
		pTempObj->Initialize();
		pTempObj->SetIndex(i + 1);

		pObjList.push_back(pTempObj);
	}
}

int main(void)
{
	//** PrototypeManager �ʱ�ȭ (�ʱ�ȭ�� ����Ǹ� ������ü�� �����Ѵ�.)
	PrototypeManager::GetInstance()->Initialize();

	//** �ʱ�ȭ
	InitObject("Object");

	for (list<Object*>::iterator iter = pObjList.begin();
		iter != pObjList.end(); ++iter)
		if ((*iter))
			(*iter)->Render();

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