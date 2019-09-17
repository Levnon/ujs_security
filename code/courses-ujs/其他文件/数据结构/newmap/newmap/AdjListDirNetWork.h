#pragma once
#ifndef DIRNETWORK_ADJ_HEADER
#define DIRNETWORK_ADJ_HEADER
#include "AdjListNetworkVex.h"
template<class ElemType, class WeightType>
class AdjListDirNetwork
{
protected:
	int vexNum, vexMaxNum, arcNum;
	AdjListNetWorkVex<ElemType, WeightType> *vexTable;
	mutable Status *tag;
	WeightType infinity;

public:
	AdjListDirNetwork(ElemType es[], int vertexNum, int vertexMaxNum = DEFAULT_SIZE, WeightType infinit = (WeightType)DEFAULT_INFINITY);
	AdjListDirNetwork(int vertexMaxNum = DEFAULT_SIZE, WeightType infincit = (WeightType)DEFAULT_INFINITY);
	~AdjListDirNetwork()
	{
		delete[]tag;
		delete[]vexTable;
	}
	void Clear();
	bool IsEmpty();
	int GetOrder(ElemType &d)const
	{
		for (int i = 0; i < vexNum;i++)
		{
			if (vexTable[i].data==d)
			{
				return i;
			}
		}
	}
	Status GetElem(int v, ElemType &e)const
	{
		e = vexTable[v].data;
		return SUCCESS;
	}
	Status SetElem(int v, const ElemType &d);
	WeightType GetInfinity()const{return infinity;}
	int GetVexNum()const{ return vexNum; }
	int GetArcNum()const;
	int FirstAdjVex(int v)const;
	int NextAdjVex(int v1, int v2)const;
	void InsertVex(const ElemType &d);
	void InsertArc(int v1, int v2, WeightType w);
	void DeleteVex(const ElemType &d);
	void DeleteArc(int v1, int v2);
	WeightType GetWeight(int v1, int v2)const
	{
		if (v1 < 0 || v1 >= vexNum)
			throw ("v1���Ϸ�!");
		if (v2 < 0 || v2 >= vexNum)
			throw ("v2���Ϸ�!");
		if (v1 == v2)
			return infinity;
		AdjListNetWorkArc<WeightType> *p = vexTable[v1].firstarc;
		while (p)
		{
			if (p->adjVex==v2)
			{
				break;
			}
			p = p->nextarc;
		}
		if (p==NULL)
		{
			return infinity;
		}
		else
		{
			return p->weight;
		}

	}
	void SetWeight(int v1, int v2, WeightType w)
	{
		if (v1 < 0 || v1 >= vexNum)
			throw ("v1���Ϸ�!");
		if (v2 < 0 || v2 >= vexNum)
			throw ("v2���Ϸ�!");
		if (v1 == v2)
			throw ("v1���ܵ���v2!");
		if (w == infinity)
			throw ("w����Ϊ�����!");
		AdjListNetWorkArc<WeightType> *p = vexTable[v1].firstarc;
		while (p)
		{
			if (p->adjVex == v2)
			{
				break;
			}
			p = p->nextarc;
		}
		if (p == NULL)
		{
			throw("������v1��v2�Ļ���");
		}
		else
		{
			p->weight = w;
		}
		//(vexTable[v1].firstarc + v2)->weight = w;

	}
	Status GetTag(int v)const{ return tag[v]; }
	void SetTag(int v, Status Tag)
	{
		tag[v] = Tag;
	}
	AdjListDirNetwork(const AdjListDirNetwork<ElemType, WeightType>&copy);
	AdjListDirNetwork<ElemType, WeightType>&operator=(const AdjListDirNetwork<ElemType, WeightType>&copy);
	void Display();
};
template<class ElemType, class WeightType>
AdjListDirNetwork<ElemType, WeightType>::AdjListDirNetwork(ElemType es[], int vertexNum, int vertexMaxNum, WeightType infinit)
{
	if (vertexMaxNum < 0)
		throw ("����Ķ��������Ŀ����Ϊ��!");
	if (vertexMaxNum < vertexNum)
		throw ("������Ŀ���ܴ�������Ķ��������Ŀ!");
	vexNum = vertexNum;
	vexMaxNum = vertexMaxNum;
	arcNum = 0;
	infinity = infinit;
	tag = new Status[vexMaxNum];
	vexTable = new AdjListNetworkVex<ElemType,
		WeightType>[vexMaxNum];
	for (int v = 0; v < vexNum; v++) {
		tag[v] = UNVISITED;
		vexTable[v].data = es[v];
		vexTable[v].firstarc = NULL;
	}
}

