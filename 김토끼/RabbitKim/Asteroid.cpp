#include "Asteroid.h"
#include "DoubleBuffer.h"





Asteroid::Asteroid()
{

}

Asteroid::~Asteroid()
{

}

void Asteroid::Initialize()
{
	int i = 0;

	switch (rand() % 3 + 1)
	{
	case 1:
	{
		AsteroidHeight = 4;
		char* str[] = {
			(char*)" ,-,-.",
			(char*)"/.( + ¢Ù",
			(char*)"¢Ù {.''/",
			(char*)" `-`-'" };

		for (i = 0; i < AsteroidHeight; ++i)
			m_pAsteroid[i] = str[i];
	}
		break;

	case 2:
	{
		AsteroidHeight = 5;

		char* str[] = {
			(char*)"   _..._",
			(char*)" .'     '. ",
			(char*)"/    .-""-¢Ù",
			//(char*)"	  |   /:.    |" ,
			(char*)"¢Ù  |:.   /",
			(char*)"  '-;:__.'" };

		for (i = 0; i < AsteroidHeight; ++i)
			m_pAsteroid[i] = str[i];
	}
		break;

	case 3:
	{
		AsteroidHeight = 2;

		char* str[] = {
			(char*)"		/£þ¢Ù",
			(char*)"		¢Ù_'/" };
		
		for(i = 0; i < AsteroidHeight; ++i)
			m_pAsteroid[i] = str[i];
	}
		break;
	}

	SetAsteroidColor();

	TransInfo.Position = Vector3(
		float(float(rand() % 100)),
		float(rand() % (30 - AsteroidHeight)) );

}

/*
 ,-,-.
/.( +.\
\ {. "/
 `-`-'
    	 _..._
	   .'     '. 
	  /    .-""-\
	  |   /:.   |
	   \  |:.   /
	    '-;:__.'

		/£þ¢Ù
		¢Ù_'/_
		 _  ¡²_¡³¡Ð¡®¡¯¡Å
		¡²_¡³

*/

int Asteroid::Update()
{
	TransInfo.Position.x -= 0.5f;

	if (TransInfo.Position.x <= 0)
	{
		SetAsteroidColor();
		TransInfo.Position = Vector3(
			float(rand() % 10 + 90),
			float(rand() % (30 - AsteroidHeight)));

	}


	return 0;
}

void Asteroid::Render()
{
	for (int i = 0; i < AsteroidHeight; ++i)
	{
		DoubleBuffer::GetInstance()->WriteBuffer(
			(int)TransInfo.Position.x,
			int(TransInfo.Position.y + i),
			m_pAsteroid[i], AsteroidColor);

	}
}

void Asteroid::Release()
{

}

void Asteroid::SetAsteroidColor()
{
	switch (rand() % 3 + 1)
	{
	case 1:
		AsteroidColor = 7;
		break;

	case 2:
		AsteroidColor = 8;
		break;

	case 3:
		AsteroidColor = 8;
		break;
	
	}
}

