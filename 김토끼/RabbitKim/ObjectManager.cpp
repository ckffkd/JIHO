#include "ObjectManager.h"
#include "ObjectFactory.h"
#include "CollisionManager.h"
#include "DoubleBuffer.h"

#include "Bullet.h"
#include "StarBullet.h"
#include "Enemy.h"
#include "Player.h"
#include "KingEnemy.h"
#include "KingBullet.h"

ObjectManager* ObjectManager::m_pInstance = NULL;


ObjectManager::ObjectManager()
{
	
}

ObjectManager::~ObjectManager()
{
	Release();
}


void ObjectManager::AddObject(Object* _pObject)
{
	//** 지금 전달받은 매개변수의 키값을 확인한다.
	//** 만약 기존에 키값이 존재 하지 않는다면 end() 를 반환 함.
	map<string, list<Object*>>::iterator iter = ObjectList.find(_pObject->Getkey());

	//** iter가 ObjectList.end()와 같다면 기존에 키값이 존재하지 않음.
	//** 만약 존재하지 않는다면....
	if (iter == ObjectList.end())
	{
		//** map에 넣을 리스트를 생성.
		list<Object*> TempList;

		//** 생성한 리스트에 전달받은 오브젝트를 추가.
		TempList.push_back(_pObject);

		//** 오브젝트를 추가한 리스트를 오브젝트의 키값으로 map에 추가. 
		ObjectList.insert(make_pair(_pObject->Getkey(), TempList));
	}

	//** 만약 기존에 동일한 키값이 존재 한다면....
	else
		//** 동일한 키값에 있는 리스트에 바로 추가해준다.
		iter->second.push_back(_pObject);

}

void ObjectManager::Initialize()
{


	for (int i = 0; i < 128; ++i)
	{
		ObjectList[OBJID_ENEMY][i] = ObjectFactory<Enemy>::CreateObject();
		BulletList[BULLETID_BULLET][i] = ObjectFactory<Bullet>::CreateObject();
		BulletList[BULLETID_STAR_BULLET][i] = ObjectFactory<StarBullet>::CreateObject();
		KingEnemyBullet[i] = ObjectFactory<KingBullet>::CreateObject();
	}

	pKingEnemy = ObjectFactory<KingEnemy>::CreateObject();

	
	m_BulletID = BULLETID_BULLET;

	Time = (ULONG)GetTickCount64();
	Score = 0;
	BulletCheck = true;
	KingEnemyCheck = false;
}

