#include "Ending.h"
#include "SceneManager.h"
#include "DoubleBuffer.h"

//토갱이들 배열만들깅(색 각각 지정)

Ending::Ending()
{

}

Ending::~Ending()
{

}

void Ending::Initialize()
{

	EndPlayer[0].Texture = (char*)"  /)/)";
	EndPlayer[1].Texture = (char*)" (> 3<)/";
	EndPlayer[2].Texture = (char*)"o(⊃  )";
	EndPlayer[3].Texture = (char*)"  U  U";
	EndPlayer[4].Texture = (char*)" ,*";
	EndPlayer[5].Texture = (char*)"ˇ";
	//EndPlayer[6].Texture = (char*)"ˇ";



	GEnding[0].Texture = (char*)"     ________   _________  _____  ______  ________      ________  ___      ________   ________  ________";
	GEnding[1].Texture = (char*)"    /   ____/| /   __   /|/  _  / __   /|/  _____/|    /  _____/|/  /|    /  _____/| /  __   /|/  __   /|";
	GEnding[2].Texture = (char*)"   /  /|____|//   /|/  / /  /|/__/|/  / /  /|____|/   /  /|___|//  / /   /  /|___ |//  /|/  / /  /|/  / / ";
	GEnding[3].Texture = (char*)"  /  / / ___ /   __   / /  / /|__|/  / /  _____/|    /  / /    /  / /   /  _____/|//  __   / /  __  _/ /  ";
	GEnding[4].Texture = (char*)" /  /_/_/  //   / /  / /  / /    /  / /  /|____|/   /  /_/__  /  /_/__ /  /|____|//  / /  / /  /|/  / /    ";
	GEnding[5].Texture = (char*)"/_________//_ _/ /__/ /__/ /    /__/ /________/|   /_______/|/_______//________/|/__/ /__/ /__/ /__/ /    ";
	GEnding[6].Texture = (char*)"|_________||___|/|__|/|__|/     |__|/|________|/   |_______||________||________|/|__|/|__|/|__|/|__|/     ";
	
	EndFriend[0].Texture = (char*)"  /)/)";
	EndFriend[1].Texture = (char*)"|(   )/";
	EndFriend[2].Texture = (char*)" ( o )";
	EndFriend[3].Texture = (char*)"  U U ";

	EndFriend[4].Texture = (char*)"  (↘(↘";
	EndFriend[5].Texture = (char*)"↖(>O <)↗";
	EndFriend[6].Texture = (char*)"  (    )o";
	EndFriend[7].Texture = (char*)"   U  U";
	
	
	/*
		 (↘(↘
	) ↖(>O <)↗
	)/	 (    )o  
	)    U  U    
	
	*/
	for (int i = 0; i < 6; i++)
	{
		EndPlayer[i].Color = 1;
		EndPlayer[i].TransPos.Position = Vector3(
			28.0f, 5.0f + (float)i);
		EndPlayer[i].TransPos.Scale = Vector3(1.0f, 1.0f);
	}

	 
	for (int i = 0; i < 7; i++)
	{
		GEnding[i].Color = 1;
		GEnding[i].TransPos.Position = Vector3(
			8.0f, 10.0f + (float)i);
		GEnding[i].TransPos.Scale = Vector3(1.0f, 1.0f);
	}


	for (int i = 0; i < 4; i++)
	{
		EndFriend[i].Color = 4;
		EndFriend[i].TransPos.Position = Vector3(
			87.0f, 22.0f + (float)i);
		EndFriend[i].TransPos.Scale = Vector3(1.0f, 1.0f);
	}

	for (int i = 4; i < 8; i++)
	{
		EndFriend[i].Color = 9;
		EndFriend[i].TransPos.Position = Vector3(
			94.0f, 17.0f + (float)i);
		EndFriend[i].TransPos.Scale = Vector3(1.0f, 1.0f);
	}

	TransInfo.Position = Vector3(0, 0);

}

void Ending::Update()
{
	


	if (GetAsyncKeyState(VK_RETURN))
		SceneManager::GetInstance()->SetScene(SCENEID_EXIT);
}

