#include <iostream>
using namespace std;
#include "status.h"
#include "SeqStack.h"
#include "Queue.h"

void main(void)
{
	Queue<int> queue;
	int data;


	cout << "������5��������11 12 13 14 15����";
	for (int i = 1; i <= 5; i++)
	{
		cin >> data;
		if (queue.EnQueue(data) == OVER_FLOW)
			cout << "����������" << endl;
	}
	cout << "��������������";
	for (int i = 1; i <= 2; i++)
	{
		if (queue.DeQueue(data) != UNDER_FLOW)
			cout << data << "  ";
		else
			cout << endl << "����Ϊ�գ�" << endl;
	}
	cout << endl;
	cout << "������4��������21 22 23 24����";
	for (int i = 1; i <= 4; i++)
	{
		cin >> data;
		if (queue.EnQueue(data) == OVER_FLOW)
			cout << "����������" << endl;
	}
	cout << "ȫ���������ӣ�";
	while (!queue.IsEmpty())
	{
		queue.DeQueue(data);
		cout << data << "  ";
	}
	cout << endl;

	system("pause");
}