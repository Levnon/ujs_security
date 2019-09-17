#include <iostream>
using namespace std;
#include "status.h"
#include "SeqStack.h"

//����Ԫ�ص����
template <class ElemType>
void Display(const ElemType & e)
{
	cout << e << "  ";
}

void main(void)
{
	SeqStack<int> stack(10);
	int data;


	cout << "������5��������11 12 13 14 15����";
	for (int i = 1; i <= 5; i++)
	{
		cin >> data;
		if (stack.Push(1, data) == OVER_FLOW)
		{
			cout << "ջ������" << endl;	exit(0);
		}
	}
	cout << "������4��������21 22 23 24����";
	for (int i = 1; i <= 4; i++)
	{
		cin >> data;
		if (stack.Push(2, data) == OVER_FLOW)
		{
			cout << "ջ������" << endl;	exit(0);
		}
	}

	cout << "ջ1���� " << stack.GetLength(1) << " ��Ԫ�أ�";
	stack.Traverse(1, Display);
	cout << endl;
	cout << "ջ2���� " << stack.GetLength(2) << " ��Ԫ�أ�";
	stack.Traverse(2, Display);
	cout << endl;

	cout << "ջ1��Ԫ�����γ�ջ��";
	while (stack.GetLength(1))
	{
		stack.Pop(1, data);
		cout << data << "  ";
	}
	cout << endl;
	cout << "ջ2��Ԫ�����γ�ջ��";
	while (stack.GetLength(2))
	{
		stack.Pop(2, data);
		cout << data << "  ";
	}
	cout << endl;

	if (stack.IsEmpty())
		cout << "��ǰջΪ�գ�" << endl;

	system("pause");
}