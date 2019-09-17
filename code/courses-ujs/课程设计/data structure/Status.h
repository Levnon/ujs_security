#pragma once
#ifndef STATUS_HEADER
#define STATUS_HEADER
#include <string>
//#include <graphics.h>
using namespace std;
enum Status{SUCCESS,FAILURE};//����Statusö������

struct DATA //���ݽṹ��
{
	string MemName;//����
	int BirthYear;//����
	int DeathYear;//����
	DATA()//�޲ι��캯��
	{
		MemName = "";
		BirthYear = 0;
		DeathYear = 0;
	}
	DATA(string name, int year_birth, int year_death)//�вι��캯��
	{
		MemName = name;
		BirthYear = year_birth;
		DeathYear = year_death;
	}
	DATA(DATA &d)//�������캯��
	{
		this->MemName = d.MemName;
		this->BirthYear = d.BirthYear;
		this->DeathYear = d.DeathYear;
	}
};

#endif


