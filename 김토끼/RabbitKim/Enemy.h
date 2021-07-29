#pragma once
#include "Object.h"


class Enemy : public Object
{
private:
	char* Texture[4][4][10];
	int Change;
	int Check;
	ULONG Time;
	float Speed;
	int Color;
	ULONG MotionTime;
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
	Enemy();
	virtual ~Enemy();
};

	//char* m_pEnemy[10];
	//int EnemyHeight;
	//int EnemyColor;
 