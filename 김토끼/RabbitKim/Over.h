#pragma once
#include "Scene.h"

//플레이어 하트 0개
class Over : public Scene
{
private:
	OVER GOver[8];
	OVER OverKing[12];
	OVER OverEnemy[4];
	OVER OverEnemy2[4];
	OVER OPlayer[8];
public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;

public:
	Over();
	virtual ~Over();
};

