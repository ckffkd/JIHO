#pragma once
#include "Scene.h"

class Ending : public Scene
{
private:

	ENDING EndPlayer[6];
	ENDING EndFriend[8];
	ENDING GEnding[64];

public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;

public:
	Ending();
	virtual ~Ending();
};

