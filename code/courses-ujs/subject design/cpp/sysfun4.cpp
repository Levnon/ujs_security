/********************************************
�ļ�����sysfun4.cpp
���ܣ�sys�ĳ�Ա����4
********************************************/
#include"alclass.h"
void sys::Delete()
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
		cout << "\t\t\t*      �˵�Ϊ�գ�ɾ��ʧ��!      *" << endl;
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
		cout << endl << endl << endl << endl;
		cout << "\t\t\t*********************************" << endl;
		cout << "\t\t\t��������Ҫɾ���Ĳ͵����";
		char * s = new char[20];
		cin >> s;
		num = atoi(s);
		system("cls");
		a[num].remove();
		cout << endl << endl << endl << endl;
		cout << "\t\t\t*********************************" << endl;
		cout << "\t\t\t*                               *" << endl;
		cout << "\t\t\t*                               *" << endl;
		cout << "\t\t\t*                               *" << endl;
		cout << "\t\t\t*                               *" << endl;
		cout << "\t\t\t*                               *" << endl;
		cout << "\t\t\t*                               *" << endl;
		cout << "\t\t\t*                               *" << endl;
		cout << "\t\t\t*           ɾ���ɹ�!           *" << endl;
		cout << "\t\t\t*                               *" << endl;
		cout << "\t\t\t*                               *" << endl;
		cout << "\t\t\t*        �Ƿ����ɾ��(y/n)      *" << endl;
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
		char c;
		c = _getch();
		if (c == 'y' || c == 'Y') Delete();
		Print();
	}

}
void sys::Search1()
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
		cout << "\t\t\t*      �˵�Ϊ�գ�����ʧ��!      *" << endl;
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
		cout << "\t\t\t��������Ҫ���ҵĲ͵����" << endl;
		cout << "\t\t\t";
		cin >> num;
		if (a[num].count <= 0)
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
			cout << "\t\t\t*             δ�ҵ�!           *" << endl;
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
			cout << "\t\t\t  " << sy.wHour << ":" << sy.wMinute << ":" << sy.wSecond << endl;
		}
		else
		{
			a[num].output1();
		}
		cout << "\t\t\t�Ƿ��������(y/n)";
		char c;
		c = _getch();
		if (c == 'y' || c == 'Y') Search1();
		Print();
	}
}
void sys::Search2()
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
		cout << "\t\t\t*      �˵�Ϊ�գ�����ʧ��!      *" << endl;
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
		cout << "\t\t\t��������Ҫ���ҵĶ������" << endl;
		cout << "\t\t\t";
		cin >> num;
		if (a[num].count <= 0)
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
			cout << "\t\t\t*             δ�ҵ�!           *" << endl;
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
			cout << "\t\t\t  " << sy.wHour << ":" << sy.wMinute << ":" << sy.wSecond << endl;
		}
		else
		{
			system("cls");
			a[num].output2();
		}
		cout << "\t\t\t�Ƿ��������(y/n)";
		char c;
		c = _getch();
		if (c == 'y' || c == 'Y') Search2();
		Print();
	}
}