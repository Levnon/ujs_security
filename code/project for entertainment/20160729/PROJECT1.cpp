/*// PROJECT1.cpp : Defines the entry point for the console application.
//



========================================================================
       CONSOLE APPLICATION : PROJECT1
========================================================================


AppWizard has created this PROJECT1 application for you.  

This file contains a summary of what you will find in each of the files that
make up your Project1 application.

PROJECT1.dsp
    This file (the project file) contains information at the project level and
    is used to build a single project or subproject. Other users can share the
    project (.dsp) file, but they should export the makefiles locally.

PROJECT1.cpp
    This is the main application source file.


/////////////////////////////////////////////////////////////////////////////
Other standard files:

StdAfx.h, StdAfx.cpp
    These files are used to build a precompiled header (PCH) file
    named Project1.pch and a precompiled types file named StdAfx.obj.


/////////////////////////////////////////////////////////////////////////////
Other notes:

AppWizard uses "TODO:" to indicate parts of the source code you
should add to or customize.

/////////////////////////////////////////////////////////////////////////////
CAUTION:


THIS PROJECT IS BASED ON ONE-SIDE LIST.



*/
#include "stdafx.h"
#include <iostream>
using namespace std;

struct SNode
{
	DATA data;
	SNode *pNext;
}*g_pHead;
DATA input()
{
	DATA da;
	char a[50],b[50],c[20],d[20],e[20];
	char *p=NULL;
	int sum=0;
	bool t=false;
	cout<<"������ѧ��:";
	cin>>a;
	for (p=a;*p!='\0';p++)
		if (((*p<'0')||(*p>'9')))
		{
			t=true;
			break;
		}
	while (t)
	{
		cout<<"�������"<<endl;
		system("pause");
		system("cls");
		cout<<"������ѧ��:";
		cin>>a;
		for (p=a;*p!='\0';p++)
			if (((*p<'0')||(*p>'9'))) 
			{
				t=true;
				break;
			}
		if (*p=='\0') t=false;
	}
	int snum=atoi(a);
	while (!testnum(snum))
	{
		cout<<"ѧ���Ѵ��ڣ�����������"<<endl;
		system("pause");
		system("cls");
		cout<<"������ѧ��:";
		cin>>a;
		for (p=a;*p!='\0';p++)
			if (((*p<'0')||(*p>'9'))) 
			{
				t=true;
				break;
			}
		if (*p=='\0') t=false;
		snum=atoi(a);
	}
	da.Snum=atoi(a);
	do
	{	
		t=false;
		system("cls");
		cout<<"����������:";
		cin>>b;
		for (p=b;*p!='\0';p++)
			if ((*p>='0')&&(*p<='9')) 
			{
				t=true;
				break;
			}
		if (t) 
		{
			cout<<"�������"<<endl;
			system("pause");
		}
	}
	while (t);
	char cj;
	while (!testname(b))
	{
		cout<<"���������Ƿ�ȷ������Y/N��";
		cin>>cj;
		while ((cj!='n')&&(cj!='N')&&(cj!='y')&&(cj!='Y'))
		{
			cout<<"������Ч�����������롣"<<endl;
			cin>>cj;
		}
		if ((cj=='y')||(cj=='Y')) break;
		do
		{	
			t=false;
			system("cls");
			cout<<"����������:";
			cin>>b;
			for (p=b;*p!='\0';p++)
				if ((*p>='0')&&(*p<='9')) 
				{
					t=true;
					break;
				}
				if (t) 
				{
					cout<<"�������"<<endl;
					system("pause");
				}
		}
		while (t);
	}
	strcpy(da.Sname,b);
	do
	{
		t=false;
		sum=0;
		system("cls");
		cout<<"������ɼ�1:";
		cin>>c;
		for (p=c;*p!='\0';p++)
			if ((*p<'0')||(*p>'9'))
			{
				if (*p='.') 
				{
					if (*(p+1)=='\0') 
					{
						t=true;
						break;
					}
					sum++;
					continue;
				}
				t=true;
				break;
			}
		if (t||(sum>1)) 
		{
			cout<<"�������"<<endl;
			system("pause");
		}
	}
	while (t||(sum>1));
	da.Smath=atof(c);
	do
		{
			t=false;
			sum=0;
			system("cls");
			cout<<"������ɼ�2:";
			cin>>d;
			for (p=d;*p!='\0';p++)
				if ((*p<'0')||(*p>'9'))
				{
					if (*p='.') 
					{
						if (*(p+1)=='\0') 
						{
							t=true;
							break;
						}
						sum++;
						continue;
					}
					t=true;
					break;
				}
			if (t||(sum>1)) 
			{
				cout<<"�������"<<endl;
				system("pause");
			}
		}
	while (t||(sum>1));
	da.Sengl=atof(d);
	do
	{
		t=false;
		sum=0;
		system("cls");
		cout<<"������ɼ�3:";
		cin>>e;
		for (p=e;*p!='\0';p++)
			if ((*p<'0')||(*p>'9')) 
			{
				if (*p='.') 
				{
					if (*(p+1)=='\0') 
					{
						t=true;
						break;
					}
					sum++;
					continue;
				}
				t=true;
				break;
			}
		if (t||(sum>1)) 
		{
			cout<<"�������"<<endl;
			system("pause");
		}
	}
	while (t||(sum>1));
	da.Schin=atof(e);
	cout<<"�����������Ϊ��"<<endl;
	output(da);
	cout<<"1.ȷ��"<<endl;
	cout<<"2.ȡ��"<<endl;
	int tp;
	do
	{
		cout<<"������������:";
		cin>>tp;
		if ((tp<1)||(tp>2)) cout<<"������Ч�����������롣"<<endl;
	}
	while ((tp<1)||(tp>2));
	switch(tp)
	{
		case 1:
			return da;
			break;
		case 2:
			cout<<"����������"<<endl;
			system("pause");
			return input();
			break;
		default:
			return input();
	}
}
void output(DATA d)
{
	cout<<d.Snum<<'\t'<<d.Sname<<'\t'<<d.Smath<<'\t'<<d.Sengl<<'\t'<<d.Schin<<endl;
}
void Addfront()//ͷ�巨
{
	DATA da=input();
	SNode *pNew=(SNode *)malloc(sizeof(SNode));
	pNew->data=da;
	pNew->pNext=g_pHead;
	g_pHead=pNew;
}
void Addback()//β�巨
{
	DATA da=input();
	SNode *pNew=(SNode *)malloc(sizeof(SNode));
	SNode *p=g_pHead;
	pNew->data=da;
	pNew->pNext=NULL;
	if (!p)
	{
		g_pHead=pNew;
		return;
	}
	while (p->pNext)
		p=p->pNext;
	p->pNext=pNew;
}
void Sequence()//˳��
{
	SNode *p=g_pHead;
	if (!p)
	{
		cout<<"����Ϊ��"<<endl;
		return;
	}
	while (p)
	{
		output(p->data);
		p=p->pNext;
	}
}
void Antitone(SNode *p)//����
{
	SNode *h=p;
	if (!g_pHead)
	{
		cout<<"����Ϊ��"<<endl;
		return;
	}
	if (h)
	{
		Antitone(h->pNext);
		output(h->data);
	}
}
void Sort()//����
{
	char c,p;
	do
	{
		system("cls");
		cout<<"1.��ѧ������"<<endl;
		cout<<"2.����������"<<endl;
		cout<<"3.���ɼ�1����"<<endl;
		cout<<"4.���ɼ�2����"<<endl;
		cout<<"5.���ɼ�3����"<<endl;
		cout<<"6.������һ���˵�"<<endl;
		cout<<"7.�������˵�"<<endl;
		int i;
		cout<<"������������:";
		cin>>p;
		i=judgenum(p);
		while ((i<1)||(i>7))
		{
			cout<<"������Ч�����������롣"<<endl;
			cin>>p;
			i=judgenum(p);
		}
		switch (i)
		{
		case 1:
			SortNum();
			break;
		case 2:
			SortName();
			break;
		case 3:
			Sort1();
			break;
		case 4:
			Sort2();
			break;
		case 5:
			Sort3();
			break;
		case 6:case 7:
			Menu();
			return;
		}
		cout<<"�Ƿ��������Y��N��:";
		cin>>c;
		while ((c!='n')&&(c!='N')&&(c!='y')&&(c!='Y'))
		{
			cout<<"������Ч�����������롣"<<endl;
			cin>>c;
		}
	}
	while ((c=='y')||(c=='Y'));
}
void SortNum()
{
	char p;
	if (!g_pHead)
	{
		cout<<"����Ϊ��"<<endl;
		return;
	}
	system("cls");
	cout<<"1.��С��������"<<endl;
	cout<<"2.�Ӵ�С����"<<endl;
	cout<<"3.������һ���˵�"<<endl;
	cout<<"4.�������˵�"<<endl;
	int i;
	cout<<"������������:";
	cin>>p;
	i=judgenum(p);
	while ((i<1)||(i>4))
	{
		cout<<"������Ч�����������롣"<<endl;
		cin>>p;
		i=judgenum(p);
	}
	switch (i)
	{
	case 1:
		SortNum_1();
		break;
	case 2:
		SortNum_2();
		break;
	case 3:
		Sort();
		return;
	case 4:
		Menu();
		return;
	}
	
}
void SortNum_1()
{
	DATA temp;
	SNode *p=g_pHead;
	SNode *q=g_pHead;
	while (p)
	{
		q=p->pNext;
		while (q)
		{
			if (q->data.Snum<p->data.Snum)
			{
				temp=q->data;
				q->data=p->data;
				p->data=temp;
			}
			q=q->pNext;
		}
		p=p->pNext;
	}
	Sequence();
}

