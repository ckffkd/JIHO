#include "Mainupdate.h"



int main(void)
{
	system("title RabbitKim");//�ܼ�â Ÿ��Ʋ

	system("mode con:cols=120 lines=30");//�ܼ�â ��, ���� ����

	srand((ULONG)GetTickCount64());


	MainUpdate Main;
	Main.Initialize();

	ULONGLONG Time = GetTickCount64();

	int FrameTime = 50;

	while (true)
	{
		if (Time + 50 < GetTickCount64())
		{
			Time = GetTickCount64();
			system("cls");

			Main.Update();
			Main.Render();


			if (GetAsyncKeyState(VK_TAB))
				FrameTime = 0;
			else
				FrameTime = 50;
		}
	}


	return 0;
}

/*

Enemy 1������ ���� 10��
 -> ���߹迭 ����ؼ� �ξ��� ��Ǹ����.(Enemy2 �̿�)

 Player Score 3000�� �޼��� Bullet��� ����

 Player Score 4000��(Ȯ��X) �޼��� �ΰ� �ִ� UFO�ξ��� ����
  -> UFO�ξ��� óġ�� ����Ŭ����! (������� �����, KingEnemy HP�������ֱ�)


 

*/