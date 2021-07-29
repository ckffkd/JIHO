#include "Over.h"
#include "SceneManager.h"
#include "DoubleBuffer.h"



Over::Over()
{

}

Over::~Over()
{

}

/*

     ____________    ____  ____________   _____ ___    ________________ 
    /  ____/     |  /    |/    / _____/  /  __  Ｋ |  /  /  ____/  __  Ｋ
   /  /   /  /|  | /  /|__ /  /  /__    /  / /  /  | /  /  /___/  /_/  /
  /  / __/  ___  |/  /    /  /  ___/   /  / /  /|  |/  /  ____/ __,___/
 /  /_/  /  / |  |  /    /  /  /____  /  /_/  / |     /  /___ /  /|  |
 Ｋ_____/__/  |__/__/   /__/_______/   Ｋ____/   |___/_______/__/  |__|

*/
void Over::Initialize()
{
	GOver[0].Texture = (char*)"     ____________    ____  ____________    ______ __    ________________ ";
	GOver[1].Texture = (char*)"    /  _____/    |  /    |/    /  ____/   /  __  Ｋ |  /  /  ____/  __  Ｋ";
	GOver[2].Texture = (char*)"   /  /    /  /| | /  /|__ /  /  /___    /  / /  /  | /  /  /___/  /_/  /";
	GOver[3].Texture = (char*)"  /  / ___/  ___ |/  /    /  /  ____/   /  / /  /|  |/  /  ____/ __, __/";
	GOver[4].Texture = (char*)" /  /_/  /  / |  |  /    /  /  /____   /  /_/  / |     /  /___ /  /|  |";
	GOver[5].Texture = (char*)" Ｋ_____/__/  |__/_/    /__/_______/   Ｋ_____/  |____/_______/__/ |__|";


	OverKing[0].Texture = (char*)"	        /\\_/\\";
	OverKing[1].Texture = (char*)"         .-=~~~~=-.";
	OverKing[2].Texture = (char*)"       Ｊ|( @∩@ )|Ｈ";
	OverKing[3].Texture = (char*)"   Ｉ式式忙------忖式式Ｋ";
	OverKing[4].Texture = (char*)"  .-====~^^^^^^^^^^~====-.";
	OverKing[5].Texture = (char*)"_` (≡)  (≡)  (≡)  (≡) `_";
	OverKing[6].Texture = (char*)" ”-====================-”";
	OverKing[7].Texture = (char*)"    |__| Ｋ.    .Ｉ |__|";
	OverKing[8].Texture = (char*)"      |     = = =";
	OverKing[9].Texture = (char*)"     ╞   Ｉ *'  Ｋ";
	OverKing[10].Texture = (char*)" ,﹞╞";
	
	
	OverEnemy[0].Texture = (char*)"  /\\_/\\";
	OverEnemy[1].Texture = (char*)"((@∩@))";
	OverEnemy[2].Texture = (char*)" ():::()";
	OverEnemy[3].Texture = (char*)"   w-w";
	
	OverEnemy2[0].Texture = (char*)"     /\\_/\\";
	OverEnemy2[1].Texture = (char*)"(Ｋ((@∩@))/)";
	OverEnemy2[2].Texture = (char*)"  (Ｋ::::/) ";
	OverEnemy2[3].Texture = (char*)"      w-w";

	OPlayer[0].Texture = (char*)"  /)/)";
	OPlayer[1].Texture = (char*)" (T足T)";
	OPlayer[2].Texture = (char*)"o(↗↖)";
	OPlayer[3].Texture = (char*)"  U  U";
	

	for (int i = 0; i < 6; i++)
	{
		GOver[i].Color = 10;
		GOver[i].TransPos.Position = Vector3(
			10.0f, 5.0f + (float)i);
		GOver[i].TransPos.Scale = Vector3(1.0f, 1.0f);
	}

	for (int i = 0; i < 11; i++)
	{
		OverKing[i].Color = 14;
		OverKing[i].TransPos.Position = Vector3(
			84.0f, 4.0f + (float)i);
		OverKing[i].TransPos.Scale = Vector3(1.0f, 1.0f);
	}

	for (int i = 0; i < 4; i++)
	{
		OverEnemy[i].Color = 6;
		OverEnemy[i].TransPos.Position = Vector3(
			110.0f, 1.0f + (float)i);
		OverEnemy[i].TransPos.Scale = Vector3(1.0f, 1.0f);
	}

	for (int i = 0; i < 4; i++)
	{
		OverEnemy2[i].Color = 6;
		OverEnemy2[i].TransPos.Position = Vector3(
			100.0f, 24.0f + (float)i);
		OverEnemy2[i].TransPos.Scale = Vector3(1.0f, 1.0f);
	}


	for (int i = 0; i < 4; i++)
	{
		OPlayer[i].Color = 1;
		OPlayer[i].TransPos.Position = Vector3(
			30.0f, 20.0f + (float)i);
		OPlayer[i].TransPos.Scale = Vector3(1.0f, 1.0f);
	}

	TransInfo.Position = Vector3(0.0, 0.0);

}

