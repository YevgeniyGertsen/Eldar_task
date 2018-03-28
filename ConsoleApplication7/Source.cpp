#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale>
#include <iostream>
using namespace std;

struct fulName
{
	char fname[15];
	char sname[15];
	char mname[15];
};

struct Student
{
	fulName Name;
	int usp[15];
	int priznak;
};

void generationStudent(Student* student);
void sort(Student student[]);

void main()
{
	srand(time(NULL));
	rand();

	Student student[10];

	for (int i = 0; i < 10; i++)
		generationStudent(&student[i]);

	/*for (int i = 0; i < 255; i++)
	{
		printf("%d - %c\n", i, i);
	}*/
	sort(student);
	for (int i = 0; i < 10; i++)
	{
		printf("#%d \t%s %s %s\t %d\n",
			i, student[i].Name.fname,
			student[i].Name.sname,
			student[i].Name.mname,
			student[i].priznak);
	}

}

void generationStudent(Student* student)
{
	for (int i = 0; i < 14; i++)
	{
		student->Name.fname[i] = 97 + rand() % 25;
		student->Name.sname[i] = 97 + rand() % 25;
		student->Name.mname[i] = 97 + rand() % 25;
		student->usp[i] = 0 + rand() % 10;
	}
	student->Name.fname[14] = '\0';
	student->Name.sname[14] = '\0';
	student->Name.mname[14] = '\0';
	int min = 10;
	for (int i = 0; i < 15; i++)
	{
		if (min < student->usp[i])
			min = student->usp[i];
	}
	student->priznak = (min + 1) / 2;
}		//https://github.com/YevgeniyGertsen/Eldar_task

void sort(Student student[])
{
	for (int i = 0; i < 10; i++)
		for (int j = i; j > 0; j--)
			if (student[j].priznak < student[j - 1].priznak)
				swap(student[j], student[j - 1]);
}
/*��� ������� �������� �������� ���� �� ��������� �������� 
�������� : 5 � ��������(������ 9 �(���) 10), 
4 � ��������(��� ������, ������ 6, �� �� ��� 9 ��� 10, 
� ���� 6 �(���) 7 �(���) 8), 3 � ��������(��� ������, 
������ 4, �� ���� 4 �(���) 5), 2 � ������������(���� 1 
�(���) 2 �(���) 3).*/