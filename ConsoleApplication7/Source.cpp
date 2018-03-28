#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale>
#include <iostream>

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

void generationStudent(Student student);

void main()
{
	Student student[10];

	for (int i = 0; i < 10; i++)
		generationStudent(student[i]);

	/*for (int i = 0; i < 255; i++)
	{
		printf("%d - %c\n", i, i);
	}*/

}

void generationStudent(Student student)
{
	for (int i = 0; i < 15; i++)
	{
		student.Name.fname[i] = 97 + rand() % 25;
		student.Name.sname[i] = 192 + rand() % 25;
		student.Name.mname[i] = 192 + rand() % 25;
	}
}
