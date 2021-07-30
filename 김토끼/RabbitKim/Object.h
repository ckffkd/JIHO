#pragma once
#include "Headers.h"

class Object
{
protected:
	Transform TransInfo;
	vector<char*> Texture;
	char* Texture[8][8];
	int Motion;
	int Motion_Max;

	int HP;
	int Damage;
	bool Active;
	int Color;

	string strKey;
public:
	virtual void Initialize()PURE;
	virtual int Update()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
public:
	void Attack(const int& _damage ) { HP -= _damage; }
	int GetHP() const { return HP; }
	int GetDamage() const { return Damage; }

	string GetKey() { return strKey; }
public:
	/*
	void SetPosition(float _x, float _y)
	{
		TransInfo.Position.x = _x;
		TransInfo.Position.y = _y;
	}
	*/
	Transform GetTransform() const { return TransInfo; }

	Vector3 GetPosition() const { return TransInfo.Position; }
	void SetPosition(const float& _x, const float& _y) { TransInfo.Position.x = _x; TransInfo.Position.y = _y; }

	Vector3 GetScale() const { return TransInfo.Scale; }

	bool GetActive() const { return Active; }
	void SetActive(const bool& _Active) { Active = _Active; }

	 
public:
	Object();
	virtual ~Object();
};

