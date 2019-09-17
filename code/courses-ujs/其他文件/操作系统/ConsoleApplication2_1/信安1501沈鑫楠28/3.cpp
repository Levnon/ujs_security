#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <vector>
#define Length 128
#define Unrefered -1
using namespace std;
struct page
{
	int num;//ҳ��
	int sign;//��־
	int block;//������
	int modifysign;//�޸ı�־
	int place;//�ڴ����ϵ�λ��
};
struct order
{
	string operate;//����
	int page_num;//ҳ��
	int unit_num;//��Ԫ��
};
struct page assignment[7] = { { 0, 1, 5, 0, 11 }, { 1, 1, 8, 0, 12 }, { 2, 1, 9, 0, 13 }, { 3, 1, 1, 0, 21 }, { 4, 0, Unrefered, 0, 22 }, { 5, 0, Unrefered, 0, 23 }, { 6, 0, Unrefered, 0, 121 } };//�����ʼҳ��
bool exist(int num, int n)//�ж��������Ƿ��Ѵ���
{
	for (int i = 0; i < 7; i++)
	{
		if (i == n)
		{

			continue;
		}
		if (assignment[i].block == num)
		{
			return true;
		}
	}
	return false;
}
int main()
{
	vector<int> vec;//����������ʾ���п�
	vec.push_back(3);
	vec.push_back(2);
	vec.push_back(1);
	vec.push_back(0);
	//��ʼ��
	
	vector<int>::iterator it;
	printf("��ʼҳ��:");
	for (it = vec.begin(); it != vec.end(); ++it)//���������ʼҳ��
	{
		printf("%d\t", *it);
	}
	printf("\n");
	fflush(stdin);
	fflush(stdout);
	struct order sequence[12];
	printf("��������ҵ��ָ������:\n");//����Ҫִ�е�ָ������
	printf("���� ҳ�� ��Ԫ��\n");
	for (int i = 0; i < 12; i++)
	{
		cin >> sequence[i].operate >> sequence[i].page_num >> sequence[i].unit_num;
	}

	for (int i = 0; i < 12; i++)
	{
		int L = sequence[i].page_num;//Ҫ���ʵ�ҳ��
		
		
		if (assignment[L].sign == 1)//��������
		{
			if (sequence[i].operate == "��" || sequence[i].operate == "cun")//���޸�
			{
				assignment[L].modifysign = 1;//�޸ı�־��Ϊ1
			}
			int addr = assignment[L].block*Length + sequence[i].unit_num;
			
			int j = 0;
			for (it = vec.begin(); it != vec.end(); ++it, ++j)
			{
				if (*it == L)//�ı���һҳ�������е�λ��
				{
					vec.erase(it);
					vec.insert(vec.begin(), L);
					break;
				}
			}
		}
		else//ȱҳ
		{
			int J = vec.back();//���������δ�����ʵ�ҳ
			if (assignment[J].modifysign==1)//���޸Ĺ�
			{
				cout << "OUT " << J << endl;//����
			}
			cout << "IN " << L << endl;//�����µ�ҳ
			vec.pop_back();
			vec.insert(vec.begin(),L);//���뵽������
			//�ɵ�ҳ���������ṹ���е����ݸı�
			assignment[J].sign = 0;
			assignment[J].block = Unrefered;
			//�µ�ҳ�����룬�ṹ����������ݸı�
			assignment[L].sign = 1;
			assignment[L].block = 0;
			do 
			{
				assignment[L].block++;
			} while (exist(assignment[L].block,L));
		}
		//���ִ������ָ���������ҳ���״̬
		cout << "��ǰ״̬��";
		for (it = vec.begin(); it != vec.end(); ++it)
		{
			printf("%d\t", *it);
		}
		cout << endl;
	}
	return 0;
}


