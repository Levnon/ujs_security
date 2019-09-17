#pragma once
#ifndef TREE_TOTAL_HEADER
#define TREE_TOTAL_HEADER
#include "BinTreeNode.h"
#include "LinkQueue.h"
#define max(a,b) a>b?a:b
template<class ElemType>
class BinaryTree
{
protected:
	//���ݳ�Ա
	BinTreeNode<ElemType> *root;
	//��������:
	BinTreeNode<ElemType> *CopyTree(BinTreeNode<ElemType> *t);//���ƶ�����
	void Destroy(BinTreeNode<ElemType> *&r);//ɾ����rΪ���Ķ�����
	void PreOrder(BinTreeNode<ElemType> *r, void(*Visit)(const ElemType&))const;//���������rΪ���Ķ�����
	void InOrder(BinTreeNode<ElemType> *r, void(*Visit)(const ElemType&))const;//���������rΪ���Ķ�����
	void PostOrder(BinTreeNode<ElemType> *r, void(*Visit)(const ElemType&))const;//���������rΪ���Ķ�����
	int Height(const BinTreeNode<ElemType> *r)const;//�������߶�
	int NodeCount(const BinTreeNode<ElemType> *r)const;//������������
	BinTreeNode<ElemType> *Parent(BinTreeNode<ElemType> *r, const BinTreeNode<ElemType>*p)const;//��rΪ���Ķ���������p��˫��
	//********************************


	

public:
	BinaryTree();//�޲ι��캯��
	BinaryTree(const ElemType &e);//�вι��캯��
	virtual ~BinaryTree();//��������
	BinTreeNode<ElemType> *GetRoot()const;//��������ĸ�
	bool IsEmpty()const;//�ж϶������Ƿ�Ϊ��
	Status GetElem(BinTreeNode<ElemType>*p, ElemType &e)const;
	Status SetElem(BinTreeNode<ElemType>*p, const ElemType &e);
	void InOrder(void(*Visit)(const ElemType &))const;//�������
	void PreOrder(void(*Visit)(const ElemType &))const;//�������
	void PostOrder(void(*Visit)(const ElemType &))const;//�������
	void LevelOrder(void(*Visit)(const ElemType &))const;//�������
	int NodeCount()const;//�������
	BinTreeNode<ElemType> *LeftChild(const BinTreeNode<ElemType> *p)const;//��������
	BinTreeNode<ElemType> *RightChild(const BinTreeNode<ElemType> *p)const;//�����Һ���
	BinTreeNode<ElemType> *LeftSibling(const BinTreeNode<ElemType> *p)const;//�������ֵ�
	BinTreeNode<ElemType> *RightSibling(const BinTreeNode<ElemType> *p)const;//�������ֵ�
	BinTreeNode<ElemType> *Parent(const BinTreeNode<ElemType>*p)const;//����˫��
	void InsertLeftChild(BinTreeNode<ElemType>*p, const ElemType &e);//��������
	void InsertRightChild(BinTreeNode<ElemType>*p, const ElemType &e);//�����Һ���
	void DeleteLeftChild(BinTreeNode<ElemType>*p);//ɾ��������
	void DeleteRightChild(BinTreeNode<ElemType>*p);//ɾ��������
	int Height()const;//��������ĸ�
	BinaryTree(const BinaryTree<ElemType>&t);//�������캯��
	BinaryTree(BinTreeNode<ElemType> *r);//������rΪ���Ķ�����
	BinaryTree<ElemType>&operator=(const BinaryTree<ElemType> &t);//��ֵ���������
	//�ñ������������������
	void CreateBtrPre(BinTreeNode<ElemType>*&r);
	//void CreateBtrIn(BinTreeNode<ElemType>*&r);
	//void CreateBtrPost(BinTreeNode<ElemType>*&r);
	//void CreateBinaryTreePreIn

	void changeroot(BinTreeNode<ElemType> *r) { root = r; }



