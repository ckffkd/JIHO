#include "Story.h"
#include "SceneManager.h"
#include "DoubleBuffer.h"

//�ؽ�Ʈ, ������ �и��ϱ�

//���ӹ��, ���丮 ���䳢�� �˷��ֱ�

Story::Story()
{

}

Story::~Story()
{

}

void Story::Initialize()
{
	/*
	
	GameStory[0].Texture = (char*)"          ����,...������� Ǯ�� ���԰��־���,,,";
	GameStory[1].Texture = (char*)"  /)/)    ���ڱ� ��¦��¦�� �׸�׸� Ÿ���ִ� �ξ��̰� ���� ��ġ����....!/����/";
	GameStory[2].Texture = (char*)" (T��T)    <SPACE>�� ������ ��¦��¦ ��պξ��� �̺� �ܰ�ξ��� �����Ĵ޶���!!";
	GameStory[3].Texture = (char*)" (����)   �ܰ�ξ��� �� �� �΋H���� ���� ������� ���ư� �� ����....";
	GameStory[4].Texture = (char*)"  U  U    ����..����.. Ż����Ѵ޶��� T ��T!!!!";
	
	59
	                   ��- ���䳢 ������ -�� ->23
	*/                                 
	Frame[0].Texture = (char*)"                                                        ._________________��- ���䳢 Ż���� -��________________. ";
	Frame[1].Texture = (char*)"	|����������������������������������������|     (|��������������������������������������������������������|) ";
	Frame[2].Texture = (char*)"	|                                        |     (|                                                        |)";
	Frame[3].Texture = (char*)"	|                                        |     (|                                                        |) ";
	Frame[4].Texture = (char*)"	|                                        |     (|                                                        |) ";
	Frame[5].Texture = (char*)"	|                                        |     (|                                                        |) ";
	Frame[6].Texture = (char*)"	|                                        |     (|                �����̽��ٸ� ������ ����!!              |) ";
	Frame[7].Texture = (char*)"	|                                        |     (|                                                        |) ";
	Frame[8].Texture = (char*)"	|                                        |     (|       ������ ���̸� �� ���� ������ �� �� �־��!       |) ";
	Frame[9].Texture = (char*)"	|                                        |     (|                                                        |) ";
	Frame[10].Texture = (char*)"        |                                        |     (|         ��պξ��� ����ġ�� �䳢�� �����ּ���!         |) ";
	Frame[11].Texture = (char*)"        |                                        |     (|                                                        |) ";
	Frame[12].Texture = (char*)"        |                                        |     (|                                                        |) ";
	Frame[13].Texture = (char*)"        |                                        |     (|                                                        |) ";
	Frame[14].Texture = (char*)"        |                                        |     (|                                                        |) ";
	Frame[15].Texture = (char*)"        |                                        |     (|                                                        |)  ";
	Frame[16].Texture = (char*)"        |                                        |     (|                 ���͸� ������ ���� ����!               |)  "; 
	Frame[17].Texture = (char*)"        |                                        |     (|                                                        |)  ";
	Frame[18].Texture = (char*)"        |                                        |     (|                                                        |)  ";
	Frame[19].Texture = (char*)"        |      	                                 |     (|                                                        |)";
	Frame[20].Texture = (char*)"        |   	                                 |     (|                                                        |)";
	Frame[21].Texture = (char*)"        |                                        |     (|________________________________________________________|) ";
	Frame[22].Texture = (char*)"         ����������������������������������������      ������������������������������������������������������������                ";
	
	
	GameStory[0].Texture = (char*)"  ����,,������� Ǯ�� ���԰� �־���.. ";
	GameStory[1].Texture = (char*)" ";
	GameStory[2].Texture = (char*)"���ڱ� ��¦��¦�� �׸�׸� ź �ξ��̰�";
	GameStory[3].Texture = (char*)" ";
	GameStory[4].Texture = (char*)"�� �͸� ���� �ű��ϴٸ� ���� ��ġ����!!!";
	GameStory[5].Texture = (char*)" ";
	GameStory[6].Texture = (char*)"     ���� ������� ���ư���ʹ���...    ";
	GameStory[7].Texture = (char*)" ";
	GameStory[8].Texture = (char*)"    Ī���䳢��� ������ʹ���../����/   ";
	GameStory[9].Texture = (char*)" ";
	GameStory[10].Texture = (char*)"     ��պξ��� �̺��ξ��� ����ġ��     ";
	GameStory[11].Texture = (char*)" ";
	GameStory[12].Texture = (char*)"      ���� ������� �������ֶ���..!     ";
	GameStory[13].Texture = (char*)" ";
	GameStory[14].Texture = (char*)"    ����..����..Ż����Ѵ޶��� T ��T!!! ";
	
	Rabbit[0].Texture = (char*)"       /)/)";
	Rabbit[1].Texture = (char*)"      (T��T)";
	Rabbit[2].Texture = (char*)"     o(����)";
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

      �ҡҡҡҡҡҡҡҡҡҡҡҡҡҡҡҡҡҡҡҡҡҡҡҡҡҡҡҡҡҡҡҡ�
     .________________________________________________________.
	(|��������������������������������������������������������������|)
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
	 "��������������������������������������������������������������"
  ��
o 


��

*/