#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<math.h>
#include<conio.h>
#include<windows.h>

void rand(int x);
int scan();
void gotoxy(int x,int y);
void dot_num(int x);

void main()
{
	system("mode con cols=96 lines=32");//��ʼ�����ڴ�С
	system("color 07");//��ʼ��������������ɫ
	SetConsoleTitle("��ǩ��"); //��ʼ�����ڱ���
	srand((unsigned)time(NULL));
	printf("**************************\n");
	printf("******��ӭʹ�ó�ǩ��******\n");
	printf("**************************\n\n");
	printf("---------ʹ�÷���---------\n");	
	printf("--���س���ǩ���������˳�--\n");
	rand(scan());
}

void gotoxy(int x,int y)//�ı���λ��
{
	HANDLE app;
	COORD  pos;
	pos.X=x;
	pos.Y=y;
	app=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(app,pos);
}

int scan()//�����ַ���������������Ƿ�Ϸ�
{
	while(1)
	{
		char s[100];
		int i,err=0,length=0,x;
		printf("\n������ѧ������");
		gets(s);
		length=strlen(s);
		for(i=0;i<length;i++)
			if(s[i]<'0'||s[i]>'9') 
				{err=1;break;}
		x=atoi(s);
			if(x!=0&&err==0){return x; break;}
		else {printf("\n������������������\n");continue;}
	}
}

void rand(int x)//�����
{
	while(1)
	{
		int t;
		t=rand()%x+1;
		system("cls");
		gotoxy(0,0);printf("��ȡ��ѧ��Ϊ��%d\t",t);
		dot_num(t);
		if(getch()==13) continue;
		else break;
	}
}

void dot_num(int x)//��ӡ��������
{
	int i=0,j=10,len=0;
	char s[10];
	itoa(x,s,10);
	len=strlen(s);
	i=(96-len*12)/2;
	for(int k=0,int t=0;k<len;k++,t++)
	{
		switch(s[k])
		{
		case '0':
			gotoxy(i,j++);printf("            ");
			gotoxy(i,j++);printf("    ������  ");
			gotoxy(i,j++);printf("  ��      ��");
			gotoxy(i,j++);printf("  ����    ��");
			gotoxy(i,j++);printf("  ��  ��  ��");
			gotoxy(i,j++);printf("  ��    ����");
			gotoxy(i,j++);printf("  ��      ��");
			gotoxy(i,j++);printf("    ������  ");
			i+=12;j=10;break;
		case '1':
			gotoxy(i,j++);printf("            ");
			gotoxy(i,j++);printf("      ��    ");
			gotoxy(i,j++);printf("    ����    ");
			gotoxy(i,j++);printf("      ��    ");
			gotoxy(i,j++);printf("      ��    ");
			gotoxy(i,j++);printf("      ��    ");
			gotoxy(i,j++);printf("      ��    ");
			gotoxy(i,j++);printf("  ����������");
			i+=12;j=10;break;
		case '2':
			gotoxy(i,j++);printf("            ");
			gotoxy(i,j++);printf("  ����������");
			gotoxy(i,j++);printf("          ��");
			gotoxy(i,j++);printf("          ��");
			gotoxy(i,j++);printf("  ����������");
			gotoxy(i,j++);printf("  ��        ");
			gotoxy(i,j++);printf("  ��        ");
			gotoxy(i,j++);printf("  ����������");
			i+=12;j=10;break;
		case '3':
			gotoxy(i,j++);printf("            ");
			gotoxy(i,j++);printf("  ����������");
			gotoxy(i,j++);printf("          ��");
			gotoxy(i,j++);printf("          ��");
			gotoxy(i,j++);printf("  ����������");
			gotoxy(i,j++);printf("          ��");
			gotoxy(i,j++);printf("          ��");
			gotoxy(i,j++);printf("  ����������");
			i+=12;j=10;break;
		case '4':
			gotoxy(i,j++);printf("            ");
			gotoxy(i,j++);printf("  ��      ��");
			gotoxy(i,j++);printf("  ��      ��");
			gotoxy(i,j++);printf("  ��      ��");
			gotoxy(i,j++);printf("  ����������");
			gotoxy(i,j++);printf("          ��");
			gotoxy(i,j++);printf("          ��");
			gotoxy(i,j++);printf("          ��");
			i+=12;j=10;break;
		case '5':
			gotoxy(i,j++);printf("            ");
			gotoxy(i,j++);printf("  ����������");
			gotoxy(i,j++);printf("  ��        ");
			gotoxy(i,j++);printf("  ��        ");
			gotoxy(i,j++);printf("  ����������");
			gotoxy(i,j++);printf("          ��");
			gotoxy(i,j++);printf("          ��");
			gotoxy(i,j++);printf("  ����������");
			i+=12;j=10;break;
		case '6':
			gotoxy(i,j++);printf("            ");
			gotoxy(i,j++);printf("  ����������");
			gotoxy(i,j++);printf("  ��        ");
			gotoxy(i,j++);printf("  ��        ");
			gotoxy(i,j++);printf("  ����������");
			gotoxy(i,j++);printf("  ��      ��");
			gotoxy(i,j++);printf("  ��      ��");
			gotoxy(i,j++);printf("  ����������");
			i+=12;j=10;break;
		case '7':
			gotoxy(i,j++);printf("            ");
			gotoxy(i,j++);printf("  ����������");
			gotoxy(i,j++);printf("          ��");
			gotoxy(i,j++);printf("          ��");
			gotoxy(i,j++);printf("          ��");
			gotoxy(i,j++);printf("          ��");
			gotoxy(i,j++);printf("          ��");
			gotoxy(i,j++);printf("          ��");
			i+=12;j=10;break;
		case '8':
			gotoxy(i,j++);printf("            ");
			gotoxy(i,j++);printf("  ����������");
			gotoxy(i,j++);printf("  ��      ��");
			gotoxy(i,j++);printf("  ��      ��");
			gotoxy(i,j++);printf("  ����������");
			gotoxy(i,j++);printf("  ��      ��");
			gotoxy(i,j++);printf("  ��      ��");
			gotoxy(i,j++);printf("  ����������");
			i+=12;j=10;break;
		case '9':
			gotoxy(i,j++);printf("            ");
			gotoxy(i,j++);printf("  ����������");
			gotoxy(i,j++);printf("  ��      ��");
			gotoxy(i,j++);printf("  ��      ��");
			gotoxy(i,j++);printf("  ����������");
			gotoxy(i,j++);printf("          ��");
			gotoxy(i,j++);printf("          ��");
			gotoxy(i,j++);printf("  ����������");
			i+=12;j=10;break;
		}
	}
}