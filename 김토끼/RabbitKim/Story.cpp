#include "Story.h"
#include "SceneManager.h"
#include "DoubleBuffer.h"

//텍스트, 프레임 분리하기

//게임방법, 스토리 김토끼가 알려주기

Story::Story()
{

}

Story::~Story()
{

}

void Story::Initialize()
{
	/*
	
	GameStory[0].Texture = (char*)"          나는,...언덕에서 풀만 뜯어먹고있었토,,,";
	GameStory[1].Texture = (char*)"  /)/)    갑자기 반짝반짝한 네모네모를 타고있는 부엉이가 나를 납치했토....!/엉엉/";
	GameStory[2].Texture = (char*)" (TºT)    <SPACE>를 눌러서 반짝반짝 대왕부엉과 쫄병 외계부엉을 물리쳐달라토!!";
	GameStory[3].Texture = (char*)" (⊃⊂)   외계부엉과 세 번 부딫히면 나는 언덕으로 돌아갈 수 없토....";
	GameStory[4].Texture = (char*)"  U  U    꼬옥..나를.. 탈출시켜달라토 T ºT!!!!";
	
	59
	                   ☆- 김토끼 구출방법 -☆ ->23
	*/                                 
	Frame[0].Texture = (char*)"                                                        ._________________☆- 김토끼 탈출방법 -☆________________. ";
	Frame[1].Texture = (char*)"	|￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣|     (|￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣|) ";
	Frame[2].Texture = (char*)"	|                                        |     (|                                                        |)";
	Frame[3].Texture = (char*)"	|                                        |     (|                                                        |) ";
	Frame[4].Texture = (char*)"	|                                        |     (|                                                        |) ";
	Frame[5].Texture = (char*)"	|                                        |     (|                                                        |) ";
	Frame[6].Texture = (char*)"	|                                        |     (|                스페이스바를 눌러서 공격!!              |) ";
	Frame[7].Texture = (char*)"	|                                        |     (|                                                        |) ";
	Frame[8].Texture = (char*)"	|                                        |     (|       점수가 쌓이면 더 멋진 공격을 할 수 있어요!       |) ";
	Frame[9].Texture = (char*)"	|                                        |     (|                                                        |) ";
	Frame[10].Texture = (char*)"        |                                        |     (|         대왕부엉을 물리치고 토끼를 구해주세요!         |) ";
	Frame[11].Texture = (char*)"        |                                        |     (|                                                        |) ";
	Frame[12].Texture = (char*)"        |                                        |     (|                                                        |) ";
	Frame[13].Texture = (char*)"        |                                        |     (|                                                        |) ";
	Frame[14].Texture = (char*)"        |                                        |     (|                                                        |) ";
	Frame[15].Texture = (char*)"        |                                        |     (|                                                        |)  ";
	Frame[16].Texture = (char*)"        |                                        |     (|                 엔터를 누르면 게임 시작!               |)  "; 
	Frame[17].Texture = (char*)"        |                                        |     (|                                                        |)  ";
	Frame[18].Texture = (char*)"        |                                        |     (|                                                        |)  ";
	Frame[19].Texture = (char*)"        |      	                                 |     (|                                                        |)";
	Frame[20].Texture = (char*)"        |   	                                 |     (|                                                        |)";
	Frame[21].Texture = (char*)"        |                                        |     (|________________________________________________________|) ";
	Frame[22].Texture = (char*)"         ￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣      ＇￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣＇                ";
	
	
	GameStory[0].Texture = (char*)"  나는,,언덕에서 풀만 뜯어먹고 있었토.. ";
	GameStory[1].Texture = (char*)" ";
	GameStory[2].Texture = (char*)"갑자기 반짝반짝한 네모네모를 탄 부엉이가";
	GameStory[3].Texture = (char*)" ";
	GameStory[4].Texture = (char*)"내 귀를 보고 신기하다며 나를 납치했토!!!";
	GameStory[5].Texture = (char*)" ";
	GameStory[6].Texture = (char*)"     나의 언덕으로 돌아가고싶다토...    ";
	GameStory[7].Texture = (char*)" ";
	GameStory[8].Texture = (char*)"    칭구토끼들과 만나고싶다토../엉엉/   ";
	GameStory[9].Texture = (char*)" ";
	GameStory[10].Texture = (char*)"     대왕부엉과 쫄병부엉을 물리치고     ";
	GameStory[11].Texture = (char*)" ";
	GameStory[12].Texture = (char*)"      나를 언덕으로 데려다주라토..!     ";
	GameStory[13].Texture = (char*)" ";
	GameStory[14].Texture = (char*)"    꼬옥..나를..탈출시켜달라토 T ºT!!! ";
	
	Rabbit[0].Texture = (char*)"       /)/)";
	Rabbit[1].Texture = (char*)"      (TºT)";
	Rabbit[2].Texture = (char*)"     o(⊃⊂)";
	Rabbit[3].Texture = (char*)"       U  U";

 
	//float Center = (120 / 2) - ((float)strlen(GameStory[10].Texture) / 2);

	for (int i = 0; i < 23; i++)
	{
		Frame[i].Color = 11;
		Frame[i].TransPos.Position = Vector3(
			0.0f, 2.0f + (float)i);
		Frame[i].TransPos.Scale = Vector3(1.0f, 1.0f);
	}
		 
	for (int i = 0; i < 15; i++)
	{
		GameStory[i].Color = 7;
		GameStory[i].TransPos.Position = Vector3(
			9.0f, 6.0f + (float)i);
		GameStory[i].TransPos.Scale = Vector3(1.0f, 1.0f);
	}

	for (int i = 0; i < 4; i++)
	{
		Rabbit[i].Color = 1;
		Rabbit[i].TransPos.Position = Vector3(
			0.0f, 20.0f + (float)i);
		Rabbit[i].TransPos.Scale = Vector3(1.0f, 1.0f);
	}
	 
}


