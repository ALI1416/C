/*�Ʊ��
���������������������
�E���ˡ��̡������衬�d�e���Y
�x�y�z�{�|�}�~��

����������������

�����������x�������U�����T���������u�v�w
���x�����Щ����ש��X�j�[�I���J������
����������ȩǩ�Ϩd�p�g���I��������
���������ة����ߩ��^�m�a�L���K������
*/

//��ʼ�����ڴ�С
#include<stdlib.h>
system("mode con cols=50 lines=15");

//��ʼ�����ڵı���
#include<windows.h>
SetConsoleTitle("����"); 

//�밴���������
#include<stdio.h>
system("PAUSE");//�밴���������. . .

//��ʼ��������������ɫ
#include<stdlib.h>
system("color 07");//����������
/*
0 = ��ɫ   8 = ��ɫ 
1 = ��ɫ   9 = ����ɫ 
2 = ��ɫ   A = ����ɫ 
3 = ǳ��ɫ B = ��ǳ��ɫ 
4 = ��ɫ   C = ����ɫ 
5 = ��ɫ   D = ����ɫ 
6 = ��ɫ   E = ����ɫ 
7 = ��ɫ   F = ����ɫ 
*/

//��ɫ
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_INTENSITY);//�ڵ������֡�	

//����ת�ַ���
#include<stdlib.h>
itoa(123,str,10);  //������ֵת��Ϊ�ַ���
itoa(123,str,10);  //��������ֵת��Ϊ�ַ���
ultoa(123,str,10); //���޷��ų�����ֵת��Ϊ�ַ���
//(��ת��������,Ŀ���ַ���,����)
//����������ANSI��׼�ǲ����ݵġ�

//�ַ�����ʽת������
#include<stdio.h>
sprintf(str,"%X",15);//ע�⣺�������
/*(Ŀ���ַ���,ת����ʽ,��ת������)
%c ����ת�ɶ�Ӧ�� ASCII ��Ԫ��
%d ����ת��ʮ��λ��
%f ����ȷ������ת�ɸ�������
%o ����ת�ɰ˽�λ��
%s ����ת���ַ�����
%x ����ת��Сдʮ����λ��
%X ����ת�ɴ�дʮ����λ��*/

//�ַ���ת����(ע�����)
#include<stdlib.h>
atoi(str);
/*atof()    ���ַ���ת��Ϊ˫���ȸ�����ֵ
 atoi()     ���ַ���ת��Ϊ����ֵ
 atol()     ���ַ���ת��Ϊ������ֵ
 strtod()   ���ַ���ת��Ϊ˫���ȸ�����ֵ�������治�ܱ�ת��������ʣ������
 strtol()   ���ַ���ת��Ϊ����ֵ�������治�ܱ�ת��������ʣ������
 strtoul()  ���ַ���ת��Ϊ�޷��ų�����ֵ�������治�ܱ�ת��������ʣ������*/

//��ʱ
#include<windows.h>
Sleep(1000);//����

//����
#include<windows.h>
system("cls");

//��ȡ�����ַ�������ʾ
#include<conio.h>
getch();

//�����
#include<stdlib.h>
#include<time.h>
srand((unsigned)time(NULL));
rand();

//��ʼ��������λ��(����)
#include<windows.h>
void gotoxy(int x,int y)
{
	HANDLE app;
	COORD  pos;
	pos.X=x;
	pos.Y=y;
	app=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(app,pos);
}

//��ȡ��ǰ������ڵ���Ļ��λ������
#include <stdio.h>
#include <afx.h>
void main()
{
    POINT point;
    ::GetCursorPos(&point);
    printf("x=%d,y=%d\n",point.x,point.y);
}

//��ȡָ��λ����ɫֵ
#include<afxwin.h>
#include<windows.h>
#pragma comment (lib,"User32.lib")
void main()
{
	HWND hWnd=::GetDesktopWindow();
	HDC hdc=::GetDC(hWnd);
	int x=100,y=100;//ָ��λ��
	COLORREF pixel=::GetPixel(hdc,x,y);
	if(pixel!=CLR_INVALID) 
	{
		int red = GetRValue(pixel);
		int green = GetGValue(pixel);
		int blue = GetBValue(pixel);
		printf("%x%x%x\n",red,green,blue);
	}
	else 
		printf("Խ�磡\n");
	system("PAUSE");//�밴���������. . .
}

