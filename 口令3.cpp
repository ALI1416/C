#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<string.h>
#define N 16

void gotoxy(int x,int y)
{
	HANDLE app;
	COORD  pos;
	pos.X=x;
	pos.Y=y;
	app=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(app,pos);
}
//printf("���������x��");

char *lim()
{
	int i=0;
	char ch;
	char *s=(char *)malloc(sizeof(char)*N);
	while(1)
	{
		ch=getch();
		if(ch>=33&&ch<=127&&i<=N-1)//��Ч�����ַ�
		{
			s[i++]=ch;
			printf("*");//���'*'
			//printf("%c",ch);//����ַ�
		}
		if(ch==32)//�ո��˳�
			exit(0);
		if(ch==8&&i>0)//�˸�
		{
			i--;
			printf("\b \b");
		}
		if(ch==13&&i>0)//�س�
		{
			s[i]=0;
			return s;
		}
	}
}

int pass(char *pw)
{
	printf("\n\n\n");
	printf("\t\t\t\t����������������������������\n");
	printf("\t\t\t\t��                        ��\n");
	printf("\t\t\t\t��       ���������       ��\n");
	printf("\t\t\t\t��    �x�x�x�x�x�x�x�x    ��\n");
	printf("\t\t\t\t��  ��                ��  ��\n");
	printf("\t\t\t\t��    ����������������    ��\n");
	printf("\t\t\t\t��[�س�]ȷ��    [�ո�]�رը�\n");
	printf("\t\t\t\t��                        ��\n");
	printf("\t\t\t\t����������������������������\n");
	gotoxy(38,7);
	int count=3;
	while(count)
	{
		char *get=lim();
		if(strcmp(get,pw)==0)
		{
			gotoxy(33,10);
			printf("������ȷ�����ڽ���ϵͳ...");
			getch();
			//delay();
			return 1;//��ȷ
		}
		else
		{
			if(count!=1)
			{
				gotoxy(33,10);
				printf("�������ʣ�ೢ�Դ���%d��",--count);
				gotoxy(38,7);
				printf("\t\t");
				gotoxy(38,7);
			}
			else
			{
			gotoxy(33,10);
				printf("������󣡰�������˳���");
				getch();
				return 0;//����
			}
		}
	}
	return 0;
}

void main()
{
	pass("123");
	
}