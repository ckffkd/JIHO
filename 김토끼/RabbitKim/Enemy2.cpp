#include "Enemy2.h"
#include "DoubleBuffer.h"



Enemy2::Enemy2()
{

}

Enemy2::~Enemy2()
{
	
}


void Enemy2::Initialize()
{
	Texture[0] = (char*)"    /\\_/\\";
	Texture[1] = (char*)"(��((@v@))/)";
	Texture[2] = (char*)"  (��:::/) ";
	Texture[3] = (char*)"     w-w";

	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3((float)strlen("    /\\_/\\"), 4.0f);

	Speed = 0.5f;

	Color = 14;
	Active = false;
}

int Enemy2::Update()
{
	TransInfo.Position.x -= Speed;

	//�߽ɿ������� ��µǱ⶧���� ������ �� ����ߵ�..�� �̷���,......���� ���� ���ϴ��� �װ�..
	if ((TransInfo.Position.x) - (TransInfo.Scale.x / 2))
	{
		Active = false;
		return -1;
	}

	return 0;
}

void Enemy2::Render()
{
	for (int i = 0; i < 4; ++i)
	{
		DoubleBuffer::GetInstance()->WriteBuffer(
			int(TransInfo.Position.x - (TransInfo.Scale.x / 2)),
			int(TransInfo.Position.y - (TransInfo.Scale.y / 2) + i),
			Texture[i], Color);
	}
}

void Enemy2::Release()
{

}

