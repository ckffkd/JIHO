#pragma once
#include "Scene.h"

class Logo : public Scene
{
private:
	LOGO MyLogo[64];


	LOGO Star;
	LOGO StarTail[27];
	int StarTailCount;

	bool StarCheck;
	ULONG  StarTime;
	ULONG  StarSetTime;

public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	Logo();
	virtual ~Logo();
};

