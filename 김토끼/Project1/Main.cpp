#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <fstream>

using namespace std;
 
struct StudentInfo
{
	char* Name;
	int Index;

	int Kor;
	int Eng;
	int Math;
};


list<StudentInfo*> StudentList;
 
void LoadDate();
void Output();
 
int main(void)
{
	LoadDate();

	//** �о�� �����͸� ������ ������ ���� �������� ������ �Ұ��̴�.
	//** ����, ����, ���� �������� ������ �� ���õ� ������ ������ �������� �����Ұ�.
	list<StudentInfo*> SortList(StudentList);
	
	while (true)
	{
		system("cls");

		cout << "1. ����" << endl;
		cout << "2. ����" << endl;
		cout << "3. ����" << endl;
		cout << "4. ��ü" << endl;
		cout << "5. ����" << endl;

		int num;

		cout << "�Է� : "; cin >> num;

		system("cls");

		switch (num)
		{ 
		case 1:
			for (list<StudentInfo*>::iterator iter = SortList.begin();
				iter != SortList.end(); ++iter)
			{
				for (list<StudentInfo*>::iterator iter2 = iter;
					iter2 != SortList.end(); ++iter2)
				{
					if ((*iter)->Kor < (*iter2)->Kor)
					{
						StudentInfo* pTemp = (*iter);
						(*iter) = (*iter2);
						(*iter2) = pTemp;
					}
				}
				cout << (*iter)->Name << " : " << (*iter)->Kor << endl;
			}
			break;

		case 2:
			for (list<StudentInfo*>::iterator iter = SortList.begin();
				iter != SortList.end(); ++iter)
			{
				for (list<StudentInfo*>::iterator iter2 = iter;
					iter2 != SortList.end(); ++iter2)
				{
					if ((*iter)->Eng < (*iter2)->Eng)
					{
						StudentInfo* pTemp = (*iter);
						(*iter) = (*iter2);
						(*iter2) = pTemp;
					}
				}
				cout << (*iter)->Name << " : " << (*iter)->Eng << endl;
			}
			break;

		case 3:
			for (list<StudentInfo*>::iterator iter = SortList.begin();
				iter != SortList.end(); ++iter)
			{
				for (list<StudentInfo*>::iterator iter2 = iter;
					iter2 != SortList.end(); ++iter2)
				{
					if ((*iter)->Math < (*iter2)->Math)
					{
						StudentInfo* pTemp = (*iter);
						(*iter) = (*iter2);
						(*iter2) = pTemp;
					}
				}
				cout << (*iter)->Name << " : " << (*iter)->Math << endl;
			}
			break;

		case 4:
			Output();
			break;

		case 5:
			exit(NULL);
			break;
		}
		system("pause");
	}


	//��...�� �̵���....
	 



	return 0;
}


void LoadDate()
{
	//** �����͸� �ҷ��´�.
	FILE* pFileCSV = fopen("StudenInfoList.csv", "r");

	//** ������ ������ �о�´�.
	while (!feof(pFileCSV))
	{
		StudentInfo* pInfo = new StudentInfo;

		char buffer[128] = "";

		fscanf(pFileCSV, "%d,%d,%d,%d,%s",
			&pInfo->Index, &pInfo->Kor, &pInfo->Eng, &pInfo->Math, buffer);

		//** �о�� ���ڿ��� �����Ϳ� �°� �����Ѵ�.
		pInfo->Name = new char[4];
		strcpy(pInfo->Name, buffer);

		//** ����Ʈ�� �߰��Ѵ�.
		StudentList.push_back(pInfo);
	}

	StudentList.pop_back();

	//** ������ �ݴ´�.
	fclose(pFileCSV);
}
 
void Output()
{
	cout << endl << endl;
	cout << "******************" << endl;
	for (list<StudentInfo*>::iterator iter = StudentList.begin();
		iter != StudentList.end(); ++iter)
	{
		cout << (*iter)->Index << " : " << (*iter)->Name << endl;
		cout << "���� ���� : " << (*iter)->Kor << endl;
		cout << "���� ���� : " << (*iter)->Eng << endl;
		cout << "���� ���� : " << (*iter)->Math << endl << endl;
	}
	cout << "******************" << endl;
}
/*
void ScoreSwap(StudentInfo& _A, StudentInfo& _B)
{
	StudentInfo Temp = _A; 

	_A = _B; 
	_B = Temp;
}
*/

