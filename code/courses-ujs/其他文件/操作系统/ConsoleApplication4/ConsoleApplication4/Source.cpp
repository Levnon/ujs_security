#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <windows.h>
using namespace std;
typedef enum { RUNNING, READY, WAITING, COMPLETED }Status;//״̬
//��������
void Initialize();
void Control();
void Execute();
void P(int &s);
void V(int &s);
struct PCB
{
	string process_name;//������
	Status process_status;//����״̬
	string waiting_cause;//�ȴ�ԭ��
	int break_point;//�ϵ�
};
PCB producer = { "producer", RUNNING, "\0", -1 };//�����߽���
PCB consumer = { "consumer", RUNNING, "\0", -1 };//�����߽���
int s1 = -1;
int s2 = -1;
int PC = -1;
PCB *current_process = NULL;//��ǰ����
int PA[5] = { 4, 0, 2, 1, 6 };//������ָ������
int SA[5] = { 0, 3, 1, 5, 6 };//������ָ������
//int temp = 0;
char B[10] = { 0 };
char ch[100];
int In = 0;
int Out = 0;
int Temp = 0;
char C, X;
void P(int &s)
{
	cout << "P(s)ִ��" << endl;
	s = s - 1;
	if (s<0)
	{
		current_process->process_status = WAITING;
		current_process->waiting_cause = (s==s1)?s1:s2;
	}
	else
	{
		current_process->process_status = READY;
	}
	/*_asm
	{
		nop
	}*/
	return;
}
void V(int &s)
{
	cout << "V(s)ִ��"<<endl;
	s = s + 1;
	if (s<0)
	{
		if (producer.process_status==WAITING)
		{
			producer.process_status = READY;
		}
		if (consumer.process_status==WAITING)
		{
			consumer.process_status = READY;
		}
	}
	current_process->process_status = READY;
	/*_asm
	{
		nop
	}*/
	return;
}
void PUT()
{
	cout << "PUTִ��" << endl;
	B[In] = C;
	In = (In + 1) % 10;
	return;
}
void GET()
{
	cout << "GETִ��" << endl;
	
	
	
	X = B[Out];
	Out = (Out + 1) % 10;
	return;
}
void Produce()
{
	cout << "Produceִ��"<<endl;
	C = ch[Temp++];
	cout << "������ַ�:";
	cout << C <<endl;
	return;
}
void Consume()
{
	cout << "Consumeִ��" << endl;
	cout << "��ӡ�ַ���";
	cout << X <<endl;
	return;
}
void GOTO(int L = 0)
{
	cout << "GOTOִ��"<<endl;
	PC = L;
	return;
}
void NOP()
{
	cout << "NOPִ��" << endl;
	_asm nop
	return;
}
void Err()
{
	cerr << "����" << endl;
	_asm int 3
	return;
}
void Initialize()//��ʼ��
{
	//��ʼ���ź���
	s1 = 10;
	s2 = 0;
	//��ʼ��PCB
	producer.process_status = READY;
	producer.break_point = 0;
	consumer.process_status = READY;
	consumer.break_point = 0;
	//���н��̳�ʼ��
	current_process = &producer;
	PC = 0;
	cout << "������һ���ַ���" << endl;
	cin >> ch;
	Control();//���������ȳ���
	return;
}
void Control()
{
	while (1)
	{
		//�����ֳ�
		current_process->break_point = PC;
		if (producer.process_status == READY || consumer.process_status == READY)
		{
			//���ѡ��һ������������Ϊ���н���
			srand((unsigned)time(NULL));
			int selected = rand() % 2;
			if (selected == 0)
			{
				current_process = &producer;
				cout << "ѡ���������߽���" << endl;
			}
			else
			{
				current_process = &consumer;
				cout << "ѡ���������߽���" << endl;
			}
			//�����н���״̬��Ϊ����̬
			current_process->process_status = RUNNING;
			//���н��̵Ķϵ�ֵ=��PC
			PC = current_process->break_point;
			Execute();//������ָ��ִ�г���

		}
		else
		{
			return;
		}
	}
}
void Execute()
{
	int i = 0;

	int j = PC;//ȡ��PC
	

	if (current_process->process_name == "producer")
	{
		i = PA[j%5];//��ȡָ����ڵ�ַ
		//��ֹ����Խ��
		switch (i)
		{
		case 0:
			P(s1);
			break;
		case 1:
			V(s1);
			break;
		case 2:
			PUT();
			break;
		case 3:
			GET();
			break;
		case 4:
			Produce();
			break;
		case 5:
			Consume();
			break;
		case 6:
			GOTO();
			break;
		case 7:
			NOP();
			break;
		default:
			Err();
			break;
		}
	}
	else
	{
		i = SA[j%5];//��ȡָ����ڵ�ַ
		//��ֹ����Խ��
		switch (i)
		{
		case 0:
			P(s2);
			break;
		case 1:
			V(s2);
			break;
		case 2:
			PUT();
			break;
		case 3:
			GET();
			break;
		case 4:
			Produce();
			break;
		case 5:
			Consume();
			break;
		case 6:
			GOTO();
			break;
		case 7:
			NOP();
			break;
		default:
			Err();
			break;
		}
		
	}
	PC = j + 1;
	current_process->process_status = READY;
	int nRe = ::MessageBoxA(NULL, "�����߽����Ƿ������", "��ʾ", MB_YESNO);
	if (nRe==IDYES)
	{
		consumer.process_status = COMPLETED;
	}
	return;
}
int main()
{
	Initialize();//���ó�ʼ������
	return 0;
}