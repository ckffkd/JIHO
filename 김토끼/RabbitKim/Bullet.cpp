#include "Bullet.h"
#include "DoubleBuffer.h"
#include "MathManager.h"
#include "ObjectManager.h"


Bullet::Bullet() : Index(0)
{

}

Bullet::~Bullet()
{
	Release();
}

void Bullet::Initialize()
{
	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(2.0f, 1.0f);
	
	Texture[0][0] = (char*)"o¡Ý";
	Texture[0][1] = (char*)"¡Û";
	Texture[0][2] = (char*)"O";
	Texture[0][3] = (char*)"o";

	Texture[1][0] = (char*)"'~¡Ù";
	Texture[1][1] = (char*)"  ¡Å¡ñ*-+";
	Texture[1][2] = (char*)"    ¡ñ¡Å¡Ø>";
	Texture[1][3] = (char*)"  ¡Å¡ñ+~";
	Texture[1][4] = (char*)",~¡Ú";

	 
	Count = 0;
	Speed = 2.0f;
	Active = false;

	Damage = 1;

}

int Bullet::Update()
{
	TransInfo.Position.x += 1.5f;

	if (TransInfo.Position.x >= (120.0f - TransInfo.Scale.x))
		return 1;

	++Count;

	if (Count >= 4)
		Count = 0;


	return 0;
}


void Bullet::Render()
{

	DoubleBuffer::GetInstance()->WriteBuffer(
		int(TransInfo.Position.x - (TransInfo.Scale.x / 2.0f)),
		int(TransInfo.Position.y - (TransInfo.Scale.y / 2.0f)),
		Texture[Index][Count], 11);


	/*
	DoubleBuffer::GetInstance()->WriteBuffer(
		(int)TransInfo.Position.x,
		(int)TransInfo.Position.y,
		(char*)"¡Û¡Ý", 11);
	*/
}

void Bullet::Release()
{
 
}


/*
 '~¡Ù
  ¡Å¡ñ*-+
	 ¡ñ¡Å¡Ø>
   ¡Å¡ñ+~
 ,~¡Ú
*/