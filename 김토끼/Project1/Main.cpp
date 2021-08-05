#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>


using namespace std;

struct StudentInfo
{
	char* Name;
	int Index;

	int Kor;
	int Eng;
	int Math;
};


list<StudentInfo> StudentList;


void LoadDate();
void ScoreSwap(StudentInfo& _A, StudentInfo& _B);

int main(void)
{
	LoadDate();

	/*
	for (list<StudentInfo>::iterator iter = StudentList.begin();
		iter != StudentList.end(); ++iter)
	{
		cout << iter->Index << " : " << iter->Name << endl;
		cout << "���� ���� : " << iter->Kor << endl;
		cout << "���� ���� : " << iter->Eng << endl;
		cout << "���� ���� : " << iter->Math << endl << endl;
	}
	*/

	//** �о�� �����͸� ������ ������ ���� �������� ������ �Ұ��̴�.
	//** ����, ����, ���� �������� ������ �� ���õ� ������ ������ �������� �����Ұ�.

	while (true)
	{
		system("cls");

		cout << "1. �л� ���� ��ü ���" << endl;
		cout << "2. ���� ���� ��ü ���" << endl;
		cout << "3. ���� ���� ��ü ���" << endl;
		cout << "4. ���� ���� ��ü ���" << endl;
		cout << "5. ����" << endl;

		int Choice = 0;

		cout << "�Է� : "; cin >> Choice;

		system("cls");

		switch (Choice)
		{
		case 1://��ü
			for (list<StudentInfo>::iterator iter = StudentList.begin();
				iter != StudentList.end(); ++iter)
			{
				cout << iter->Index << " : " << iter->Name << endl;
				cout << "���� ���� : " << iter->Kor << endl;
				cout << "���� ���� : " << iter->Eng << endl;
				cout << "���� ���� : " << iter->Math << endl << endl;
			}
			break;
			
		case 2://����
			for (list<StudentInfo>::iterator iter = StudentList.begin(); iter != StudentList.end(); ++iter)
			{
				for (list<StudentInfo>::iterator iter2 = iter; iter2 != StudentList.end(); ++iter2)
				{
					if ((*iter).Kor < (*iter2).Kor)
					{
						ScoreSwap((*iter), (*iter2));
					}
				}

				cout << iter->Name << " : " << iter->Kor << endl;
			}
			break;

		case 3://����
			for (list<StudentInfo>::iterator iter = StudentList.begin(); iter != StudentList.end(); ++iter)
			{
				for (list<StudentInfo>::iterator iter2 = iter; iter2 != StudentList.end(); ++iter2)
				{
					if ((*iter).Eng < (*iter2).Eng)
					{
						ScoreSwap((*iter), (*iter2));
					}
				}
				cout << iter->Name << " : " << iter->Eng << endl;
			}
			break;

		case 4://����
			for (list<StudentInfo>::iterator iter = StudentList.begin(); iter != StudentList.end(); ++iter)
			{
				for (list<StudentInfo>::iterator iter2 = iter; iter2 != StudentList.end(); ++iter2)
				{
					if ((*iter).Math < (*iter2).Math)
					{
						ScoreSwap((*iter), (*iter2));
					}
				}
				cout << iter->Name << " : " << iter->Math << endl;
			}
			break;


		case 5:
			exit(NULL);
			break;
		}
		system("pause");
	}


	return 0;
}


void LoadDate()
{
	//** �����͸� �ҷ��´�.
	FILE* pFileCSV = fopen("StudenInfoList.csv", "r");

	//** ������ ������ �о�´�.
	while (!feof(pFileCSV))
	{
		StudentInfo Info;

		char buffer[128] = "";

		fscanf(pFileCSV, "%d,%d,%d,%d,%s",
			&Info.Index, &Info.Kor, &Info.Eng, &Info.Math, buffer);


		//** �о�� ���ڿ��� �����Ϳ� �°� �����Ѵ�.
		Info.Name = new char[4];
		strcpy(Info.Name, buffer);

		//** ����Ʈ�� �߰��Ѵ�.
		StudentList.push_back(Info);
	}

	//** ������ �ݴ´�.
	fclose(pFileCSV);
}

void ScoreSwap(StudentInfo& _A, StudentInfo& _B)
{
	StudentInfo Temp = _A; 

	_A = _B; 
	_B = Temp;
}

