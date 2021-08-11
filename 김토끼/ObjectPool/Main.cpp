#include <iostream>
#include <Windows.h>
#include <list>

using namespace std;

template <typename T>
inline void Safe_Delete(T& _Obj)
{
	if (_Obj)
	{
		delete _Obj;
		_Obj = NULL;
	}
}
#define SAFE_DELETE(type) Safe_Delete(type)

struct ObjectPool
{
	int Key;
	int Value;
	bool Active;

	ObjectPool() : Key(0), Value(0), Active(false) { }

	ObjectPool(int _Key, int _Value, bool _Active)
		: Key(_Key), Value(_Value), Active(_Active) { }

	~ObjectPool() {};
};

bool check = false;
int Count = 0;

int main(void)
{
	//ObjectPool* Array[128] = { NULL };
	list<ObjectPool*> ObjectList;

	int i = 0;
	 
	/*
	for (list<ObjectPool*>::iterator iter = ObjectList.begin();
		iter != ObjectList.end(); ++iter)
	{
		ObjectList.push_back(new ObjectPool(i, 0, false));
		 
	} //오~오오오오~~~나는 바보 나는 바보~~~
	*/

	/*
	for (int i = 0; i < 128; ++i)
	{
		Array[i] = new ObjectPool;
		Array[i]->Active = false;
		Array[i]->Key = i;
		Array[i]->Value = 0;
	}
	*/

	while (true)
	{
		system("cls");

		check = false;

		if (GetAsyncKeyState(VK_RETURN))
			check = true;

		if (check)
		{
			//list<ObjectPool*>::iterator iter = ObjectList.begin();

			if (ObjectList.empty())
			{
				ObjectList.push_back(
					new ObjectPool(Count++, 0, false));
			}

			else
			{
			//for (int i = 0; i < 128; ++i)
				for (list<ObjectPool*>::iterator iter = ObjectList.begin();
				iter != ObjectList.end(); ++iter)
				{  
					if (!(*iter)->Active)
					{
						(*iter)->Active = true;
						(*iter)->Value = 0;
						(*iter)->Key = 0;
						break;
					} 
				}
			}
		}

		for (list<ObjectPool*>::iterator iter = ObjectList.begin();
			iter != ObjectList.end(); ++iter)
		{
			if ((*iter)->Active) //머 이래 빼먹은게 많노
			{
				(*iter)->Value++;
				cout << (*iter)->Key << " : "
					<< (*iter)->Value << endl << endl;

				if ((*iter)->Value >= 50)
				{
					(*iter)->Active = false; 
				}
			}
		}

		Sleep(50);
	}

	for (list<ObjectPool*>::iterator iter = ObjectList.begin();
		iter != ObjectList.end(); ++iter)
	{
		SAFE_DELETE(*iter);
	}
	ObjectList.clear();
	

	return 0;
}

/*
void InputKey(ObjectPool* _pool)
{
	if (!check)
		return;

	_pool->Active = true;
	_pool->Key = ++Count;
	_pool->Value = 0;
}
*/