/*
 
  /)/)
 (T足T)
o(↗↖)
  U  U


		  /\\_/\\";
		 .-=~~~=-.";
	   Ｊ|( @∩@ )|Ｈ";
	 Ｉ式式式忙------忖式式式Ｋ";
  .=====~^^^^^^^^^~=====.";
_` (≡)  (≡)  (≡)  (≡) '_";
 ”.....................”";
			Ｋ.    .Ｉ";
		   = = =";
		  Ｉ *' Ｋ";


*/
void Over::Update()
{
	for (int i = 0; i < 6; ++i)
	{     
		DoubleBuffer::GetInstance()->WriteBuffer(
			int(GOver[i].TransPos.Position.x),
			int(GOver[i].TransPos.Position.y),
			GOver[i].Texture,
			GOver[i].Color);
	}

	for (int i = 0; i < 11; ++i)
	{
		DoubleBuffer::GetInstance()->WriteBuffer(
			int(OverKing[i].TransPos.Position.x),
			int(OverKing[i].TransPos.Position.y),
			OverKing[i].Texture,
			OverKing[i].Color);
	}

	for (int i = 0; i < 4; ++i)
	{
		DoubleBuffer::GetInstance()->WriteBuffer(
			int(OverEnemy[i].TransPos.Position.x),
			int(OverEnemy[i].TransPos.Position.y),
			OverEnemy[i].Texture,
			OverEnemy[i].Color);
	}

	for (int i = 0; i < 4; ++i)
	{
		DoubleBuffer::GetInstance()->WriteBuffer(
			int(OverEnemy2[i].TransPos.Position.x),
			int(OverEnemy2[i].TransPos.Position.y),
			OverEnemy2[i].Texture,
			OverEnemy2[i].Color);
	}

	for (int i = 0; i < 4; ++i)
	{
		DoubleBuffer::GetInstance()->WriteBuffer(
			int(OPlayer[i].TransPos.Position.x),
			int(OPlayer[i].TransPos.Position.y),
			OPlayer[i].Texture,
			OPlayer[i].Color);
	}



	if (GetAsyncKeyState(VK_RETURN))
		SceneManager::GetInstance()->SetScene(SCENEID_EXIT);
}

