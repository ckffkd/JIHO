#include "BackGround.h"
#include "DoubleBuffer.h"
#include "Asteroid.h"


BackGround::BackGround()
{

}

BackGround::~BackGround()
{
	Release();
}


void BackGround::Initialize()
{
	for (int i = 0; i < ASTEROID_CNT_MAX; ++i)
	{
		m_pAsteroid[i] = new Asteroid;
		m_pAsteroid[i]->Initialize();
	}
	TransInfo.Position = Vector3(80, 0);
}

int BackGround::Update()
{
	for (int i = 0; i < ASTEROID_CNT_MAX; ++i)
		m_pAsteroid[i]->Update();

	return 0;
}

void BackGround::Render()
{

	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x, (int)TransInfo.Position.y, (char*)"   ,        ~+", 5);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x, (int)TransInfo.Position.y + 1, (char*)"                 *       +", 5);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x, (int)TransInfo.Position.y + 2, (char*)"           '                   |", 5);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x, (int)TransInfo.Position.y + 3, (char*)"       ()    .-.,=＂-'=.     - o - ", 5);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x, (int)TransInfo.Position.y + 4, (char*)"             '=/_       ☆     |", 5);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x, (int)TransInfo.Position.y + 5, (char*)"          *   |  '=._    |", 5);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x, (int)TransInfo.Position.y + 6, (char*)"               ☆     `=./`,    ", 5);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x, (int)TransInfo.Position.y + 7, (char*)"            .   '=.__.=' `='    ", 5);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x, (int)TransInfo.Position.y + 8, (char*)"   +                         +", 5);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x, (int)TransInfo.Position.y + 9, (char*)"       O      *        '       .", 5);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 3, (int)TransInfo.Position.y + 10, (char*)"*", 5);

	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x - 70, (int)TransInfo.Position.y + 10, (char*)"         .                      .", 3);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x - 70, (int)TransInfo.Position.y + 11, (char*)"         .                      ;", 3);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x - 70, (int)TransInfo.Position.y + 12, (char*)"         :                  - --+- -", 3);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x - 70, (int)TransInfo.Position.y + 13, (char*)"         !           .          !", 3);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x - 70, (int)TransInfo.Position.y + 14, (char*)"         |        .             .", 3);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x - 70, (int)TransInfo.Position.y + 15, (char*)"         |_         +", 3);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x - 70, (int)TransInfo.Position.y + 16, (char*)"      ,＇| `.", 3);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x - 70, (int)TransInfo.Position.y + 17, (char*)"--- --+-<#>-+- ---  --  -", 3);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x - 70, (int)TransInfo.Position.y + 18, (char*)"      `._|_,'", 3);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x - 70, (int)TransInfo.Position.y + 19, (char*)"         T", 3);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x - 70, (int)TransInfo.Position.y + 20, (char*)"         |", 3);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x - 70, (int)TransInfo.Position.y + 21, (char*)"         !", 3);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x - 70, (int)TransInfo.Position.y + 22, (char*)"         :         . : ", 3);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x - 70, (int)TransInfo.Position.y + 23, (char*)"         .       *", 3);

	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x - 80, (int)TransInfo.Position.y + 1, (char*)" +                         ,                          *",8);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x - 75, (int)TransInfo.Position.y + 8, (char*)" +                                 *",6);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 30, (int)TransInfo.Position.y + 20, (char*)" /",8);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 31, (int)TransInfo.Position.y + 19, (char*)" /",8);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 28, (int)TransInfo.Position.y + 21, (char*)" ※",6);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x -42, (int)TransInfo.Position.y + 21, (char*)" †",6);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x -20, (int)TransInfo.Position.y + 15, (char*)" ‘",6);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x -5, (int)TransInfo.Position.y + 27, (char*)" ×",8);
	
	
	 
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x -1, (int)TransInfo.Position.y + 1, (char*)"↙",8);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x -3, (int)TransInfo.Position.y + 2, (char*)"↙",8);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x -5, (int)TransInfo.Position.y + 3, (char*)"☆",6);
	 




	// 어두운 회색8 완전 흰색14
	//§ ↙


	for (int i = 0; i < ASTEROID_CNT_MAX; ++i)
		m_pAsteroid[i]->Render();
}

void BackGround::Release()
{
	for (int i = 0; i < ASTEROID_CNT_MAX; ++i)
	{
		delete m_pAsteroid[i];
		m_pAsteroid[i] = NULL;
	}
}


/*





*/