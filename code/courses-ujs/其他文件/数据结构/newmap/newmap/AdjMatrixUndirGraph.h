#pragma once
#ifndef UNDIRGRAPH_ADJMATRIX_HEADER
#define UNDIRGRAPH_ADJMATRIX_HEADER
template <class ElemType>
class AdjMatrixUndirGraph
{
protected:
	int vexNum, vexMaxNum, arcNum;//������Ŀ����󶥵���Ŀ������Ŀ
	int **arcs;//��ű���Ϣ���ڽӾ���
	ElemType *vertexes;//��Ŷ�����Ϣ������
	mutable Status *tag;//��־����
public:
	AdjMatrixUndirGraph(ElemType es[], int vertexNum,
		int vertexMaxNum = DEFAULT_SIZE);
	AdjMatrixUndirGraph(int vertexMaxNum = DEFAULT_SIZE);
	~AdjMatrixUndirGraph();
	void Clear();//���ͼ
	bool IsEmpty();//�ж�����ͼ�Ƿ�Ϊ��
	int GetOrder(ElemType &d) const;//�󶥵�����
	Status GetElem(int v, ElemType &d) const;//�󶥵�Ԫ�ص�ֵ 
	Status SetElem(int v, const ElemType &d);//���ö����Ԫ��ֵ
	int GetVexNum() const;//���ض������
	int GetArcNum() const;//���ر���
	int FirstAdjVex(int v) const;//���ض���v�ĵ�һ���ڽӵ�
	int NextAdjVex(int v1, int v2) const;//���ض���v1�����v2����һ���ڽӵ�
	void InsertVex(const ElemType &d);//����Ԫ��ֵΪd�Ķ���
	void InsertArc(int v1, int v2);//���붥��Ϊv1��v2�ı�
	void DeleteVex(const ElemType &d);//ɾ��Ԫ��ֵΪd�Ķ���
	void DeleteArc(int v1, int v2);//ɾ������Ϊv1��v2�ı�
	Status GetTag(int v) const;//���ض���v�ı�־
	void SetTag(int v, Status val)//���ö���v�ı�־Ϊval
	{
		tag[v] = val;
	}
	AdjMatrixUndirGraph(const
		AdjMatrixUndirGraph<ElemType> &g);	//�������캯��
	AdjMatrixUndirGraph<ElemType> &operator =(
		const AdjMatrixUndirGraph<ElemType> &g); //��ֵ����
	void Display();//��ʾ�ڽӾ�������ͼ
};
template <class ElemType>
AdjMatrixUndirGraph<ElemType>::AdjMatrixUndirGraph(int vertexMaxNum)
{
	if (vertexMaxNum < 0)
		throw out_of_range("����Ķ��������Ŀ����Ϊ��!");
	vexNum = 0;
	vexMaxNum = vertexMaxNum;
	arcNum = 0;
	vertexes = new ElemType[vexMaxNum];
	tag = new Status[vexMaxNum];
	arcs = (int **)new int *[vexMaxNum];
	for (int v = 0; v < vexMaxNum; v++)
		arcs[v] = new int[vexMaxNum];
}
template <class ElemType>
AdjMatrixUndirGraph<ElemType>::AdjMatrixUndirGraph(ElemType es[],
	int vertexNum, int vertexMaxNum)   {
	if (vertexMaxNum < 0)
		throw out_of_range("����Ķ��������Ŀ����Ϊ��!");
	if (vertexMaxNum < vertexNum)
		throw out_of_range("������Ŀ���ܴ�������Ķ��������Ŀ!");
	vexNum = vertexNum;	vexMaxNum = vertexMaxNum;
	arcNum = 0;	vertexes = new ElemType[vexMaxNum];
	tag = new Status[vexMaxNum];
	arcs = (int **)new int *[vexMaxNum];
	for (int v = 0; v < vexMaxNum; v++) 	arcs[v] = new int[vexMaxNum];
	for (int v = 0; v < vexNum; v++) {
		vertexes[v] = es[v];  tag[v] = UNVISITED;
		for (int u = 0; u < vexNum; u++)  arcs[v][u] = 0;
	}
}
template <class ElemType>
int AdjMatrixUndirGraph<ElemType>::FirstAdjVex(int v) const
{
	if (v < 0 || v >= vexNum)
		throw out_of_range("v���Ϸ�!");
	for (int u = 0; u < vexNum; u++)
	if (arcs[v][u] != 0)
		return u;
	return -1;
}
template <class ElemType>
int AdjMatrixUndirGraph<ElemType>::NextAdjVex(int v1,
	int v2) const
{
	if (v1 < 0 || v1 >= vexNum)   throw out_of_range("v1���Ϸ�!");
	if (v2 < 0 || v2 >= vexNum)    throw out_of_range("v2���Ϸ�!");
	if (v1 == v2) throw out_of_range("v1���ܵ���v2!");
	for (int u = v2 + 1; u < vexNum; u++)
	if (arcs[v1][u] != 0)
		return u;
	return -1;
}
template <class ElemType>
void AdjMatrixUndirGraph<ElemType>::InsertVex(const ElemType &d)  {
	if (vexNum == vexMaxNum)
		throw out_of_range("ͼ�Ķ��������ܳ�������������!");
	vertexes[vexNum] = d;
	tag[vexNum] = UNVISITED;
	for (int v = 0; v <= vexNum; v++) {
		arcs[vexNum][v] = 0;
		arcs[v][vexNum] = 0;
	}
	vexNum++;
}
template <class ElemType>
void AdjMatrixUndirGraph<ElemType>::InsertArc(int v1, int v2)
{
	if (v1 < 0 || v1 >= vexNum)    throw out_of_range("v1���Ϸ�!");
	if (v2 < 0 || v2 >= vexNum)    throw out_of_range("v2���Ϸ�!");
	if (v1 == v2)    throw out_of_range("v1���ܵ���v2!");
	if (arcs[v1][v2] == 0) {
		arcNum++;
		arcs[v1][v2] = 1;
		arcs[v2][v1] = 1;
	}
}
template <class ElemType>
void AdjMatrixUndirGraph<ElemType>::DeleteVex(const ElemType &d)  {
	int v;
	for (v = 0; v < vexNum; v++)//Ѱ�Ҷ���d�ڶ��������е��±�
	if (vertexes[v] == d)     break;
	if (v == vexNum)  throw out_of_range("ͼ�в�����Ҫɾ���Ķ���!");
	for (int u = 0; u < vexNum; u++) //ɾ�������ڶ���d�ı�
	if (arcs[v][u] == 1) {
		arcNum--;
		arcs[v][u] = 0;
		arcs[u][v] = 0;
	}
	vexNum--; //������Ŀ��1
	if (v < vexNum) {//����d���Ƕ���������һ������
		//�ƶ����һ��������Ϣ������d��λ��
		vertexes[v] = vertexes[vexNum];
		tag[v] = tag[vexNum];//�ƶ����һ������ķ��ʱ�־
		//�ƶ��ڽӾ��������һ�к����һ�е�����d���к���
		for (int u = 0; u <= vexNum; u++)
			arcs[v][u] = arcs[vexNum][u];
		for (int u = 0; u <= vexNum; u++)
			arcs[u][v] = arcs[u][vexNum];
	}
}
template <class ElemType>
void AdjMatrixUndirGraph<ElemType>::DeleteArc(int v1, int v2)
{
	if (v1 < 0 || v1 >= vexNum)    throw out_of_range("v1���Ϸ�!");
	if (v2 < 0 || v2 >= vexNum)    throw out_of_range("v2���Ϸ�!");
	if (v1 == v2)    throw out_of_range("v1���ܵ���v2!");
	if (arcs[v1][v2] != 0)
	{
		arcNum--;
		arcs[v1][v2] = 0;
		arcs[v2][v1] = 0;
	}
}







#endif // !STATUS_HEADER
