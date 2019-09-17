/*
�ļ�����Source.cpp
��������Server_Station.sln
*/

#pragma once
#pragma warning(disable : 4996)
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#ifndef _AFXDLL
#define _AFXDLL
#ifndef _WIN32_WINNT_MAXVER
#define _WIN32_WINNT_MAXVER
#include <iostream>
#include <conio.h>
//#include <atltime.h>
#include <afxmt.h>
#include <windows.h>
#include <time.h>

//�ú�ķ�ʽ���峣����
//�Ա����ʱ�޸ķ��㡣
//��ʵ��ʹ��ʱ��
//Ӧ�ѳ����޸�Ϊ��Ŀ��Ҫ�����Ŀ��
#define MAX_NUM_CUSTOMER 5000//�˿͵��������
#define CONTAIN_NUM_HALL 200//�����������ɵ��������
#define MAX_NUM_EACHQUEUE 200//ÿ�����������Ŷ�����


//����꺯����
//ʹ�ô��������׶���
#define P_OPERATION(semaphore) WaitForSingleObject(semaphore,INFINITE)//P��������
//P���������������������
//���ֱ��ʹ����д�����Ƚ��鷳
//���ҵڶ������������κ��ź������Զ���ȷ�����ı��
//���Կ��԰�������Ϊ�꺯����ͬʱ�ѵڶ��������̶�ΪINFINITE
//����ʹ��P����������Եü��
#define V_OPERATION(semaphore) ReleaseSemaphore(semaphore,1,NULL)//V��������
//V���������������������
//���еڶ����͵����������ǹ̶���
//���۶�ʲô�ź�������V����
//����ͬ��ֻ�ǵ�һ������
//���Կ��԰ѵڶ��������̶�Ϊ1�������������̶�ΪNULL
#define _Time_(t) GetLocalTime(t)//��ȡ��ǰʱ��
//��ȡ��ǰʱ���������
//��������������������д
//���԰�������Ϊ�꣬�Ķ�һ��
//���������������������
#define WAIT_MS(t) Sleep(t)//�Ⱥ�һ��ʱ�䣨����Ϊ��λ��
#define WAIT_S(t) Sleep(t*1000)//�Ⱥ�һ��ʱ�䣨��Ϊ��λ��
//���������ڵȺ�һ��ʱ��ĺ���
//ʵ�����ǵ��õ�ͬһ������
//Ψһ��������ǲ�����ͬ
//��ʵ��Ӧ����
//������ʱ���ú�����㷽�㣬��ʱ��������㷽��
//���Զ����������꺯��
#define Err_Code() GetLastError()//���ش������
//�����������������
//���԰�������Ϊ�꣬�Ķ�һ��
//���������������������
#define Sem_Create(INI_,MAX_) CreateSemaphore(NULL,INI_,MAX_,NULL)//�����ź���ϵͳ����
//�����ź����������
//һ���溯����̫������������д
//��һ�����ĸ������������������ǹ̶���
//���԰�������Ϊ�꺯����Ϊ����
//�����ں����ʹ��
#define Until_Terminate_All_Threads(NUM,THREAD) WaitForMultipleObjects(NUM,THREAD,TRUE,INFINITE)
//�ȴ�����߳̽���
//��������ĸ�������ֻ���������õ���
//���������ǹ̶���
//��������Ϊ�꺯�����Ӽ��
//���ø��ӷ���
#endif
#endif
#endif
using namespace std;//ʹ�������ռ�
//���Ͷ���
//ʹ��������Ϊֱ��
typedef struct ID_STRUCT//ID
{
	int num;
}DATA_CUST_ID,*DATA_POINTER_ID;//�洢�˿ͱ�ŵĽṹ��
typedef SYSTEMTIME Current_Time;//��ǰʱ��
typedef CCriticalSection Mutex_District;//�ٽ���

Current_Time Time = { 0 };//ʱ��ṹ��
//Ϊ��ȡ��ǰϵͳʱ����׼��
//�Ժ�Ҫ��ȡϵͳʱ��ʱ��
//ֻҪ����GetLocalTime(&Time)����������ɡ�

