/********************************************
�ļ�����sysfun3.cpp
���ܣ�sys�ĳ�Ա����3
********************************************/
#include"alclass.h"
void sys::Modify1()
{
	int num;
	system("cls");
	if (count <= 0)
	{
		cout << endl << endl << endl << endl;
		cout << "\t\t\t*********************************" << endl;
		cout << "\t\t\t*                               *" << endl;
		cout << "\t\t\t*                               *" << endl;
		cout << "\t\t\t*                               *" << endl;
		cout << "\t\t\t*                               *" << endl;
		cout << "\t\t\t*                               *" << endl;
		cout << "\t\t\t*                               *" << endl;
		cout << "\t\t\t*                               *" << endl;
		cout << "\t\t\t*      �˵�Ϊ�գ��޸�ʧ��!      *" << endl;
		cout << "\t\t\t*                               *" << endl;
		cout << "\t\t\t*                               *" << endl;
		cout << "\t\t\t*                               *" << endl;
		cout << "\t\t\t*                               *" << endl;
		cout << "\t\t\t*                               *" << endl;
		cout << "\t\t\t*                               *" << endl;
		cout << "\t\t\t*                               *" << endl;
		cout << "\t\t\t*                               *" << endl;
		cout << "\t\t\t*********************************" << endl;
		SYSTEMTIME sy;
		GetLocalTime(&sy);
		cout << "\t\t\t  " << sy.wYear << "��" << sy.wMonth << "��" << sy.wDay << "��" << endl;
		cout << "\t\t\t  " << sy.wHour << ":" << sy.wMinute << ":" << sy.wSecond;
		Sleep(1000);
		Print();
	}
	else
	{
		cout << "\t\t\t��������Ҫ�޸ĵĲ͵����" << endl;
		char * s = new char[20];
		cin >> s;
		system("cls");
		cout << endl << endl << endl << endl;
		num = atoi(s);
		a[num].output1();
		Sleep(1000);
		system("cls");
	loop1:a[num].input();
		if (test())
		{
			cout << endl << endl << endl << endl;
			cout << "\t\t\t*********************************" << endl;
			cout << "\t\t\t*                               *" << endl;
			cout << "\t\t\t*                               *" << endl;
			cout << "\t\t\t*                               *" << endl;
			cout << "\t\t\t*                               *" << endl;
			cout << "\t\t\t*                               *" << endl;
			cout << "\t\t\t*                               *" << endl;
			cout << "\t\t\t*                               *" << endl;
			if (count>10)
				cout << "\t\t\t*    �޸ĳɹ����������Ϊ" << num << "     *" << endl;
			else
				cout << "\t\t\t*    �޸ĳɹ����������Ϊ0" << num << "     *" << endl;
			cout << "\t\t\t*                               *" << endl;
			cout << "\t\t\t*                               *" << endl;
			cout << "\t\t\t*                               *" << endl;
			cout << "\t\t\t*                               *" << endl;
			cout << "\t\t\t*      �Ƿ�����޸�(y/n)        *" << endl;
			cout << "\t\t\t*                               *" << endl;
			cout << "\t\t\t*                               *" << endl;
			cout << "\t\t\t*                               *" << endl;
			cout << "\t\t\t*********************************" << endl;
			SYSTEMTIME sy;
			GetLocalTime(&sy);
			cout << "\t\t\t  " << sy.wYear << "��" << sy.wMonth << "��" << sy.wDay << "��" << endl;
			cout << "\t\t\t  " << sy.wHour << ":" << sy.wMinute << ":" << sy.wSecond << endl;
		}
		else
		{
			cout << endl << endl << endl << endl;
			cout << "\t\t\t*********************************" << endl;
			cout << "\t\t\t*                               *" << endl;
			cout << "\t\t\t*                               *" << endl;
			cout << "\t\t\t*                               *" << endl;
			cout << "\t\t\t*                               *" << endl;
			cout << "\t\t\t*                               *" << endl;
			cout << "\t\t\t*                               *" << endl;
			cout << "\t\t\t*                               *" << endl;
			cout << "\t\t\t*      �۸�һ��,�޸�ʧ�ܣ�    *" << endl;
			cout << "\t\t\t*                               *" << endl;
			cout << "\t\t\t*                               *" << endl;
			cout << "\t\t\t*                               *" << endl;
			cout << "\t\t\t*                               *" << endl;
			cout << "\t\t\t*                               *" << endl;
			cout << "\t\t\t*                               *" << endl;
			cout << "\t\t\t*                               *" << endl;
			cout << "\t\t\t*                               *" << endl;
			cout << "\t\t\t*********************************" << endl;
			SYSTEMTIME sy;
			GetLocalTime(&sy);
			cout << "\t\t\t  " << sy.wYear << "��" << sy.wMonth << "��" << sy.wDay << "��" << endl;
			cout << "\t\t\t  " << sy.wHour << ":" << sy.wMinute << ":" << sy.wSecond;
			Sleep(1000);
			goto loop1;
		}
		char c;
		c = _getch();
		if (c == 'y' || c == 'Y') Modify1();
		Print();
		delete[]s;
	}
}
void sys::Modify2()
{
	int num;
	system("cls");
	if (count <= 0)
	{
		cout << endl << endl << endl << endl;
		cout << "\t\t\t*********************************" << endl;
		cout << "\t\t\t*                               *" << endl;
		cout << "\t\t\t*                               *" << endl;
		cout << "\t\t\t*                               *" << endl;
		cout << "\t\t\t*                               *" << endl;
		cout << "\t\t\t*                               *" << endl;
		cout << "\t\t\t*                               *" << endl;
		cout << "\t\t\t*                               *" << endl;
		cout << "\t\t\t*      �˵�Ϊ�գ��޸�ʧ��!      *" << endl;
		cout << "\t\t\t*                               *" << endl;
		cout << "\t\t\t*                               *" << endl;
		cout << "\t\t\t*                               *" << endl;
		cout << "\t\t\t*                               *" << endl;
		cout << "\t\t\t*                               *" << endl;
		cout << "\t\t\t*                               *" << endl;
		cout << "\t\t\t*                               *" << endl;
		cout << "\t\t\t*                               *" << endl;
		cout << "\t\t\t*********************************" << endl;
		SYSTEMTIME sy;
		GetLocalTime(&sy);
		cout << "\t\t\t  " << sy.wYear << "��" << sy.wMonth << "��" << sy.wDay << "��" << endl;
		cout << "\t\t\t  " << sy.wHour << ":" << sy.wMinute << ":" << sy.wSecond;
		Sleep(1000);
		Print();
	}
	else
	{
		cout << "\t\t\t��������Ҫ�޸ĵĲ͵����" << endl;
		char * s = new char[20];
		cin >> s;
		system("cls");
		cout << endl << endl << endl << endl;
		cout << "\t\t\t*********************************" << endl;
		cout << "\t\t\t��Ҫ�޸ĵ��������£�";
		num = atoi(s);
		a[num].output2();
		Sleep(1000);
		system("cls");
	loop1:a[num].input();
		if (test())
		{
			cout << endl << endl << endl << endl;
			cout << "\t\t\t*********************************" << endl;
			cout << "\t\t\t*                               *" << endl;
			cout << "\t\t\t*                               *" << endl;
			cout << "\t\t\t*                               *" << endl;
			cout << "\t\t\t*                               *" << endl;
			cout << "\t\t\t*                               *" << endl;
			cout << "\t\t\t*                               *" << endl;
			cout << "\t\t\t*                               *" << endl;
			if (count>10)
				cout << "\t\t\t*    �޸ĳɹ����������Ϊ" << num << "     *" << endl;
			else
				cout << "\t\t\t*    �޸ĳɹ����������Ϊ0" << num << "     *" << endl;
			cout << "\t\t\t*                               *" << endl;
			cout << "\t\t\t*                               *" << endl;
			cout << "\t\t\t*                               *" << endl;
			cout << "\t\t\t*                               *" << endl;
			cout << "\t\t\t*      �Ƿ�����޸�(y/n)        *" << endl;
			cout << "\t\t\t*                               *" << endl;
			cout << "\t\t\t*                               *" << endl;
			cout << "\t\t\t*                               *" << endl;
			cout << "\t\t\t*********************************" << endl;
			SYSTEMTIME sy;
			GetLocalTime(&sy);
			cout << "\t\t\t  " << sy.wYear << "��" << sy.wMonth << "��" << sy.wDay << "��" << endl;
			cout << "\t\t\t  " << sy.wHour << ":" << sy.wMinute << ":" << sy.wSecond << endl;
		}
		else
		{
			cout << endl << endl << endl << endl;
			cout << "\t\t\t*********************************" << endl;
			cout << "\t\t\t*                               *" << endl;
			cout << "\t\t\t*                               *" << endl;
			cout << "\t\t\t*                               *" << endl;
			cout << "\t\t\t*                               *" << endl;
			cout << "\t\t\t*                               *" << endl;
			cout << "\t\t\t*                               *" << endl;
			cout << "\t\t\t*                               *" << endl;
			cout << "\t\t\t*      �۸�һ��,�޸�ʧ�ܣ�    *" << endl;
			cout << "\t\t\t*                               *" << endl;
			cout << "\t\t\t*                               *" << endl;
			cout << "\t\t\t*                               *" << endl;
			cout << "\t\t\t*                               *" << endl;
			cout << "\t\t\t*                               *" << endl;
			cout << "\t\t\t*                               *" << endl;
			cout << "\t\t\t*                               *" << endl;
			cout << "\t\t\t*                               *" << endl;
			cout << "\t\t\t*********************************" << endl;
			SYSTEMTIME sy;
			GetLocalTime(&sy);
			cout << "\t\t\t  " << sy.wYear << "��" << sy.wMonth << "��" << sy.wDay << "��" << endl;
			cout << "\t\t\t  " << sy.wHour << ":" << sy.wMinute << ":" << sy.wSecond;
			Sleep(1000);
			goto loop1;
		}
		char c;
		c = _getch();
		if (c == 'y' || c == 'Y') Modify2();
		Print();
		delete[]s;
	}
}
