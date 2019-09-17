#include <iostream>
#include <fstream>
#include <stdlib.h>
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
void DFS(const AdjMatrixUndirGraph<ElemType> &g, int v, void(*Visit)(const ElemType &))
{
	ElemType e;
	g.SetTag(v, VISITED); //���ö���v �ѷ��ʱ��
	g.GetElem(v, e);	//ȡ����v������Ԫ��
	Visit(e);//���ʶ���v
	for (int w = g.FirstAdjVex(v); w != -1; w = g.NextAdjVex(v, w))
	if (g.GetTag(w) == UNVISITED)
		DFS(g, w, Visit);//��v���ڽӵ�w��ʼ�����������
}
template <class ElemType>
void DFSTraverse(const AdjMatrixUndirGraph<ElemType> &g, void(*Visit)(const ElemType &))
{
	int v;
	for (v = 0; v < g.GetVexNum(); v++)//����δ���ʱ�־
		g.SetTag(v, UNVISITED);
	//����ж϶��㣬��δ���ʶ��㿪ʼ�����������
	for (v = 0; v < g.GetVexNum(); v++)
	if (g.GetTag(v) == UNVISITED)
		DFS(g, v, Visit);
}
template <class ElemType>
void BFS(const AdjMatrixUndirGraph<ElemType> &g, int v, void(*Visit)(const ElemType &))
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
		for (w = g.FirstAdjVex(u); w != -1; w = g.NextAdjVex(u, w))
		if (g.GetTag(w) == UNVISITED){
			g.SetTag(w, VISITED);
			g.GetElem(w, e);
			Visit(e);
			q.EnQueue(w);
		}
	}
}
template <class ElemType>
void BFSTraverse(const AdjMatrixUndirGraph<ElemType> &g, void(*Visit)(const ElemType &)) 
{
	int v;
	for (v = 0; v < g.GetVexNum(); v++)//����δ���ʱ�־
		g.SetTag(v, UNVISITED);
	//����ж϶��㣬��δ���ʶ��㿪ʼ�����������
	for (v = 0; v < g.GetVexNum(); v++)
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


template <class ElemType, class WeightType> 
void ShortestPathDij( AdjListDirNetwork<ElemType, WeightType> &g, int v0, int *path, WeightType *dist) 
{
	WeightType minVal, infinity = g.GetInfinity();
	int v, u;
	//��ʼ��path��dist�Ͷ����־
	for (v = 0; v < g.GetVexNum(); v++) 
	{
		dist[v] = g.GetWeight(v0, v);
		if (dist[v] == infinity)   path[v] = -1;
		else path[v] = v0;
		g.SetTag(v, UNVISITED);
	}
	g.SetTag(v0, VISITED);
	//ȷ��Դ��v0���������ж�������·��
	for (int i = 1; i < g.GetVexNum(); i++){
		//��δȷ�����·���Ķ�����Ѱ�ҵ�v0������̵Ķ���u
		minVal = infinity;      u = v0;//��ʼ��̾���Ϊ���uΪv0
		for (v = 0; v < g.GetVexNum(); v++)
		if (g.GetTag(v) == UNVISITED && dist[v] < minVal)  {
			u = v; 	//�ҵ��ȵ�ǰ��̾���С�Ķ���
			minVal = dist[v];
		}
		g.SetTag(u, VISITED);//ȷ���˶���u�����·�������䶥���־
		//�޸�����δȷ�����·���Ķ���ĵ�ǰ��̾���͵�ǰ���·��
		for (v = g.FirstAdjVex(u); v != -1; v = g.NextAdjVex(u, v))
		if (g.GetTag(v) == UNVISITED &&
			minVal + g.GetWeight(u, v) < dist[v]) {
			dist[v] = minVal + g.GetWeight(u, v);//�޸ĵ�ǰ��̾���
			path[v] = u;//�޸ĵ�ǰ���·��
		}
	}
}











void Display(const char &e)
{
	cout << e << " ";
}
void Play(const char &e)
{

}
bool LoadData(AdjListDirNetwork<char, int> &g)
{
	ifstream in("GraphData.txt", ios::in);
	while (!in)
	{
		in.open("G:\\VS\\C++\\newmap\\Debug\\GraphData.txt", ios::in);
	}
	int a, b;
	in >> a >> b;
	char c[15];
	for (int i = 0; i<a; i++)
	{
		in >> c[i];
		g.InsertVex(c[i]);
	}
	int e1[35], e2[35], we[35];
	//int j = 0;
	for (int j = 0; j < b;j++)
	{
		in >> e1[j] >> e2[j] >> we[j];
		g.InsertArc(e1[j], e2[j], we[j]);
		//j++;
	}

	in.close();
	return true;
}
template <class ElemType, class WeightType>
bool ExistPathDFS(AdjListDirNetwork<ElemType, WeightType> &g, ElemType beg, ElemType en)
{
	ElemType e;
	int start, finish;
	for (int i = 0; i < g.GetVexNum();i++)
	{
		g.GetElem(i, e);
		if (e==beg)
		{
			start = i;
		}
		if (e==en)
		{
			finish = i;
		}
	}
	int v;
	void(*Visit)(const ElemType &) = Play;
	for (v = 0; v < g.GetVexNum(); v++)//����δ���ʱ�־
		g.SetTag(v, UNVISITED);
	for (v = start; v < finish; v++)
	if (g.GetTag(v) == UNVISITED)
		DFS(g, v, Visit);
	if (g.GetTag(start)==VISITED&&g.GetTag(finish)==VISITED)
	{
		return true;
	} 
	else if (g.GetTag(start) == VISITED&&g.GetTag(finish == UNVISITED))
	{
		return false;
	}
	
}
template <class ElemType, class WeightType>
bool ExistPathBFS(AdjListDirNetwork<ElemType, WeightType> &g, ElemType beg, ElemType en)
{
	ElemType e;
	int start, finish;
	for (int i = 0; i < g.GetVexNum(); i++)
	{
		g.GetElem(i, e);
		if (e == beg)
		{
			start = i;
		}
		if (e == en)
		{
			finish = i;
		}
	}
	int v;
	void(*Visit)(const ElemType &) = Play;
	for (v = 0; v < g.GetVexNum(); v++)//����δ���ʱ�־
		g.SetTag(v, UNVISITED);
	for (v = start; v < finish; v++)
	if (g.GetTag(v) == UNVISITED)
		BFS(g, v, Visit);
	if (g.GetTag(start) == VISITED&&g.GetTag(finish) == VISITED)
	{
		return true;
	}
	else if (g.GetTag(start) == VISITED&&g.GetTag(finish == UNVISITED))
	{
		return false;
	}


}

template<class ElemType,class WeightType>
void OutputShortestPathDij(AdjListDirNetwork<ElemType, WeightType> &g, int v0, int *path, WeightType *dist)
{
	for (int i = 1; i < g.GetVexNum();i++)
	{
		if (dist[i]==g.GetInfinity())
		{
			cout << "���";
			ElemType e;
			g.GetElem(v0, e);
			cout << e;
			cout << "���յ�";
			g.GetElem(i, e);
			cout << e;
			cout << "������·����" << endl;
		} 
		else
		{
			cout << "���";
			ElemType e,e0;
			g.GetElem(v0, e);
			cout << e;
			cout << "���յ�";
			g.GetElem(i, e);
			cout << e;
			cout << "�����·��Ϊ:";
			int j = i;
			int k = 0;
			int a[100];
			a[k++] = j;
			while (j!=0)
			{
				a[k++] = path[j];
				j = path[j];
			}
			for (int l = k-1; l >=0;l--)
			{
				g.GetElem(a[l], e0);
				cout << e0;
			}
			cout << " ";
			cout << "��̾���Ϊ:" << dist[i] << endl;

		}
	}
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
		//-----------------------------���²��Ե�1��------------------------------------------------
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
	
	system("pause");
}
