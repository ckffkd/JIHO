#pragma once
#include "Object.h"

class KingBullet : public Object
{
private:
	int Count;
	int Check;
	ULONG Time;

	Object* Target;
	
	float Speed;
	ULONG MotionTime;

public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;

public:
	void SetTarget(Object* _Target) { Target = _Target; } 
public:
	KingBullet();
	virtual ~KingBullet();
};

