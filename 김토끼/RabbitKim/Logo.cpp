#include "Logo.h"
#include "SceneManager.h"
#include "DoubleBuffer.h"

//백그라운드랑 로고문구 분리하기
Logo::Logo()
{

}

Logo::~Logo()
{

}

void Logo::Initialize()
{

	MyLogo[0].Texture = (char*)"     _________  ________  ________  ________  ___  __________  ";
	MyLogo[1].Texture = (char*)"    /   __   /|/  __   /|/  __   /|/  __   /|/  /|/___   ___/|";
	MyLogo[2].Texture = (char*)"   /   /|/  / /  /|/  / /  /|/  / /  /|/  / /  / /|_ /  / __|/";
	MyLogo[3].Texture = (char*)"  /   _  _ / /  __   / /  __  /  /  __  /  /  / /   /  / /";
	MyLogo[4].Texture = (char*)" /   //   / /  / /  / /  /|/  / /  /|/  / /  / /   /  / /";
	MyLogo[5].Texture = (char*)"/__ //__ / /_ / /__/ /_______/ /_______/ /__/ /   /__/ /";
	MyLogo[6].Texture = (char*)"|__|/|__|/|__| /|__|/|_______|/|_______|/|__|/    |__|/";
	
	MyLogo[7].Texture = (char*)"      ___   ___  ___  _____ _______";
	MyLogo[8].Texture = (char*)"     /  /| /  /|/  /|/  _  / __   /|";
	MyLogo[9].Texture = (char*)"    /  /_↗ ↗ /  / /  / /__/|/  / /";
	MyLogo[10].Texture = (char*)"   /   ___ ↘ /  / /  / |__|//  / /";
	MyLogo[11].Texture = (char*)"  /  / //  / /  / /  / /    /  / /";
	MyLogo[12].Texture = (char*)" /__/ //__/ /__/ /__/ /    /__/ / ";
	MyLogo[13].Texture = (char*)" |__|/ |__|/|__|/|__|/     |__|/";



	Star.Color = 15;
	Star.Texture = (char*)"*";
	Star.TransPos.Position = Vector3(113.0f, 5.0f);
	Star.TransPos.Scale = Vector3(1.0f, 1.0f);


	for (int i = 0; i < 27; ++i)
	{
		StarTail[i].Color = 15;
		StarTail[i].TransPos.Position = Vector3( (i * 2) + 60.0f, 5.0f);
		StarTail[i].TransPos.Scale = Vector3(0.0f, 0.0f);
	}

	StarTail[0].Texture = (char*)"━";
	StarTail[1].Texture = (char*)"━";
	StarTail[2].Texture = (char*)"━";
	StarTail[3].Texture = (char*)"━";
	StarTail[4].Texture = (char*)"─";
	StarTail[5].Texture = (char*)"─";
	StarTail[6].Texture = (char*)"─";
	StarTail[7].Texture = (char*)"─";
	StarTail[8].Texture = (char*)"─";
	StarTail[9].Texture = (char*)"─";
	StarTail[10].Texture = (char*)"─";
	StarTail[11].Texture = (char*)" ";
	StarTail[12].Texture = (char*)"-";
	StarTail[13].Texture = (char*)" ";
	StarTail[14].Texture = (char*)"-";
	StarTail[15].Texture = (char*)" ";
	StarTail[16].Texture = (char*)" ";
	StarTail[17].Texture = (char*)"-";
	StarTail[18].Texture = (char*)" ";
	StarTail[19].Texture = (char*)" ";
	StarTail[20].Texture = (char*)" ";
	StarTail[21].Texture = (char*)"-";
	StarTail[22].Texture = (char*)" ";
	StarTail[23].Texture = (char*)" ";
	StarTail[24].Texture = (char*)" ";
	StarTail[25].Texture = (char*)" ";
	StarTail[26].Texture = (char*)"-";


	
	StarTail[0].Color = 15;
	StarTail[1].Color = 12;
	StarTail[2].Color = 12;
	StarTail[3].Color = 12;
	StarTail[4].Color = 12;
	StarTail[5].Color = 10;
	StarTail[6].Color = 10;
	StarTail[7].Color = 10;
	StarTail[8].Color = 14;
	StarTail[9].Color = 14;
	StarTail[11].Color = 3;
	StarTail[10].Color = 3;
	StarTail[12].Color = 3;
	StarTail[14].Color = 3;
	StarTail[13].Color = 3;
	StarTail[15].Color = 3;
	StarTail[16].Color = 9;
	StarTail[17].Color = 9;
	StarTail[18].Color = 9;
	StarTail[19].Color = 9;
	StarTail[20].Color = 9;
	StarTail[22].Color = 9;
	StarTail[21].Color = 9;
	StarTail[23].Color = 5;
	StarTail[24].Color = 5;
	StarTail[25].Color = 5;
	StarTail[26].Color = 5;


	/*
	5 9 4 3 14 10 12 15
	
	*/




	StarTailCount = 27;


	for (int i = 0; i < 7; i++)
	{
		MyLogo[i].Color = 11;
		MyLogo[i].TransPos.Position = Vector3(
			55.0f, 6.0f + (float)i);
		MyLogo[i].TransPos.Scale = Vector3(1.0f, 1.0f);
	}

	
	for (int i = 7; i < 14; i++)
	{
		MyLogo[i].Color = 1;
		MyLogo[i].TransPos.Position = Vector3(
			73.0f, 7.0f + (float)i);
		MyLogo[i].TransPos.Scale = Vector3(1.0f, 1.0f);

	}
	
	
	TransInfo.Position = Vector3(1, 0);

	StarTime = GetTickCount64();
	StarCheck = false;
	StarSetTime = 0;
}