//��ȡ��ǰ������ڹ���̨������
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
void main(int argc,char*argv[])
{
    HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coordScreen={0,0}; 
    CONSOLE_SCREEN_BUFFER_INFO csbi;
	int x,y;
    if (GetConsoleScreenBufferInfo(hConsole,&csbi))
	{
		x=csbi.dwCursorPosition.X;
		y=csbi.dwCursorPosition.Y;
	}
	printf("�������:(%d,%d)\n",x,y);
}

//���ʱ��
#include <stdio.h>
#include <time.h>  
void main ()
{
	time_t rawtime;
	struct tm*timeinfo;
	time(&rawtime);
	timeinfo=localtime(&rawtime);
	char CruuentTime[50];
	strftime(CruuentTime,24,"%Y-%m-%d %H:%M:%S\n",timeinfo);//��ʽ��ʱ��
	printf(CruuentTime);
}

#include <time.h>
#include<stdio.h>
/*struct tm1{
int tm_sec;  //����Ŀǰ����, ������ΧΪ0-59, ��������61 ��
int tm_min;  //����Ŀǰ����, ��Χ0-59
int tm_hour;  //����ҹ�����ʱ��, ��ΧΪ0-23
int tm_mday;  //Ŀǰ�·ݵ�����, ��Χ01-31
int tm_mon;  //����Ŀǰ�·�, ��һ������, ��Χ��0-11
int tm_year;  //��1900 ���������������
int tm_wday;  //һ���ڵ�����, ������һ����, ��ΧΪ0-6
int tm_yday;  //�ӽ���1 ��1 ���������������, ��ΧΪ0-365
int tm_isdst;  //�չ��Լʱ������
};*/
void main(){
    char *wday[] = {"����", "��һ", "�ܶ�", "����", "����", "����", "����"};
    time_t timep;
    struct tm *p;
    time(&timep);
    p = gmtime(&timep);
    printf("%d-%d-%d", (1900+p->tm_year), (1+p->tm_mon), p->tm_mday);
    printf(" %s %d:%d:%d\n", wday[p->tm_wday], p->tm_hour, p->tm_min, p->tm_sec);
}

//���������������
#include<stdio.h>
#include<string.h>
#include<math.h>
int num(char s[])
{
	int i,x,err=0,length=0,num=0;
	length=strlen(s);
	for(i=0;i<length;i++)
		if(s[i]<'0'||s[i]>'9') 
		{err=1;break;}
		if(err==0)
		{
			for(i=0;i<length;i++)
			{
				x=((int)s[i])-48;
				num+=(pow(10,(length-i-1))*x);
			}
			return num;
		}
		else 
			return -1;
}

void main()
{
	char s[10];
	gets(s);
	printf("%d",num(s));
}

//�������ַ������
#include<stdio.h>
#include<string.h>
int num(char s[])
{
	int i,x,err=0,length=0,num=0;
	length=strlen(s);
	for(i=0;i<length;i++)
		if(s[i]<'0'||s[i]>'9') 
		{err=1;break;}
		return err;
}

void main()
{
	char s[10];
	gets(s);
	if(num(s)==0) puts(s);
}

//ð������
for(j=0;j<n-1;j++)
for(i=0;i<n-1-j;i++)
{
	if(a[i]>a[i+1])
	{t=a[i];a[i]=a[i+1];a[i+1]=t;}
}

//ѡ������
for(i=0;i<N-1;i++)
{
	k=i;
	for(j=i+1;j<N;j++)
		if(a[k]<a[j])k=j;
		if(k!=i){t=a[i];a[i]=a[k];a[k]=t;}
}

//�ַ�������
void sort(struct people *p)
{
	int i,j,k;
	struct people tmp;
	for(i=0;i<N-1;i++)
	{
		k=i;
		for(j=i+1;j<N;j++)
		{
			if(strcmp(p[k].name,p[j].name)>0)k=j;
			if(k!=j){tmp=p[i];p[i]=p[j];p[j]=tmp;}
		}
	}
}