/*�����ٽ���*/
Mutex_District s_enter, //���
s_exit,//����
s_output,//�������
//�Ƚ϶���ʱ�Ļ���
s_mashine,
s_person,
//���еĻ����ź�
mutex_change,//��ǩ/��Ʊ����
mutex_buy1,//1���˹�����
mutex_buy2,//2���˹�����
mutex_mashine1,//1�Ż���
mutex_mashine2,//2�Ż���
mutex_mashine3,//3�Ż���
//��������ʹ��
s_mashine1,//1
s_mashine2,//2
s_mashine3;//3





/*�����ź���*/
HANDLE s,//��Ʊ������ʣ���λ
//�Ⱥ�˿͵�ӪҵԱ
s_serverchange, //��ǩ/��Ʊ����
s_serverbuy1,//1���˹�����
s_serverbuy2,//2���˹�����
s_servermashine1,//1�Ż���
s_servermashine2,//2�Ż���
s_servermashine3,//3�Ż���
//�Ⱥ�ӪҵԱ�Ĺ˿�
s_custchange,//��ǩ/��Ʊ����
s_custbuy1,//1���˹�����
s_custbuy2,//2���˹�����
s_custmashine1,//1�Ż���
s_custmashine2,//2�Ż���
s_custmashine3;//3�Ż���



/*���������*/
INT person_sum_number = 0,//�����ڵ�����
waiting_in_number = 0,//�ȴ����������
waiting_out_number = 0,//�ȴ��˳�������
waiting_person1_count = 0,//�ȴ�1���˹����ڵ�����
waiting_person2_count = 0,//�ȴ�2���˹����ڵ�����
waiting_mashine1_count = 0,//�ȴ�1�Ż���������
waiting_mashine2_count = 0,//�ȴ�2�Ż���������
waiting_mashine3_count = 0,//�ȴ�3�Ż���������
waiting_change_refund_count = 0;//�ȴ���ǩ/��Ʊ���ڵ�����



inline WORD Get_min_NUM(WORD a, WORD b, WORD c)//��3������Сֵ
{
	return (a > b) ? min(b, c) : min(a, c);
}

UINT Init_all_Semaphore()
{
	/*��ʼ���ź���*/
	s = Sem_Create( CONTAIN_NUM_HALL, CONTAIN_NUM_HALL);//�����ź���
	if (!s)
	{
		cerr << "�ź�������ʧ��:" << Err_Code() << endl;//�쳣����
		ExitProcess(1);
	}
	s_serverchange = Sem_Create( 0, 1);//�����ź���
	if (!s_serverchange)
	{
		cerr << "�ź�������ʧ��:" << Err_Code() << endl;//�쳣����
		ExitProcess(1);
	}
	s_serverbuy1 = Sem_Create( 0, 1);//�����ź���
	if (!s_serverbuy1)
	{
		cerr << "�ź�������ʧ��:" << Err_Code() << endl;//�쳣����
		ExitProcess(1);
	}
	s_serverbuy2 = Sem_Create( 0, 1);//�����ź���
	if (!s_serverbuy2)
	{
		cerr << "�ź�������ʧ��:" << Err_Code() << endl;//�쳣����
		ExitProcess(1);
	}
	s_servermashine1 = Sem_Create( 0, 1);//�����ź���
	if (!s_servermashine1)
	{
		cerr << "�ź�������ʧ��:" << Err_Code() << endl;//�쳣����
		ExitProcess(1);
	}
	s_servermashine2 = Sem_Create( 0, 1);//�����ź���
	if (!s_servermashine2)
	{
		cerr << "�ź�������ʧ��:" << Err_Code() << endl;//�쳣����
		ExitProcess(1);
	}
	s_servermashine3 = Sem_Create( 0, 1);//�����ź���
	if (!s_servermashine3)
	{
		cerr << "�ź�������ʧ��:" << Err_Code() << endl;//�쳣����
		ExitProcess(1);
	}
	s_custchange = Sem_Create( 0, CONTAIN_NUM_HALL);//�����ź���
	if (!s_custchange)
	{
		cerr << "�ź�������ʧ��:" << Err_Code() << endl;//�쳣����
		ExitProcess(1);
	}
	s_custbuy1 = Sem_Create( 0, CONTAIN_NUM_HALL);//�����ź���
	if (!s_custbuy1)
	{
		cerr << "�ź�������ʧ��:" << Err_Code() << endl;//�쳣����
		ExitProcess(1);
	}
	s_custbuy2 = Sem_Create( 0, CONTAIN_NUM_HALL);//�����ź���
	if (!s_custbuy2)
	{
		cerr << "�ź�������ʧ��:" << Err_Code() << endl;//�쳣����
		ExitProcess(1);
	}
	s_custmashine1 = Sem_Create( 0, CONTAIN_NUM_HALL);//�����ź���
	if (!s_custmashine1)
	{
		cerr << "�ź�������ʧ��:" << Err_Code() << endl;//�쳣����
		ExitProcess(1);
	}
	s_custmashine2 = Sem_Create( 0, CONTAIN_NUM_HALL);//�����ź���
	if (!s_custmashine2)
	{
		cerr << "�ź�������ʧ��:" << Err_Code() << endl;//�쳣����
		ExitProcess(1);
	}
	s_custmashine3 = Sem_Create( 0, CONTAIN_NUM_HALL);//�����ź���
	if (!s_custmashine3)
	{
		cerr << "�ź�������ʧ��:" << Err_Code() << endl;//�쳣����
		ExitProcess(1);
	}


	return 0;
}