void Logo::Update()
{
	if (StarCheck)
	{
		if ( !(Star.TransPos.Position.x < 60) )
		{
			Star.TransPos.Position.x -= 5.0f;
		}	
		/*
		Sleep(100);
		Star.Texture = (char*)"";
		*/

		if (StarTailCount <= 0)
		{
			StarTailCount = 27;
			StarCheck = false;
			StarTime = GetTickCount64();
			Star.TransPos.Position.x = 113.0f;
			Star.Texture = (char*)"*";
			StarSetTime = 3000;
		}
		
		StarTailCount -= 2;
		

		if (StarTailCount <= 0)
			StarTailCount = 0;
	}
	else
	{
		if (StarTime + StarSetTime < GetTickCount64())
		{
			StarTime = GetTickCount64();

			StarCheck = true;
		}
	}
		


	if (GetAsyncKeyState(VK_RETURN))
		SceneManager::GetInstance()->SetScene(SCENEID_MENU);
}

void Logo::Render()
{
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x - 1, (int)TransInfo.Position.y + 1, (char*)" ＇	＇	＇	'                   '      '", 7);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x, (int)TransInfo.Position.y + 2, (char*)"＇	＇	＇	'                   '      '", 7);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x, (int)TransInfo.Position.y + 3, (char*)"＇	＇	＇	'                   '      '", 7);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x, (int)TransInfo.Position.y + 4, (char*)"＇	＇	＇	★	/\\_/\\      ★      '", 7);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x, (int)TransInfo.Position.y + 5, (char*)"＇	＇	☆            .-=~~~=-.            ☆",7);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x, (int)TransInfo.Position.y + 6, (char*)"＇	★                    |( @v@ )|", 7);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x, (int)TransInfo.Position.y + 7, (char*)"＇	                      ┌-----┐", 7);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x, (int)TransInfo.Position.y + 8, (char*)"☆		           .=~^^^^^^^^^~=.", 7);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x, (int)TransInfo.Position.y + 9, (char*)"	                 _` ()  ()  ()  ()'_      ↙", 7);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x, (int)TransInfo.Position.y + 10, (char*)"                        〃...............〃    ↙", 7);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x, (int)TransInfo.Position.y + 11, (char*)"            /	              ↘.   .↙        *", 7);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x, (int)TransInfo.Position.y + 12, (char*)"           /                   = = =", 7);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x, (int)TransInfo.Position.y + 13, (char*)"          + 	              ↙  *' ↘                ↙", 7);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x, (int)TransInfo.Position.y + 14, (char*)"                            ↙    | *↘             ↙");
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x, (int)TransInfo.Position.y + 15, (char*)"		    	.   ↙  '   |  ↘          ↙");
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x, (int)TransInfo.Position.y + 16, (char*)"                          ↙    /  * ' ↘       ※");
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x, (int)TransInfo.Position.y + 17, (char*)"      ↙	  .       ↙   /   *   . ↘   .       .");
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x, (int)TransInfo.Position.y + 18, (char*)"    ↙    	   __    ↙  .     .      ↘       .       .");
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x, (int)TransInfo.Position.y + 19, (char*)"  ＠	.    _    / |      .       .  *                 _  .     .");
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x, (int)TransInfo.Position.y + 20, (char*)"	     | ↘_| |  *         /)/)       .  +       | | __");
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x, (int)TransInfo.Position.y + 21, (char*)"          _+|      |       +   (TºT)   *  _          | |/  |");
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x, (int)TransInfo.Position.y + 22, (char*)"	  | ↘      |    .     o(⊃⊂)      | |       /  |   ↘");
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x, (int)TransInfo.Position.y + 23, (char*)"         |  |      ↘ ,         U  U       | |  *   /   |    |");
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x, (int)TransInfo.Position.y + 24, (char*)"       _/____↘--...↘___. *...  '__...__..|__↘-..|____/____/__");
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x, (int)TransInfo.Position.y + 25, (char*)"   _￣ 	        .     .                .       .	 .￣￣ '__ ,");
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x, (int)TransInfo.Position.y + 26, (char*)"￣-  	  .    . .       .          .                .                      ￣");

	
	for (int i = 0; i < 14; ++i)
		DoubleBuffer::GetInstance()->WriteBuffer(
			int(MyLogo[i].TransPos.Position.x),
			int(MyLogo[i].TransPos.Position.y),
			MyLogo[i].Texture,
			MyLogo[i].Color);
	
	if (StarCheck)
	{
		for (int i = 26; i >= StarTailCount; --i)
		{
			DoubleBuffer::GetInstance()->WriteBuffer(
				(int)StarTail[i].TransPos.Position.x,
				(int)StarTail[i].TransPos.Position.y,
				StarTail[i].Texture, StarTail[i].Color);
		}
		
		DoubleBuffer::GetInstance()->WriteBuffer(
			(int)Star.TransPos.Position.x,
			(int)Star.TransPos.Position.y,
			Star.Texture, Star.Color);
	}
}

