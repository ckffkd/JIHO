#pragma once
#include "Headers.h"

class Object;
class ObjectpoolManager
{
private:
	static ObjectpoolManager* Instance;
public:
	static ObjectpoolManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new ObjectpoolManager;
		return Instance;
	}
private:
	//** 실제 사용한 오브젝트 (랜더링 될 오브젝트 리스트)
	list<Object*> EnableList;

	//** 사용을 마친 오브젝트 리스트 (랜더링 되지 않음)
	list<Object*> DesableList;

public:
	ObjectpoolManager();
	~ObjectpoolManager();
};