void SortNum_2()
{
	DATA temp;
	SNode *p=g_pHead;
	SNode *q=g_pHead;
	while (p)
	{
		q=p->pNext;
		while (q)
		{
			if (q->data.Snum>p->data.Snum)
			{
				temp=q->data;
				q->data=p->data;
				p->data=temp;
			}
			q=q->pNext;
		}
		p=p->pNext;
	}
	Sequence();
}
void SortName()
{
	char p;
	if (!g_pHead)
	{
		cout<<"����Ϊ��"<<endl;
		return;
	}
	system("cls");
	cout<<"1.��С��������"<<endl;
	cout<<"2.�Ӵ�С����"<<endl;
	cout<<"3.������һ���˵�"<<endl;
	cout<<"4.�������˵�"<<endl;
	int i;
	cout<<"������������:";
	cin>>p;
	i=judgenum(p);
	while ((i<1)||(i>4))
	{
		cout<<"������Ч�����������롣"<<endl;
		cin>>p;
		i=judgenum(p);
	}
	switch (i)
	{
	case 1:
		SortName_1();
		break;
	case 2:
		SortName_2();
		break;
	case 3:
		Sort();
		return;
	case 4:
		Menu();
		return;
	}
}
void SortName_1()
{
	DATA temp;
	SNode *p=g_pHead;
	SNode *q=g_pHead;
	while (p)
	{
		q=p->pNext;
		while (q)
		{
			if (strcmp(q->data.Sname,p->data.Sname)<0)
			{
				temp=q->data;
				q->data=p->data;
				p->data=temp;
			}
			q=q->pNext;
		}
		p=p->pNext;
	}
	Sequence();
}
void SortName_2()
{
	DATA temp;
	SNode *p=g_pHead;
	SNode *q=g_pHead;
	while (p)
	{
		q=p->pNext;
		while (q)
		{
			if (strcmp(q->data.Sname,p->data.Sname)>0)
			{
				temp=q->data;
				q->data=p->data;
				p->data=temp;
			}
			q=q->pNext;
		}
		p=p->pNext;
	}
	Sequence();
}
void Sort1()
{
	char p;
	if (!g_pHead)
	{
		cout<<"����Ϊ��"<<endl;
		return;
	}
	system("cls");
	cout<<"1.��С��������"<<endl;
	cout<<"2.�Ӵ�С����"<<endl;
	cout<<"3.������һ���˵�"<<endl;
	cout<<"4.�������˵�"<<endl;
	int i;
	cout<<"������������:";
	cin>>p;
	i=judgenum(p);
	while ((i<1)||(i>4))
	{
		cout<<"������Ч�����������롣"<<endl;
		cin>>p;
		i=judgenum(p);
	}
	switch (i)
	{
	case 1:
		Sort1_1();
		break;
	case 2:
		Sort1_2();
		break;
	case 3:
		Sort();
		return;
	case 4:
		Menu();
		return;
	}
}
void Sort1_1()
{
	DATA temp;
	SNode *p=g_pHead;
	SNode *q=g_pHead;
	while (p)
	{
		q=p->pNext;
		while (q)
		{
			if (q->data.Smath<p->data.Smath)
			{
				temp=q->data;
				q->data=p->data;
				p->data=temp;
			}
			q=q->pNext;
		}
		p=p->pNext;
	}
	Sequence();
	
}
void Sort1_2()
{
	DATA temp;
	SNode *p=g_pHead;
	SNode *q=g_pHead;
	while (p)
	{
		q=p->pNext;
		while (q)
		{
			if (q->data.Smath>p->data.Smath)
			{
				temp=q->data;
				q->data=p->data;
				p->data=temp;
			}
			q=q->pNext;
		}
		p=p->pNext;
	}
	Sequence();
}
void Sort2()
{
	char p;
	if (!g_pHead)
	{
		cout<<"����Ϊ��"<<endl;
		return;
	}
	system("cls");
	cout<<"1.��С��������"<<endl;
	cout<<"2.�Ӵ�С����"<<endl;
	cout<<"3.������һ���˵�"<<endl;
	cout<<"4.�������˵�"<<endl;
	int i;
	cout<<"������������:";
	cin>>p;
	i=judgenum(p);
	while ((i<1)||(i>4))
	{
		cout<<"������Ч�����������롣"<<endl;
		cin>>p;
		i=judgenum(p);
	}
	switch (i)
	{
	case 1:
		Sort2_1();
		break;
	case 2:
		Sort2_2();
		break;
	case 3:
		Sort();
		return;
	case 4:
		Menu();
		return;
	}
}
void Sort2_1()
{
	DATA temp;
	SNode *p=g_pHead;
	SNode *q=g_pHead;
	while (p)
	{
		q=p->pNext;
		while (q)
		{
			if (q->data.Sengl<p->data.Sengl)
			{
				temp=q->data;
				q->data=p->data;
				p->data=temp;
			}
			q=q->pNext;
		}
		p=p->pNext;
	}
	Sequence();
}
void Sort2_2()
{
	DATA temp;
	SNode *p=g_pHead;
	SNode *q=g_pHead;
	while (p)
	{
		q=p->pNext;
		while (q)
		{
			if (q->data.Sengl>p->data.Sengl)
			{
				temp=q->data;
				q->data=p->data;
				p->data=temp;
			}
			q=q->pNext;
		}
		p=p->pNext;
	}
	Sequence();
}
void Sort3()
{
	char p;
	if (!g_pHead)
	{
		cout<<"����Ϊ��"<<endl;
		return;
	}
	system("cls");
	cout<<"1.��С��������"<<endl;
	cout<<"2.�Ӵ�С����"<<endl;
	cout<<"3.������һ���˵�"<<endl;
	cout<<"4.�������˵�"<<endl;
	int i;
	cout<<"������������:";
	cin>>p;
	i=judgenum(p);
	while ((i<1)||(i>4))
	{
		cout<<"������Ч�����������롣"<<endl;
		cin>>p;
		i=judgenum(p);
	}
	switch (i)
	{
	case 1:
		Sort3_1();
		break;
	case 2:
		Sort3_2();
		break;
	case 3:
		Sort();
		return;
	case 4:
		Menu();
		return;
	}
}
void Sort3_1()
{
	DATA temp;
	SNode *p=g_pHead;
	SNode *q=g_pHead;
	while (p)
	{
		q=p->pNext;
		while (q)
		{
			if (q->data.Schin<p->data.Schin)
			{
				temp=q->data;
				q->data=p->data;
				p->data=temp;
			}
			q=q->pNext;
		}
		p=p->pNext;
	}
	Sequence();
}
void Sort3_2()
{
	DATA temp;
	SNode *p=g_pHead;
	SNode *q=g_pHead;
	while (p)
	{
		q=p->pNext;
		while (q)
		{
			if (q->data.Schin>p->data.Schin)
			{
				temp=q->data;
				q->data=p->data;
				p->data=temp;
			}
			q=q->pNext;
		}
		p=p->pNext;
	}
	Sequence();
}
void Browse()//���
{
	char c,p;
	do
	{
		system("cls");
		cout<<"1.˳�����"<<endl;
		cout<<"2.�������"<<endl;
		cout<<"3.������һ���˵�"<<endl;
		cout<<"4.�������˵�"<<endl;
		int i;
		cout<<"������������:";
		cin>>p;
		i=judgenum(p);
		while ((i<1)||(i>4))
		{
			cout<<"������Ч�����������롣"<<endl;
			cin>>p;
			i=judgenum(p);
		}
		switch (i)
		{
		case 1:
			Sequence();
			system("pause");
			break;
		case 2:
			Antitone(g_pHead);
			system("pause");
			break;
		case 3:case 4:
			Menu();
			return;
		}
		cout<<"�Ƿ���������Y��N��:";
		cin>>c;
	}
	while ((c=='y')||(c=='Y'));
}
void Insert()//����
{
	char c,p;
	do
	{
		system("cls");
		cout<<"1.���뵽ͷ"<<endl;
		cout<<"2.���뵽β"<<endl;
		cout<<"3.������һ���˵�"<<endl;
		cout<<"4.�������˵�"<<endl;
		int i;
		cout<<"������������:";
		cin>>p;
		i=judgenum(p);
		while ((i<1)||(i>4))
		{
			cout<<"������Ч�����������롣"<<endl;
			cin>>p;
			i=judgenum(p);
		}
		switch (i)
		{
		case 1:
			Addfront();
			break;
		case 2:
			Addback();
			break;
		case 3:case 4:
			Menu();
			return;
		}
		cout<<"����ɹ�"<<endl;
		cout<<"�����������£�"<<endl;
		Sequence();
		cout<<"�Ƿ�������루Y��N��:";
		cin>>c;
		while ((c!='n')&&(c!='N')&&(c!='y')&&(c!='Y'))
		{
			cout<<"������Ч�����������롣"<<endl;
			cin>>c;
		}
	}
	while ((c=='y')||(c=='Y'));
}
void Delete()//ɾ��
{
	system("cls");
	char c;
	if (!g_pHead)
	{
		cout<<"����Ϊ��"<<endl;
		system("pause");
		return;
	}
	do
	{
		system("cls");
		cout<<"�����������£�"<<endl;
		Sequence();
		SNode *p=g_pHead;
		cout<<"��������Ҫɾ����ѧ��ѧ��:"<<endl;
		int n;
		int s=0;
		cin>>n;
		int tp;
		SNode *q;
		if (p->data.Snum==n)
		{
			cout<<"����ɾ����"<<endl;
			output(p->data);
			cout<<"1.ȷ��"<<endl;
			cout<<"2.ȡ��"<<endl;
			do
			{
				cout<<"������������:";
				cin>>tp;
				if ((tp<1)||(tp>2)) cout<<"������Ч�����������롣"<<endl;
			}
			while ((tp<1)||(tp>2));
			if (tp==1)
			{
				g_pHead=p->pNext;
				free(p);
				cout<<"ɾ���ɹ�"<<endl;
				system("pause");
				return;
			}
			else 
			{
				system("cls");
				Delete();
			}
		}
		while (p)
		{
			if (p->data.Snum==n)
			{
				cout<<"����ɾ����"<<endl;
				output(p->data);
				cout<<"1.ȷ��"<<endl;
				cout<<"2.ȡ��"<<endl;
				do
				{
					cout<<"������������:";
					cin>>tp;
					if ((tp<1)||(tp>2)) cout<<"������Ч�����������롣"<<endl;
				}
				while ((tp<1)||(tp>2));
				if (tp==1)
				{
					q->pNext=p->pNext;
					free(p);
					cout<<"ɾ���ɹ�"<<endl;
					s=1;
					system("pause");
					break;
				}
				else 
				{
					system("pause");
					Delete();
				}
			}
			q=p;//q��p��ǰ���ڵ�	
			p=p->pNext;
		}
		if (!s) 
		{
			cout<<"δ�ҵ�������,����������"<<endl;
			system("pause");
			Delete();
		}
		cout<<"�Ƿ����ɾ����Y��N��:";
		cin>>c;
		while ((c!='n')&&(c!='N')&&(c!='y')&&(c!='Y'))
		{
			cout<<"������Ч�����������롣"<<endl;
			cin>>c;
		}
	}
	while ((c=='y')||(c=='Y'));
}
void Modify()//�޸�
{
	char c;
	char a[50];
	char *k=NULL;
	bool t=false;
	if (!g_pHead)
	{
		cout<<"����Ϊ��"<<endl;
		system("pause");
		return;
	}
	do
	{
		system("cls");
		cout<<"�����������£�"<<endl;
		Sequence();
		SNode *p=g_pHead;
		cout<<"��������Ҫ�޸ĵ�ѧ��ѧ��:"<<endl;
		int n;
		int s=0;
		cin>>a;
		for (k=a;*k!='\0';k++)
			if (((*k<'0')||(*k>'9')))
			{
				t=true;
				break;
			}
		while (t)
		{
			cout<<"�������"<<endl;
			system("pause");
			system("cls");
			cout<<"��������Ҫ�޸ĵ�ѧ��ѧ��:";
			cin>>a;
			for (k=a;*k!='\0';k++)
			if (((*k<'0')||(*k>'9'))) 
			{
				t=true;
				break;
			}
			if (*k=='\0') t=false;
		}
		n=atoi(a);
		while (p)
		{
			if (p->data.Snum==n)
			{
				output(p->data);
				cout<<"�������޸ĺ������:"<<endl;
				p->data.Snum=-1;
				strcpy(p->data.Sname,"");
				p->data=input();
				s=1;
				cout<<"�޸ĳɹ�"<<endl;
				system("pause");
				break;
			}
			p=p->pNext;
		}
		if (!s) 
		{
			cout<<"δ�ҵ�������,����������"<<endl;
			system("pause");
			Modify();
		}
		cout<<"�Ƿ�����޸ģ�Y��N��:";
		cin>>c;
		while ((c!='n')&&(c!='N')&&(c!='y')&&(c!='Y'))
		{
			cout<<"������Ч�����������롣"<<endl;
			cin>>c;
		}
	}
	while ((c=='y')||(c=='Y'));
}
void FindNum()
{
	char a[50];
	char *k=NULL;
	bool t=false;
	if (!g_pHead)
	{
		cout<<"����Ϊ��"<<endl;
		system("pause");
		return;
	}
	SNode *p=g_pHead;
	cout<<"��������Ҫ���ҵ�ѧ��ѧ��:"<<endl;
	int n;
	int s=0;
	cin>>a;
	for (k=a;*k!='\0';k++)
		if (((*k<'0')||(*k>'9')))
		{
			t=true;
			break;
		}
	while (t)
	{
		cout<<"�������"<<endl;
		system("pause");
		system("cls");
		cout<<"��������Ҫ���ҵ�ѧ��ѧ��:";
		cin>>a;
		for (k=a;*k!='\0';k++)
		if (((*k<'0')||(*k>'9'))) 
		{
			t=true;
			break;
		}
		if (*k=='\0') t=false;
	}
	n=atoi(a);	
	cout<<"������:"<<endl;
	while (p)
	{
		if (p->data.Snum==n)
		{
			output(p->data);
			s=1;			
		}
		p=p->pNext;
	}
	if (s==1)
		system("pause");
	if (!s) 
	{
		system("cls");
		cout<<"δ�ҵ�������,����������"<<endl;
		system("pause");
		FindNum();
	}
}
void FindName()
{
	char b[50];
	char *k=NULL;
	bool t=false;
	if (!g_pHead)
	{
		cout<<"����Ϊ��"<<endl;
		system("pause");
		return;
	}
	SNode *p=g_pHead;
	cout<<"��������Ҫ���ҵ�ѧ������:"<<endl;
	char n[50];
	int s=0;
	cin>>b;
	for (k=b;*k!='\0';k++)
		if ((*k>='0')&&(*k<='9')) 
		{
			t=true;
			break;
		}
	if (*k=='\0') t=false;
	while (t)
	{
		cout<<"�������"<<endl;
		system("pause");
		system("cls");
		cout<<"��������Ҫ���ҵ�ѧ������:";
		cin>>b;
		for (k=b;*k!='\0';k++)
		if (((*k<'0')||(*k>'9'))) 
		{
			t=true;
			break;
		}
		if (*k=='\0') t=false;
	}
	strcpy(n,b);
	cout<<"������:"<<endl;
	while (p)
	{
		if (strcmp(p->data.Sname,n)==0)
		{
			output(p->data);
			s=1;
		}
		p=p->pNext;
	}
	if (s==1)
		system("pause");
	if (!s) 
	{
		system("cls");
		cout<<"δ�ҵ�������,����������"<<endl;
		system("pause");
		FindName();
	}
}
void Find1()
{
	char a[20];
	char *k=NULL;
	bool t=false;
	if (!g_pHead)
	{
		cout<<"����Ϊ��"<<endl;
		system("pause");
		return;
	}
	SNode *p=g_pHead;
	cout<<"��������Ҫ���ҵ�ѧ���ɼ�1:"<<endl;
	int n;
	int s=0;
	cin>>a;
	for (k=a;*k!='\0';k++)
		if (((*k<'0')||(*k>'9')))
		{
			t=true;
			break;
		}
	while (t)
	{
		cout<<"�������"<<endl;
		system("pause");
		system("cls");
		cout<<"��������Ҫ���ҵ�ѧ���ɼ�1:";
		cin>>a;
		for (k=a;*k!='\0';k++)
		if (((*k<'0')||(*k>'9'))) 
		{
			t=true;
			break;
		}
		if (*k=='\0') t=false;
	}
	n=atoi(a);
	cout<<"������:"<<endl;
	while (p)
	{
		if (p->data.Smath==n)
		{
			output(p->data);
			s=1;
		}
		p=p->pNext;
	}
	if (s==1)
		system("pause");
	if (!s) 
	{
		system("cls");
		cout<<"δ�ҵ�������,����������"<<endl;
		system("pause");
		Find1();
	}
}
void Find2()
{
	char a[20];
	char *k=NULL;
	bool t=false;
	if (!g_pHead)
	{
		cout<<"����Ϊ��"<<endl;
		system("pause");
		return;
	}
	SNode *p=g_pHead;
	cout<<"��������Ҫ���ҵ�ѧ���ɼ�2:"<<endl;
	int n;
	int s=0;
	cin>>a;
	for (k=a;*k!='\0';k++)
		if (((*k<'0')||(*k>'9')))
		{
			t=true;
			break;
		}
	while (t)
	{
		cout<<"�������"<<endl;
		system("pause");
		system("cls");
		cout<<"��������Ҫ���ҵ�ѧ���ɼ�2:";
		cin>>a;
		for (k=a;*k!='\0';k++)
		if (((*k<'0')||(*k>'9'))) 
		{
			t=true;
			break;
		}
		if (*k=='\0') t=false;
	}
	n=atoi(a);
	while (p)
	{
		if (p->data.Sengl==n)
		{
			cout<<"������:"<<endl;
			output(p->data);
			s=1;
		}
		p=p->pNext;
	}
	if (s==1)
		system("pause");
	if (!s) 
	{
		system("cls");
		cout<<"δ�ҵ�������,����������"<<endl;
		system("pause");
		Find2();
	}
}
void Find3()
{
	char a[20];
	char *k=NULL;
	bool t=false;
	if (!g_pHead)
	{
		cout<<"����Ϊ��"<<endl;
		system("pause");
		return;
	}
	SNode *p=g_pHead;
	cout<<"��������Ҫ���ҵ�ѧ���ɼ�3:"<<endl;
	int n;
	int s=0;
	cin>>a;
	for (k=a;*k!='\0';k++)
		if (((*k<'0')||(*k>'9')))
		{
			t=true;
			break;
		}
	while (t)
	{
		cout<<"�������"<<endl;
		system("pause");
		system("cls");
		cout<<"��������Ҫ���ҵ�ѧ���ɼ�3:";
		cin>>a;
		for (k=a;*k!='\0';k++)
		if (((*k<'0')||(*k>'9'))) 
		{
			t=true;
			break;
		}
		if (*k=='\0') t=false;
	}
	n=atoi(a);
	cout<<"������:"<<endl;
	while (p)
	{
		if (p->data.Schin==n)
		{
			output(p->data);
			s=1;
		}
		p=p->pNext;
	}
	if (s==1)
		system("pause");
	if (!s) 
	{
		system("cls");
		cout<<"δ�ҵ�������,����������"<<endl;
		system("pause");
		Find3();
	}
}
bool testnum(int n)
{
	SNode *p=g_pHead;
	while (p)
	{
		if (p->data.Snum==n) return false;
		p=p->pNext;
	}
	return true;
}
bool testname(char c[])
{
	SNode *p=g_pHead;
	while (p)
	{
		if (strcmp(p->data.Sname,c)==0) return false;
		p=p->pNext;
	}
	return true;
}
void Search()//����
{
	char c,p;
	do
	{
		system("cls");
		cout<<"1.��ѧ�Ų���"<<endl;
		cout<<"2.����������"<<endl;
		cout<<"3.���ɼ�1����"<<endl;
		cout<<"4.���ɼ�2����"<<endl;
		cout<<"5.���ɼ�3����"<<endl;
		cout<<"6.������һ���˵�"<<endl;
		cout<<"7.�������˵�"<<endl;
		int i;
		cout<<"������������:";
		cin>>p;
		i=judgenum(p);
		while ((i<1)||(i>7))
		{
			cout<<"������Ч�����������롣"<<endl;
			cin>>p;
			i=judgenum(p);
		}
		switch (i)
		{
		case 1:
			FindNum();
			break;
		case 2:
			FindName();
			break;
		case 3:
			Find1();
			break;
		case 4:
			Find2();
			break;
		case 5:
			Find3();
			break;
		case 6:case 7:
			Menu();
			return;
		}
		cout<<"�Ƿ�������ң�Y��N��:";
		cin>>c;
		while ((c!='n')&&(c!='N')&&(c!='y')&&(c!='Y'))
		{
			cout<<"������Ч�����������롣"<<endl;
			cin>>c;
		}
	}
	while ((c=='y')||(c=='Y'));
}
void leave()//��ֹ�ڴ�й©
{
	system("cls");
	SNode *p=g_pHead;
	while (g_pHead)
	{
		p=g_pHead->pNext;
		free(g_pHead);
		g_pHead=p;
	}
	cout<<"�˳��ɹ�"<<endl;
	system("pause");
}
void Menu()//���˵�
{
	system("cls");
	cout<<"1.���������Ϣ"<<endl;
	cout<<"2.�����Ϣ"<<endl;
	cout<<"3.ɾ����Ϣ"<<endl;
	cout<<"4.�޸���Ϣ"<<endl;
	cout<<"5.������Ϣ"<<endl;
	cout<<"6.������Ϣ"<<endl;
	cout<<"7.�˳�"<<endl;
	int i=0;
	char p;
	do
	{
		cout<<"������������:";
		cin>>p;
		i=judgenum(p);
		if ((i<1)||(i>7)) cout<<"������Ч�����������롣"<<endl;
	}
	while ((i<1)||(i>7));
	switch (i)
	{
		case 1:
			Browse();//���
			break;
		case 2:
			Insert();//����
			break;
		case 3:
			Delete();//ɾ��
			break;
		case 4:
			Modify();//�޸�
			break;
		case 5:
			Search();//����
			break;
		case 6:
			Sort();//����
			break;
		default:
			leave();
			exit(0);
			return;
	}
}
int judgenum(char h)
{
	if ((h<'0')||(h>'9')) return -1;
	else return h-'0';
}
int main(int argc, char* argv[])
{
	while (1)
		Menu();
	return 0;
}
/*
1.��֤�������Ч�ԣ�ѧ���Ƿ��ظ��������ظ�ʱ����ʾ��ʾ��Ϣ��
2.�������Ŀ����ԣ�ɾ���޸�ǰ��ʾ�ֶΣ������ɺ���ʾ�ֶΣ�
3.�ļ����������
4.ɾ����ʽ�Ķ����ԣ�����ѧ�š��������ɼ�1��2��3ɾ����
5.����ʽ�Ķ����ԣ�������ͬʱ����ѧ������ȵ�)
6.�����ܷ֡�ÿ��ƽ���֡�ÿ��ƽ����
7.���ʱ�����ͷ
*/