#pragma once
#include "Object.h"

class Bullet : public Object
{
private:
	int Count;
	Object* Target;
	float Speed;
	int Index;

	bool BulletChange;
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	void SetTarget(Object* _Target) { Target = _Target; }
public:
	Bullet();
	virtual ~Bullet();
};

