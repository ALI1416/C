#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//����
void rand(int a[52],int b[52]);//������
void print(int a[],int b[],int c[]);//���
int count(int j[]);//������

void rand(int a[52],int b[52])//������
{	//z[]ÿһ�����ֵĸ���,a[]һ����,b[]������,n����
	int z[14]={0},n=0,i,x;
	for (i=0;n<52;i++)
	{
		x=rand()%13+1;  //����[1,13]�������
		{
			if(z[x]<4)
			{
				z[x]++;n++;
				if(n<27) a[n-1]=x;
				else b[n-27]=x;
			}
		}
	}
}

int count(int j[])//������
{
	for(int i=0;i<52;i++)
		if(j[i]==0) return i;
}

void print(int a[],int b[],int c[])//���
{
	int i;
	printf("��  �ƣ���%d��\n",count(c));//����
	for(i=0;i<14;i++)
	{
		if(c[i]!=0)
		{
		if((i+1)%10==0)printf("%-4d\n",c[i]);
		else printf("%-4d",c[i]);
		}
	}
	printf("\n���һ����%d��\n",count(a));//���һ
	for(i=0;i<52;i++)
	{
		if(a[i]!=0)
		{
		if((i+1)%10==0)printf("%-4d\n",a[i]);
		else printf("%-4d",a[i]);
		}
	}
	printf("\n��Ҷ�����%d��\n",count(b));//��Ҷ�
	for(i=0;i<52;i++)
	{
		if(b[i]!=0)
		{
		if((i+1)%10==0)printf("%-4d\n",b[i]);
		else printf("%-4d",b[i]);
		}
	}
	printf("\n");
}

void main()
{
	int a[52]={0},b[52]={0},c[14]={0};//a[]һ����,b[]������,c[]����
	srand((unsigned)time(NULL)); //��ʱ�������ӣ�ÿ�β����������һ��
	rand(a,b);
	print(a,b,c);
}