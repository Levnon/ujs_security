#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#define Length 128
#define Unrefered -1
using namespace std;
struct page
{
	int num;//ҳ��
	int sign;//��־
	int block;//������
	int place;//�ڴ����ϵ�λ��
};
struct order
{
	string operate;//����
	int page_num;//ҳ��
	int unit_num;//��Ԫ��
};
struct page assignment[7] = { { 0, 1, 5, 11 }, { 1, 1, 8, 12 }, { 2, 1, 9, 13 }, { 3, 1, 1, 21 }, { 4, 0, Unrefered, 22 }, { 5, 0, Unrefered, 23 }, { 6, 0, Unrefered, 121 } };//�����ʼ��ҵ��ҳ��
bool exist(int num,int n)//�ж��������Ƿ��Ѵ���
{
	for (int i = 0; i < 7;i++)
	{
		if (i==n)
		{

			continue;
		}
		if (assignment[i].block==num)
		{
			return true;
		}
	}
	return false;
}
int main()
{
	//��ӡ��ʼҳ��
	printf("��ʼҳ��\n");
	for (int i = 0; i < 7;i++)
	{
		printf("%d %d %d %d\n", assignment[i].num, assignment[i].sign, assignment[i].block, assignment[i].place);
	}
	struct order sequence[12];
	//������Ҫִ�е�ָ������
	printf("��������ҵ��ָ������:\n");
	printf("���� ҳ�� ��Ԫ��\n");
	for (int i = 0; i < 12;i++)
	{
		cin >> sequence[i].operate >> sequence[i].page_num >> sequence[i].unit_num;
	}
	//���ÿ��ָ��ִ��ʱ���ʵĵ�ַ
	printf("���� ҳ�� ��ַ\n");
	for (int i = 0; i < 12;i++)
	{
		if (assignment[sequence[i].page_num].sign==1)//��־Ϊ1�����ڴ���
		{
			int addr = assignment[sequence[i].page_num].block*Length + sequence[i].unit_num;//����������ַ
			
			cout << sequence[i].operate << " " << sequence[i].page_num << " " << addr << endl;//���
		}
		else//��־Ϊ0��ȱҳ�ж�
		{
			cout<<sequence[i].operate<<" "<<sequence[i].page_num<<"*"<<endl;//���
			//�жϴ�����ҳ���������
			assignment[sequence[i].page_num].sign = 1;
			assignment[sequence[i].page_num].block = 0;
			do 
			{	
				assignment[sequence[i].page_num].block++;
			} while (exist(assignment[sequence[i].page_num].block, sequence[i].page_num));//����������
		}
	}
	return 0;
}


