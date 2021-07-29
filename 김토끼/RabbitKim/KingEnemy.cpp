#include "KingEnemy.h"
#include "DoubleBuffer.h"
#include "ObjectManager.h"
#include "SceneManager.h"
#include "KingBullet.h"


KingEnemy::KingEnemy()
{ 

}

KingEnemy::~KingEnemy()
{
 
}

void KingEnemy::Initialize()
{
	Motion = 0;
	Motion_Max = 3;


	/*
	Texture[0][0][0] = (char*)"      /\\_/\\";
	Texture[0][0][1] = (char*)"     .-=~~~=-.";
	Texture[0][0][2] = (char*)"     |( @v@ )|";
	Texture[0][0][3] = (char*)"      ┌-----┐";
	Texture[0][0][4] = (char*)"  .=~^^^^^^^^^~=.";
	Texture[0][0][5] = (char*)"_` ()  ()  ()  ()'_";
	Texture[0][0][6] = (char*)" 〃...............〃";
	Texture[0][0][7] = (char*)"	     ↘.   .↙";
	Texture[0][0][8] = (char*)"       = = =";
	Texture[0][0][9] = (char*)"      ↙ *' ↘";
	*/




	//공격
	Texture[0][0] = (char*)"	    /\\_/\\";
	Texture[0][1] = (char*)"         .-=~~~~=-.";
	Texture[0][2] = (char*)"       ↖|( @▽@ )|↗";
	Texture[0][3] = (char*)"   ↙──┌------┐──↘";
	Texture[0][4] = (char*)"  .-====~^^^^^^^^^^~====-.";
	Texture[0][5] = (char*)"_` (⊙)  (⊙)  (⊙)  (⊙) `_";
	Texture[0][6] = (char*)" 〃-====================-〃";
	Texture[0][7] = (char*)"    |__| ↘.    .↙ |__|";
	Texture[0][8] = (char*)"            = = =";
	Texture[0][9] = (char*)"          ↙ *' ↘";

	 
	Texture[1][0] = (char*)"	    /\\_/\\";
	Texture[1][1] = (char*)"         .-=~~~~=-.";
	Texture[1][2] = (char*)"       ↖|( @▽@ )|↗";
	Texture[1][3] = (char*)"   ↙──┌------┐──↘";
	Texture[1][4] = (char*)"  .-====~^^^^^^^^^^~====-.";
	Texture[1][5] = (char*)"_` (◎)  (◎)  (◎)  (◎) `_";
	Texture[1][6] = (char*)" 〃-====================-〃";
	Texture[1][7] = (char*)"    |__| ↘.    .↙ |__|";
	Texture[1][8] = (char*)"    ※※    = = =   ※※"; 
	Texture[1][9] = (char*)"    ※※  ↙ *' ↘  ※※";

	/*
		    /\\_/\\";      
	         .-=~~~~=-.";   
	       ↖|( @▽@ )|↗";    ●○
	   ↙──┌------┐──↘";
	  .-====~^^^^^^^^^^~====-.";
	_` (◎)  (◎)  (◎)  (◎) `_";
	 〃-====================-〃";
	     |_| ↘.    .↙ |_|";
	      |     = = =";
	     /    ↙ *' ↘";
	*/

	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3((float)strlen("_` (◎)  (◎)  (◎)  (◎) `_"), 10.0f);

	Speed = 0.8f;// -> 세로로만 움직였으면 좋겠음.

	Color = 14;
	Active = false;

	Time = (ULONG)GetTickCount64();
	BulletTime = (ULONG)GetTickCount64();
	MotionTime = 300;
	Damage = 1; //수정할 것
	Check = 0;
	HP = 100;//수정할 것


	Vertical = 0;
}

int KingEnemy::Update()
{
	if (Vertical) //수직
	{
		TransInfo.Position.y -= Speed;

		if((TransInfo.Position.y - (TransInfo.Scale.y / 2) < 2 ))
			Vertical = !Vertical;
	}
	else
	{
		TransInfo.Position.y += Speed;

		if ((TransInfo.Position.y + (TransInfo.Scale.y / 2) > 28))
			Vertical = !Vertical;
	}


	if ((TransInfo.Position.x - (TransInfo.Scale.x / 2)) <= ((Change != 0) ? 4.5f : 3.5f))
	{ 
		Active = false;
		return -1;
	}

	if (Time + MotionTime < GetTickCount64())
	{
		Time = (ULONG)GetTickCount64();
		Motion = !Motion;
	}

	if (HP <= 50)
	{
		Speed = 1.7f;
		Color = 11;
		Check = 1;
		MotionTime = 500; 
	}

	if (HP <= 30)
	{
		Speed = 2.5f;
		Color = 11;
		Check = 1;
		MotionTime = 500;

	}

	if (HP <= 0)
	{
		Active = false;
		
		SceneManager::GetInstance()->SetScene(SCENEID_ENDING);
		//얘가 주그면 엔딩으로 씬전환 해야
		return 1;
	}


	
	if (BulletTime + 500 < GetTickCount64())
	{
		BulletTime = GetTickCount64();

		ObjectManager::GetInstance()->AddKingEnemyBullet();
	}

	

	//if(GetAsyncKeyState(VK_CONTROL))
		//ObjectManager::GetInstance()->AddKingEnemyBullet();
	return 0;
}

void KingEnemy::Render()
{ 
	for (int i = 0; i < 10; ++i)
	{
		DoubleBuffer::GetInstance()->WriteBuffer(
			int(TransInfo.Position.x - (TransInfo.Scale.x / 2)),	
			int(TransInfo.Position.y - (TransInfo.Scale.y / 2) + i),
			Texture[Motion][i], Color);
	}
	 
	DoubleBuffer::GetInstance()->WriteBuffer(
		int(TransInfo.Position.x - (TransInfo.Scale.x / 2)),
		int(TransInfo.Position.y - (TransInfo.Scale.y / 2)),
		HP, Color);
}

void KingEnemy::Release()
{

}
/*

	   /\\_/\\
	  .-=~~~=-.
	  |( @v@ )|
	   ┌-----┐  
   .=~^^^^^^^^^~=.
 _` ()  ()  ()  ()'_
  "..............."
	   \.   ./
		= = =
	  ↙	*	'↘
*/