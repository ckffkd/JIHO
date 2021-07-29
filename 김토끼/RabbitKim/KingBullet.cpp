#include "KingBullet.h"
#include "DoubleBuffer.h"
#include "ObjectManager.h"
#include "KingEnemy.h"


KingBullet::KingBullet()
{

}

KingBullet::~KingBullet()
{

}

void KingBullet::Initialize()
{
	Motion = 0;
	Motion_Max = 2;


	Texture[0][0] = (char*)"   .";
	Texture[0][1] = (char*)" _¡Ø¡Ø_";
	Texture[0][2] = (char*)"  ¡Ø¡Ø";
	Texture[0][3] = (char*)"   '";

	Texture[1][0] = (char*)"   ¢¬|¢¬";
	Texture[1][1] = (char*)"¢¬_+¡Ø¡Ø+_¢¬";
	Texture[1][2] = (char*)"   +¡Ø¡Ø+";
	Texture[1][3] = (char*)"    '|'";


	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3((float)strlen("¢¬_+¡Ø¡Ø+_¢¬"), 4.0f);

	Speed = 2.0f;
	Active = false;
	Count = 0;

	Color = 14;

	Time = (ULONG)GetTickCount64();
	MotionTime = 500;
	Check = 0;
	Damage = 5; 

}



int KingBullet::Update()
{
	TransInfo.Position.x -= 1.5f;

	 
	if (Time + MotionTime < GetTickCount64())
	{
		Time = (ULONG)GetTickCount64();
		Motion = !Motion;
		 
	}  



	if ((TransInfo.Position.x - (TransInfo.Scale.x / 2.0f)) < 1)
		return 1;
	  

	return 0;
}

void KingBullet::Render()
{
	for (int i = 0; i < 4; i++)
	{
		DoubleBuffer::GetInstance()->WriteBuffer(
			int(TransInfo.Position.x - (TransInfo.Scale.x / 2.0f)),
			int(TransInfo.Position.y - (TransInfo.Scale.y / 2.0f)) + i,
			Texture[Motion][i], Color);
	}
}

void KingBullet::Release()
{

}