void Ending::Render()
{

	//언덕
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x, (int)TransInfo.Position.y + 22, (char*)"                        "); 
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x, (int)TransInfo.Position.y + 23, (char*)"                       VV                                                                                      _…………↗" ,2);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x, (int)TransInfo.Position.y + 24, (char*)"               ,＿…＿       ― /↘_へ_                                                                   ↗｀   *", 2);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x, (int)TransInfo.Position.y + 25, (char*)"           ___/       ¸            ¸ ↘_--＊√¸_ ∧                                            ___……∥  ",2);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x, (int)TransInfo.Position.y + 26, (char*)"       __↙＋      ｀∧     ^       ¸      ^          ￣,ぺ__…__                        ___,.↗  ¸         ¸",2);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x, (int)TransInfo.Position.y + 27, (char*)"  ___↙		 .                 ^^          ¸          ¸      ↘~==-,___,--'〃〃`---〃' ¸   ^   ＋    ｀    ∧",2);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x, (int)TransInfo.Position.y + 28, (char*)"↙        ^          ,      ¸             .          ∧              . ¸   ^     .    ¸         .     '  ¸      ..",2);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x, (int)TransInfo.Position.y + 29, (char*)"         	  ^                   ＋                     .      ＋            ^        ^    ,¸      ¸",2);
	
	//당근
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x +22 , (int)TransInfo.Position.y + 24, (char*)"(= )", 10);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x +36 , (int)TransInfo.Position.y + 4, (char*)" ψ", 2);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x +36 , (int)TransInfo.Position.y + 5, (char*)"(Ξ)", 10);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x +36 , (int)TransInfo.Position.y + 6, (char*)" ∇", 10);

	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x +10 , (int)TransInfo.Position.y + 25, (char*)" ψ", 2);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x +10 , (int)TransInfo.Position.y + 26, (char*)"(Ξ)", 10);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x +36 , (int)TransInfo.Position.y + 6, (char*)" ∇", 10);
	

	
	//칭구들 노래
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x +91 , (int)TransInfo.Position.y + 20, (char*)"♪", 9);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x +93 , (int)TransInfo.Position.y + 19, (char*)"♬      ♩", 4);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x +90 , (int)TransInfo.Position.y + 18, (char*)" ♩      ♬   ♪", 14);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x +95 , (int)TransInfo.Position.y + 17, (char*)"       ＋ ♬", 9);
	 
	//구름
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x +95 , (int)TransInfo.Position.y + 3, (char*)"      ,--.", 15);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x +95 , (int)TransInfo.Position.y + 4, (char*)"    _(  ' )-.__", 15);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x +95 , (int)TransInfo.Position.y + 5, (char*)" ,~' '     ' )_)", 15);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x +95 , (int)TransInfo.Position.y + 6, (char*)"(_(_.~  ~_)_)", 15);

	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 20, (int)TransInfo.Position.y + 2, (char*)"      ,--.", 9);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 20, (int)TransInfo.Position.y + 3, (char*)"    _(  ' )-.__", 9);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 20, (int)TransInfo.Position.y + 4, (char*)" ,~' '     ' )_)", 9);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 20, (int)TransInfo.Position.y + 5, (char*)"(_(_.~  ~_)_)", 9);

	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 4, (int)TransInfo.Position.y + 1, (char*)"         _(   )_", 7);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 4, (int)TransInfo.Position.y + 2, (char*)"     _(        '_)", 7);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 4, (int)TransInfo.Position.y + 3, (char*)" _(`(           __)", 7);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 4, (int)TransInfo.Position.y + 4, (char*)"(    (..__.: '-'", 7);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 4, (int)TransInfo.Position.y + 5, (char*)" (_       )  )", 7);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 4, (int)TransInfo.Position.y + 6, (char*)"   -__.:'", 7);


	/*
	        _(   )_",
	     _(        '_",
	  _(`(           _)",
	((    (..__.: '-'",
	 (_      ) )",
	   -__.:'"	 };

	*/


	for (int i = 0; i < 6; ++i)
	{
		DoubleBuffer::GetInstance()->WriteBuffer(
			int(EndPlayer[i].TransPos.Position.x),
			int(EndPlayer[i].TransPos.Position.y),
			EndPlayer[i].Texture,
			EndPlayer[i].Color);
	}

	for (int i = 0; i < 7; ++i)
	{
		DoubleBuffer::GetInstance()->WriteBuffer(
			int(GEnding[i].TransPos.Position.x),
			int(GEnding[i].TransPos.Position.y),
			GEnding[i].Texture,
			GEnding[i].Color);
	}

	for (int i = 0; i < 8; ++i)
	{
		DoubleBuffer::GetInstance()->WriteBuffer(
			int(EndFriend[i].TransPos.Position.x),
			int(EndFriend[i].TransPos.Position.y),
			EndFriend[i].Texture,
			EndFriend[i].Color);
	}

}

