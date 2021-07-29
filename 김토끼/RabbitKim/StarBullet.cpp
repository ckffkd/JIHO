#include "StarBullet.h"
#include "DoubleBuffer.h"
#include "MathManager.h"
#include "ObjectManager.h"



StarBullet::StarBullet()
{

}

StarBullet::~StarBullet()
{
	Release();
}


void StarBullet::Initialize()
{
	Texture[0][0] = (char*)"'~¡Ù";
	Texture[0][1] = (char*)" ¡Å¡ñ*-+";
	Texture[0][2] = (char*)"    ¡ñ¡Å¡Ø>";
	Texture[0][3] = (char*)"  ¡Å¡ñ+~";
	Texture[0][4] = (char*)",~¡Ú";
	
	
	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3((float)strlen("   ¡ñ¡Å¡Ø>"), 5.0f);

	Damage = 5;
	Speed = 3.0f;
	Active = false;
}

int StarBullet::Update()
{
	TransInfo.Position.x += Speed;

	if (TransInfo.Position.x + (TransInfo.Scale.x / 2) >= 117)
		Active = false;

	return 0;
}

void StarBullet::Render()
{
	for (int i = 0; i < 5; ++i)
	{
		DoubleBuffer::GetInstance()->WriteBuffer(
			int(TransInfo.Position.x - (TransInfo.Scale.x / 2.0f)),
			int(TransInfo.Position.y - (TransInfo.Scale.y / 2.0f) + i),
			Texture[0][i], 13);
	}
}

void StarBullet::Release()
{

}