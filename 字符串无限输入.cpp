#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define N 10
#define M 8

char *inf()//����������
{
	char *arr=(char *)malloc(sizeof(char)*N);//�����ַ�������ʼ�����趨ΪN
	char input;//����һ����������������ַ�
	int strSize=N;//����arr�ַ����ܴ洢����󳤶�
	int Ngth=0;//�洢arr�Ѿ��洢���ַ�������
	while((input=getc(stdin))!= '\n')//����������ȡһ���ַ����������ַ�����\n
	{
		arr[Ngth]=input;//������ַ�����arr
		++Ngth;//arr�Ѵ洢���ȼ�1
		if(Ngth==strSize)// ����ַ��������Ѿ�������arr������ܴ洢����
		{
			arr=(char *)realloc(arr,strSize+N);//��ԭ��arr�Ĵ�С�ϣ���������һ����N���ȵĿռ�
			strSize+=N;//��arr�ܴ洢����󳤶ȸ���
		}
	}
	arr[Ngth]='\0';//���ַ���ĩβ��'\0'��ʾ����
	return arr;
}

void main()
{
	char *s=inf();
	int len=strlen(s);
	if(len>0&&len<=M)
		printf("�ַ�����%s�����ȣ�%d\n",s,len);
	else
		printf("����\n");
}