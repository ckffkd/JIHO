#pragma once
#include "Headers.h"

class Object;
class ObjectManager
{
private:
	static ObjectManager* m_pInstance;
public:
	static ObjectManager* GetInstance()
	{
		if (m_pInstance == NULL)
			m_pInstance = new ObjectManager;
		return m_pInstance;
	}
private:

	map<string, list<Object*>> ObjectList;

	/*
	Object* pPlayer;
	Object* pKingEnemy;
	Object* ObjectList[OBJID_MAX][128];
	Object* BulletList[BULLETID_MAX][128];
	Object* KingEnemyBullet[128];
	*/
	  
	BULLETID m_BulletID;
	OBJID m_ObjID;

	ULONG Time;
	
	int Score;
	bool BulletCheck;
	bool KingEnemyCheck;
public:
	//void SetPlayer(Object* _pPlayer) { pPlayer = _pPlayer; }

	int GetScore() const { return Score; }
	void AddScore(const int& _score ) { Score += _score; }

public:
	void AddObject(Object* _pObject);

	template <typename T>
	void InsertList(const int& _count, const string& _strKey);

	void Initialize();
	void Update();
	void Render();
	void Release();

public:
	void FireBullet();
	void CreateKingEnemy();
	void AddKingEnemyBullet();
	void CreateEnemy(int _Index);
private:
	ObjectManager();
public:
	~ObjectManager();
};

