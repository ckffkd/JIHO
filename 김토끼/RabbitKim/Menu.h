#pragma once
#include "Scene.h"

class Menu : public Scene
{
private:
	MENU MyMenu[3];

	int Choice;
	float Sleep;
public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	Menu();
	virtual ~Menu();
};

