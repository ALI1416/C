#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<math.h>
#include<conio.h>
#include<windows.h>

void rand(int x);
int scan();
int num(char s[]);

void main()
{
	SetConsoleTitle("��ǩ��"); //����
	srand((unsigned)time(NULL));
	printf("**************************\n");
	printf("******��ӭʹ�ó�ǩ��******\n");
	printf("**************************\n\n");
	printf("---------ʹ�÷���---------\n");	
	printf("--���س���ǩ���������˳�--\n");
	rand(scan());
}

int scan()//�����ַ���
{
	while(1)
	{
		char x[100];
		int t;
		printf("\n������ѧ������");
		gets(x);
		t=num(x);
		if(t>0){return t;break;}
		else {printf("\n������������������\n");continue;}
	}
}
int num(char s[])//�ַ���ת������
{
	int i=0,n=0,err=0,length=0,num=0;
	length=strlen(s);
	for(i=0;i<length;i++)
		if(s[i]<'0'||s[i]>'9') {err=1;break;}
		if(err==0)
		{
			for(i=0;i<length;i++)
			{
				n=((int)s[i])-48;
				num+=(pow(10,(length-i-1))*n);
			}
			return num;
		}
		else return -1;
}

void rand(int x)//�����
{
	while(1)
	{
		printf("���ڳ�ǩ��....\n");
		Sleep(300);//��ʱ300ms
		printf("��ȡ��ѧ��Ϊ��%d\n",rand()%x+1);
		if(getch()==13) continue;
		else break;
	}
}



