#include <iostream>
using namespace std;
#include "status.h"
#include "Node.h"
#include "LinkQueue.h"
#include "BinTreeNode.h"
#include "BinaryTree.h"

template <class Elemtype>
void Display(const Elemtype e)
{
	cout << e << " ";
}

void main(void)
{
	BinaryTree<char> tree;
	BinTreeNode<char> *r = tree.GetRoot();
	cout << "��������������������У�#��ʾ��ָ�루ABDG#L##HM###EIN##O###C#FJ##K##����" << endl;
	tree.CreateBtrPre(r);//���룺ABDG#L##HM###EIN##O###C#FJ##K##
	tree.changeroot(r);
	cout << "����������������Ϊ��";
	tree.PreOrder(Display);
	cout << endl;
	cout << "����������������Ϊ��";
	tree.InOrder(Display);
	cout << endl;
	cout << "�������ĺ�������Ϊ��";
	tree.PostOrder(Display);
	cout << endl;
	cout << "�������Ĳ������Ϊ��";
	tree.LevelOrder(Display);
	cout << endl;
	//---------------------���²��Ե�9�⺯��--------------------------------------------
	cout << "�������������Ϊ��" << tree.Width() << endl;//--------���õ�9�⺯��
	//---------------------���²��Ե�14�⺯��----------------------------------------------------------------
	cout << "��������Ҷ�ӽڵ���ĿΪ��" << tree.CountLeaf(tree.GetRoot()) << endl;//----------���õ�14�⺯��

	system("pause");
}