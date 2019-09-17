// alg_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <graphics.h>
#include <conio.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <ctype.h>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define eps 1e-8 //����
#define INF 0x7fffffff //�����
#define PI acos(-1.0) //��ȷֵ
#define seed 31 //����
#define maxn 100005 //n�����ֵ
#define min(X,Y) X<Y?X:Y //����������Сֵ
#define min3(X,Y,Z) X<(Y<Z?Y:Z)?X:(Y<Z?Y:Z) //����������Сֵ
typedef long LL;
typedef unsigned long ULL;
using namespace std;

//�����㷨���ά������
struct Point
{
  double x,y;
}p[maxn];//�����Ľṹ��

int a[maxn];
int minpix1=-1,minpix2=-1;
inline int cmpx(Point a,Point b)//�Ƚ�x����
{
  return a.x<b.x;
}
inline int cmpy(int a,int b)//�Ƚ�y����
{
  return p[a].y<p[b].y;
}
inline double dis(Point a,Point b)//����������
{
   return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double closest(int low,int high)//����һϵ�е������Сֵ
{
   int i,j,k;
   int mid3;
   if(low+1==high) //ֻ��������
   { 
	minpix1=low;
	minpix2=high;
    return dis(p[low],p[high]);
   }
   if(low+2==high)//ֻ��������
   { 
	 mid3=low+1;
	 double dis1=dis(p[low],p[high]);
	 double dis2=dis(p[low],p[mid3]);
	 double dis3=dis(p[mid3],p[high]);
	 if(dis1<=dis2&&dis1<=dis3)
	 {
		 minpix1=low;
		 minpix2=high;
	 }
	 else if(dis2<=dis1&&dis2<=dis3)
	 {
		 minpix1=low;
		 minpix2=mid3;
	 }
	 else
	 {
		 minpix1=mid3;
		 minpix2=high;
	 }
     return min3(dis(p[low],p[high]),dis(p[low],p[mid3]),dis(p[mid3],p[high]));
   }
   int mid=(low+high)/2; //���е㼴�����Ӽ��ķֽ���
   double d=min(closest(low,mid),closest(mid+1,high));//��ߺ��ұߵ���С����
   for(i=low,k=0;i<=high;i++)//��x������p[mid].x-d  ~  p[mid].x+d��Χ�ڵĵ�ɸѡ����
   { 
     if(p[i].x>=p[mid].x-d&&p[i].x<=p[mid].x+d){
        a[k++]=i; //������Щ����±�����
     }
   }
   sort(a,a+k,cmpy); //��y���������������
   for(i=0;i<k;i++)
   {
    for(j=i+1;j<k;j++)
	{
       if(p[a[j]].y-p[a[i]].y>=d) //ע���±�����
            break;
	   if(dis(p[a[i]],p[a[j]])<d)
	   {
		   minpix1=a[i];
		   minpix2=a[j];
	   }
       d=min(d,dis(p[a[i]],p[a[j]]));
    }
   }
   return d;
}


int main(int argc, char* argv[])
{
	int i,n;
	cout<<"�������ĸ���:";
	cin>>n;
	cout<<"��ֱ����������꣨x��y��,ע�� -400<x<400 -300<y<300 "<<endl;
	for(i=0;i<n;i++)
	{
		
		do
		{
			cout<<"��"<<i+1<<"���㣺";
			cin>>p[i].x>>p[i].y;
		}
		while(p[i].x<-400||p[i].x>400||p[i].y<-300||p[i].y>300);
	}
	sort(p , p + n , cmpx);//��x���������������
   
	cout<<"���������ʼ������ӽ�����......";
	getch();
	double mindist=closest(0,n-1);
	char buffer[20];
	sprintf(buffer,"%lf",mindist);
	char noti[50]="��̾��룺";
	// ��ʼ��ͼ��ģʽ
	initgraph(800, 600);
	setbkcolor(0x005478);//���ñ���ɫ
	cleardevice();//����
	setcolor(WHITE);
	line(0,300,800,300);
	line(400,0,400,600);
	outtextxy(410,280,'O');
	outtextxy(780,280,'x');
	outtextxy(410,5,'y');
	BeginBatchDraw();
	setfillcolor(RED);
	setlinecolor(RED);
	for(i=0;i<n;i++)
		fillcircle(p[i].x+400,-p[i].y+300,2);
	setcolor(BLUE);
	line(p[minpix1].x+400,-p[minpix1].y+300,p[minpix2].x+400,-p[minpix2].y+300);
	setcolor(WHITE);
	outtextxy((p[minpix1].x+400+p[minpix2].x+400)/2+20,(-p[minpix1].y+300-p[minpix2].y+300)/2,noti);
	outtextxy((p[minpix1].x+400+p[minpix2].x+400)/2+20,(-p[minpix1].y+300-p[minpix2].y+300)/2+20,buffer);
	FlushBatchDraw();
	EndBatchDraw();
	while(!kbhit());//��������˳�
	closegraph();
	return 0;
}
