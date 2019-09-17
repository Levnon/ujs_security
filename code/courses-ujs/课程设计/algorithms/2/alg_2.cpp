// alg_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
#define max_int 0x7FFFFFFF

//Prim�㷨ʵ��
void prim_alg()
{
    int n;
	cout<<"����������Ŀ��";
    cin>>n;
    vector<vector<int> > a(n, vector<int>(n));
	cout<<"�������ڽӾ���"<<n<<"*"<<n<<"����ע����·��������-1"<<endl;
    for(int i = 0; i < n ; i++) 
	{
        for(int j = 0; j < n; j++) 
		{
            cin>>a[i][j];
			if(a[i][j]<0) a[i][j]=max_int;
        }
    }
	cout<<"��С������������......"<<endl;
	cout<<"(";
	int flag=1;
    int pos=0, minimum;
    int min_tree = 0;
    //lowcost�����¼ÿ2�������СȨֵ��visited������ĳ���Ƿ��ѷ���
    vector<int> visited, lowcost;
    for ( i = 0; i < n; i++) 
	{
        visited.push_back(0);    //��ʼ��Ϊ0����ʾ��û����
    }
    visited[0] = 1;   //��С�������ӵ�һ�����㿪ʼ
    for ( i = 0; i < n; i++) 
	{
        lowcost.push_back(a[0][i]);    //Ȩֵ��ʼ��Ϊ0
    }
	
    for ( i = 0; i < n; i++) //ö��n������
	{    
		
        minimum = max_int;
        for (int j = 0; j < n; j++) //�ҵ���СȨ�߶�Ӧ����
		{    
            if(!visited[j] && minimum > lowcost[j]) 
			{
                minimum = lowcost[j];
				
			
                pos = j;
            }
        }
	
        if (minimum == max_int)    //���min = max_int��ʾ�Ѿ������е���Լ�����С��������
            break;
        min_tree += minimum;
		if(flag) cout<<minimum;
		else cout<<","<<minimum;
		flag=0;
        visited[pos] = 1;     //������С��������
        for ( j = 0; j < n; j++) 
		{
            if(!visited[j] && lowcost[j] > a[pos][j]) lowcost[j] = a[pos][j];   //���¿ɸ��±ߵ�Ȩֵ
        }
    }
	cout<<")"<<endl;
	cout<<"��С������������ϣ�ȨֵΪ��";
    cout<<min_tree<<endl;
	
}


int main(int argc, char* argv[])
{
	prim_alg();
	return 0;
}