void Logo::Release()
{

}

/*

																	   _________  ________  ________  ________  ___  __________
		＇	＇	＇	＇	＇	       /\\_/\\							  /   __   /|/  __   /|/  __   /|/  __   /|/  /|/___   ___/|
		＇	＇	＇	＇	＇	      .-=~~~=-.							 /   /|/  / /  /|/  / /  /|/  / /  /|/  / /  / /|_ /  / __|/
		＇	＇	＇	＇	☆	      |( @v@ )|							/   _  _ / /  __   / /  __  /  /  __  /  /  / /   /  / /
		＇	＇	＇	★		      | ┌───┐ |						   /   //   / /  / /  / /  /|/  / /  /|/  / /  / /   /  / /
		＇	＇	☆		       .=~^^^^^^^^^~=.					  /__ //__ / /_ / /__/ /_______/ /_______/ /__/ /   /__/ /
		＇	★			     _` ()  ()  ()  ()'_            ↙	  |__|/|__|/|__| /|__|/|_______|/|_______|/|__|/    |__|/
		＇				      "..............."           ↙
		☆	             /	       \.   ./               *
						/			= = =											     ___   ___  ___  _____ _______
					   + 	      ↙	*	'↘                       ↙		         	    /  /| /  /|/  /|/  _  / __  / |
								 ↙    | * ↘                   ↙				       /  /_↗ ↗ /  / /  / /__/|/  / /
						.    	↙  '   |   ↘                ↙						  /   ___ ↘ /  / /  / |__|//  / /
							   ↙    /  * '  ↘             ※			    		 /  / //  / /  / /  / /    /  / /
						   +  ↙   "       *  ↘										/__/ //__/ /__/ /__/ /    /__/ /
			  ↙	  .          ↙   /   *     .  ↘   .       .				  	    |__|/ |__|/|__|/|__|/     |__|/
			↙		   . _  ↙  .     .         ↘       .       .
		  ＠	    .    _  / |      .       .  *           _  .     .
					| \_| |  *       /)/)       .  +   | | __
				  _+|     |       + (T ºT)   * _       | |/  |
				 | \      |    .    (⊃⊂)     | |     /  |    \
				 |  |     \ ,        U U      | |  * /    |     \
			   _/____\--...\___. *...  ' __...|__\-..|____\_____/__
			  __￣	  .     .                .       .				.￣￣ ' __ ,
			-  	   .    . .       .          .                .                ￣
					  .       .    .    ，       .         .

 ________  ________  ________  ________  ___  _________        ___  __    ___  _____ ______
|\   __  \|\   __  \|\   __  \|\   __  \|\  \|\___   ___\     |\  \|\  \ |\  \|\   _ \  _   \
\ \  \|\  \ \  \|\  \ \  \|\ /\ \  \|\ /\ \  \|___ \  \_|     \ \  \/  /|\ \  \ \  \\\__\ \  \
 \ \   _  _\ \   __  \ \   __  \ \   __  \ \  \   \ \  \       \ \   ___  \ \  \ \  \\|__| \  \
  \ \  \\  \\ \  \ \  \ \  \|\  \ \  \|\  \ \  \   \ \  \       \ \  \\ \  \ \  \ \  \    \ \  \
   \ \__\\ _\\ \__\ \__\ \_______\ \_______\ \__\   \ \__\       \ \__\\ \__\ \__\ \__\    \ \__\
	\|__|\|__|\|__|\|__|\|_______|\|_______|\|__|    \|__|        \|__| \|__|\|__|\|__|     \|__|



  ♡

	  ____									    	:	
	+/_\/_\+								    	|	
  __ \_||_/ _								    	|	
	|_|__|_|								     ~──※──~
   _\ /__\ /_							 	    	|	
											    	|	
											    	:	

 


＇　　＇　　＇　　＇　　＇		
＇　　＇　　＇　　＇　　＇		    	＇	   ＇	  ＇		 ＇		＇
＇　　＇　　＇　　＇　　☆				＇	   ＇	  ＇		 ＇		＇
＇　　＇　　＇　　★					☆	   ＇	  ＇		 ＇		＇				
＇　　＇　　☆							   ★	  ＇		 ＇		＇				
＇　　★											  ☆		 ＇		＇				
＇													     ★		＇				
☆ 															    ＇				
																☆
														
														
			   _________  ________  ________  ________  ___  __________       ___   ___  ___  _____ _______	
			  /   __   /|/  __   /|/  __   /|/  __   /|/  /|/___   ___/|     /  /| /  /|/  /|/  _  / __  / |
			 /   /|/  / /  /|/  / /  /|/  / /  /|/  / /  / /|_ /  / __|/    /  /_↗ ↗ /  / /  / /__/|/  / /
			/   _  _ / /  __   / /  __  /  /  __  /  /  / /   /  / /       /   ___ ↘ /  / /  / |__|//  / /
		   /   //   / /  / /  / /  /|/  / /  /|/  / /  / /   /  / /       /  / //  / /  / /  / /    /  / /
		  / _ //__ / /_ / /__/ /_______/ /_______/ /__/ /   /__/ /       /__/ //__/ /__/ /__/ /    /__/ /
		  |__|/|__|/|__| /|__|/|_______|/|_______|/|__|/    |__|/        |__|/ |__|/|__|/|__|/     |__|/
																			 	  


	
	
	
	
	
	
					
					
				




*/