UINT Change_Method(INT m = 0,INT id = 0)
{
	mutex_change.Lock();//�����ٽ���
	waiting_change_refund_count++;//�Ŷ�����+1
	_Time_(&Time);//��õ�ǰ����ʱ��
	
	V_OPERATION(s_custchange);
	mutex_change.Unlock();//�˳��ٽ���
	//�������
	s_output.Lock();
	cout << "��ǰʱ�䣺" << Time.wHour << ":" << Time.wMinute << ":" << Time.wSecond << "\t";
	cout << "�˿�" << id << "��ʼ�Ŷӣ���ǩ/��Ʊ���ڣ�" //<< endl;
		<< " ";
	cout << "��ǰ�ȴ�������" << waiting_change_refund_count << endl;
	s_output.Unlock();
	P_OPERATION(s_serverchange);
	_Time_(&Time);//��õ�ǰ����ʱ��
	s_output.Lock();
	cout << "��ǰʱ�䣺" << Time.wHour << ":" << Time.wMinute << ":" << Time.wSecond << "\t";
	if (m==0)
		cout << "�˿�" << id << "��ʼ��ǩ" << endl;
	else if (m==1)
		cout << "�˿�" << id << "��ʼ��Ʊ" << endl;
	s_output.Unlock();
	//��ʼ��ǩ/��Ʊ����
	//���������Ҫһ��ʱ��
	//����Ϊ35��
	//��ˣ���Ҫ�Ⱥ�35����ټ�������
	WAIT_S(35);
	
	
	
	
			

	return 0;
}

