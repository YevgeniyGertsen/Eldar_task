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
/*ƒл€ каждого студента получить одно из следующих значений 
признака : 5 Ц отличник(только 9 и(или) 10), 
4 Ц хорошист(нет оценок, меньше 6, но не все 9 или 10, 
а есть 6 и(или) 7 и(или) 8), 3 Ц троечник(нет оценок, 
меньше 4, но есть 4 и(или) 5), 2 Ц неуспевающий(есть 1 
и(или) 2 и(или) 3).*/