#include<afxwin.h>
#include<windows.h>
#include<stdio.h>
#pragma comment (lib,"User32.lib")

void main()
{
	SetConsoleTitle("ʰɫ��");//����
	system("mode con cols=30 lines=3");//ָ�����ڴ�С
	while(1)
	{
		POINT point;
		::GetCursorPos(&point);//��ȡָ������
		HWND hWnd=::GetDesktopWindow();
		HDC hdc=::GetDC(hWnd);
		int x=point.x,y=point.y;
		COLORREF pixel=::GetPixel(hdc,x,y);
		if(pixel!=CLR_INVALID) //��ȡ����RGBֵ
		{
			int red = GetRValue(pixel);
			int green = GetGValue(pixel);
			int blue = GetBValue(pixel);
			printf("�� ��:(%d,%d)\nRGBֵ:%X%X%X",x,y,red,green,blue);
		}
		else 
			printf("Խ�磡\n");
		Sleep(200);//��ʱ
		system("cls");//����
	}
}