UINT Mashine_Selection(INT id = 0)
{
	s_mashine.Lock();//�����ٽ���
	INT i = Get_min_NUM(waiting_mashine1_count, waiting_mashine2_count, waiting_mashine3_count);//�����е���Сֵ
	INT a = waiting_mashine1_count;
	INT b = waiting_mashine2_count;
	INT c = waiting_mashine3_count;
	if (i==a)//��һ����С
	{
		s_mashine.Unlock();
		mutex_mashine1.Lock();
		waiting_mashine1_count++;
		_Time_(&Time);//��õ�ǰ����ʱ��
		s_output.Lock();
		cout << "��ǰʱ�䣺" << Time.wHour << ":" << Time.wMinute << ":" << Time.wSecond << "\t";
		cout << "�˿�" << id << "��ʼ�Ŷӣ�1�Ż�����" << " ";
		cout << "��ǰ�ȴ�����:" << waiting_mashine1_count - 1 << endl;
		s_output.Unlock();
		
		mutex_mashine1.Unlock();
	
		_Time_(&Time);//��õ�ǰ����ʱ��
		s_mashine1.Lock();
		s_output.Lock();
		cout << "��ǰʱ�䣺" << Time.wHour << ":" << Time.wMinute << ":" << Time.wSecond << "\t";
		cout << "�˿�" << id << "��ʼ��1�Ż�����Ʊ" << endl;
		s_output.Unlock();
		
		WAIT_S(35);
		s_mashine1.Unlock();
		

		mutex_mashine1.Lock();
		waiting_mashine1_count--;
		mutex_mashine1.Unlock();
		
	}
	else if (i==b)//�ڶ�����С
	{
		s_mashine.Unlock();
		mutex_mashine2.Lock();
		waiting_mashine2_count++;
		_Time_(&Time);//��õ�ǰ����ʱ��
		s_output.Lock();
		cout << "��ǰʱ�䣺" << Time.wHour << ":" << Time.wMinute << ":" << Time.wSecond << "\t";
		cout << "�˿�" << id << "��ʼ�Ŷӣ�2�Ż�����" << " ";
		cout << "��ǰ�ȴ�����:" << waiting_mashine2_count - 1<< endl;
		s_output.Unlock();
	
		mutex_mashine2.Unlock();
		
		_Time_(&Time);//��õ�ǰ����ʱ��
		s_mashine2.Lock();
		s_output.Lock();
		cout << "��ǰʱ�䣺" << Time.wHour << ":" << Time.wMinute << ":" << Time.wSecond << "\t";
		cout << "�˿�" << id << "��ʼ��2�Ż�����Ʊ" << endl;
		s_output.Unlock();
		
		WAIT_S(35);
		s_mashine2.Unlock();
		

		mutex_mashine2.Lock();
		waiting_mashine2_count--;
		mutex_mashine2.Unlock();
		
	}
	else //��������С
	{
		s_mashine.Unlock();
		mutex_mashine3.Lock();
		waiting_mashine3_count++;
		_Time_(&Time);//��õ�ǰ����ʱ��
		s_output.Lock();
		cout << "��ǰʱ�䣺" << Time.wHour << ":" << Time.wMinute << ":" << Time.wSecond << "\t";
		cout << "�˿�" << id << "��ʼ�Ŷӣ�3�Ż�����" << " ";
		cout << "��ǰ�ȴ�����:" << waiting_mashine3_count - 1<< endl;
		s_output.Unlock();
		
		mutex_mashine3.Unlock();
		
		_Time_(&Time);//��õ�ǰ����ʱ��
		s_mashine3.Lock();
		s_output.Lock();
		cout << "��ǰʱ�䣺" << Time.wHour << ":" << Time.wMinute << ":" << Time.wSecond << "\t";
		cout << "�˿�" << id << "��ʼ��3�Ż�����Ʊ" << endl;
		s_output.Unlock();
		
		WAIT_S(35);
		s_mashine3.Unlock();

		mutex_mashine3.Lock();
		waiting_mashine3_count--;
		mutex_mashine3.Unlock();
		
	}

	return 0;
}

UINT Person_Selection(INT id = 0)
{
	s_person.Lock();//�����ٽ���
	
	INT i = min(waiting_person1_count, waiting_person2_count);//�����е���Сֵ
	INT a = waiting_person1_count;
	INT b = waiting_person2_count;
	if (i==a)//��һ����С
	{
		s_person.Unlock();
		
		mutex_buy1.Lock();
		waiting_person1_count++;
		_Time_(&Time);//��õ�ǰ����ʱ��
		
		V_OPERATION(s_custbuy1);
		mutex_buy1.Unlock();

		s_output.Lock();
		cout << "��ǰʱ�䣺" << Time.wHour << ":" << Time.wMinute << ":" << Time.wSecond << "\t";
		cout << "�˿�" << id << "��ʼ�Ŷӣ�1���˹����ڣ�" //<< endl;
			<< " ";
		cout << "��ǰ�ȴ�����:" << waiting_person1_count << endl;
		s_output.Unlock();


		P_OPERATION(s_serverbuy1);
		_Time_(&Time);//��õ�ǰ����ʱ��
		s_output.Lock();
		cout << "��ǰʱ�䣺" << Time.wHour << ":" << Time.wMinute << ":" << Time.wSecond << "\t";
		cout << "�˿�" << id << "��ʼ��1���˹�������Ʊ" << endl;
		s_output.Unlock();
		
		
		
			
		
	}
	else//�ڶ�����С
	{
		s_person.Unlock();
		
		mutex_buy2.Lock();
		waiting_person2_count++;
		_Time_(&Time);//��õ�ǰ����ʱ��
		
		V_OPERATION(s_custbuy2);
		mutex_buy2.Unlock();
		s_output.Lock();
		cout << "��ǰʱ�䣺" << Time.wHour << ":" << Time.wMinute << ":" << Time.wSecond << "\t";
		cout << "�˿�" << id << "��ʼ�Ŷӣ�2���˹����ڣ�" //<< endl;
			<< " ";
		cout << "��ǰ�ȴ�����:" << waiting_person2_count << endl;
		s_output.Unlock();

		P_OPERATION(s_serverbuy2);
		_Time_(&Time);//��õ�ǰ����ʱ��
		s_output.Lock();
		cout << "��ǰʱ�䣺" << Time.wHour << ":" << Time.wMinute << ":" << Time.wSecond << "\t";
		cout << "�˿�" << id << "��ʼ��2���˹�������Ʊ" << endl;
		s_output.Unlock();
	
		
		
		
	}




	return 0;
}