void Ending::Release()
{

}

/*
      ________   _________  _____  ______  ________         ________   ___       ________   ________  ________
     /   ____/| /   __   /|/  _  / __   /|/  _____/|       /  _____/| /  /|     /  _____/| /  __   /|/  __   /|
    /  /|____|//   /|/  / /  /|/__/|/  / /  /|____|/      /  /|___|/ /  / /    /  /|___ |//  /|/  / /  /|/  / /
   /  / / ___ /   __   / /  / /|__|/  / /  _____/|	     /  / /     /  / /    /  _____/|//  __   / /  __  _/ /
  /  /_/_/  //   / /  / /  / /    /  / /  /|____|/	    /  /_/__   /  /_/__  /  /|____|//  / /  / /  /|/  / /
 /_________//_ _/ /__/ /__/ /    /__/ /________/|	   /_______/| /_______/|/________/|/__/ /__/ /__/ /__/ /
 |_________||___|/|__|/|__|/     |__|/|________|/	   |_______|/|________|/|________|/|__|/|__|/|__|/|__|/

           
           				 /)/)
           				(> 3<)/
           			   o(⊃  )                                                               ♩
           				 U  U                                                               ＋ ♬
           			   ,*                                                      ♩         ♬   ♪
           			  ˇ                                                          ♬        ♩
           																		♪	 (↘(↘
           																	  /)/) ↖(>O <)↗
             ^ 																|(   )/	 (    )o    _…………
           	  ^   ,＿…＿…………―/↘_へ_											 ( o )    U  U    ↗,   ^
           	___/       ¸         ¸ ↘_--＊√¸_ ∧                               U U       ___……∥    ¸
       __↙＋      ｀∧     ^       ¸      ^     ￣,ぺ__…__                         ___,.↗  ¸   . 
         		 .              ^^            ¸            ¸↘~==-,___,--'""`---"' ¸   ^   ＋
         ^          ,      ¸             .          ∧              . ¸   ^     .
          	  ^                   ＋                     .      ＋
           


*/
/*

 ∧^
 ↙↗↘↖†ぅへぺл ŉи ″ℓ
 ￣∥＾¤

 __    +      *                         `'       `'|.    `:
"'  `---"""----....____,..^---`^``----.,.___          `.    `.  .    ____,.,-
	___,--'""`---"'   ^  ^ ^        ^       """'---,..___ __,..---""'
--"'                                   ^                         ``--..,__
 
   /)/)
  (TºT)
 o(⊃⊂)
   U  U  
   /)/)
 |(   )/
  ( o )
   U U
*/

/*

  ψ
 (Ξ)
  ∇
 


        ________   _________  _____  ______  ________           ________   ___       ________   ________  ________
       /   ____/| /   __   /|/  _  / __   /|/  _____/|         /  _____/| /  /|     /  _____/| /  __   /|/  __   /|
	  /  /|____|//   /|/  / /  /|/__/|/  / /  /|____|/        /  /|___|/ /  / /    /  /|___ |//  /|/  / /  /|/  / /
	 /  / / ___ /   __   / /  / /|__|/  / /  _____/|         /  / /     /  / /    /  _____/|//  __   / /  __  _/ /
	/  /_/_/  //   / /  / /  / /    /  / /  /|____|/        /  /_/__   /  /_/__  /  /|____|//  / /  / /  /|/  / /
   /_________//_ _/ /__/ /__/ /    /__/ /________/|        /_______/| /_______/|/________/|/__/ /__/ /__/ /__/ /
   |_________||___|/|__|/|__|/     |__|/|________|/        |_______|/|________|/|________|/|__|/|__|/|__|/|__|/


	 

*/
