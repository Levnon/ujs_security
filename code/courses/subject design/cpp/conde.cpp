/********************************************
�ļ�����conde.cpp
���ܣ����졢��������
********************************************/
#include"alclass.h"
dish::dish()
{
	num = 0;
	price = 0;
	score = 0;
	name ="";
}
dish::~dish(){}
menu::menu()
{
	for (int i = 0; i<10; i++) a[i] = dish();
	count = 0;
}
menu::~menu(){}
sys::sys()
{
	for (int i = 0; i<10; i++)
		a[i] = menu();
	count = 0;
	system("color 60");
	cout << endl << endl << endl << endl;
	cout << "\t\t\t*********************************" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*    ��ӭ����Ƶ��͹���ϵͳ   *" << endl;
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
	/*system("cls");
	cout << endl << endl << endl << endl;
	cout << "\t\t\t*********************************" << endl;
	cout << "\t\t\tĬ���û����������Ϊroot" << endl;
	cout << "\t\t\t*********************************" << endl;
	cout << "\t\t\t�û�����";
	char * s1 = new char[50];
	cin >> s1;
	cout << "\t\t\t���룺";
	char s2[50];
	int j = 0;
	do{
		s2[j] = _getch();
	if (s2[j]!=13)	
		if (s2[j]!=8) cout << "*";
		else {
			cout << "\b \b"; s2[j] = 0; j--;
		}
	else break;
		j++;
	} while (1);*/
}
sys::~sys(){}