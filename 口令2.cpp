#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<string.h>

void main()
{
	printf("��ӭʹ��ѧ������ϵͳ\n");
	printf("��������\n");
	char get[10],pw[]="123";//����
	int count=3;
	while(count)
	{
		gets(get);
		if(strcmp(get,pw)==0)
		{
			printf("������ȷ�����ڽ���ϵͳ...\n");
			Sleep(500);//head();
		}
		else
		{
			if(count!=1)
			{
				printf("����������������룡\n");
				printf("������%d�λ��ᣡ\n",--count);
			}
			else
			{
				printf("������󣡰�������˳�ϵͳ��\n");
				getch();exit(1);
			}
		}
	}
}