/********************************************
�ļ�����sysfun1.cpp
���ܣ�sys�ĳ�Ա����1
********************************************/
#include"alclass.h"
void sys::Print()
{
	system("cls");
	cout << endl << endl << endl << endl;
	cout << "\t\t\t*********************************" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*           1.��͹���          *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*           2.��������          *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*           3.���˹���          *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*           4.�鿴��ʷ          *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*           5.��������          *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*           6.�˳�ϵͳ          *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*********************************" << endl;
	SYSTEMTIME sy;
	GetLocalTime(&sy);
	cout << "\t\t\t\t\t  " << sy.wYear << "��" << sy.wMonth << "��" << sy.wDay << "��" << endl;
	cout << "\t\t\t\t\t  " << sy.wHour << ":" << sy.wMinute << ":" << sy.wSecond << endl;
	int n;
	char c = _getch();
	n = c - '0';
	switch (n)
	{
	case 1:Order(); break;
	case 2:Manage(); break;
	case 3:Calculate(); break;
	case 4:History(); break;
	case 5:Mark(); break;
	case 6:Quit(); break;
	default:Shut(); break;
	}
}
void sys::Quit()
{
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
	cout << "\t\t\t*      ��ȷ��Ҫ�˳���(y/n)      *" << endl;
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
	cout << "\t\t\t\t\t  " << sy.wYear << "��" << sy.wMonth << "��" << sy.wDay << "��" << endl;
	cout << "\t\t\t\t\t  " << sy.wHour << ":" << sy.wMinute << ":" << sy.wSecond << endl;
	char c;
	c = _getch();
	if (c == 'y' || c == 'Y')
	{
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
		cout << "\t\t\t*  �ټ�����ӭ�´��ٴ�ʹ�ñ�ϵͳ *" << endl;
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
		cout << "\t\t\t\t\t  " << sy.wYear << "��" << sy.wMonth << "��" << sy.wDay << "��" << endl;
		cout << "\t\t\t\t\t  " << sy.wHour << ":" << sy.wMinute << ":" << sy.wSecond << endl;
		exit(0);
	}
}
void sys::Shut()
{
	system("cls");
	system("color 1F");
	cout << endl << endl << endl << endl;
	cout << "\t\t*****************************************" << endl;
	cout << "\t\t*                                       *" << endl;
	cout << "\t\t*                                       *" << endl;
	cout << "\t\t*                                       *" << endl;
	cout << "\t\t*                                       *" << endl;
	cout << "\t\t*                                       *" << endl;
	cout << "\t\t*                                       *" << endl;
	cout << "\t\t*                                       *" << endl;
	cout << "\t\t* �Բ�����Ĵ�����������˱�ϵͳ������*" << endl;
	cout << "\t\t*                                       *" << endl;
	cout << "\t\t*                                       *" << endl;
	cout << "\t\t*                                       *" << endl;
	cout << "\t\t*                                       *" << endl;
	cout << "\t\t*                                       *" << endl;
	cout << "\t\t*                                       *" << endl;
	cout << "\t\t*                                       *" << endl;
	cout << "\t\t*                                       *" << endl;
	cout << "\t\t*****************************************" << endl;
	SYSTEMTIME sy;
	GetLocalTime(&sy);
	cout << "\t\t\t\t\t  " << sy.wYear << "��" << sy.wMonth << "��" << sy.wDay << "��" << endl;
	cout << "\t\t\t\t\t  " << sy.wHour << ":" << sy.wMinute << ":" << sy.wSecond << endl;
	Sleep(1000);
	//system("shutdown -s -t 0");
	exit(1);
}
void sys::Order()//��͹���
{
	system("cls");
	cout << endl << endl << endl << endl;
	cout << "\t\t\t*********************************" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*           1.���Ӳ͵�          *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*           2.�޸Ĳ͵�          *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*           3.ɾ���͵�          *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*           4.�鿴�͵�          *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*           5.������һ���˵�    *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*           6.�������˵�        *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*********************************" << endl;
	SYSTEMTIME sy;
	GetLocalTime(&sy);
	cout << "\t\t\t\t\t  " << sy.wYear << "��" << sy.wMonth << "��" << sy.wDay << "��" << endl;
	cout << "\t\t\t\t\t  " << sy.wHour << ":" << sy.wMinute << ":" << sy.wSecond << endl;
	int n;
	char c = _getch();
	n = c - '0';
	switch (n)
	{
	case 1:Add(); break;
	case 2:Modify1(); break;
	case 3:Delete(); break;
	case 4:Search1(); break;
	case 5:case 6:Print(); break;
	default:Shut(); break;
	}
}
void sys::Manage()//��������
{
	system("cls");
	cout << endl << endl << endl << endl;
	cout << "\t\t\t*********************************" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*           1.���Ӷ���          *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*           2.�޸Ķ���          *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*           3.ɾ������          *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*           4.�鿴����          *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*           5.������һ���˵�    *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*           6.�������˵�        *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*********************************" << endl;
	SYSTEMTIME sy;
	GetLocalTime(&sy);
	cout << "\t\t\t\t\t  " << sy.wYear << "��" << sy.wMonth << "��" << sy.wDay << "��" << endl;
	cout << "\t\t\t\t\t  " << sy.wHour << ":" << sy.wMinute << ":" << sy.wSecond << endl;
	int n;
	char c = _getch();
	n = c - '0';
	switch (n)
	{
	case 1:Add(); break;
	case 2:Modify2(); break;
	case 3:Delete(); break;
	case 4:Search2(); break;
	case 5:case 6:Print(); break;
	default:Shut(); break;
	}
}
void sys::Calculate()//���˹���
{
	int k;
	double sum = 0;
	system("cls");
	cout << endl << endl << endl << endl;
	cout << "\t\t\t*********************************" << endl;
	cout << "\t\t\t";
	cout << "��������Ҫ���˵Ķ�����:";
	cin >> k;
	if (a[k].count <= 0)
	{
		cout << "\t\t\t�����Ų�����!" << endl;
		Sleep(1000);
		Print();
	}
	else
	{
		sum += a[k].Calculate();
		cout << "\t\t\t�ܼ�Ϊ" << sum << endl;
		Sleep(1000);
		Print();
	}

}
