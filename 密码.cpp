#include <stdio.h>
#include <conio.h>
#define MAX_PSD_LEN 20

char PassWord[MAX_PSD_LEN],*p=PassWord,ch;
int count=0;
void main()
{
	printf("input password:");
	
    ch=getch();   //����һ���ַ���������ʾ
    while(ch!=13&&count<MAX_PSD_LEN-1)       /*�����»س��������볤�ȴﵽ19�����˳�ѭ��*/
    {
       
         if((ch<='Z'&&ch>='A')||(ch<='z'&&ch>='a')||(ch<='9'&&ch>='0'))
                                                  /*�����������������Ч�ַ�*/
        {
            printf("*");          /*���һ���Ǻ�*/
            count++;
            *p=ch;                /*��¼��������*/
            p++;
        }
        ch=getch();                    /*�ȴ�������һ���ַ�*/
    }
    PassWord[count]=0;
    printf("\nThe Password you input is:\n");
    printf("%s\n",PassWord);
}


