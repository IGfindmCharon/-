// ѧ������ϵͳ.cpp : �������̨Ӧ�ó������ڵ㡣
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
int vac[100];//���ɾ����λ
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
			printf("������1~6������\n");
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
	printf("������ѧ������:\n");
	scanf_s("%s", student[*index].name, 10);
	printf("������ѧ��ѧ�ţ�\n");
	scanf_s("%s", student[*index].ID, 12);
	printf("������ѧ���ɼ�:\n");
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
	printf("1.�޸�����\n");
	printf("2.�޸�ѧ��\n");
	printf("3.�޸ĳɼ�\n");
	printf("4.����\n");
	int a;
	scanf_s("%d", &a);
	while (a != 4)
	{
		switch (a)
		{
			case 1:
				emptyname(student, locat);
				printf("������������\n");
				scanf_s("%s", student[locat].name, 10);
			case 2:
				emptyID(student, locat);
				printf("������ѧ��ѧ�ţ�\n");
				scanf_s("%s", student[locat].ID, 12);
			case 3:
				printf("������ѧ���ɼ���\n");
				scanf_s("%d", student[locat].score);
			default:
				printf("������1��2��3��");
				scanf_s("%d", &a);
		}
	}
	return 0;
}
int seek(data student[], int *count)
{
	int locat;
	locat = find(student, *count);
	printf("������");
	printf("%s\n", student[locat].name);
	printf("ѧ�ţ�");
	printf("%s\n", student[locat].ID);
	printf("�ɼ���");
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
			printf("������Ҫ������ѧ��������\n");
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
			printf("������Ҫ������ѧ��ѧ�ţ�\n");
			char str[13];
			scanf_s("%s", ch, 13);
			for (i = 0, j = 0; j < count&&student[i].name != str&&student[i].score != 101; ++i)
			{
				if (student[i].ID != 0)
					++j;
			}
			return i;
		default:printf("������1��2��");
			scanf_s("%d", &a);
		}
	}
	return 0;


}
void showmenu1()
{
	printf("ѧ������ϵͳ\n");
	printf("1.¼��ѧ���ɼ��ͻ�����Ϣ\n");
	printf("2.ɾ��ѧ����Ϣ\n");
	printf("3.�޸�ѧ����Ϣ\n");
	printf("4.��ѯѧ����Ϣ\n");
	printf("5.�˳�\n");
	printf("������1~6������\n");
}
void showmenu2()
{
	printf("1.���������ң�\n");
	printf("2.��ѧ�Ų��ң�\n");
	printf("3.������һ�㣺\n");
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