// map.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
using namespace std;
#include <exception>
#include <fstream>
#include "status.h"
#include "AdjListNetworkArc.h"
#include "AdjListNetworkVex.h"
#include "AdjListDirNetwork.h"
#include "AdjMatrixUndirGraph.h"
#include "Node.h"
#include "LinkQueue.h"

template <class ElemType>
void DFS(const AdjMatrixUndirGraph<ElemType> &g,int v,void (*Visit)(const ElemType &))  
{	
    ElemType e;	
    g.SetTag(v, VISITED); //���ö���v �ѷ��ʱ��
    g.GetElem(v, e);	//ȡ����v������Ԫ��
    Visit(e);//���ʶ���v
    for (int w=g.FirstAdjVex(v); w != -1;w=g.NextAdjVex(v, w))
        if (g.GetTag(w) == UNVISITED)
            DFS(g, w, Visit);//��v���ڽӵ�w��ʼ�����������
}
template <class ElemType>
void DFSTraverse(const AdjMatrixUndirGraph<ElemType> &g, void (*Visit)(const ElemType &))  
{
	int v;
	for (v=0; v < g.GetVexNum(); v++)//����δ���ʱ�־
		g.SetTag(v, UNVISITED);
          //����ж϶��㣬��δ���ʶ��㿪ʼ�����������
	for (v=0; v < g.GetVexNum(); v++)
 		if (g.GetTag(v) == UNVISITED)
			DFS(g, v, Visit);
}
template <class ElemType>
void BFS(const AdjMatrixUndirGraph<ElemType> &g, int v, void (*Visit)(const ElemType &))
{	
    LinkQueue<int> q;
    int u, w;
    ElemType e;    
    g.SetTag(v, VISITED); //���÷��ʱ�־  
    g.GetElem(v, e);//ȡ����v������Ԫ��ֵ
    Visit(e);//���ʶ���v
    q.EnQueue(v);//����v���
	while (!q.IsEmpty())  {	
        q.DelQueue(u);//��ͷ����u����
        //����ж�u���ڽӵ㣬��δ���������֮�����
        for (w=g.FirstAdjVex(u); w != -1; w=g.NextAdjVex(u, w))
            if (g.GetTag(w) == UNVISITED){ 
                g.SetTag(w, VISITED); 
                g.GetElem(w, e);	
	     Visit(e);  
                q.EnQueue(w);
            }	
     }
}
template <class ElemType>
void BFSTraverse(const AdjMatrixUndirGraph<ElemType> &g,  void (*Visit)(const ElemType &)) {
	int v;
	for (v=0; v < g.GetVexNum(); v++)//����δ���ʱ�־
	     g.SetTag(v, UNVISITED);
           //����ж϶��㣬��δ���ʶ��㿪ʼ�����������
	for (v=0; v < g.GetVexNum(); v++)
		if (g.GetTag(v) == UNVISITED) 
			BFS(g, v, Visit);
}






//�Ӷ���v��ʼ���������������
template <class ElemType, class WeightType>
void DFS(AdjListDirNetwork<ElemType, WeightType> &graph, int v, void(*Visit)(const ElemType &))
{
	ElemType e;
	graph.SetTag(v, VISITED); //���ö���v �ѷ��ʱ��
	graph.GetElem(v, e);	//ȡ����v������Ԫ��
	Visit(e);//���ʶ���v
	for (int w = graph.FirstAdjVex(v); w != -1; w = graph.NextAdjVex(v, w))
	if (graph.GetTag(w) == UNVISITED)
		DFS(graph, w, Visit);//��v���ڽӵ�w��ʼ�����������
}

//��ͼgraph����������ȱ���
template <class ElemType, class WeightType>
void DFSTraverse(AdjListDirNetwork<ElemType, WeightType> &graph, void(*Visit)(const ElemType &))
{
	int v;
	for (v = 0; v < graph.GetVexNum(); v++)//����δ���ʱ�־
		graph.SetTag(v, UNVISITED);
	//����ж϶��㣬��δ���ʶ��㿪ʼ�����������
	for (v = 0; v < graph.GetVexNum(); v++)
	if (graph.GetTag(v) == UNVISITED)
		DFS(graph, v, Visit);
}