void Story::Update()
{
	if (GetAsyncKeyState(VK_RETURN))
		SceneManager::GetInstance()->SetScene(SCENEID_STAGE);
		
	if (GetAsyncKeyState(VK_ESCAPE))
		SceneManager::GetInstance()->SetScene(SCENEID_MENU);
}

void Story::Render()
{
	for (int i = 0; i < 23; ++i)
		DoubleBuffer::GetInstance()->WriteBuffer(
			int(Frame[i].TransPos.Position.x),
			int(Frame[i].TransPos.Position.y),
			Frame[i].Texture,
			Frame[i].Color);

	for (int i = 0; i < 15; ++i)
		DoubleBuffer::GetInstance()->WriteBuffer(
			int(GameStory[i].TransPos.Position.x),
			int(GameStory[i].TransPos.Position.y),
			GameStory[i].Texture,
			GameStory[i].Color);

	for (int i = 0; i < 4; ++i)
		DoubleBuffer::GetInstance()->WriteBuffer(
			int(Rabbit[i].TransPos.Position.x),
			int(Rabbit[i].TransPos.Position.y),
			Rabbit[i].Texture,
			Rabbit[i].Color);
}

void Story::Release()
{

}

/*

      ⌒⌒⌒⌒⌒⌒⌒⌒⌒⌒⌒⌒⌒⌒⌒⌒⌒⌒⌒⌒⌒⌒⌒⌒⌒⌒⌒⌒⌒⌒⌒⌒⌒
     .________________________________________________________.
	(|￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣|)
	(|                                                        |)
	(|                                                        |)
	(|                                                        |)
	(|                                                        |)
	(|                                                        |)
	(|                                                        |)
	(|                                                        |)
	(|                                                        |)
	(|                                                        |)
    (|________________________________________________________|)
	 "￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣"
  ○
o 


⌒

*/