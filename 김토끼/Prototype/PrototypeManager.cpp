#include "PrototypeManager.h"
#include "Object.h"

PrototypeManager* PrototypeManager::Instance = nullptr;


PrototypeManager::PrototypeManager()
{

}

PrototypeManager::~PrototypeManager()
{

}

void PrototypeManager::Initialize()
{
	//** Prototype ����
	Transform TransInfo;
	TransInfo.Position = Vector3(0.0f, 0.0f);

	PrototypeList["Object"] = new Object(TransInfo);
}

Object* PrototypeManager::FineObject(string _str)
{
	//** map�� ������Ʈ�� �ִ��� Ȯ��. 
	map<string, Object*>::iterator iter = PrototypeList.find(_str);

	//** ã�� ������Ʈ�� ���ٸ� nullptr �� ��ȯ.
	if (iter == PrototypeList.end())
		return nullptr;

	//** �ƴ϶�� ã�� ������Ʈ�� ��ȯ.
	return iter->second;
}
