#include <iostream>
using namespace std;
#include "status.h"
#include "Node.h"
#include "LinkQueue.h"
#include "TreeNode.h"
#include "Tree.h"

template <class Elemtype>
void Display(const Elemtype e)
{
	cout << e << " ";
}

void main(void)
{
	Tree<char> tree;
	cout << "�����������ȸ����У�#��ʾ��ָ�루ABE#FK#L###CG##DH#IM#N##J####����" << endl;
	TreeNode<char> *r;
	tree.CreateTree(r);//���룺ABE#FK#L###CG##DH#IM#N##J####
	tree.changeroot(r);
	cout << "�����ȸ�����Ϊ��";
	tree.PreOrder(Display);
	cout << endl;
	cout << "���ĺ������Ϊ��";
	tree.PostOrder(Display);
	cout << endl;
	cout << "���Ĳ������Ϊ��";
	tree.LevelOrder(Display);
	cout << endl;
	//---------------------���²��Ե�10�⺯��--------------------------------------------
	//cout << "�������Ϊ��" << tree.Height() << endl;//--------���õ�10�⺯��
	//---------------------���²��Ե�15�⺯��----------------------------------------------------------------
	//cout << "���Ķ�Ϊ��" << tree.Degree() << endl;//----------���õ�15�⺯��

	system("pause");
}