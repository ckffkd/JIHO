#pragma once
#include "Object.h"

class Asteroid : public Object
{
private:
	char* m_pAsteroid[10];
	int AsteroidHeight;
	int AsteroidColor;
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	void SetAsteroidColor();
public:
	Asteroid();
	virtual ~Asteroid();
};

