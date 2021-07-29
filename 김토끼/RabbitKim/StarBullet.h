#pragma once
#include "Object.h"

class StarBullet : public Object
{
private:	
	Object* Target;
	float Speed;
	
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;

public:
	void SetTarget(Object* _Target) { Target = _Target; }
public:
	StarBullet();
	virtual ~StarBullet();
};
