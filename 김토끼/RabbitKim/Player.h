#pragma once
#include "Object.h"


class Player : public Object
{
private:
	bool AttackColl;
	ULONG Time;
	
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	void SetAttackColl()
	{
		if (AttackColl)
			return;

		Time = (ULONG)GetTickCount64();
		AttackColl = true;
	}

	bool GetAttackColl() const 
	{
		return !AttackColl;
	}


	void CheckKey();
public:
	Player();
	virtual ~Player();
};

	//char* Texture[5];
	//Object* m_Bullet[128];
