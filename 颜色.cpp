#include <windows.h>  
#include <stdio.h>
#include <stdlib.h>
/*
FOREGROUND_BLUE ��ɫ
FOREGROUND_GREEN ��ɫ
FOREGROUND_RED ��ɫ
FOREGROUND_INTENSITY ��ǿ
BACKGROUND_BLUE ��ɫ����
BACKGROUND_GREEN ��ɫ����
BACKGROUND_RED ��ɫ����
BACKGROUND_INTENSITY ����ɫ��ǿ
COMMON_LVB_REVERSE_VIDEO ��ɫ
GetConsoleScreenBufferInfo ��ȡ����̨������Ϣ
GetConsoleTitle ��ȡ����̨���ڱ���
ScrollConsoleScreenBuffer �ڻ��������ƶ����ݿ�
SetConsoleScreenBufferSize ����ָ����������С
SetConsoleTitle ���ÿ���̨���ڱ���
SetConsoleWindowInfo ���ÿ���̨������Ϣ
*/
int main()  
{  
	HANDLE hOut=GetStdHandle(STD_OUTPUT_HANDLE);    
 	
	//  ��ȡ������ľ��
	
	SMALL_RECT rc = {350,250,500,500};
	SetConsoleWindowInfo(hOut,true ,&rc);
	system("mode con cols=94 lines=30");//��Ļ��С

	COORD size={94,100};
	SetConsoleScreenBufferSize(hOut,size);//��������С
	
	printf("��ͨ��ɫ����\n");
	
	SetConsoleTextAttribute(hOut,  
		FOREGROUND_GREEN |		// ǰ��ɫ_��ɫ
		FOREGROUND_INTENSITY ); // ǰ��ɫ_��ǿ
	printf("������ǳ��ɫ\n");  
	printf("��������֮���һֱ��ǳ��ɫ\n");
	
	SetConsoleTextAttribute(hOut,  
		FOREGROUND_BLUE |		// ǰ��ɫ_��ɫ
		FOREGROUND_INTENSITY |	// ǰ��ɫ_��ǿ
		COMMON_LVB_UNDERSCORE);	// ����»���
	printf("������ɫ���ټӸ��»���\n");    
	
	SetConsoleTextAttribute(hOut,  
		FOREGROUND_RED |		// ǰ��ɫ_��ɫ
		FOREGROUND_INTENSITY |	// ǰ��ɫ_��ǿ
		BACKGROUND_BLUE );		// ����ɫ_��ɫ
	printf("�������ֺ�ɫ��������ɫ\n");  
	
	SetConsoleTextAttribute(hOut,  
		FOREGROUND_RED |			// ǰ��ɫ_��ɫ
		FOREGROUND_INTENSITY |		// ǰ��ɫ_��ǿ
		COMMON_LVB_GRID_LVERTICAL );// ����_��_��
	printf("                      �� �� ����\n");  
	
	SetConsoleTextAttribute(hOut,  
		FOREGROUND_RED |			// ǰ��ɫ_��ɫ
		FOREGROUND_INTENSITY |		// ǰ��ɫ_��ǿ
		COMMON_LVB_GRID_RVERTICAL );// ����_��_��  
	printf("                      �� �� ����\n");    
	SetConsoleTextAttribute(hOut,  
		FOREGROUND_RED |  // ǰ��ɫ_��ɫ
		FOREGROUND_BLUE | // ǰ��ɫ_��ɫ
		FOREGROUND_INTENSITY);// ��ǿ
	printf(" �� + �� = ��ɫ ^_^\n");  
	SetConsoleTextAttribute(hOut,  
		FOREGROUND_RED |	// ǰ��ɫ_��ɫ
		FOREGROUND_GREEN |	// ǰ��ɫ_��ɫ
		FOREGROUND_BLUE );  // ǰ��ɫ_��ɫ
	printf("�Ļذ�ɫ\n");  
	//system("pause");
	SetConsoleTextAttribute(hOut,4);
	printf("�Ļذ�ɫ\n");  
	return 0;  
}