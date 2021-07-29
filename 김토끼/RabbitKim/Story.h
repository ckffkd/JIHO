#pragma once
#include "Scene.h"

class Story : public Scene
{
private:
	STORY GameStory[64];
	STORY Frame[48];
	STORY Rabbit[4];
	//int Color;

public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;

public:
	Story();
	virtual ~Story();
};