template<class ElemType, class WeightType>
AdjListDirNetwork<ElemType, WeightType>::AdjListDirNetwork(int vertexMaxNum, WeightType infinit)
{
	if (vertexMaxNum < 0)
		throw ("�������󶥵���Ŀ����Ϊ����");
	vexNum = 0;
	vexMaxNum = vertexMaxNum;
	arcNum = 0;
	infinity = infinit;
	tag = new Status[vexMaxNum];
	vexTable = new AdjListNetWorkVex<ElemType, WeightType>[vexMaxNum];

}
template <class ElemType, class WeightType>
int AdjListDirNetwork<ElemType, WeightType>::FirstAdjVex(int v) const
{
	if (v < 0 || v >= vexNum)
		throw out_of_range("v���Ϸ�!"); // �׳��쳣
	if (vexTable[v].firstarc == NULL)
		return -1;              // �������ڽӵ�
	else
		return vexTable[v].firstarc->adjVex;
}
template <class ElemType, class WeightType>
int AdjListDirNetwork<ElemType, WeightType>::NextAdjVex(int v1, int v2) const
{
	AdjListNetWorkArc<WeightType> *p;
	if (v1 < 0 || v1 >= vexNum)   throw ("v1���Ϸ�!");
	if (v2 < 0 || v2 >= vexNum)   throw ("v2���Ϸ�!");
	if (v1 == v2)     throw ("v1���ܵ���v2!");
	p = vexTable[v1].firstarc;
	while (p != NULL && p->adjVex != v2)
		p = p->nextarc;
	if (p == NULL || p->nextarc == NULL)  return -1;
	else	return p->nextarc->adjVex;
}
template <class ElemType, class WeightType>
void AdjListDirNetwork<ElemType, WeightType>::InsertVex(const ElemType &d)
{
	if (vexNum == vexMaxNum)
	{
		throw ("ͼ�Ķ��������ܳ�������������!");
		
	}
	vexTable[vexNum].data = d;
	vexTable[vexNum].firstarc = NULL;
	tag[vexNum] = UNVISITED;
	vexNum++;
}
template <class ElemType, class WeightType>
void AdjListDirNetwork<ElemType, WeightType>::InsertArc(int v1, int v2, WeightType w)
{
	if (v1 < 0 || v1 >= vexNum)  
	throw ("v1���Ϸ�!");
	if (v2 < 0 || v2 >= vexNum) 
	throw ("v2���Ϸ�!");
	if (v1 == v2) 
	throw ("v1���ܵ���v2!"); 
	if (w == infinity) 
	throw ("w����Ϊ�����!"); 
	AdjListNetWorkArc<WeightType> *p;
	p = vexTable[v1].firstarc;
	vexTable[v1].firstarc =
		new  AdjListNetWorkArc<WeightType>(v2, w, p);
	arcNum++;
}
template <class ElemType, class WeightType>
void AdjListDirNetwork<ElemType, WeightType>::DeleteArc(int v1, int v2)
{
	if (v1 < 0 || v1 >= vexNum)  throw out_of_range("v1���Ϸ�!");
	if (v2 < 0 || v2 >= vexNum)  throw out_of_range("v2���Ϸ�!");
	if (v1 == v2) throw out_of_range("v1���ܵ���v2!");
	AdjListNetworkArc<WeightType> *p, *q;
	p = vexTable[v1].firstarc;
	while (p != NULL && p->adjVex != v2) {
		q = p;    p = p->nextarc;
	}

	if (p != NULL) {
		if (vexTable[v1].firstarc == p)
			vexTable[v1].firstarc = p->nextarc;
		else
			q->nextarc = p->nextarc;
		delete p;
		arcNum--;
	}
}
template <class ElemType, class WeightType>
void AdjListDirNetwork<ElemType, WeightType>::DeleteVex(const ElemType &d)
{
	int v;//��¼��ɾ����d�����
	AdjListNetworkArc<WeightType> *p, *q;
	for (v = 0; v < vexNum; v++)
	if (vexTable[v].data == d)    break;
	if (v == vexNum) throw out_of_range("ͼ�в�����Ҫɾ���Ķ���!");
	for (int u = 0; u < vexNum; u++) //ɾ���Զ���dΪ��ͷ�Ļ�
	if (u != v)     DeleteArc(u, v);
	p = vexTable[v].firstarc; //ɾ���Զ���dΪ��β�Ļ�
	while (p != NULL) {
		vexTable[v].firstarc = p->nextarc; delete p;
		p = vexTable[v].firstarc;  arcNum--;
	}
	vexNum--;
	vexTable[v].data = vexTable[vexNum].data;
	vexTable[v].firstarc = vexTable[vexNum].firstarc;
	vexTable[vexNum].firstarc = NULL;
	tag[v] = tag[vexNum];
	for (int u = 0; u < vexNum; u++)
	if (u != v) {
		p = vexTable[u].firstarc;
		while (p != NULL) {
			if (p->adjVex == vexNum) p->adjVex = v;
			p = p->nextarc;
		}
	}
}























#endif // !DIRNETWORK_ADJ_HEADER