void ObjectManager::Update()
{
	if (!KingEnemyCheck)
		if (Time + 800 < GetTickCount64())
		{
			Time = (ULONG)GetTickCount64();

			for (int i = 0; i < 128; ++i)
			{
				if (!ObjectList[OBJID_ENEMY][i]->GetActive())
				{
					CreateEnemy(i);
					break;
				}
			}
		}


	
	for (int i = 0; i < OBJID_MAX; ++i)
	{
		for (int j = 0; j < 128; ++j)
		{
			int iResult = 0;

			if (ObjectList[i][j]->GetActive())
				iResult = ObjectList[i][j]->Update();

			if (iResult == 1)
				ObjectList[i][j]->SetActive(false);
		}
	}



	for (int i = 0; i < 128; ++i)
	{
		int iResult = 0;

		if (BulletList[m_BulletID][i]->GetActive())
			iResult = BulletList[m_BulletID][i]->Update();

		if (iResult == 1)
			BulletList[m_BulletID][i]->SetActive(false);
	}

	 
	

		/*
			if (BulletCheck)
			{
				if (Score == 50)
				{
					for (int n = 0; n < 128; ++n)
					{
						SAFE_RELEASE(BulletList[m_BulletID][n]);
		
						BulletList[m_BulletID][n] = ObjectFactory<StarBullet>::CreateObject();
					}
		
					BulletCheck = false;
				}
			}
		
		*/
			 



	if (Score == 300)
		m_BulletID = BULLETID_STAR_BULLET;

	CreateKingEnemy();
	


	
	
		

	// Enemy<->Bullet충돌
	for (int i = 0; i < 128; ++i)
	{
		for (int j = 0; j < 128; ++j)
		{
			if (ObjectList[OBJID_ENEMY][i]->GetActive())
			{
				if (BulletList[m_BulletID][j]->GetActive())
				{
					if (CollisionManager::CollisionRact(
						ObjectList[OBJID_ENEMY][i]->GetTransform(),
						BulletList[m_BulletID][j]->GetTransform()))
					{
						if (ObjectList[OBJID_ENEMY][i]->GetHP() != 0)
						{
							ObjectList[OBJID_ENEMY][i]->Attack(
								BulletList[m_BulletID][j]->GetDamage());
						}

						if(m_BulletID != BULLETID_STAR_BULLET)
							BulletList[m_BulletID][j]->SetActive(false);
						 
					} 
				}
			}
		}

		//Player <-> Enemy 충돌반작ㅂㄴ짝
		
		if (ObjectList[OBJID_ENEMY][i]->GetActive())
		{
			if (CollisionManager::CollisionRact(
				pPlayer->GetTransform(), ObjectList[OBJID_ENEMY][i]->GetTransform()))
			{
				if (((Player*)pPlayer)->GetAttackColl())
				{
					if (ObjectList[OBJID_ENEMY][i]->GetHP() != 0)
					{
						pPlayer->Attack(BulletList[m_BulletID][i]->GetDamage());
						((Player*)pPlayer)->SetAttackColl();

					}
					
				}
			}
		}

	


		//Player<->KingEnemy 충돌 반짝반짝
		if ((pKingEnemy)->GetActive())
		{
			if (CollisionManager::CollisionRact(
				pPlayer->GetTransform(), (pKingEnemy)->GetTransform()))
			{
				if (((Player*)pPlayer)->GetAttackColl())
				{
					if ((pKingEnemy)->GetHP() != 0)
					{
						pPlayer->Attack(BulletList[m_BulletID][i]->GetDamage());
						((Player*)pPlayer)->SetAttackColl();
					}
					else
					{
						((Player*)pPlayer)->SetActive(false);
 
					}
				}
			}
		}

		//KingBullet<->Player
	
		if (KingEnemyBullet[i]->GetActive())
		{
			if (CollisionManager::CollisionRact(
				pPlayer->GetTransform(), KingEnemyBullet[i]->GetTransform()))
			{
				if (((Player*)pPlayer)->GetAttackColl())
				{
					pPlayer->Attack(KingEnemyBullet[i]->GetDamage());
					((Player*)pPlayer)->SetAttackColl();
				}
			}
		}

		
	}


	 
	//KingEnemy<->StarBullet
	for (int j = 0; j < 128; ++j)
	{
		if ((pKingEnemy)->GetActive())
		{
			if (BulletList[m_BulletID][j]->GetActive())
			{
				if (CollisionManager::CollisionRact(
					(pKingEnemy)->GetTransform(),
					BulletList[m_BulletID][j]->GetTransform()))
				{
					if ((pKingEnemy)->GetHP() != 0)
					{ 
						AddScore(10);

						(pKingEnemy)->Attack(
							BulletList[m_BulletID][j]->GetDamage());
						BulletList[m_BulletID][j]->SetActive(false);
					}

					if (m_BulletID != BULLETID_STAR_BULLET)
						BulletList[m_BulletID][j]->SetActive(false);

				}
			}

		}
	}
	 
	 
	if (KingEnemyCheck)
		pKingEnemy->Update();

	 

	
	for (int i = 0; i < 128; ++i)
	{
		if (KingEnemyBullet[i]->GetActive())
		{
			int Result = KingEnemyBullet[i]->Update();

			if (Result == 1)
				KingEnemyBullet[i]->SetActive(false);
		}

	}


	 




	pPlayer->Update();
}

