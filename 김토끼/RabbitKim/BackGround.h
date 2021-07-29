#pragma once
#include "Object.h"



class BackGround : public Object
{
private:
	Object* m_pAsteroid[ASTEROID_CNT_MAX];

public:
	virtual void Initialize()override;
	virtual int  Update()override;
	virtual void Render()override;
	virtual void Release()override;

public:
	BackGround();
	virtual ~BackGround();
};

