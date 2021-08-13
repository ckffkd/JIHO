#include "PrototypeManager.h"
#include "Object.h"


//Object* pObjList[3];
list<Object*> pObjList;

void InitObject(string _Key)
{
	//** PrototypeManager 에서 원본 객체를 찾아옴.
	Object* pObj = PrototypeManager::GetInstance()->FineObject(_Key);

	//** 찾으려는 객체가 없다면...
	if (pObj == nullptr)
	{
		//** 오류 메시지를 출력하고...
		COORD Pos = { (SHORT)50, (SHORT)15 };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
		cout << "복제할 원본 객체가 없습니다." << endl;

		// ** 함수 종료.
		return;
	}


	// ** 참조된 원형 객체의 복사본을 넘겨줌

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
	//** PrototypeManager 초기화 (초기화가 진행되면 원형객체를 생성한다.)
	PrototypeManager::GetInstance()->Initialize();

	//** 초기화
	InitObject("Object");

	for (list<Object*>::iterator iter = pObjList.begin();
		iter != pObjList.end(); ++iter)
		if ((*iter))
			(*iter)->Render();

	//** 삭제
	for (list<Object*>::iterator iter = pObjList.begin();
		iter != pObjList.end(); ++iter)
	{
		SAFE_DELETE((*iter));
	}
	pObjList.clear();


	return 0;
}


/**********************
 * 초기 구문
 * 변경사항에 대한 구문
 * 출력 구문
 * 삭제
***********************/