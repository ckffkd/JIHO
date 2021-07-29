#pragma once
#include "Headers.h"

class Scene
{
protected:
	Transform TransInfo;
	char* Texture[5];
	
public:
	virtual void Initialize()PURE;
	virtual void Update()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
public:
	Scene();
	virtual ~Scene();
};

