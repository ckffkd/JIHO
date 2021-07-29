#pragma once
#include "Object.h"



class KingEnemy : public Object
{
private:
	char* Texture[2][10];
	int Change;
	int Check;
	ULONG Time;
	ULONG BulletTime;

	//Object* pKingBullet[128];

	float Speed;
	int Color;
	ULONG MotionTime;
	 
	int Vertical;

public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;

public:
	void SetMotion(float _speed, int _color, int _check)
	{
		Speed = _speed;
		Color = _color;
		Check = _check;
	}

public:
	KingEnemy();
	virtual ~KingEnemy();
};

