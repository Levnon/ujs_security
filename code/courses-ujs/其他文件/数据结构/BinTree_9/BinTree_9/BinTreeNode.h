#pragma once
#ifndef NODE_HEADER_TREE
#define NODE_HEADER_TREE


#include "Status.h"
template<class ElemType>
struct BinTreeNode
{
//protected:
	//���ݳ�Ա
	ElemType data;//������
	//ָ����
	BinTreeNode<ElemType> *leftChild;//����ָ��
	BinTreeNode<ElemType> *rightChild;//�Һ���ָ��

//public:
	//������Ա

	BinTreeNode();//�޲ι��캯��
	BinTreeNode(const ElemType &d, BinTreeNode<ElemType> *lChild = NULL, BinTreeNode<ElemType> *rChild = NULL);//�вι��캯��
	virtual ~BinTreeNode();//��������

};

template<class ElemType>
BinTreeNode<ElemType>::BinTreeNode()
{
	leftChild = rightChild = NULL;
}
template<class ElemType>
BinTreeNode<ElemType>::BinTreeNode(const ElemType &d, BinTreeNode<ElemType> *lChild /* = NULL */, BinTreeNode<ElemType> *rChild /* = NULL */)
{
	data = d;
	leftChild = lChild;
	rightChild = rChild;
}
template<class ElemType>
BinTreeNode<ElemType>::~BinTreeNode()
{

}

#endif // !NODE_HEADER_TREE