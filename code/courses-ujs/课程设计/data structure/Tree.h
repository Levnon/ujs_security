#pragma once
#ifndef TREE_HEADER
#define TREE_HEADER
#include <graphics.h>//EasyXͼ�ο��ļ�
#include "Status.h"
#include "TreeNode.h"
#include "LinkQueue.h"
class Tree
{
private:
	struct TreeNode *root;//�����
public:
	Tree();//�޲ι��캯��
	Tree(DATA &d);//�вι��캯��
	virtual ~Tree();//��������
	Status Init();//��ʼ����������ʼ����
	void Menu();//��ʼ����
protected:
	//��������
	int  GetGeneration(TreeNode *r);//���ؽ���ǵڼ���
	int GetNumber(TreeNode *r);//���ؽ����һ���еĵڼ���
	TreeNode *GetParent(TreeNode *r);//���ؽ���˫�׽ڵ�
	void LOrder();//�������
	void NOrder(TreeNode *r);//��ͨ����
	void Print(TreeNode *r );
	Status GetNode(string name, struct TreeNode *&node,struct TreeNode *r)const;//ͨ���������ҽ��
	Status Saving();//��������浽�ļ���
	Status Insert(struct TreeNode *tn, string ParentName);//�����µĽ��
	void Delete(TreeNode *&node);//ɾ�����
	void Enquire_Generation(int gen);
	/*
		�����˵��ڲ�ʵ�ֵķ���
	*/
	void Choice();//���˵�
	void Menu_1();//һ���˵�����ʾ��
	void Menu_2();//�����˵�����ӣ�
	void Menu_3();//�����˵����޸ģ�
	void Menu_4();//�ļ��˵���ɾ����
	void Menu_5();//�弶�˵�����ѯ��
	void Menu_6();//�����˵����˳���
	void Menu_7();//�߼��˵����ָ�Ĭ�ϣ�
	/*
		�Ӳ˵�
	*/
	void Menu_3_1(TreeNode*&node);//�����Ӳ˵����޸�����
	void Menu_3_2(TreeNode*&node);//�����Ӳ˵����޸�����
	void Menu_3_3(TreeNode*&node);//�����Ӳ˵����޸�����
	//
	void Menu_5_1();//�弶�Ӳ˵��а�������ѯ
	void Menu_5_2();//�弶�Ӳ˵��а�����ѯ
	void Menu_5_3();//�弶�Ӳ˵��в�ѯ����
	void Menu_5_4();//�弶�Ӳ˵��в�ѯ����
	void Menu_5_5();//�弶�Ӳ˵��в�ѯ�ֵ�
};
TreeNode *Tree::GetParent(TreeNode *r)
{
	LinkQueue<TreeNode *>q;
	TreeNode *p = NULL;
	TreeNode *temp;
	if (r==NULL||r==root)
	{
		return NULL;
	}
	if (root)
	{
		q.EnQueue(root);
	}
	while (!q.IsEmpty())
	{
		q.DelQueue(p);
		TreeNode *t = p->FirstChild;
		while (t)
		{
			if (t == r) return p;
			t = t->NextSibling;
		}
		if (p->FirstChild)
		{
			q.EnQueue(p->FirstChild);
		}
		temp = p->FirstChild;
		while (temp&&temp->NextSibling)
		{
			q.EnQueue(temp->NextSibling);
			temp = temp->NextSibling;
		}

	}
}
int Tree::GetGeneration(TreeNode *r)
{
	int sum = 0;
	if (r==root)
	{
		return 1;
	}
	else
	{
		TreeNode *p = GetParent(r);
		return GetGeneration(p)+1;
	}
}
void Tree::LOrder()
{
	system("cls");
	LinkQueue<TreeNode *>q;
	TreeNode *p=NULL;
	TreeNode *temp;
	if (root)
	{
		q.EnQueue(root);
	}
	while (!q.IsEmpty())
	{
		q.DelQueue(p);
		TreeNode *t = GetParent(p);
		cout << p->data.MemName << " " << p->data.BirthYear << " " << p->data.DeathYear;
		if (p!=root)
		{
			cout << " " << t->data.MemName;
		} 
		cout << endl;
		if (p->FirstChild)
		{
			q.EnQueue(p->FirstChild);
		}
		temp = p->FirstChild;
		while (temp&&temp->NextSibling)
		{
			q.EnQueue(temp->NextSibling);
			temp = temp->NextSibling;
		}

	}
}
Tree::Tree()
{
	root =NULL;
}
Tree::Tree(DATA &d)
{
	root = new struct TreeNode(d);
}
Tree::~Tree()
{
	delete root;
}
Status Tree::GetNode(string name, struct TreeNode *&node, struct TreeNode *r)const
{
	LinkQueue<TreeNode *>q;
	TreeNode * p=NULL;
	TreeNode * temp;
	if (r)
	{
		q.EnQueue(root);
	}
	while (!q.IsEmpty())
	{
		q.DelQueue(p);
		//
		string d = "";
		p->GetName(d);
		if (d==name)
		{
			node = p;
			return SUCCESS;
		}
		//

		if (p->FirstChild)
		{
			q.EnQueue(p->FirstChild);
		}
		temp = p->FirstChild;
		while (temp&&temp->NextSibling)
		{
			q.EnQueue(temp->NextSibling);
			temp = temp->NextSibling;
		}

	}
	
	return FAILURE;
}
void Tree::NOrder(TreeNode *r)
{
	//_asm int 3
	if (r)
	{
		
		/*if (GetGeneration(r) > 2)
		{
			for (int j = 2; j < GetGeneration(r); j++)
			{
				cout << "        ";
			}
		}
			*/
	
			cout << r->data.MemName << endl ;
	}
	else 
		return;
	
	
	if (r->FirstChild)
	{
		TreeNode *p = r->FirstChild;
		
		
		
		while (p)
		{
			cout << "|";
			for (int i = 1; i < GetGeneration(p);i++)
			{
				cout << "����������";
				//cout << "\t";
			}
			
			NOrder(p);
			
			p = p->NextSibling;
			//cout << endl;

		}
	}

}
void Tree::Print(TreeNode *r)
{
	if (!r)
	{
		return;
	}
	else
	{
		int width = 1551;
		int height = 695;
		initgraph(width, height, NOCLOSE | NOMINIMIZE );

		loadimage(NULL, L"G:\\VS\\C++\\subject designing\\INHERITANCE_OF_KING\\INHERITANCE_OF_KING\\03j58PICcrW.jpg", width, height, false);
		setbkcolor(WHITE);
		HWND hWnd = GetHWnd();//��ô��ھ��
		SetWindowTextW(hWnd, L"���Ĵ��С������ݽṹ�γ����");//���ô��ڱ���
		settextcolor(GREEN);
		//int i = 0;
		//int gen = GetGeneration(r);
		BeginBatchDraw();//��ʼ������ͼ

		LinkQueue<TreeNode *>q;
		TreeNode *p = NULL;
		TreeNode *temp;
		if (root)
		{
			q.EnQueue(root);
		}
		while (!q.IsEmpty())
		{
			q.DelQueue(p);
			//TreeNode *t = GetParent(p);
			//if (GetGeneration(p) == gen)
			{
				int y = 90 * GetGeneration(p) + 15;
				//i++;
				int x = 92 * GetNumber(p) + 30;
				CString name;
				name=p->data.MemName.c_str();
				outtextxy(x, y, name);
			}

			if (p->FirstChild)
			{
				q.EnQueue(p->FirstChild);
			}
			temp = p->FirstChild;
			while (temp&&temp->NextSibling)
			{
				q.EnQueue(temp->NextSibling);
				temp = temp->NextSibling;
			}


		}
		FlushBatchDraw();//ִ��δ��ɵĻ�ͼ����
			//return i;
		setlinecolor(MAGENTA);
		LinkQueue<TreeNode *>r;
		TreeNode *s = NULL;
		TreeNode *te;
		if (root)
		{
			r.EnQueue(root);
		}
		while (!r.IsEmpty())
		{
			r.DelQueue(s);
			//TreeNode *t = GetParent(s);
			//if (GetGeneration(p) == gen)
			TreeNode *t = s->FirstChild;
			while (t)
			{
				//int y = 90 * GetGeneration(s) + 15;
				//i++;
				//int x = 92 * GetNumber(s) + 30;
				//CString name;
				//name = s->data.MemName.c_str();
				//outtextxy(x, y, name);
				int x_x = 92 * GetNumber(s) + 50;
				int y_x = 90 * GetGeneration(s) + 29;
				int x_y = 92 * GetNumber(t) + 52;
				int y_y = 90 * GetGeneration(t) + 22;
				line(x_x, y_x, x_y, y_y);





				t = t->NextSibling;
			}

			if (s->FirstChild)
			{
				r.EnQueue(s->FirstChild);
			}
			te = s->FirstChild;
			while (te&&te->NextSibling)
			{
				r.EnQueue(te->NextSibling);
				te = te->NextSibling;
			}


		}

		FlushBatchDraw();//ִ��δ��ɵĻ�ͼ����


		EndBatchDraw();//����������ͼ

		char c = 0;
		while (c != 27)//������Escʱ����
		{
			c = _getch();
		}

		
		

		//_getch();

		closegraph();
	}
}
int Tree::GetNumber(TreeNode *r)
{
	int i = 0;
	int gen = GetGeneration(r);
	LinkQueue<TreeNode *>q;
	TreeNode *p = NULL;
	TreeNode *temp;
	if (root)
	{
		q.EnQueue(root);
	}
	while (!q.IsEmpty())
	{
		q.DelQueue(p);
		TreeNode *t = GetParent(p);
		if (GetGeneration(p) == gen)
		{
			
			i++;
			if (p==r)
			{
				break;
			}
		}

		if (p->FirstChild)
		{
			q.EnQueue(p->FirstChild);
		}
		temp = p->FirstChild;
		while (temp&&temp->NextSibling)
		{
			q.EnQueue(temp->NextSibling);
			temp = temp->NextSibling;
		}
		

	}
	return i;
}
Status Tree::Insert(struct TreeNode *tn,string ParentName)
{
	if (!root)
	{
		root = tn;
		return SUCCESS;
	} 
	else
	{
		struct TreeNode *p = root;
		struct TreeNode *q = root;
		struct TreeNode *node=NULL;
		if (GetNode(ParentName,node,root)==SUCCESS)
		{
			if (node->FirstChild)
			{
				p = node->FirstChild;
				/*while (p->NextSibling)
				{
					p = p->NextSibling;
				}
				p->NextSibling = tn;
				tn->NextSibling = NULL;*/
				while (p&&p->data.BirthYear<=tn->data.BirthYear)
				{
					q = p;
					p=p->NextSibling;
				}
				if (p)
				{
					if (p==node->FirstChild)
					{
						node->FirstChild = tn;
						tn->NextSibling = p;
					}
					q->NextSibling = tn;
					tn->NextSibling = p;
				}
				else 
				{
					q->NextSibling = tn;
					tn->NextSibling = NULL;
				}
				return SUCCESS;
			}
			else
			{
				node->FirstChild = tn;
				return SUCCESS;
			}
		} 
		else
		{
			return FAILURE;
		}


	}
}
void Tree::Delete(TreeNode *&node)
{
	
	if (node->FirstChild==NULL)
	{
		if (node==root)
		{
			delete node;
			root = NULL;
			return;
		}
		TreeNode *p = GetParent(node);
		TreeNode*q = p->FirstChild;
		TreeNode *t = node;
		if (q == node)
		{
			p->FirstChild = q->NextSibling;
			delete q;
			return;
		}
		while (q != node)
		{
			t = q;
			q = q->NextSibling;
		}
		t->NextSibling = q->NextSibling;
		delete q;
		return;
	}
	else
	{
		TreeNode*temp = node->FirstChild;
		TreeNode*q ;
		while (temp)
		{
			q = temp->NextSibling;
			delete temp;
			temp = q;
		}
		node->FirstChild = NULL;
		if (node==root)
		{
			delete node;
			root = NULL;
			return;
		}
		TreeNode *p = GetParent(node);
		q = p->FirstChild;
		TreeNode *t=node;
		if (q==node)
		{
			p->FirstChild = q->NextSibling;
			delete q;
			return;
		}
		while (q!=node)
		{
			t = q;
			q = q->NextSibling;
		}
		t->NextSibling = q->NextSibling;
		delete q;
	}
	return;
}
Status Tree::Init()
{
	ifstream fin("G:\\VS\\C++\\subject designing\\Genghis Khan.txt", ios::in);
	if (!fin)
		return FAILURE;
	else
	{
		string name1,name2=" ";
		int y1, y2;
		fin >> name1 >> y1 >> y2;
		DATA dr = { name1, y1, y2 };
		struct TreeNode *p = new struct TreeNode(dr);
		Insert(p,name2);
		
		while (!fin.eof())
		{
			fin >> name1 >> y1 >> y2 >> name2;
			DATA d = { name1, y1, y2 };
			struct TreeNode *p1 = new struct TreeNode(d);
			Insert(p1, name2);
		}

		fin.close();
		//NOrder(root);
		//cout << root->data.BirthYear << "\t" << root->data.DeathYear << endl;
		return SUCCESS;
	}
}
Status Tree::Saving()
{
	ofstream fout("G:\\VS\\C++\\subject designing\\test.txt", ios::out);
	if (!fout)
	{
		return FAILURE;
	}
	LinkQueue<TreeNode *>q;
	TreeNode *p = NULL;
	TreeNode *temp;
	if (root)
	{
		q.EnQueue(root);
	}
	while (!q.IsEmpty())
	{
		q.DelQueue(p);
		TreeNode *t = GetParent(p);
		fout << p->data.MemName << " " << p->data.BirthYear << " " << p->data.DeathYear;
		if (p != root)
		{
			fout << " " << t->data.MemName;
		}
		
			
		if (p->FirstChild)
		{
			q.EnQueue(p->FirstChild);
		}
		temp = p->FirstChild;
		while (temp&&temp->NextSibling)
		{
			q.EnQueue(temp->NextSibling);
			temp = temp->NextSibling;
		}

		if (!q.IsEmpty())
		{
			fout << endl;
		}
	}
	fout.close();
	return SUCCESS;
}
void Tree::Enquire_Generation(int gen)
{
	int i = 0;
	system("cls");
	CString str1("��ѯ����������Ϣ����:\n");
	CString str2("����     ����     ����\n");
	CString str = str1 + str2;
	CString temp1, temp2, tt, tem;
	LinkQueue<TreeNode *>q;
	TreeNode *p = NULL;
	TreeNode *temp;
	if (root)
	{
		q.EnQueue(root);
	}
	while (!q.IsEmpty())
	{
		q.DelQueue(p);
		TreeNode *t = GetParent(p);
		if (GetGeneration(p)==gen)
		{
			temp1.Format(L"%d", p->data.BirthYear);
			temp2.Format(L"%d", p->data.DeathYear);
			tt = p->data.MemName.c_str();
			tem = tt + L"     " + temp1 + L"     " + temp2;
			str = str + tem;
			i = 1;
			//cout << p->data.MemName << " " << p->data.BirthYear << " " << p->data.DeathYear << endl;
		}

		if (p->FirstChild)
		{
			q.EnQueue(p->FirstChild);
		}
		temp = p->FirstChild;
		while (temp&&temp->NextSibling)
		{
			q.EnQueue(temp->NextSibling);
			temp = temp->NextSibling;
		}
		if (!q.IsEmpty() && GetGeneration(p) == gen)
		{
			str = str + L"\n";
		}
		
	}
	if (i == 0)
	{
		::MessageBoxW(NULL, L"δ��ѯ��!", L"ע��", MB_ICONERROR | MB_OK);
		return;
	}
	else
	{
		
		::MessageBoxW(NULL, str, L"��ѯ���", MB_ICONINFORMATION | MB_OK);
		return;
	}
}
void Tree::Menu()
{
	system("cls");//����
	/*
	
	��ӡϵͳ��ʼ��ӭ����

	*/
	cout << endl << endl << endl << endl;
	cout << "\t\t\t*********************************" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*         ��ӭ����ϵͳ          *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*********************************" << endl;
	/*
	��ӡϵͳʱ��
	*/
	SYSTEMTIME sy;
	GetLocalTime(&sy);//��ȡϵͳʱ��
	cout << "\t\t\t  " << sy.wYear << "��" << sy.wMonth << "��" << sy.wDay << "��" << endl;//��ӡ����
	cout << "\t\t\t  " << sy.wHour << ":" << sy.wMinute << ":" << sy.wSecond<<endl;//��ӡʱ��
	Sleep(1000);//��ͣ1��
	Choice();//����ϵͳ���˵�
}
void Tree::Choice()
{
LOOP2:	system("cls");//����
	/*
	��ӡϵͳ���˵�����
	
	*/
	cout << endl << endl << endl << endl;
	cout << "\t\t\t*********************************" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*         ��1.��ʾ����          *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*         ��2.��ӳ�Ա          *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*         ��3.�޸ĳ�Ա          *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*         ��4.ɾ����Ա          *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*         ��5.��ѯ��Ϣ          *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*         ��6.�˳�ϵͳ          *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*         ��7.�ָ�Ĭ��          *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*********************************" << endl;
	/*
	
	��ӡϵͳʱ��
	*/
	SYSTEMTIME sy;
	GetLocalTime(&sy);//��ȡϵͳʱ��
	cout << "\t\t\t  " << sy.wYear << "��" << sy.wMonth << "��" << sy.wDay << "��" << endl;//��ӡ����
	cout << "\t\t\t  " << sy.wHour << ":" << sy.wMinute << ":" << sy.wSecond << endl;//��ӡʱ��
	char c=0;
	//c = _getch();//����������
	while (c<'1' || c>'7')//������ǲ˵��е���ȷѡ��
	{
		fflush(stdin);//������뻺����
		c = _getch();//���´Ӽ��̻�ȡ������ַ�
		//goto LOOP2;
	}
	int selected = c - '0';//���ַ�ת��Ϊ�˵��ж�Ӧ������
	switch (selected)//����ѡ��Ĳ˵���Ŀ��ת����Ӧ���Ӳ˵�����ִ����Ӧ�Ĺ���
	{
	case 1:
		Menu_1();
		break;
	case 2:
		Menu_2();
		break;
	case 3:
		Menu_3();
		break;
	case 4:
		Menu_4();
		break;
	case 5:
		Menu_5();
		break;
	case 6:
		Menu_6();
		break;
	case 7:
		Menu_7();
		break;
	default:
		break;
	}
	goto LOOP2;//���˵����������˳��������û�Ҫ���˳�
}
void Tree::Menu_1()
{
	system("cls");//����
	if (root==NULL)//����㲻����
	{
		::MessageBoxW(NULL, L"�������Ѳ������κν��", L"��ʾ", MB_ICONWARNING | MB_OK);
		return;
	}
//	NOrder(root);//���δ�ӡÿ�����
	//LOrder();
	Print(root);
	
	return;
	
	
}
void Tree::Menu_6()
{
	
		int n6 = ::MessageBoxW(NULL, L"�Ƿ񱣴�", L"��ʾ", MB_ICONQUESTION | MB_YESNOCANCEL);//��ʾ�Ƿ񱣴�
		if (n6 == IDYES)//�û����±����
		{
			Status s = Saving();//���б������
			if (s == FAILURE)//����ʧ�ܣ����ʧ����Ϣ
				::MessageBoxW(NULL, L"����ʧ��", L"ע��", MB_ICONERROR | MB_OK);
			else//����ɹ�������ɹ���Ϣ
				::MessageBoxW(NULL, L"�ѱ���", L"��ʾ", MB_ICONINFORMATION | MB_OK);
			exit(0);//�˳�ϵͳ
		}
		else if (n6==IDNO)//�û�������
		{
			exit(1);//ֱ���˳�ϵͳ
		} 
		else//�û������˳�ϵͳ
		{
			return;//�����������˵�
		}
	
}
void Tree::Menu_7()
{
	int nRe7 = ::MessageBoxW(NULL, L"�Ƿ�ָ�Ĭ��ֵ��", L"��ʾ", MB_ICONQUESTION | MB_YESNO);//��ʾ�û��Ƿ�ָ�Ĭ��ֵ
	if (nRe7 == IDYES)//�û�ѡ����
	{
		Delete(root);//���������
		Status s = Init();//���´��ļ������벢������������
		if (s == FAILURE)//����ʧ�ܣ���ʾ������Ϣ���˳�ϵͳ
		{
			::MessageBoxW(NULL, L"�ָ�Ĭ��ʧ��", L"ע��", MB_ICONERROR | MB_OK);
			exit(1);
		}
		else//����ɹ�����ʾ�ɹ���Ϣ
		{
			::MessageBoxW(NULL, L"�ѻָ�Ĭ��ֵ", L"��ʾ", MB_ICONINFORMATION | MB_OK);
			return;
		}
	}
	else
		return;//���ָ�Ĭ�ϣ�ֱ�ӷ������˵�
}
void Tree::Menu_2()
{
LOOP1:	system("cls");//����
	string name1, name2;//�Լ������֣����׵�����
	int year1, year2;//���꣬����
	/*
	��ӡ����Ľ���

	*/
	cout << endl << endl << endl << endl;
	cout << "\t\t\t*********************************" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*         �V��������" ;
	cin >> name1;//����Ҫ��ӵ��˵�����
	cout << "\t\t\t*         �U                    *" << endl;
	cout << "\t\t\t*         �U                    *" << endl;
	cout << "\t\t\t*         �U�����꣺" ;
	cin >> year1;//����Ҫ��ӵ��˵�����
	cout << "\t\t\t*         �U                    *" << endl;
	cout << "\t\t\t*         �U                    *" << endl;
	cout << "\t\t\t*         �U�����꣺";
	cin >> year2; //����Ҫ��ӵ��˵�����
	cout << "\t\t\t*         �U                    *" << endl;
	cout << "\t\t\t*         �U                    *" << endl;
	cout << "\t\t\t*         �\����������" ;
	cin >> name2;//����Ҫ��ӵ��˵ĸ�������
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*********************************" << endl;
	/*
	ƴ���ַ�������string��int����ȫ��ת��ΪCString����
	�ѽ�Ҫ��ӵ��˵���Ϣ�Ե�������ʽչ������Ļ�ϣ�Ҫ���û�ȷ���Ƿ����
	*/
	CString str1("������Ϣ����:\n");
	CString str2("������"), str3("���꣺"), str4("���꣺"),str5("����������"),temp1,temp2,tt1,tt2;
	temp1.Format(L"%d", year1);
	temp2.Format(L"%d", year2);
	tt1 = name1.c_str();
	tt2 = name2.c_str();
	CString cnn("\n");
	CString str = str1 + str2 + tt1 + cnn + str3 + temp1 + cnn + str4 + temp2 + cnn + str5 + tt2;
	int re = ::MessageBoxW(NULL, str, L"�Ƿ�ȷ����ӣ�", MB_ICONQUESTION | MB_YESNO);//������ѯ���û��Ƿ�ȷ�����
	if (re==IDYES)//ѡ���ǣ��������
	{
		DATA d = { name1, year1, year2 };//�ṹ�����
		struct TreeNode *p = new struct TreeNode(d);//�½����
		Insert(p, name2);//���뵽����
	}
	re = ::MessageBoxW(NULL, L"�Ƿ������ӣ�", L"��ʾ", MB_ICONQUESTION | MB_YESNO);//ѯ���û��Ƿ�������
	if (re==IDYES)//ѡ���ǣ���ת��������ͷ����ִ��
	{
		goto LOOP1;
	}
	return;
}
void Tree::Menu_3()
{
LOOP1:	system("cls");//����
	cout << endl << endl << endl << endl;
	cout << "\t\t\t*********************************" << endl;
	cout << "\t\t\t*    ����Ҫ�޸ĵĳ�Ա������";//
	string name;
	cin >> name;//������Ҫ�޸ĵ��˵�����
	TreeNode*node_modify;//��Ҫ�޸ĵĽ��
	Status s = GetNode(name, node_modify, root);//��������Ѱ��������
	if (s==FAILURE)//û�ҵ�����ʾ����
	{
		CString str("δ�ҵ�!"),temp;
		temp = name.c_str();
		str =temp +str ;
		::MessageBoxW(NULL, str, L"ע��", MB_ICONERROR | MB_OK);
		int nRe = ::MessageBoxW(NULL, L"�Ƿ�����޸�", L"��ʾ", MB_ICONQUESTION | MB_YESNO);//������ѯ���Ƿ�����޸�
		if (nRe==IDYES)//ѡ���ǣ��ӱ�����ͷ����ִ��
		{
			goto LOOP1;
		}
		return;
	} 
	else//�ҵ�
	{
		/*
		��ӡ�Ӳ˵������û�ѡ��
		
		*/
		system("cls");
		cout << endl << endl << endl << endl;
		cout << "\t\t\t*********************************" << endl;
		cout << "\t\t\t*                               *" << endl;
		cout << "\t\t\t*                               *" << endl;
		cout << "\t\t\t*                               *" << endl;
		cout << "\t\t\t*         ��1.�޸�����          *" << endl;
		cout << "\t\t\t*                               *" << endl;
		cout << "\t\t\t*                               *" << endl;
		cout << "\t\t\t*                               *" << endl;
		cout << "\t\t\t*         ��2.�޸�����          *" << endl;
		cout << "\t\t\t*                               *" << endl;
		cout << "\t\t\t*                               *" << endl;
		cout << "\t\t\t*                               *" << endl;
		cout << "\t\t\t*         ��3.�޸�����          *" << endl;
		cout << "\t\t\t*                               *" << endl;
		cout << "\t\t\t*                               *" << endl;
		cout << "\t\t\t*                               *" << endl;
		cout << "\t\t\t*                               *" << endl;
		cout << "\t\t\t*********************************" << endl;
		char c = 0;
		while (c<'1'||c>'3')//�����벻��ȷʱ����������
		{
			fflush(stdin);
			c = _getch();
		}
		int select = c - '0';//��������ַ�ת��Ϊ�˵��ж�Ӧ������
		switch (select)//����ѡ�����Ŀ��ת���Ӳ˵������м���ִ��
		{
		case 1:
			Menu_3_1(node_modify);
			break;
		case 2:
			Menu_3_2(node_modify);
			break;
		case 3:
			Menu_3_3(node_modify);
			break;
		default:
			break;
		}
	}
	return;
}
void Tree::Menu_4()
{
LOOP:	system("cls");//����
	cout << endl << endl << endl << endl;
	cout << "\t\t\t*********************************" << endl;
	cout << "\t\t\t*    ����Ҫɾ���ĳ�Ա������";
	string name;
	cin >> name;//������Ҫɾ���ĳ�Ա����
	TreeNode*node_delete;//��ɾ���Ľ��
	Status s = GetNode(name, node_delete, root);//Ѱ��������
	if (s == FAILURE)//û�ҵ�������������Ϣ
	{
		CString str("δ�ҵ�!"), temp;
		temp = name.c_str();
		str = temp + str;
		::MessageBoxW(NULL, str, L"ע��", MB_ICONERROR | MB_OK);
		int nRe = ::MessageBoxW(NULL, L"�Ƿ����ɾ����", L"��ʾ", MB_ICONQUESTION | MB_YESNO);//��ʾ�Ƿ����ɾ��
		if (nRe==IDYES)//ѡ���ǣ���ת����������ͷ����ִ��
		{
			goto LOOP;
		}
		return;
	}
	else//�ҵ��˽��
	{
		/*
		
		�ַ���ƴ�ӣ���������ʾ����ɾ���Ľڵ���Ϣ
		
		���û�ѡ���Ƿ�ȷ��ɾ��
		*/
		CString s1("����ɾ���Ľ�㣺\n"), s2("  ������"), s3("  ���꣺"), s4("  ���꣺");
		CString tem,tt1,tt2,s;
		tem = name.c_str();
		tt1.Format(L"%d", node_delete->data.BirthYear);
		tt2.Format(L"%d", node_delete->data.DeathYear);
		s = s1 + s2 + tem + L"\n" + s3 + tt1 + L"\n" + s4 + tt2 ;
		int n=::MessageBoxW(NULL, s, L"�Ƿ�ȷ��ɾ����", MB_ICONQUESTION | MB_YESNO);//���û�ѡ���Ƿ�ȷ��ɾ��
		if (n==IDNO)//ѡ��񣬲�ɾ��
		{
			int nRe = ::MessageBoxW(NULL, L"�Ƿ����ɾ����", L"��ʾ", MB_ICONQUESTION | MB_YESNO);//��ʾ�Ƿ����ɾ��
			if (nRe == IDYES)
			{
				goto LOOP;
			}
		}

		else//ѡ���ǣ�ɾ�����
		{
			Delete(node_delete);//����ɾ������

			/*
			�ַ���ƴ�ӣ���ʾ�û������ɾ��
			
			*/
			CString str("��ɾ��!"), temp;
			temp = name.c_str();
			str = temp + str;
			::MessageBoxW(NULL, str, L"��ʾ", MB_ICONINFORMATION | MB_OK);
			int nR = ::MessageBoxW(NULL, L"�Ƿ����ɾ����", L"��ʾ", MB_ICONQUESTION | MB_YESNO);//���û�ѡ���Ƿ����ɾ��
			if (nR == IDYES)//�û�ѡ����
			{
				goto LOOP;//ת��������ͷ����ִ��
			}

		}
		
	}

	return;
}
void Tree::Menu_5()
{
	system("cls");//����
	/*
	��ӡ�˵������û�ѡ���ѯ��ʽ
	
	*/
	cout << endl << endl << endl << endl;
	cout << "\t\t\t*********************************" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*         ��1.��������ѯ        *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*         ��2.������ѯ          *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*         ��3.��ѯ����          *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*         ��4.��ѯ����          *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*         ��5.��ѯ�ֵ�          *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*                               *" << endl;
	cout << "\t\t\t*********************************" << endl;
	char c = 0;
	while (c<'1' || c>'5')//������벻�Ϸ�
	{
		
		fflush(stdin);//������뻺����
		c = _getch();//��ȡ������������

		
	}
	int selected = c - '0';//��������ַ�ת��Ϊ����
	switch (selected)//����ѡ��Ĳ˵���ת����Ӧ���Ӳ˵�
	{
	case 1:
		Menu_5_1();
		break;
	case 2:
		Menu_5_2();
		break;
	case 3:
		Menu_5_3();
		break;
	case 4:
		Menu_5_4();
		break;
	case 5:
		Menu_5_5();
		break;
	
	default:
		break;
	}
}
void Tree::Menu_3_1(TreeNode*&node)
{
	system("cls");//����
	cout << endl << endl << endl << endl;
	cout << "\t\t\t*********************************" << endl;
	cout << "\t\t\t*    ���޸ĺ��������";
	string name;
	cin >> name;//�����޸ĺ������
	/*
	�ַ���ƴ��
	
	������Ա��޸�ǰ������ݲ���

	��ʾ�û��Ƿ�ȷ���޸�
	
	*/


	CString str1("        �޸�֮ǰ�����ݣ�   �޸�֮������ݣ�\n"), str2("������"), str3("���꣺"), str4("���꣺"), temp1, temp2,tt1,tt2;
	temp1 = node->data.MemName.c_str();
	temp2 = name.c_str();
	tt1.Format(L"%d", node->data.BirthYear);
	tt2.Format(L"%d", node->data.DeathYear);
	str2 = str2 + temp1 + L"                     " + temp2 + L"\n";
	str3 = str3 + tt1 + L"                    " + tt1 + L"\n";
	str4 = str4 + tt2 + L"                    " + tt2 + L"\n";
	int nRe=::MessageBoxW(NULL, str1 + str2 + str3 + str4, L"�Ƿ�ȷ���޸ģ�", MB_ICONQUESTION | MB_YESNO);//��������ʾ�û�ѡ���Ƿ�ȷ���޸�
	if (nRe == IDYES)//����û�ȷ�����޸�
	{
		node->data.MemName = name;//�����޸�
		int re = ::MessageBoxW(NULL, L"�Ƿ�����޸�?", L"��ʾ", MB_ICONQUESTION | MB_YESNO);//������ѯ���Ƿ�����޸�
		if (re == IDYES)//ѡ���ǣ������޸�
		{
			Menu_3();//�����޸ĺ���
			return;//����
		}
		else
			return;//�������޸ģ�ֱ�ӷ���
	}
	else//�û�δȷ���޸ģ�����
		return;
}
void Tree::Menu_3_2(TreeNode*&node)
{
	system("cls");//����
	cout << endl << endl << endl << endl;
	cout << "\t\t\t*********************************" << endl;
	cout << "\t\t\t*    ���޸ĺ�����꣺";
	int year;
	cin >> year;//�����޸ĺ������
	/*
	
	�ַ���ƴ��
	

	������Ա��޸�ǰ�������


	��ʾ�û�ѡ���Ƿ�ȷ���޸�
	
	*/



	CString str1("        �޸�֮ǰ�����ݣ�   �޸�֮������ݣ�\n"), str2("������"), str3("���꣺"), str4("���꣺"), temp1, temp2, tt1, tt2;
	tt1 = node->data.MemName.c_str();
	temp1.Format(L"%d", node->data.BirthYear);
	temp2.Format(L"%d", year);
	tt2.Format(L"%d", node->data.DeathYear);
	str2 = str2 + tt1 + L"                   " + tt1 + L"\n";
	str3 = str3 + temp1 + L"                    " + temp2 + L"\n";
	str4 = str4 + tt2 + L"                    " + tt2 + L"\n";
	int nRe = ::MessageBoxW(NULL, str1 + str2 + str3 + str4, L"�Ƿ�ȷ���޸ģ�", MB_ICONQUESTION | MB_YESNO);//��������ʾ�û��Ƿ�ȷ���޸�
	if (nRe == IDYES)//�û�ѡ���ǣ��޸�����
	{
		if (node==root)
		{
			node->data.BirthYear = year;
			int Re = ::MessageBoxW(NULL, L"�Ƿ�����޸�?", L"��ʾ", MB_ICONQUESTION | MB_YESNO);//��ʾ�Ƿ�����޸�
			if (Re == IDYES)//ѡ���ǣ������޸�
			{
				Menu_3();
				return;//����
			}
			else
				return;
		}
		else
		{
			TreeNode *pa=GetParent(node);//��ȡ���ĸ��׽��
			TreeNode *p = pa->FirstChild; 
			TreeNode *q=NULL;
			if (p == node)//���Ҫ�޸ĵĽ���ǵ�һ�����ӽ�㣬�Ƚ����׽��ĺ���ָ��ָ�����ĺ�һ�����
			{
				pa->FirstChild = node->NextSibling;
				p = NULL;//��ֹ������һ��ѭ�������쳣
			}
			while (p)
			{

				if (p&&p->NextSibling == node)//������޸ĵĽ��Ϊ��һ�����
				{
					p->NextSibling = node->NextSibling;//���˽����ֵ�ָ��ָ���޸ĵĽ�����һ���ֵ�
					//���ѽ�Ҫ�޸ĵĽ����뿪��
					break;
				} 
				p = p->NextSibling;
			}
			//p = pa->FirstChild;
			
			p = pa->FirstChild;//���¸�ֵp
			if (year<=p->data.BirthYear)//���Ҫ�����λ���ǵ�һ��λ��
			{
				pa->FirstChild = node;
				node->NextSibling = p;//����
				goto LOOP;//��������Ĳ��裬ֱ�ӽ����޸Ĳ���
			}
			while (p)
			{
				q = p;//q���浱ǰ����ǰһ�����
				p = p->NextSibling;//p���浱ǰ���
				
				if (p&&q->data.BirthYear <= year&&p->data.BirthYear >= year)//����޸ĺ������������֮�䣬�����Ӧ�ò����λ��
				{
					q->NextSibling = node;
					node->NextSibling = p;//����
					break;//������ϣ�����ѭ��
				}
			}
			if (!p&&q->data.BirthYear<=year)//���Ҫ�����λ��Ϊ���һ��λ��
			{
				q->NextSibling = node;
				node->NextSibling = NULL;//����
			}
		LOOP:node->data.BirthYear = year;//�޸�����
			int re = ::MessageBoxW(NULL, L"�Ƿ�����޸�?", L"��ʾ", MB_ICONQUESTION | MB_YESNO);//��ʾ�Ƿ�����޸�
			if (re == IDYES)//ѡ���ǣ������޸�
			{
				Menu_3();
				return;//����
			}
			else
				return;

		}
		
	}
	else
		return;
}
void Tree::Menu_3_3(TreeNode*&node)
{
	system("cls");//����
	cout << endl << endl << endl << endl;
	cout << "\t\t\t*********************************" << endl;
	cout << "\t\t\t*    ���޸ĺ�����꣺";
	int year;
	cin >> year;//�����޸ĺ������
	/*
	
	�ַ���ƴ��

	������Ա��޸�ǰ������ݲ���
	
	��ʾ�û�ѡ���Ƿ�ȷ���޸�
	
	*/



	CString str1("        �޸�֮ǰ�����ݣ�   �޸�֮������ݣ�\n"), str2("������"), str3("���꣺"), str4("���꣺"), temp1, temp2, tt1, tt2;
	tt1 = node->data.MemName.c_str();
	temp1.Format(L"%d", node->data.DeathYear);
	temp2.Format(L"%d", year);
	tt2.Format(L"%d", node->data.BirthYear);
	str2 = str2 + tt1 + L"                   " + tt1 + L"\n";
	str3 = str3 + tt2 + L"                    " + tt2 + L"\n";
	str4 = str4 + temp1 + L"                    " + temp2 + L"\n";
	int nRe = ::MessageBoxW(NULL, str1 + str2 + str3 + str4, L"�Ƿ�ȷ���޸ģ�", MB_ICONQUESTION | MB_YESNO);//���������û�ѡ���Ƿ�ȷ���޸�
	if (nRe == IDYES)//ȷ���޸�
	{
		node->data.BirthYear = year;//�޸�����
		int re = ::MessageBoxW(NULL, L"�Ƿ�����޸�?", L"��ʾ", MB_ICONQUESTION | MB_YESNO);//��ʾ�û��Ƿ�����޸�
		if (re == IDYES)//�����޸ģ������޸ĵĺ���
		{
			Menu_3();
			return;//����
		}
		else
			return;
	}
	else
		return;
}
void Tree::Menu_5_1()
{
LOOP3:	system("cls");//����
	cout << endl << endl << endl << endl;
	cout << "\t\t\t*********************************" << endl;  
	cout << "\t\t\t*    ����Ҫ��ѯ��������";
	string name;
	cin >> name;//������Ҫ��ѯ������
	TreeNode *temp = NULL;
	Status s = GetNode(name, temp, root);//�����������ҽ��
	/*
	�ַ���ƴ��

	���û�в�ѯ�ɹ�����������ʾ����

	�����ѯ�ɹ�����������ʾ��ѯ�����Ľ��
	
	
	*/
	CString st;
	st = name.c_str();
	if (s==FAILURE)//��ѯʧ��
	{	
		st = st + L"δ��ѯ����";
		::MessageBoxW(NULL, st, L"ע��", MB_ICONERROR | MB_OK);//��ʾ������Ϣ
		
	}
	else//��ѯ�ɹ�
	{
		CString str1("��ѯ����������Ϣ����:\n");
		CString str2("������"), str3("���꣺"), str4("���꣺"), temp1, temp2, tt1;
		temp1.Format(L"%d", temp->data.BirthYear);
		temp2.Format(L"%d", temp->data.DeathYear);
		tt1 = name.c_str();
		CString cnn("\n");
		CString str = str1 + str2 + tt1 + cnn + str3 + temp1 + cnn + str4 + temp2 + cnn ;
		::MessageBoxW(NULL, str, L"��ʾ", MB_ICONINFORMATION | MB_OK);//��ʾ��ѯ�Ľ��
	}
	//ѯ���Ƿ������ѯ
	int nRet = ::MessageBoxW(NULL, L"�Ƿ������ѯ?", L"��ʾ", MB_ICONQUESTION | MB_YESNO);
	if (nRet == IDYES)//������ѯ
	{
		goto LOOP3;//��ת������ͷ������ִ��
	}
}
void Tree::Menu_5_2()
{
LOOP4:	system("cls");//����
	cout << endl << endl << endl << endl;
	cout << "\t\t\t*********************************" << endl;
	cout << "\t\t\t*    ����Ҫ��ѯ�Ĵ���";
	int generation;
	cin >> generation;//������ĺ���
	Enquire_Generation(generation);//���ݵڼ�����ѯ��Ա��Ϣ
	int nRet = ::MessageBoxW(NULL, L"�Ƿ������ѯ?", L"��ʾ", MB_ICONQUESTION | MB_YESNO);//��������ʾ�Ƿ������ѯ
	if (nRet==IDYES)//������ѯ
	{
		goto LOOP4;//��ת������ͷ����ִ��
	}
}
void Tree::Menu_5_3()
{
LOOP3:	system("cls");//����
	cout << endl << endl << endl << endl;
	cout << "\t\t\t*********************************" << endl;
	cout << "\t\t\t*    ����Ҫ��ѯ�ĳ�Ա������";
	string name;
	cin >> name;//����Ҫ��ѯ������
	TreeNode *temp = NULL;
	Status s = GetNode(name, temp, root);//���������ҵ�������

	/*
	�ַ���ƴ��


	�������ʧ�ܵ���ʧ����Ϣ


	������ҳɹ��������ҽ��
	
	
	*/
	CString st;
	st = name.c_str();
	if (s == FAILURE)
	{
		st = st + L"δ��ѯ����";
		::MessageBoxW(NULL, st, L"ע��", MB_ICONERROR | MB_OK);//������Ϣ

	}
	else
	{
		TreeNode *p = temp->FirstChild;
		CString str1("��ѯ���ĺ�����Ϣ����:\n");
		CString str2("����     ����     ����\n");
		CString str = str1 + str2;
		CString temp1, temp2, tt, tem;
		st = name.c_str();
		st = st + L"û�к���!";
		if (!p)
		{
			::MessageBoxW(NULL,st , L"ע��", MB_ICONERROR | MB_OK);//û�к��ӣ�����

		}
		else
		{
			while (p)
			{
				temp1.Format(L"%d", p->data.BirthYear);
				temp2.Format(L"%d", p->data.DeathYear);
				tt = p->data.MemName.c_str();
				tem = tt + L"     " + temp1 + L"     " + temp2;
				str = str + tem;
				//cout << p->data.MemName << " " << p->data.BirthYear << " " << p->data.DeathYear << endl;

				p = p->NextSibling;
				if (p)
				{
					str = str + L"\n";
				}
			}
			::MessageBoxW(NULL, str, L"��ѯ���", MB_ICONINFORMATION | MB_OK);//��������ʾ��ѯ���
		}
	}
	int nRet = ::MessageBoxW(NULL, L"�Ƿ������ѯ?", L"��ʾ", MB_ICONQUESTION | MB_YESNO);//��ʾ�Ƿ������ѯ
	if (nRet == IDYES)//������ѯ���ӱ�������ͷ����ִ��
	{
		goto LOOP3;
	}
}
void Tree::Menu_5_4()
{
LOOP5:	system("cls");//����
	cout << endl << endl << endl << endl;
	cout << "\t\t\t*********************************" << endl;
	cout << "\t\t\t*    ����Ҫ��ѯ�ĳ�Ա������";
	string name;
	cin >> name;//��ѯ�ĳ�Ա����
	TreeNode *temp = NULL;
	Status s = GetNode(name, temp, root);//�����������ҽ��
	TreeNode *q=GetParent(temp);//�ҵ�������ĸ���

	/*
	�ַ���ƴ��

	�����ѯ�ɹ�����������ʾ��ѯ���Ľ��

	�����ѯʧ�ܣ���������ʾ������Ϣ

	*/


	if (q)
	{
		
		CString str1("��ѯ���ĸ�����Ϣ����:\n");
		CString str2("������"), str3("���꣺"), str4("���꣺"), temp1, temp2, tt1;
		temp1.Format(L"%d", q->data.BirthYear);
		temp2.Format(L"%d", q->data.DeathYear);
		tt1 = q->data.MemName.c_str();
		CString cnn("\n");
		CString str = str1 + str2 + tt1 + cnn + str3 + temp1 + cnn + str4 + temp2 + cnn;
		::MessageBoxW(NULL, str, L"��ʾ", MB_ICONINFORMATION | MB_OK);//��������ʾ��ѯ���



		//cout << q->data.MemName << " " << q->data.BirthYear << " " << q->data.DeathYear << endl;
	
	}
	else
	{
		CString st;
		st = name.c_str();
		st = st + L"û�и���!";
		
		
		::MessageBoxW(NULL, st, L"ע��", MB_ICONERROR | MB_OK);//û�и��ף���ʾ����

		
	}
	int nRet = ::MessageBoxW(NULL, L"�Ƿ������ѯ?", L"��ʾ", MB_ICONQUESTION | MB_YESNO);//��ʾ�Ƿ������ѯ
	if (nRet == IDYES)//������ѯ���ӱ�����ͷ��ʼ��������
	{
		goto LOOP5;
	}
}
void Tree::Menu_5_5()
{
LOOP1:	system("cls");//����
	cout << endl << endl << endl << endl;
	cout << "\t\t\t*********************************" << endl;
	cout << "\t\t\t*    ����Ҫ��ѯ�ĳ�Ա������";
	string name;
	cin >> name;//������Ҫ��ѯ�ĳ�Ա����
	int i = 0;
	TreeNode *temp = NULL;
	Status s = GetNode(name, temp, root);//����������

	/*
	
	�ַ���ƴ��


	���ҳɹ�����������ʾ���ҽ��
	
	
	����ʧ�ܣ���������ʾ������Ϣ

	
	*/


	CString st;
	st = name.c_str();
	if (s == FAILURE)
	{
		st = st + L"δ��ѯ����";
		::MessageBoxW(NULL, st, L"ע��", MB_ICONERROR | MB_OK);//û���ҵ������㣬����

	}
	else
	{
		TreeNode *q = GetParent(temp);//���Ҹ��׽��
		CString str1("��ѯ�����ֵ���Ϣ����:\n");
		CString str2("����     ����     ����\n");
		CString str = str1 + str2;
		CString temp1, temp2, tt, tem;
		if (q)
		{//���ҳɹ�
			q = q->FirstChild;
			while (q)//���α������ĺ��ӽ��
			{
				if (q->data.MemName != name)//���������ҵĽ�㣬Ѱ�������ֵܽڵ�
				{
					temp1.Format(L"%d", q->data.BirthYear);
					temp2.Format(L"%d", q->data.DeathYear);
					tt = q->data.MemName.c_str();
					tem = tt + L"     " + temp1 + L"     " + temp2;
					str = str + tem;
					//cout << q->data.MemName << " " << q->data.BirthYear << " " << q->data.DeathYear << endl;

				}
				q = q->NextSibling;
				if (q&&q->data.MemName == name)
				{
					q = q->NextSibling;
				}
				if (q)
				{
					str = str + L"\n";
				}
			}
			::MessageBoxW(NULL, str, L"��ѯ���", MB_ICONINFORMATION | MB_OK);//��ʾ��ѯ���
	
		}
		else
		{
			::MessageBoxW(NULL, L"��ѯʧ�ܣ�", L"ע��", MB_ICONERROR | MB_OK);//û�и��׽�㣬����
		}
	}
	int nRet = ::MessageBoxW(NULL, L"�Ƿ������ѯ?", L"��ʾ", MB_ICONQUESTION | MB_YESNO);//������ѯ���Ƿ������ѯ
	if (nRet == IDYES)//������ѯ����ת����������ͷ����ִ��
	{
		goto LOOP1;
	}

}
































































#endif