void Over::Render()
{ 
	/*
	  /\\_/\\"
	((@∩@))";
	 ():::()";
	   w-w";
	*/

	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 75, (int)TransInfo.Position.y + 16, (char*)"   /\\_/\\", 6);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 75, (int)TransInfo.Position.y + 17, (char*)"  ((@v@))", 6);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 75, (int)TransInfo.Position.y + 18, (char*)"  ():::()", 6);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 75, (int)TransInfo.Position.y + 19, (char*)"    w-w", 6);

	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x +86, (int)TransInfo.Position.y + 7, (char*)"   ,        ~+", 5);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x +86, (int)TransInfo.Position.y + 8, (char*)"                 *       +", 5);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x +86, (int)TransInfo.Position.y + 9, (char*)"           '                   |", 5);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x +86, (int)TransInfo.Position.y + 10, (char*)"       ()    .-.,=ㄑ-'=.     - o - ", 5);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x +86, (int)TransInfo.Position.y + 11, (char*)"             '=/_       ≧     |", 5);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x +86, (int)TransInfo.Position.y + 12, (char*)"          *   |  '=._    |", 5);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x +86, (int)TransInfo.Position.y + 13, (char*)"               ≧     `=./`,    ", 5);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x +86, (int)TransInfo.Position.y + 14, (char*)"            .   '=.__.=' `='    ", 5);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x +86, (int)TransInfo.Position.y + 15, (char*)"                             +", 5);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x +86, (int)TransInfo.Position.y + 16, (char*)"               *        '       .", 5);
 

	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x +5, (int)TransInfo.Position.y + 13, (char*)"         .                      .", 3);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x +5, (int)TransInfo.Position.y + 14, (char*)"         .                      ;", 3);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x +5, (int)TransInfo.Position.y + 15, (char*)"         :                  - --+- -", 3);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x +5, (int)TransInfo.Position.y + 16, (char*)"         !           .          !", 3);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x +5, (int)TransInfo.Position.y + 17, (char*)"         |        .             .", 3);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x +5, (int)TransInfo.Position.y + 18, (char*)"         |_         +", 3);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x +5, (int)TransInfo.Position.y + 19, (char*)"      ,ㄖ| `.", 3);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x +5, (int)TransInfo.Position.y + 20, (char*)"--- --+-<#>-+- ---  --  -", 3);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x +5, (int)TransInfo.Position.y + 21, (char*)"      `._|_,'", 3);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x +5, (int)TransInfo.Position.y + 23, (char*)"         T", 3);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x +5, (int)TransInfo.Position.y + 24, (char*)"         |", 3);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x +5, (int)TransInfo.Position.y + 25, (char*)"         !", 3);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x +5, (int)TransInfo.Position.y + 26, (char*)"         :         . : ", 3);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x +5, (int)TransInfo.Position.y + 27, (char*)"         .       *", 3);

	 
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x+46, (int)TransInfo.Position.y + 19, (char*)".﹞╞﹞.");
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x+45, (int)TransInfo.Position.y + 20, (char*)"﹞");
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x+54, (int)TransInfo.Position.y + 20, (char*)"`﹞.");
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x+44, (int)TransInfo.Position.y + 21, (char*)"╞");
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x+59, (int)TransInfo.Position.y + 21, (char*)"`﹞╞.");
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x+64, (int)TransInfo.Position.y + 22, (char*)" `.");
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x+39, (int)TransInfo.Position.y + 22, (char*)" .﹞╞");
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x+36, (int)TransInfo.Position.y + 23, (char*)".﹞╞");
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x+65, (int)TransInfo.Position.y + 23, (char*)" *");
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x+62, (int)TransInfo.Position.y + 24, (char*)",.﹞");
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x+59, (int)TransInfo.Position.y + 24, (char*)"`﹞..");
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x+58, (int)TransInfo.Position.y + 23, (char*)"﹞");
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x+58, (int)TransInfo.Position.y + 22, (char*)",`");
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x+63, (int)TransInfo.Position.y + 20, (char*)" ,﹞`");
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x+64, (int)TransInfo.Position.y + 20, (char*)".﹞╞");
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x+68, (int)TransInfo.Position.y + 19, (char*)".╞");
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x+70, (int)TransInfo.Position.y + 18, (char*)"`");
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x+70, (int)TransInfo.Position.y + 17, (char*)".╞");
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x+72, (int)TransInfo.Position.y + 16, (char*)".﹞╞`");
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x+78, (int)TransInfo.Position.y + 15, (char*)".﹞╞`");
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x+84, (int)TransInfo.Position.y + 14, (char*)",`");
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x+85, (int)TransInfo.Position.y + 13, (char*)",﹞`");
	
	 
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x+14, (int)TransInfo.Position.y + 20, (char*)"Help me....");
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x+16, (int)TransInfo.Position.y + 21, (char*)"Save me....");
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x+11, (int)TransInfo.Position.y + 22, (char*)"I wanna go back...");
	  
}

