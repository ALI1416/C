#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define PW "123"//����
#define N 8//�����������

void main()
{
	char s[]=PW;
	char *t=(char *)malloc(N);
	while(1)
	{
		gets(t);
		if(strlen(t)>N)
		{
			printf("���������\n");
		}
		else
		{
			if(strcmp(s,t)==0)
			{
				printf("������ȷ��\n");
				break;
			}
			else
			{
				printf("�������\n");
			}
		}
	}
}