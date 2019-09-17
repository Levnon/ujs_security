#pragma once
#ifndef TNODE_HEADER
#define TNODE_HEADER
#include "Status.h"
using namespace std;
struct TreeNode
{
public:
	DATA data;//������
	TreeNode *FirstChild;//����ָ��
	TreeNode *NextSibling;//�ֵ�ָ��
	TreeNode();//�޲ι��캯��
	TreeNode(DATA d,TreeNode*child=NULL,TreeNode*sibling=NULL);//�вι��캯��
	//��������
	Status GetName(string &name)const;
};
TreeNode::TreeNode():data()
{
	FirstChild = NULL;
	NextSibling = NULL;
}
TreeNode::TreeNode(DATA d, TreeNode*child/* =NULL */, TreeNode*sibling/* =NULL */) : data(d)//����������ṹ��Ĺ��캯��
{
	FirstChild = child;
	NextSibling = sibling;
	/*
	����ָ�븳ֵ
	*/
}
Status TreeNode::GetName(string &name)const
{
	name = data.MemName;
	return SUCCESS;
}


#endif
