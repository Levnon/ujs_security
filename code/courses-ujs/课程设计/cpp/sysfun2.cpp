/********************************************
�ļ�����sysfun2.cpp
���ܣ�sys�ĳ�Ա����2
********************************************/
#include"alclass.h"
void sys::History()//�鿴��ʷ
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
		cout << "\t\t\t*        û��������ʷ��         *" << endl;
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
	for (num = 1; num <= count; num++)
	{
		cout << "\t\t\t*********************************" << endl;
		cout << "\t\t\t����" << num << endl;
		a[num].output2();
	}
	Print();
}
void sys::Mark()//��������
{
	system("cls");
	cout << endl << endl << endl << endl;
	cout << "\t\t\t*********************************" << endl;
	cout << "\t\t\t��������Ҫ���ֵĲ���:";
	string d;
	cin >> d;
	cout << "\t\t\t���������:";
	double sco;
	cin >> sco;
	for (int i = 1; i <= count; i++)
	for (int j = 1; j <= a[i].count; j++)
	if (a[i].a[j].name== d) a[i].a[j].score = sco;
	system("cls");
	cout << endl << endl << endl << endl;
	cout << "\t\t\t*********************************" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*            ���ֳɹ���         *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*        �Ƿ��������(y/n)      *" << endl;
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
	if (c == 'y' || c == 'Y') Mark();
	Print();
}
bool sys::test()
{
	for (int i = 1; i <= count; i++)
	for (int j = 1; j <= a[i].count; j++)
	for (int k = 1; k <= count; k++)
	for (int l = 1; l <= a[k].count; l++)
	if ((a[i].a[j].name==a[k].a[l].name) && (a[i].a[j].price != a[k].a[l].price)) return false;
	return true;
}
void sys::Add()
{
	system("cls");
	if (count >= 100)
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
		cout << "\t\t\t*    �˵���������������ʧ�ܣ�   *" << endl;
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
		count++;
	loop2:a[count].input();
		system("cls");
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
				cout << "\t\t\t*    ��ӳɹ����������Ϊ" << count << "     *" << endl;
			else
				cout << "\t\t\t*    ��ӳɹ����������Ϊ0" << count << "     *" << endl;
			cout << "\t\t\t*                               *" << endl;
			cout << "\t\t\t*                               *" << endl;
			cout << "\t\t\t*                               *" << endl;
			cout << "\t\t\t*       �Ƿ��������(y/n)       *" << endl;
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
			cout << endl << endl << endl << endl;
			cout << "\t\t\t*********************************" << endl;
			cout << "\t\t\t*                               *" << endl;
			cout << "\t\t\t*                               *" << endl;
			cout << "\t\t\t*                               *" << endl;
			cout << "\t\t\t*                               *" << endl;
			cout << "\t\t\t*                               *" << endl;
			cout << "\t\t\t*                               *" << endl;
			cout << "\t\t\t*                               *" << endl;
			cout << "\t\t\t*      �۸�һ��,����ʧ�ܣ�    *" << endl;
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
			goto loop2;
		}
		char c;
		c = _getch();
		if (c == 'y' || c == 'Y') Add();
		Print();
	}
}