void ObjectManager::Render()
{
	for (int i = 0; i < OBJID_MAX; ++i)
	{
		for (int j = 0; j < 128; ++j)
		{
			if (ObjectList[i][j]->GetActive())
				ObjectList[i][j]->Render();
		}
	}

	for (int i = 0; i < 128; ++i)
	{
		if (BulletList[m_BulletID][i]->GetActive())
			BulletList[m_BulletID][i]->Render();

	}


	//스코어 출력
	DoubleBuffer::GetInstance()->WriteBuffer(5, 1, (char*)"Score : ");
	DoubleBuffer::GetInstance()->WriteBuffer(13, 1,Score);


	//Score
	//DoubleBuffer::GetInstance()->WriteBuffer(102 ,1, (char*)"Score : ");
	//DoubleBuffer::GetInstance()->WriteBuffer(110 ,1, Score);
	if (KingEnemyCheck)
		pKingEnemy->Render();

	pPlayer->Render();

	for (int i = 0; i < 128; ++i)
	{
		if (KingEnemyBullet[i]->GetActive())
		{
			KingEnemyBullet[i]->Render();
		}
	}

}


void ObjectManager::Release()
{
	SAFE_RELEASE(pPlayer);
	
	for (int i = 0; i < OBJID_MAX; ++i)
		for (int j = 0; j < 128; ++j)
			SAFE_RELEASE(ObjectList[i][j]);
}

void ObjectManager::FireBullet()
{
	if (m_BulletID == BULLETID_STAR_BULLET)
	{
		BulletList[m_BulletID][0]->SetActive(true);

		BulletList[m_BulletID][0]->SetPosition(
			pPlayer->GetPosition().x + 6,
			pPlayer->GetPosition().y - 1);
	}
	else
	{
		for (int i = 0; i < 128; ++i)
		{
			if (!BulletList[m_BulletID][i]->GetActive())
			{
				BulletList[m_BulletID][i]->SetActive(true);

				BulletList[m_BulletID][i]->SetPosition(
					pPlayer->GetPosition().x + 6,
					pPlayer->GetPosition().y - 1);

				break;
			}
		}
	}
}

void ObjectManager::CreateKingEnemy()
{
	if (KingEnemyCheck)
		return;

	if (Score == 500) //점수 바꾸기
	{
		pKingEnemy->SetPosition(102, 12);
		pKingEnemy->SetActive(true);
		KingEnemyCheck = true;
	}
}

//KingBullet 생성하ㅡㄴㄴ곳
void ObjectManager::AddKingEnemyBullet()
{
	for (int i = 0; i < 128; ++i)
	{
		if (!KingEnemyBullet[i]->GetActive())
		{
			KingEnemyBullet[i]->SetActive(true);

			KingEnemyBullet[i]->SetPosition(
				int(pKingEnemy->GetPosition().x - (pKingEnemy->GetScale().x / 2)),
				int(pKingEnemy->GetPosition().y + (pKingEnemy->GetScale().y / 2)) );
			  
			break;
		}
	}
}

void ObjectManager::CreateEnemy(int _Index)
{
	ObjectList[OBJID_ENEMY][_Index]->Initialize();
	ObjectList[OBJID_ENEMY][_Index]->SetPosition(105.0f, float(rand() % 25 + 3));
	ObjectList[OBJID_ENEMY][_Index]->SetActive(true);
}

//** 보스가 특정 점수를 달성하면 등장.
//** 보스가 나올때 몬스터가 사라짐.




	/*
	for (int j = 0; j < 128; ++j)
	{
		//(pKingEnemy) 왜 한두방맞고 죽지
		if ((pKingEnemy)->GetActive())
		{
			if (BulletList[m_BulletID][j]->GetActive())
			{
				if (CollisionManager::CollisionRact(
					(pKingEnemy)->GetTransform(),
					BulletList[m_BulletID][j]->GetTransform()))
				{
					if ((pKingEnemy)->GetHP() != 0)
					{
					(pKingEnemy)->Atack(
							BulletList[m_BulletID][j]->GetDamage());
					}

					 if (m_BulletID != BULLETID_STAR_BULLET)
						 BulletList[m_BulletID][j]->SetActive(false);

				}
			}

		}
	}
	*/