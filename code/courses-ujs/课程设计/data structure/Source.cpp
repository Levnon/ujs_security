
#include "resource.h"
int main(int argc,char *argv[])
{
	system("color 64");
	HWND hwnd = GetForegroundWindow();//ʹhwnd������ǰ�˵Ĵ���
	ShowWindow(hwnd, SW_MAXIMIZE);//��� hwnd ������Ĵ��� 
	//SetConsoleTitle(L"���Ĵ��С������ݽṹ�γ����");//���ô��ڱ���
	SetWindowTextW(hwnd, L"���Ĵ��С������ݽṹ�γ����");
	Tree t;
	Status s=t.Init();
	if (s==FAILURE)
	{
		::MessageBoxW(NULL, L"��ʼ��ʧ��", L"ע��", MB_ICONERROR | MB_OK);
		return -1;
	}
	t.Menu();
	system("pause");

	return 0;
}