//�Ӷ���v��ʼ�����������
template <class ElemType, class WeightType>
void BFS(AdjListDirNetwork<ElemType, WeightType> &graph, int v, void(*Visit)(const ElemType &))
{
	LinkQueue<int> q;
	int u, w;
	ElemType e;
	graph.SetTag(v, VISITED); //���÷��ʱ�־  
	graph.GetElem(v, e);//ȡ����v������Ԫ��ֵ
	Visit(e);//���ʶ���v
	q.EnQueue(v);//����v���
	while (!q.IsEmpty())
	{
		q.DelQueue(u);//��ͷ����u����
		//����ж�u���ڽӵ㣬��δ���������֮�����
		for (w = graph.FirstAdjVex(u); w != -1; w = graph.NextAdjVex(u, w))
		if (graph.GetTag(w) == UNVISITED)
		{
			graph.SetTag(w, VISITED);
			graph.GetElem(w, e);
			Visit(e);
			q.EnQueue(w);
		}
	}
}

//��ͼgraph���й�����ȱ���
template <class ElemType, class WeightType>
void BFSTraverse(AdjListDirNetwork<ElemType, WeightType> &graph, void(*Visit)(const ElemType &))
{
	int v;
	for (v = 0; v < graph.GetVexNum(); v++)//����δ���ʱ�־
		graph.SetTag(v, UNVISITED);
	//����ж϶��㣬��δ���ʶ��㿪ʼ�����������
	for (v = 0; v < graph.GetVexNum(); v++)
	if (graph.GetTag(v) == UNVISITED)
		BFS(graph, v, Visit);
}

void Display(const char &e)
{
	cout << e << " ";
}
bool LoadData(AdjListDirNetwork<char, int> &g)
{
	ifstream in("GraphData.txt",ios::in);
	if (!in) return false;
	int a,b;
	in>>a>>b;
	char c[15];
	for (int i=0;i<a;i++)
	{ 
		in>>c[i];
		g.InsertVex(c[i]);
	}
	int e1[35],e2[35],we[35];
	int j=0;
	while(!in.eof())
	{
		in>>e1[j]>>e2[j]>>we[j];
		g.InsertArc(e1[j],e2[j],we[j]);
		j++;
	}

	in.close();
	return true;
}
void main(void)
{
	AdjListDirNetwork<char, int> graph(20, 9999);
	char start, end;

	//���ļ�GraphData.txt�ж�ȡ����ͼ���ݣ�����ͼgraph
	if (!LoadData(graph))//--------------------����LoadData�������ļ�GraphData.txt��ȡ����ͼ���ݽ���ͼgraph�����Լ�ʵ��
	{
		cout << "ͼ����ʧ�ܣ�" << endl;
		exit(1);
	}
	cout << "ͼ��������ȱ�������Ϊ��";
	DFSTraverse(graph, Display);
	cout << endl;
	cout << "ͼ�Ĺ�����ȱ�������Ϊ��";
	BFSTraverse(graph, Display);
	cout << endl;
/*	//-----------------------------���²��Ե�1��------------------------------------------------
	cout << "������·����������ƣ�A����";
	cin >> start;//���룺A
	cout << "������·�����յ����ƣ�G����";
	cin >> end;//���룺G
	if (ExistPathDFS(graph, start, end))//------------------���õ�1�⺯��--------------------------
		cout << "��������������������жϣ�" << start << "��" << end << "����·��!" << endl;
	else
		cout << "��������������������жϣ�" << start << "��" << end << "������·��!" << endl;
	//-----------------------------���²��Ե�2��------------------------------------------------
	cout << "������·����������ƣ�A����";
	cin >> start;//���룺A
	cout << "������·�����յ����ƣ�H����";
	cin >> end;//���룺H
	if (ExistPathBFS(graph, start, end))//------------------���õ�2�⺯��--------------------------
		cout << "���չ���������������жϣ�" << start << "��" << end << "����·��!" << endl;
	else
		cout << "���չ���������������жϣ�" << start << "��" << end << "������·��!" << endl;
	//-----------------------------���²��Ե�3��------------------------------------------------
	cout << "������������·����������ƣ�A����";
	cin >> start;//���룺A
	int *path = new int[graph.GetVexNum()], *dist = new int[graph.GetVexNum()];
	ShortestPathDij(graph, graph.GetOrder(start), path, dist);//------------------���õ�3�⺯��--------------------------
	//�����㵽���ж�������·�������·������
	OutputShortestPathDij(graph, graph.GetOrder(start), path, dist);//-------------------����OutputShortestPathDij���������������Լ�ʵ��
	delete[]path;
	delete[]dist;
*/
	system("pause");
}
