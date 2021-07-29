#pragma once
#include "Object.h"

class Enemy2 : public Object
{
private:
	float Speed;
	int Color;
	
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;

public:
	Enemy2();
	virtual ~Enemy2();
};

