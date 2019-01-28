// 学生管理系统.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
	int score;
	char ID[12];
	char name[10];
}data;
data student[100];
int increase(int *index, int *count);
int cancel(data student[], int *count, int vac[]);
int modifi(data student[], int *count);
int seek(data student[], int *count);
void showmenu1();
void showmenu2();
int find(data student[], int count);
int vac[100];//存放删除空位
int emptyID(data student[], int n);
int emptyname(data student[], int n);

int main()
{
	for (int i = 0; i < 100; ++i)
	{
		vac[i] = 100;
	}
	showmenu1();
	int x;
	int index = 0;
	int count = 0;
	scanf_s("%d", &x);
	while (x != 5)
	{
		if (x < 1 || x>6)
			printf("请输入1~6的数：\n");
		else
		{
			switch (x)
			{
			case 1:increase(&index, &count); break;
			case 2:cancel(student, &count, vac); break;
			case 3:modifi(student, &count); break;
			case 4:seek(student, &count);
			}
			system("cls");
			showmenu1();
		}
		scanf_s("%d", &x);
	}

	return 0;
}

int increase(int *index, int *count)
{
	printf("请输入学生姓名:\n");
	scanf_s("%s", student[*index].name, 10);
	printf("请输入学生学号：\n");
	scanf_s("%s", student[*index].ID, 12);
	printf("请输入学生成绩:\n");
	scanf_s("%d", &student[*index].score);
	index++;
	count++;
	return 0;
}
int cancel(data student[], int *count, int vac[])
{
	int locat;
	locat = find(student, *count);
	emptyID(student,locat);
	emptyname(student, locat);
	for (int i = 0; i < 100; ++i)
	{
		if (vac[i] == 100)
			vac[i] = locat;
	}
	student[locat].score = 101;
	count--;
	return 0;
}
int modifi(data student[], int *count)
{
	showmenu2();
	int locat;
	locat = find(student, *count);
	printf("1.修改名字\n");
	printf("2.修改学号\n");
	printf("3.修改成绩\n");
	printf("4.返回\n");
	int a;
	scanf_s("%d", &a);
	while (a != 4)
	{
		switch (a)
		{
			case 1:
				emptyname(student, locat);
				printf("请输入姓名：\n");
				scanf_s("%s", student[locat].name, 10);
			case 2:
				emptyID(student, locat);
				printf("请输入学生学号：\n");
				scanf_s("%s", student[locat].ID, 12);
			case 3:
				printf("请输入学生成绩：\n");
				scanf_s("%d", student[locat].score);
			default:
				printf("请输入1、2、3：");
				scanf_s("%d", &a);
		}
	}
	return 0;
}
int seek(data student[], int *count)
{
	int locat;
	locat = find(student, *count);
	printf("姓名：");
	printf("%s\n", student[locat].name);
	printf("学号：");
	printf("%s\n", student[locat].ID);
	printf("成绩：");
	printf("%d\n", student[locat].score);
	getchar();
	getchar();
	return 0;
}
int find(data student[], int count)
{
	showmenu2();
	int a;
	scanf_s("%d", &a);
	while (a != 3)
	{
		switch (a)
		{
		case 1:
			printf("请输入要操作的学生姓名：\n");
			char ch[10];
			scanf_s("%s", ch, 10);
			int i, j;
			for (i = 0, j = 0; j < count&&student[i].name != ch&&student[i].score != 101; ++i)
			{
				if (student[i].ID != 0)
					++j;
			}
			return i;
			break;
		case 2:
			printf("请输入要操作的学生学号：\n");
			char str[13];
			scanf_s("%s", ch, 13);
			for (i = 0, j = 0; j < count&&student[i].name != str&&student[i].score != 101; ++i)
			{
				if (student[i].ID != 0)
					++j;
			}
			return i;
		default:printf("请输入1或2：");
			scanf_s("%d", &a);
		}
	}
	return 0;


}
void showmenu1()
{
	printf("学生管理系统\n");
	printf("1.录入学生成绩和基本信息\n");
	printf("2.删除学生信息\n");
	printf("3.修改学生信息\n");
	printf("4.查询学生信息\n");
	printf("5.退出\n");
	printf("请输入1~6的数：\n");
}
void showmenu2()
{
	printf("1.按姓名查找：\n");
	printf("2.按学号查找：\n");
	printf("3.返回上一层：\n");
}
int emptyname(data student[],int n)
{
	for (int i = 0; i < 10; ++i)
	{
		student[n].name[i] = '\0';
	}
	return 0;
}
int emptyID(data student[],int n)
{
	for (int i = 0; i < 12; ++i)
	{
		student[n].ID[i] = '\0';
	}
	return 0;
}