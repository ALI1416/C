#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define N 8

char *lim()
{
	int i=0;
	char ch;
	char *s=(char *)malloc(sizeof(char)*N);
	while(1)
	{
		ch=getch();
		if(ch>=32&&ch<=127&&i<=N-1)//��Ч�����ַ�
		{
			s[i++]=ch;
			printf("*");//���'*'
			//printf("%c",ch);//����ַ�
		}
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

void main()
{
	char *s=lim();
	printf("%s",s);
}