	//�ھ���
	int Width()const
	{
		LinkQueue<BinTreeNode<ElemType> *>q;
		BinTreeNode<ElemType> *p;
		int s[100] = { 0 };
		int i = 0, j = 0;
		if (root)
		{
			q.EnQueue(root);
		}
		while (!q.IsEmpty())
		{
			q.DelQueue(p);
			
			s[i++] = Height()-Height(p)+1;//��ÿ���������
			if (p->leftChild)
			{
				q.EnQueue(p->leftChild);
			}
			if (p->rightChild)
			{
				q.EnQueue(p->rightChild);
			}
		}
		//���һ���Ľ����ͬһ�㣬�ȶ������������Ȼ���ҳ����һ���ĵ�ĸ��������ֵ
		for (i = 0; i < 100;i++)
		{
			if (s[i]==0)
			{
				break;
			}
		}
		int n = i;//�����е���Чֵ����
		//�Ƚ�����
		for (i = 0; i < n;i++)
			for (j = i+1; j < n;j++)
				if (s[i]>s[j])
				{
					int swap = s[i];
					s[i] = s[j];
					s[j] = swap;
				}
		//��������������ֵͬ�ĸ��������ֵ
		int summax = 0;
		int c = 0;
		for (i = 0; i < n; i++)
		{
			c = 0;
			for (j = i + 1; j < n; j++)
				if (s[i]==s[j])
				{
					c++;
					if (c>summax)
					{
						summax = c;
					}
				} 
				else
				{
					break;
				}
		}
			
		return summax;

	}
	//��ʮ����
	int CountLeaf(BinTreeNode<ElemType> *r)const
	{
		if (!r)
		{
			return 0;
		} 
		else if (r->leftChild==NULL&&r->rightChild==NULL)
		{
			return 1;
		}
		else
		{
			return CountLeaf(r->leftChild) + CountLeaf(r->rightChild);
		}
	}

};

template<class ElemType>
BinTreeNode<ElemType>* BinaryTree<ElemType>::CopyTree(BinTreeNode<ElemType> *t)
{
	BinaryTree<ElemType>*r=new BinaryTree<ElemType>(t->data);
	return r;
}
template<class ElemType>
void BinaryTree<ElemType>::Destroy(BinTreeNode<ElemType> *&r)
{
	if (r)
	{
		Destroy(r->leftChild);
		Destroy(r->rightChild);
		delete r;
		r = NULL;
	}
}
template<class ElemType>
void BinaryTree<ElemType>::PreOrder(BinTreeNode<ElemType> *r, void(*Visit)(const ElemType&))const
{
	if (r)
	{
		(*Visit)(r->data);
		PreOrder(r->leftChild,Visit);
		PreOrder(r->rightChild,Visit);
	}
}
template<class ElemType>
void BinaryTree<ElemType>::InOrder(BinTreeNode<ElemType> *r, void(*Visit)(const ElemType&))const
{
	if (r)
	{
		InOrder(r->leftChild,Visit);
		(*Visit)(r->data);
		InOrder(r->rightChild,Visit);
	}
}
template<class ElemType>
void BinaryTree<ElemType>::PostOrder(BinTreeNode<ElemType> *r, void(*Visit)(const ElemType&))const
{
	if (r)
	{
		PostOrder(r->leftChild,Visit);
		PostOrder(r->rightChild,Visit);
		(*Visit)(r->data);
	}
}
template<class ElemType>
int BinaryTree<ElemType>::Height(const BinTreeNode<ElemType> *r)const
{
	if (r)
	{
		return max(Height(r->leftChild) + 1, Height(r->rightChild) + 1);
	} 
	else
	{
		return 0;
	}
}
template<class ElemType>
int BinaryTree<ElemType>::NodeCount(const BinTreeNode<ElemType> *r)const
{
	if (r)
	{
		return NodeCount(r->leftChild) + NodeCount(r->rightChild) + 1;
	} 
	else
	{
		return 0;
	}
}
template<class ElemType>
BinTreeNode<ElemType>* BinaryTree<ElemType>::Parent(BinTreeNode<ElemType> *r, const BinTreeNode<ElemType>*p)const
{
	if (!r)
	{
		return NULL;
	} 
	else if (r->leftChild==p||r->rightChild==p)
	{
		return r;
	} 
	else
	{
		BinTreeNode<ElemType>*tmp;
		tmp = Parent(r->leftChild, p);
		if (tmp)
		{
			return tmp;
		} 
		tmp = Parent(r->rightChild, p);
		if (tmp)
		{
			return tmp;
		} 
		else
		{
			return NULL;
		}
	}
}


