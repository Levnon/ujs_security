#include <iostream>
#include <string>
#include <queue>
#include <math.h>
using namespace std;
enum Direction{UP,DOWN};
struct Table
{
	string process_name;//������
	int cylinder_num;//�����
	int track_num;//�ŵ���
	int record_num;//�����¼��
};
//queue<Table> q;
//��ʼ��
Table t[100];//= { { "P1", 1, 2, 3 }, { "P2", 1, 3, 4 }, { "P3", 2, 4, 3 } };
int table_num=0;//= 3;
Direction current_direction = UP;//��ǰ����
int current_cylinder = 0;//��ǰ�����
//int current_track = 0;//��ǰ�ŵ���
int current_record = 0;//��ǰ��¼��

/*



*/
void DriverModify()
{
	int tag=-1;
	int i = 0;
	int num = -1;
	if (table_num>0)//����I/O��������
	{
		for (i = 0; i < table_num;i++)//����
		{
			if (t[i].cylinder_num==current_cylinder)//�뵱ǰ������ͬ
			{
				int tem = abs(t[i].record_num - current_record);//��ת����
				if (num==-1||num>tem)//�ҳ���̵���ת����
				{
					tag = i;
					num = tem;
				}
			}
		}
		if (num>=0)
		{
			current_cylinder = t[tag].cylinder_num;
			current_record = t[tag].record_num;
			cout << "����IO��"<<endl;
			for (i = 0; i < table_num;i++)
			{
				cout << t[i].process_name << " " << t[i].cylinder_num << " " << t[i].track_num << " " << t[i].record_num << endl;
			}
			cout << "��ǰ�Ʊ۷���:" << current_direction << endl;
			cout << "��ǰ����ţ�" << current_cylinder << endl;
			cout << "��ǰ�����¼�ţ�" << current_record << endl; 
			table_num--;
			for (i = tag; i < table_num;i++)
			{
				t[i] = t[i + 1];
			}
		}
		//û���뵱ǰ������ͬ�ķ�����
		else if (current_direction==UP)//�Ʊ۷�������
		{
			for (i = 0; i < table_num;i++)//����
			{
				if (t[i].cylinder_num>current_cylinder)//�ȵ�ǰ����Ŵ������
				{
					int tem = t[i].cylinder_num;
					if (num == -1 || num > tem)//����С��
					{
						tag = i;
						num = tem;
					}
				}
			}
			if (num>=0)
			{
				current_cylinder = t[tag].cylinder_num;
				current_record = t[tag].record_num;
				cout << "����IO��"<<endl;
				for (i = 0; i < table_num; i++)
				{
					cout << t[i].process_name << " " << t[i].cylinder_num << " " << t[i].track_num << " " << t[i].record_num << endl;
				}
				cout << "��ǰ�Ʊ۷���:" << current_direction << endl;
				cout << "��ǰ����ţ�" << current_cylinder << endl;
				cout << "��ǰ�����¼�ţ�" << current_record << endl;
				table_num--;
				for (i = tag; i < table_num; i++)
				{
					t[i] = t[i + 1];
				}

			}
			else//û�бȵ�ǰ����Ŵ������
			{
				num = -1;
				current_direction = DOWN;//�Ʊ۷�����Ϊ����
				for (i = 0; i < table_num; i++)
				{
					if (t[i].cylinder_num<current_cylinder)//�ȵ�ǰ�����С������
					{
						int tem = t[i].cylinder_num;
						if (num == -1 || num < tem)//�������
						{
							tag = i;
							num = tem;
						}
					}
				}
				if (num>=0)
				{
					current_cylinder = t[tag].cylinder_num;
					current_record = t[tag].record_num;
					cout << "����IO��"<<endl;
					for (i = 0; i < table_num; i++)
					{
						cout << t[i].process_name << " " << t[i].cylinder_num << " " << t[i].track_num << " " << t[i].record_num << endl;
					}
					cout << "��ǰ�Ʊ۷���:" << current_direction << endl;
					cout << "��ǰ����ţ�" << current_cylinder << endl;
					cout << "��ǰ�����¼�ţ�" << current_record << endl;
					table_num--;
					for (i = tag; i < table_num; i++)
					{
						t[i] = t[i + 1];
					}
				}
				else;

			}
		}
		else//��ǰ�Ʊ۷�������
		{
			num = -1;
			for (i = 0; i < table_num; i++)//����
			{
				if (t[i].cylinder_num < current_cylinder)//�ȵ�ǰ�����С�ķ�������
				{
					int tem = t[i].cylinder_num;
					if (num == -1 || num < tem)//�������
					{
						tag = i;
						num = tem;
					}
				}
			}
			if (num>=0)
			{
				current_cylinder = t[tag].cylinder_num;
				current_record = t[tag].record_num;
				cout << "����IO��"<<endl;
				for (i = 0; i < table_num; i++)
				{
					cout << t[i].process_name << " " << t[i].cylinder_num << " " << t[i].track_num << " " << t[i].record_num << endl;
				}
				cout << "��ǰ�Ʊ۷���:" << current_direction << endl;
				cout << "��ǰ����ţ�" << current_cylinder << endl;
				cout << "��ǰ�����¼�ţ�" << current_record << endl;
				table_num--;
				for (i = tag; i < table_num; i++)
				{
					t[i] = t[i + 1];
				}
			}
			else//û�бȵ�ǰ�����С�ķ�������
			{
				num = -1;
				current_direction = DOWN;//�Ʊ۷�����Ϊ����
				for (i = 0; i < table_num; i++)
				{
					if (t[i].cylinder_num > current_cylinder)//Ѱ�ұȵ�ǰ����Ŵ�ķ�������
					{
						int tem = t[i].cylinder_num;
						if (num == -1 || num > tem)//Ѱ����С��
						{
							tag = i;
							num = tem;
						}
					}
				}
				if (num >= 0)
				{
					current_cylinder = t[tag].cylinder_num;
					current_record = t[tag].record_num;
					cout << "����IO��"<<endl;
					for (i = 0; i < table_num; i++)
					{
						cout << t[i].process_name << " " << t[i].cylinder_num << " " << t[i].track_num << " " << t[i].record_num << endl;
					}
					cout << "��ǰ�Ʊ۷���:" << current_direction << endl;
					cout << "��ǰ����ţ�" << current_cylinder << endl;
					cout << "��ǰ�����¼�ţ�" << current_record << endl;
					table_num--;
					for (i = tag; i < table_num; i++)
					{
						t[i] = t[i + 1];
					}
				}
				else;
			}
		}
		
	}
}
void RequestReceive()
{
	cout << "�Ƿ�������(Y/N)";
	char c;
	cin >> c;
	if (c=='y'||c=='Y')//������
	{
		cout << "�����������������š��ŵ��š������¼�ţ�";
		string name;
		int num1, num2, num3;
		cin >> name >> num1 >> num2 >> num3;//����������������ַ
	
		Table temp = { name, num1, num2, num3 };
		//q.push(temp);
		t[table_num++] = temp;//�Ǽ�����I/O��
	}
	return;
}
int main(_In_ int _Argc, _In_reads_(_Argc) _Pre_z_ char ** _Argv, _In_z_ char ** _Env)
{
	
	double input_num = 0.0;
	while (cout<<"������һ���������"&&cin>>input_num)//���������
	{
		if (input_num>0.5)//����0.5
		{
			DriverModify();//��������
		}
		else//С��0.5
		{
			RequestReceive();//��������
		}
	}
	return 0;
}