UINT Purchase_Method_Choice(INT id = 0)
{
	srand(time(NULL));
LOOP:	INT way = //0;
		rand() % 3;//�����
	switch (way)
	{
	
	case 1:
	
	
		//ѡ���˹���Ʊ
			Person_Selection(id);

			break;
	
	case 2:
		
		//ѡ�������Ʊ
			Mashine_Selection(id);
			
			break;
	default:
		goto LOOP;
		break;
	}
	
	


	return 0;
}


UINT Receive_ServiceSort_Choice(INT id=0)
{
	srand(time(NULL));
	INT ser = //2;
		rand() % 10;//�����
	switch (ser)
	{
	case 0://��ǩ
		Change_Method(0,id);
		break;
	case 1://��Ʊ
		Change_Method(1,id);
		break;
	case 2://��Ʊ
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		//Ϊ�˱��ָ��ʷ���ʵ�ʣ�ʹ����Ʊ����Ʊ/��ǩ�������࣬����2-9��Ϊ��Ʊ�������
		Purchase_Method_Choice(id);
		break;
	default:
		return 1;
		break;
	}




	




	return 0;
}









DWORD WINAPI Customer_Thread(LPVOID lp)//�˿��߳�
{
	DATA_CUST_ID *pmda = (DATA_POINTER_ID)lp;
	INT ID = pmda->num + 1;//�˿ͱ��
	//�˿ͽ������
	P_OPERATION(s);
	s_enter.Lock();//�����ٽ���
	_Time_(&Time);//��õ�ǰ����ʱ��
	s_output.Lock();
	cout << "��ǰʱ�䣺" << Time.wHour << ":" << Time.wMinute << ":" << Time.wSecond << "\t";
	cout << "�˿�" << ID << "�ѽ�����Ʊ������" << "\t";
	waiting_in_number--;
	person_sum_number++;
	cout << "��Ʊ������������" << person_sum_number << endl;
	s_output.Unlock();
	s_enter.Unlock();//�˳��ٽ���

	Receive_ServiceSort_Choice(ID);//�˿ͽ��ܷ���
	waiting_out_number++;
	
	s_exit.Lock();//�����ٽ���
	//�˿��˳�����
	_Time_(&Time);//��õ�ǰ����ʱ��
	s_output.Lock();
	cout << "��ǰʱ�䣺" << Time.wHour << ":" << Time.wMinute << ":" << Time.wSecond << "   ";
	cout << "�˿�" << ID << "���˳���Ʊ������" << " ";
	waiting_out_number--;
	person_sum_number--;
	cout << "ʣ��ȴ��˳�������" << waiting_out_number << " ";
	cout << "��Ʊ������������" << person_sum_number << endl;
	s_output.Unlock();
	s_exit.Unlock();//�˳��ٽ���
	V_OPERATION(s);
	return 0;






}

DWORD WINAPI Server_Person1_Thread(LPVOID lp=NULL)//1����Ʊ���ڽ���
{
	DATA_CUST_ID *pmda = (DATA_POINTER_ID)lp;
	INT ID = 1;//���Ϊ1
	while (1)
	{
		
		P_OPERATION(s_custbuy1);
		mutex_buy1.Lock();//�����ٽ���
		waiting_person1_count--;//�Ŷ�����-1
		
		
		
		
		V_OPERATION(s_serverbuy1);
		mutex_buy1.Unlock();//�˳��ٽ���
		WAIT_S(35);//�ȴ�һ��ʱ���Ϊ��һ���˿ͷ���
		//��εȴ���ʱ�����ΪΪ��һ���û����������ѵ�ʱ��
		//����Ϊ35��
		




	}
	return 0;
}


