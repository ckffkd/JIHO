#include "Object.h"

Object::Object()
{

}

Object::~Object()
{

}


void Object::Initialize()
{
	str = "Object";
	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Index = 0;
}

int Object::Update()
{
	return 0;
}

void Object::Render()
{
	COORD Pos = { (SHORT)TransInfo.Position.x, SHORT(TransInfo.Position.y + TransInfo.Index) };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	cout << TransInfo.Index << " : " << str << endl;
}