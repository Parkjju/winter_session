#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "members.h"
#include "employee.h"

Employee* work_calender(List*, char*,int);
int main(void)
{
	printf("직원정보 입력\n");
	List members;
	ListInit(&members);

	int date = 7;
	Employee* person;
	Employee* searc;

	person = (Employee*)malloc(sizeof(Data));
	strcpy(person->name, "park");
	person->empNum = 201710342;
	LInsert(&members, person);
	
	person = (Employee*)malloc(sizeof(Data));
	strcpy(person->name, "kimkim");
	person->empNum = 2018123455;
	LInsert(&members, person);

	searc = work_calender(&members, "park", 1);
	printf("names 7일 이후 당직자 : ");
	puts(searc->name);

	return 0;
}

Employee* work_calender(List* mem, char* pname,int pnum)
{
	int i = 0;
	int num;
	num = LCount(mem);
	Employee* search;
	LFirst(mem, &search);
	if (strcmp(search->name, pname) != 0)
	{
		for (i = 0; i < num - 1; i++)
		{
			LNext(mem, &search);
			if (strcmp(search->name, pname) == 0)
				break;
		}
	}

	for (i = 0; i < pnum; i++)
	{
		LNext(mem, search);
	}
	return search;
}