DWORD WINAPI Server_Person2_Thread(LPVOID lp = NULL)//2����Ʊ�����߳�
{
	DATA_CUST_ID *pmda = (DATA_POINTER_ID)lp;
	INT ID = 2;//���Ϊ2
	while (1)
	{
		
		P_OPERATION(s_custbuy2);
		mutex_buy2.Lock();//�����ٽ���
		waiting_person2_count--;//�Ⱥ�����-1
		
		
		
		
		V_OPERATION(s_serverbuy2);
		mutex_buy2.Unlock();//�˳��ٽ���
		WAIT_S(35);//�ȴ�һ��ʱ���Ϊ��һ���˿ͷ���
		//��εȴ���ʱ�����ΪΪ��һ���û����������ѵ�ʱ��
		//����Ϊ35��
		





	}
	return 0;
}

DWORD WINAPI Server_ChangeRefund_Thread(LPVOID lp=NULL)//��ǩ/��Ʊ�����߳�
{
	while (1)
	{
		

		P_OPERATION(s_custchange);
		mutex_change.Lock();//�����ٽ���
		waiting_change_refund_count--;//�Ⱥ�����-1
		
		
		
		
		V_OPERATION(s_serverchange);
		mutex_change.Unlock();//�˳��ٽ���
		WAIT_S(35);//�ȴ�һ��ʱ���Ϊ��һ���˿ͷ���
		//��εȴ���ʱ�����ΪΪ��һ���û����������ѵ�ʱ��
		//����Ϊ35��
		





	}




	return 0;
}




