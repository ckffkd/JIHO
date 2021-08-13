#pragma once
#include "Headers.h"

class Object
{
private:
	string str;
	Transform TransInfo;
public:
	void Initialize();
	int Update();
	void Render();
public:
	//** Ŭ�а�ü�� ����.
	Object* Clone() { return new Object(*this); }

	void SetIndex(int _index) { TransInfo.Index = _index; }
public:
	Object();
	Object(const Transform& _TransInfo) : TransInfo(_TransInfo) { }
	~Object();
};