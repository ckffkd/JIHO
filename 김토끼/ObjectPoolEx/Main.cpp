#include <iostream>
#include <Windows.h>
#include <list>
#include <map>


using namespace std;

struct Vector3
{
	float x, y, z;

	Vector3() {};

	Vector3(float _x, float _y)
		:x(_x), y(_y), z(0) {};

	Vector3(float _x, float _y, float _z)
		:x(_x), y(_y), z(_z) {};
};


struct Transform
{
	Vector3 Position;
	Vector3 Scale;
};


class Object
{
private:
	int Key;
	string Texture;
	Transform TransInfo;
public:
	void Initialize()
	{
		//Key = 0;
		//(2, 15, ""); �� ���䳢 ���鶧 ���� ���ڳ�
		Texture = "��";
		TransInfo.Position = Vector3(2, 15); 
		TransInfo.Scale = Vector3(strlen("��"), 1);
	}

	int Update()
	{
		TransInfo.Position.x += 1.5f;

		if (TransInfo.Position.x >= (120 - TransInfo.Scale.x))
			return 1;

		return 0;
	}

	void Output(float _x, float _y, string _str)
	{
		COORD Pos = { _x, _y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
		cout << _str << endl;
	}
public:
	Object() { }
	~Object() { }
};


bool check = false;
int Count = 0;
 
void Output(float _x, float _y, string _str);
 
int main(void)
{
	//** ���� ����� ������Ʈ (������ �� ������Ʈ ����Ʈ)
	list<Object*> EnableList;

	//** ����� ��ģ ������Ʈ ����Ʈ (������ ���� ����)
	list<Object*> DesableList;


	while (true)
	{
		system("cls");


		//** �Ѿ��� �߻�� ��ġ.
		Output(2, 15, "��");
		 

		check = false;

		//** Ű �Է� �̺�Ʈ Ȯ��
		if (GetAsyncKeyState(VK_RETURN))
			//** �ѹ��� �Է¹ޱ�����.
			check = true;


		//** �Է��� �Ǿ��ٸ�..
		if (check)
		{
			//** DesableList �� ������ ������Ʈ�� �ִ��� Ȯ�� �ϰ� ���ٸ�...
			if (DesableList.empty())
			{
				//** 5���� ������Ʈ�� �߰� ������ ��...
				for (int i = 0; i < 5; ++i)
				{
					DesableList.push_back(
						new Object);
				}
			}

			//** �߰� ������ ������Ʈ �ϳ��� ����.
			list<Object*>::iterator iter = DesableList.begin();


			//** �ʱ�ȭ �� �ʿ��� ���� �ۼ�.
			(*iter)->Initialize();

			//** ����� ����Ʈ�� �߰�.
			EnableList.push_back((*iter));

			//** ���� ����Ʈ���� ����.
			DesableList.pop_front();
		}

		 

		//** �������� ����.


		//** Render 
		cout << "EnableList" << endl;
		for (list<Object*>::iterator iter = EnableList.begin();
			iter != EnableList.end();/* �������� �Ʒ��ʿ� */)
		{
			//** Value �� ����
			(*iter)->Output();

			//** �ܼ�â�� ���
			//cout << (*iter)->Key << " : " << (*iter)->Value << endl;

			//** ��µ� ������Ʈ�� Value ���� ���� �̻��� �ȴٸ�....
			if ((*iter)->Value >= 50)
			{
				//** ���� ����Ʈ���� DesableList �� �Ȱܳ���
				DesableList.push_back((*iter));

				//** ���� ����Ʈ���� ����.
				iter = EnableList.erase(iter);
			}
			else
				++iter; //** ������Ʈ�� �������� ������ ������Ŵ..
		}



		//cout << "DesableList" << endl;
		for (list<Object*>::iterator iter = DesableList.begin();
			iter != DesableList.end(); ++iter)
		{
			//** �ܼ�â�� ���
			cout << (*iter)->Key << endl;
		}

		Sleep(50);
	}



	//** DesableList ���� ����
	for (list<Object*>::iterator iter = DesableList.begin();
		iter != DesableList.end(); ++iter)
	{
		delete (*iter);
		(*iter) = NULL;
	}
	DesableList.clear();


	//** EnableList ���� ����
	for (list<Object*>::iterator iter = EnableList.begin();
		iter != EnableList.end(); ++iter)
	{
		delete (*iter);
		(*iter) = NULL;
	}
	EnableList.clear();

	return 0;
}
 


void Output(float _x, float _y, string _str)
{
	COORD Pos = { _x, _y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	cout << _str << endl;
}