template<class ElemType>
BinaryTree<ElemType>::BinaryTree()
{
	root = new BinTreeNode<ElemType>();
}
template<class ElemType>
BinaryTree<ElemType>::BinaryTree(const ElemType &e)
{
	root = new BinTreeNode<ElemType>(e);
}
template<class ElemType>
BinaryTree<ElemType>::~BinaryTree()
{
}
template<class ElemType>
BinTreeNode<ElemType>* BinaryTree<ElemType>::GetRoot()const
{
	return root;
}
template<class ElemType>
bool BinaryTree<ElemType>::IsEmpty()const
{
	return root == NULL;
}
template<class ElemType>
Status BinaryTree<ElemType>::GetElem(BinTreeNode<ElemType>*p, ElemType &e)const
{
	if (p)
	{
		e = p->data;
		return SUCCESS;
	} 
	else
	{
		return NOT_PRESENT;
	}
}
template<class ElemType>
Status BinaryTree<ElemType>::SetElem(BinTreeNode<ElemType>*p, const ElemType &e)
{
	if (p)
	{
		p->data = e;
		return SUCCESS;
	} 
	else
	{
		return NOT_PRESENT;
	}
}
template<class ElemType>
void BinaryTree<ElemType>::InOrder(void(*Visit)(const ElemType &))const
{
	InOrder(root, Visit);
}
template<class ElemType>
void BinaryTree<ElemType>::PreOrder(void(*Visit)(const ElemType &))const
{
	PreOrder(root, Visit);
}
template<class ElemType>
void BinaryTree<ElemType>::PostOrder(void(*Visit)(const ElemType &))const
{
	PostOrder(root, Visit);
}
template<class ElemType>
void BinaryTree<ElemType>::LevelOrder(void(*Visit)(const ElemType &))const
{
	LinkQueue<BinTreeNode<ElemType> *>q;
	BinTreeNode<ElemType> *p;
	if (root)
	{
		q.EnQueue(root);
	}
	while (!q.IsEmpty())
	{
		q.DelQueue(p);
		(*Visit)(p->data);
		if (p->leftChild)
		{
			q.EnQueue(p->leftChild);
		}
		if (p->rightChild)
		{
			q.EnQueue(p->rightChild);
		}
	}
}
template<class ElemType>
int BinaryTree<ElemType>::NodeCount()const
{
	return NodeCount(root);
}
template<class ElemType>
BinTreeNode<ElemType>* BinaryTree<ElemType>::LeftChild(const BinTreeNode<ElemType> *p)const
{
	return p->leftChild;
}
template<class ElemType>
BinTreeNode<ElemType>* BinaryTree<ElemType>::RightChild(const BinTreeNode<ElemType> *p)const
{
	return p->rightChild;
}
template<class ElemType>
BinTreeNode<ElemType>* BinaryTree<ElemType>::LeftSibling(const BinTreeNode<ElemType> *p)const
{
	BinTreeNode<ElemType>*r = Parent(root,p);
	if (!r)
	{
		return NULL;
	}
	else if (r->rightChild==p)
	{
		return r->leftChild;
	} 
	else
	{
		return NULL;
	}
	
}
template<class ElemType>
BinTreeNode<ElemType>* BinaryTree<ElemType>::RightSibling(const BinTreeNode<ElemType> *p)const
{
	BinTreeNode<ElemType>*r = Parent(root,p);
	if (!r)
	{
		return NULL;
	}
	else if (r->leftChild == p)
	{
		return r->rightChild;
	}
	else
	{
		return NULL;
	}
}
template<class ElemType>
BinTreeNode<ElemType>* BinaryTree<ElemType>::Parent(const BinTreeNode<ElemType>*p)const
{
	return Parent(root, p);
}
template<class ElemType>
void BinaryTree<ElemType>::InsertLeftChild(BinTreeNode<ElemType>*p, const ElemType &e)
{
	if (!p)
	{
		return;
	} 
	else
	{
		BinTreeNode<ElemType> *child = new BinTreeNode<ElemType>(e);
		if (p->leftChild)
		{
			child->leftChild = p->leftChild;
		}
		p->leftChild = child;
	}
	
}
template<class ElemType>
void BinaryTree<ElemType>::InsertRightChild(BinTreeNode<ElemType>*p, const ElemType &e)
{
	if (!p)
	{
		return;
	}
	else
	{
		BinTreeNode<ElemType> *child = new BinTreeNode<ElemType>(e);
		if (p->rightChild)
		{
			child->rightChild = p->rightChild;
		}
		p->rightChild = child;
	}

}
template<class ElemType>
void BinaryTree<ElemType>::DeleteLeftChild(BinTreeNode<ElemType>*p)
{
	if (!p)
	{
		return;
	} 
	else
	{
		p->leftChild = NULL;
	}
}
template<class ElemType>
void BinaryTree<ElemType>::DeleteRightChild(BinTreeNode<ElemType>*p)
{
	if (!p)
	{
		return;
	}
	else
	{
		p->rightChild = NULL;
	}
}
template<class ElemType>
int BinaryTree<ElemType>::Height()const
{
	return Height(root);
}
template<class ElemType>
BinaryTree<ElemType>::BinaryTree(BinTreeNode<ElemType>*r)
{
	root = r;
	
}
template<class ElemType>
BinaryTree<ElemType>& BinaryTree<ElemType>::operator=(const BinaryTree<ElemType>&t)
{
	return t;
}
template<class ElemType>
void BinaryTree<ElemType>::CreateBtrPre(BinTreeNode<ElemType>*&r)
{
	ElemType ch;
	cin >> ch;
	if (ch==(ElemType)'#')
	{
		r = NULL;
	} 
	else
	{
		r = new BinTreeNode<ElemType>(ch);
		CreateBtrPre(r->leftChild);
		CreateBtrPre(r->rightChild);
	}
}
























#endif // !TREE_TOTAL_HEADER