void Over::Release()
{

}

/*

	GOver[0].Texture = (char*)"		     /\\_/\\";
	GOver[1].Texture = (char*)"		    .-=~~~=-.";
	GOver[2].Texture = (char*)"	      Ｊ|( @∩@ )|Ｈ";
	GOver[3].Texture = (char*)"	    Ｉ式式式忙------忖式式式Ｋ";
	GOver[4].Texture = (char*)"  .=====~^^^^^^^^^~=====.";
	GOver[5].Texture = (char*)"_` (≡)  (≡)  (≡)  (≡) '_";
	GOver[6].Texture = (char*)" ”......................”";
	GOver[7].Texture = (char*)"			Ｋ.    .Ｉ";
	GOver[8].Texture = (char*)"		      = = =";
	GOver[9].Texture = (char*)"		     Ｉ *' Ｋ";

	GOver[10].Texture = (char*)"";
	GOver[11].Texture = (char*)"";

	  

 _______  _______  __   __  _______    _______  __   __  _______  ______
|       ||   _   ||  |_|  ||       |  |       ||  | |  ||       ||    _ |
|    ___||  |_|  ||       ||    ___|  |   _   ||  |_|  ||    ___||   | ||
|   | __ |       ||       ||   |___   |  | |  ||       ||   |___ |   |_||_
|   ||  ||       ||       ||    ___|  |  |_|  ||       ||    ___||    __  |
|   |_| ||   _   || ||_|| ||   |___   |       | |     | |   |___ |   |  | |
|_______||__| |__||_|   |_||_______|  |_______|  |___|  |_______||___|  |_|



	 _/_/_/    _/_/    _/      _/  _/_/_/_/        _/_/    _/      _/  _/_/_/_/  _/_/_/
  _/        _/    _/  _/_/  _/_/  _/            _/    _/  _/      _/  _/        _/    _/
 _/  _/_/  _/_/_/_/  _/  _/  _/  _/_/_/        _/    _/  _/      _/  _/_/_/    _/_/_/
_/    _/  _/    _/  _/      _/  _/            _/    _/    _/  _/    _/        _/    _/
 _/_/_/  _/    _/  _/      _/  _/_/_/_/        _/_/        _/      _/_/_/_/  _/    _/

       ___________    __  _________   ____ __    ____________";
	  /  ____/   |  /  |/  / ____/  / __ Ｋ |  / / ____/ __ Ｋ";
	 /  / __/ /| | / /|_/ / __/    / / /  / | / / __/ / /_/ /";
	/  /_/ / ___ |/ /  / / /___   / /_/  /| |/ / /___/ _, _/";
	Ｋ____/_/  |_/_/  /_/_____/   Ｋ____/ |___/_____/_/ |_|";


		____________    ____  ____________    ______ __    ________________ ";
	   /  _____/    |  /    |/    /  ____/   /  __  Ｋ |  /  /  ____/  __  Ｋ";
	  /  /____/  /| | /  /|__ /  /  /___    /  / /  /  | /  /  /___/  /_/  /";
	 /  //_  /  ___ |/  /    /  /  ____/   /  / /  /|  |/  /  ____/ __,___/";
	/  /__/ /  / |  |  /    /  /  /____   /  /_/  / |     /  /___ /  /|  |";
	Ｋ_____/__/  |__/_/    /__/_______/   Ｋ_____/  |____/_______/__/ |__|";





Ｋ


*/
