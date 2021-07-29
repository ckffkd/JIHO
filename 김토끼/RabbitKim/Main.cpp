#include "Mainupdate.h"



int main(void)
{
	system("title RabbitKim");//콘솔창 타이틀

	system("mode con:cols=120 lines=30");//콘솔창 폭, 높이 지정

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

Enemy 1마리당 점수 10점
 -> 다중배열 사용해서 부엉이 모션만들기.(Enemy2 이용)

 Player Score 3000점 달성시 Bullet모양 변경

 Player Score 4000점(확정X) 달성시 로고에 있는 UFO부엉이 등장
  -> UFO부엉이 처치시 게임클리어! (엔딩장면 만들기, KingEnemy HP지정해주기)


 

*/