INT main(_In_ INT _Argc, _In_reads_(_Argc) _Pre_z_ PSTR _Argv[], _In_z_ PSTR _Env[])//���������
{
	INT sum = 0;
	srand(time(NULL));//�������
	Init_all_Semaphore();//��ʼ��
	HANDLE hServer_Buy1, hServer_Buy2, hCustomer[MAX_NUM_CUSTOMER];
	HANDLE hServer_Change;
	HANDLE hServer_Mashine1, hServer_Mashine2, hServer_Mashine3;
	DATA_POINTER_ID pDataArray_Server1, pDataArray_Server2, pDataArray_Customer[MAX_NUM_CUSTOMER];
	DWORD   dwThreadIdArray_Server1, dwThreadIdArray_Server2, dwThreadIdArray_Customer[MAX_NUM_CUSTOMER];
	DWORD   dwThreadIdArray_Server_Change;
	DWORD   dwThreadIdArray_Mashine1, dwThreadIdArray_Mashine2, dwThreadIdArray_Mashine3;
	
	pDataArray_Server1 = (DATA_POINTER_ID)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY,sizeof(DATA_CUST_ID));
	pDataArray_Server1->num = 1;
	_Time_(&Time);//��õ�ǰ����ʱ��
	//�������
	s_output.Lock();
	cout << "��ǰʱ�䣺" << Time.wHour << ":" << Time.wMinute << ":" << Time.wSecond << " ";
	cout << "�˹���Ʊ����" <<  1 << "�߳��ѽ���" << endl;
	s_output.Unlock();
	hServer_Buy1 = CreateThread(NULL, 0, Server_Person1_Thread, NULL, 0, &dwThreadIdArray_Server1);//�����̣߳��˹���Ʊ���񴰿ڣ�
	if (!hServer_Buy1)
	{
		cerr << "�߳̽�������:" << Err_Code() << endl;
		ExitProcess(1);
	}
		
	WAIT_MS(1000);
	pDataArray_Server2 = (DATA_POINTER_ID)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(DATA_CUST_ID));
	pDataArray_Server2->num = 2;
	_Time_(&Time);//��õ�ǰ����ʱ��
	s_output.Lock();
	cout << "��ǰʱ�䣺" << Time.wHour << ":" << Time.wMinute << ":" << Time.wSecond << " ";
	cout << "�˹���Ʊ����" << 2 << "�߳��ѽ���" << endl;
	s_output.Unlock();
	hServer_Buy2 = CreateThread(NULL, 0, Server_Person2_Thread, NULL, 0, &dwThreadIdArray_Server2);//�����̣߳��˹���Ʊ���񴰿ڣ�
	if (!hServer_Buy2)
	{
		cerr << "�߳̽�������:" << Err_Code() << endl;
		ExitProcess(1);
	}
	
	hServer_Change = CreateThread(NULL, 0, Server_ChangeRefund_Thread, NULL, 0, &dwThreadIdArray_Server_Change);//�������̣��˹���ǩ��Ʊ���ڣ�
	if (!hServer_Change)
	{
		cerr << "�߳̽�������:" << Err_Code() << endl;
		ExitProcess(1);
	}
	_Time_(&Time);//��õ�ǰ����ʱ��
	s_output.Lock();
	cout << "��ǰʱ�䣺" << Time.wHour << ":" << Time.wMinute << ":" << Time.wSecond << " ";
	cout << "�˹���ǩ��Ʊ�����߳��ѽ���" << endl;
	cout << endl << endl;
	cout << "*********���д����߳̾��ѽ����ɹ���**********" << endl;
	s_output.Unlock();
	
	WAIT_S(3);
	system("cls");
	Current_Time t_time = Time;//��¼��ǰʱ��
	for (INT i = 0; i < MAX_NUM_CUSTOMER; i++)
	{
		pDataArray_Customer[i] = (DATA_POINTER_ID)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(DATA_CUST_ID));//����ռ��¼�߳�ID
		pDataArray_Customer[i]->num = i;
		_Time_(&Time);//��õ�ǰ����ʱ��
		if ((Time.wHour - t_time.wHour) >2)//���񳬹�2Сʱ����
		{
			cerr << "****************���շ����ѽ���*****************" << endl;
			sum = i;
			break;
		}
		s_output.Lock();
		cout << "��ǰʱ�䣺" << Time.wHour << ":" << Time.wMinute << ":" << Time.wSecond << " ";
		cout << "�˿�" << i + 1 << "�ѵ�����Ʊ�����ſڣ��ŶӵȺ����" << " ";
		waiting_in_number++;
		cout << "��ǰ�ȴ�����������" << waiting_in_number << endl;
		s_output.Unlock();
		hCustomer[i] = CreateThread(NULL, 0, Customer_Thread, pDataArray_Customer[i], 0, &dwThreadIdArray_Customer[i]);//�����̣߳��˹���Ʊ���񴰿ڣ�
		if (!hCustomer[i])
		{
			cerr << "�߳̽�������:" << Err_Code() << endl;
			ExitProcess(1);
		}
		
		DWORD t = 1500 + rand() % 2000;
		WAIT_MS(t);//�˿͵�����ʱ���������
		if (i!=0&&i%4==0)//ÿ4������һ��
		{
			WAIT_S(5);
			system("cls");//����
		}
	}


	

	Until_Terminate_All_Threads(sum, hCustomer);//�ȴ��߳̽���


	Until_Terminate_All_Threads(1, &hServer_Buy1);
	Until_Terminate_All_Threads(1, &hServer_Buy2);
	Until_Terminate_All_Threads(1, &hServer_Change);
	//�ر��߳�
	BOOL nRe1=CloseHandle(hServer_Buy1);
	if (nRe1!=S_OK)
	{
		cerr << "�߳�(�˹�����1���ر�ʧ��:" << Err_Code() << endl;
		ExitProcess(1);
	}
	BOOL nRe2=CloseHandle(hServer_Buy2);
	if (nRe2 != S_OK)
	{
		cerr << "�̣߳��˹�����2���ر�ʧ��:" << Err_Code() << endl;
		ExitProcess(1);
	}
	BOOL nRe3=CloseHandle(hServer_Change);
	if (nRe3 != S_OK)
	{
		cerr << "�̣߳��˹���ǩ/��Ʊ���ڣ��ر�ʧ��:" << Err_Code() << endl;
		ExitProcess(1);
	}
	s_output.Lock();
	cout << endl << endl;
	cout << "********���д����߳̾��ѽ���!***************" << endl;
	s_output.Unlock();
	return 0;
}


















