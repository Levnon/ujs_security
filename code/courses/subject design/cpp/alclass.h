/********************************************
�ļ�����alclass.h
���ܣ�ͷ�ļ�
********************************************/
#include<iostream>
#include<string>
#include<conio.h>
#include<windows.h>
#include<time.h>
#include<stdlib.h>
#include<process.h>
using namespace std;
class dish//����
{
public:
	double score;//����
	string name;//����
	int num;//�˵ı��
	double price;//����
	dish();
	~dish();
	void input();
	void output1();
	void output2();
	double Calculate();
};
class menu//�˵���
{
private:
	int del;//ɾ�������count
public:
	int count;//�����������
	dish a[100];
	void input();
	void output1();
	void output2();
	void remove();
	double Calculate();
	menu();
	~menu();
};
class sys//ϵͳ��
{
private:
	menu a[100];
	int count;//�˵�������
public:
	void Print();
	void Order();
	void Manage();
	void Calculate();
	void History();
	void Mark();
	void Add();
	void Modify1();
	void Modify2();
	void Delete();
	void Search1();
	void Search2();
	void Quit();
	void Shut();
	bool test();
	sys();
	~sys();
};