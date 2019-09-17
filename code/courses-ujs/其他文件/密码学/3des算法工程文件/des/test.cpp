#include"des.h"
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <string>

#define PACKETLEN 8
#define RAND_MAX 0x7fff
using namespace std;

des_key s_k1,s_k2,s_k3;
string m_temp[100],c_temp[100],p_temp[100],ctr_temp[100];
unsigned char IV[8];
void _3DES_Startup(string k1,string k2,string k3)
{
	srand((unsigned)time(NULL));
	for(int i=0;i<8;i++)
		IV[i]=(unsigned char)(rand()%255 + 1);
	for(i=0;i<100;i++)
	{
		m_temp[i]="";
		c_temp[i]="";
		p_temp[i]="";
		ctr_temp[i]="";
	}
	int n1=k1.length();
	int n2=k2.length();
	int n3=k3.length();
	unsigned char *key1=new unsigned char[8];
	unsigned char *key2=new unsigned char[8];
	unsigned char *key3=new unsigned char[8];
	strcpy((char*)key1,k1.c_str());
	strcpy((char*)key2,k2.c_str());
	strcpy((char*)key3,k3.c_str());
	key1[7]=0;
	key2[7]=0;
	key3[7]=0;
	des_setup((unsigned char*)key1,8,0,&s_k1);
	des_setup((unsigned char*)key2,8,0,&s_k2);
	des_setup((unsigned char*)key3,8,0,&s_k3);
}

string _3DES_Encrypt(string m)
{
	unsigned char *pt=new unsigned char[m.length()+1];
	unsigned char *temp1=new unsigned char[m.length()+1];
	unsigned char *temp2=new unsigned char[m.length()+1];
	unsigned char *ct=new unsigned char[m.length()+1];
	for(int i=0;i<m.length()+1;i++)
	{
		pt[i]=0;
		temp1[i]=0;
		temp2[i]=0;
		ct[i]=0;
	}
	strcpy((char *)pt,m.c_str());
	pt[m.length()]=0;
	des_ecb_encrypt(pt,temp1,&s_k1);//k1����
	des_ecb_decrypt(temp1,temp2,&s_k2);//k2����
	des_ecb_encrypt(temp2,ct,&s_k3);//k3����
	string c((char *)ct);
	return c;
}

string _3DES_Decrypt(string c)
{
	unsigned char *pt=new unsigned char[c.length()+1];
	unsigned char *temp1=new unsigned char[c.length()+1];
	unsigned char *temp2=new unsigned char[c.length()+1];
	unsigned char *ct=new unsigned char[c.length()+1];
	for(int i=0;i<c.length()+1;i++)
	{
		pt[i]=0;
		temp1[i]=0;
		temp2[i]=0;
		ct[i]=0;
	}
	strcpy((char *)ct,c.c_str());
	ct[c.length()]=0;
	des_ecb_decrypt(ct,temp2,&s_k3);//k3����
	des_ecb_encrypt(temp2,temp1,&s_k2);//k2����
	des_ecb_decrypt(temp1,pt,&s_k1);//k1����
	string m((char *)pt);
	return m;
}

void Inintialize_Encrypt_Decrypt(string s1,string s2,string s3)
{
	_3DES_Startup(s1,s2,s3);
}


string Encrypt_All_Data_ECB_ZERO(string m)//ECBģʽ���ܣ����ֽ����
{
	string c="";
	int k=0;
	
	do
	{
		m_temp[k]=m.substr(8*k,8);
		//�������
		if(m_temp[k].length()<8)
		{
			int count_sub=8-m_temp[k].length();
			m_temp[k].append(count_sub,0x00);
		}
		c_temp[k]=_3DES_Encrypt(m_temp[k]);
		c=c+c_temp[k];
		k++;
	}
	while(8*k<m.length());
	c_temp[k]="\0";
	return c;
}

string Decrypt_All_Data_ECB_ZERO(string c)//ECBģʽ���ܣ����ֽ����
{
	int k=0;
	string p="";
	do
	{
		p_temp[k]=_3DES_Decrypt(c_temp[k]);
		//�������
		for(int i=0;i<p_temp[k].length();i++)
			if(p_temp[k][i]<0x08) 
				p_temp[k]=p_temp[k].substr(0,i);
		p=p+p_temp[k];
		k++;
	}
	while(c_temp[k]!="\0");
	return p;
}

string Encrypt_All_Data_ECB_PKCS7(string m)//ECBģʽ���ܣ�PKCS7��ʽ���
{
	string c="";
	int k=0;
	
	do
	{
		m_temp[k]=m.substr(8*k,8);
		//�������
		if(m_temp[k].length()<8)
		{
			int count_sub=8-m_temp[k].length();
			m_temp[k].append(count_sub,(char)count_sub);
		}
		c_temp[k]=_3DES_Encrypt(m_temp[k]);
		c=c+c_temp[k];
		k++;
	}
	while(8*k<m.length());
	c_temp[k]="\0";
	return c;
}

string Decrypt_All_Data_ECB_PKCS7(string c)//ECBģʽ���ܣ�PKCS7��ʽ���
{
	int k=0;
	string p="";
	do
	{
		p_temp[k]=_3DES_Decrypt(c_temp[k]);
		//�������
		for(int i=0;i<p_temp[k].length();i++)
			if(p_temp[k][i]<0x08) 
				p_temp[k]=p_temp[k].substr(0,i);
		p=p+p_temp[k];
		k++;
	}
	while(c_temp[k]!="\0");
	return p;
}


string Encrypt_All_Data_ECB_ANSIX923(string m)//ECBģʽ���ܣ�ANSI X.923��ʽ���
{
	string c="";
	int k=0;
	
	do
	{
		m_temp[k]=m.substr(8*k,8);
		//�������
		if(m_temp[k].length()<8)
		{
			int count_sub=8-m_temp[k].length();
			if(count_sub-1>0)
				m_temp[k].append(count_sub-1,0x00);
			m_temp[k].append(1,(char)count_sub);
		}
		c_temp[k]=_3DES_Encrypt(m_temp[k]);
		c=c+c_temp[k];
		k++;
	}
	while(8*k<m.length());
	c_temp[k]="\0";
	return c;
}

string Decrypt_All_Data_ECB_ANSIX923(string c)//ECBģʽ���ܣ�ANSI X.923��ʽ���
{
	int k=0;
	string p="";
	do
	{
		p_temp[k]=_3DES_Decrypt(c_temp[k]);
		//�������
		for(int i=0;i<p_temp[k].length();i++)
			if(p_temp[k][i]<0x08) 
				p_temp[k]=p_temp[k].substr(0,i);
		p=p+p_temp[k];
		k++;
	}
	while(c_temp[k]!="\0");
	return p;
}

string Encrypt_All_Data_ECB_ISO10126(string m)//ECBģʽ���ܣ�ISO 10126��ʽ���
{
	string c="";
	int k=0;
	
	do
	{
		m_temp[k]=m.substr(8*k,8);
		//�������
		if(m_temp[k].length()<8)
		{
			int count_sub=8-m_temp[k].length();
			if(count_sub-1>0)
			{
				srand((unsigned)time(NULL));
				unsigned int fill=rand()%256;
				m_temp[k].append(count_sub-1,(char)fill);
			}
			m_temp[k].append(1,(char)count_sub);
		}
		c_temp[k]=_3DES_Encrypt(m_temp[k]);
		c=c+c_temp[k];
		k++;
	}
	while(8*k<m.length());
	c_temp[k]="\0";
	return c;
}

string Decrypt_All_Data_ECB_ISO10126(string c)//ECBģʽ���ܣ�ISO 10126��ʽ���
{
	int k=0;
	string p="";
	do
	{
		p_temp[k]=_3DES_Decrypt(c_temp[k]);
		//�������
		for(int i=0;i<p_temp[k].length();i++)
			if(p_temp[k][i]<0x08) 
				p_temp[k]=p_temp[k].substr(0,p_temp[k].length()-(int)p_temp[k][i]);
		p=p+p_temp[k];
		k++;
	}
	while(c_temp[k]!="\0");
	return p;
}


string Encrypt_All_Data_CBC_ZERO(string m)//CBCģʽ���ܣ����ֽ����
{
	string c="";
	int k=0;
	
	do
	{
		m_temp[k]=m.substr(8*k,8);
		
		//�������
		if(m_temp[k].length()<8)
		{
			int count_sub=8-m_temp[k].length();
			m_temp[k].append(count_sub,0x00);
		}

		//�������
		if(k==0)
			for(int i=0;i<8;i++)
				m_temp[k][i]=m_temp[k][i]^IV[i];
		else
			for(int i=0;i<8;i++)
				m_temp[k][i]=m_temp[k][i]^c_temp[k-1][i];
		c_temp[k]=_3DES_Encrypt(m_temp[k]);
		c=c+c_temp[k];
		k++;
	}
	while(8*k<m.length());
	c_temp[k]="\0";
	return c;
}

string Decrypt_All_Data_CBC_ZERO(string c)//CBCģʽ���ܣ����ֽ����
{
	int k=0;
	string p="";
	do
	{
		p_temp[k]=_3DES_Decrypt(c_temp[k]);

		//�������
		if(k==0)
			for(int i=0;i<8;i++)
				p_temp[k][i]=p_temp[k][i]^IV[i];
		else
			for(int i=0;i<8;i++)
				p_temp[k][i]=p_temp[k][i]^c_temp[k-1][i];
		//�������
		for(int i=0;i<p_temp[k].length();i++)
			if(p_temp[k][i]<0x08) 
				p_temp[k]=p_temp[k].substr(0,i);
		
		p=p+p_temp[k];
		k++;
	}
	while(c_temp[k]!="\0");
	return p;
}


string Encrypt_All_Data_CBC_PKCS7(string m)//CBCģʽ���ܣ�PKCS7��ʽ���
{
	string c="";
	int k=0;
	
	do
	{
		m_temp[k]=m.substr(8*k,8);
		
		//�������
		if(m_temp[k].length()<8)
		{
			int count_sub=8-m_temp[k].length();
			m_temp[k].append(count_sub,(char)count_sub);
		}

		//�������
		if(k==0)
			for(int i=0;i<8;i++)
				m_temp[k][i]=m_temp[k][i]^IV[i];
		else
			for(int i=0;i<8;i++)
				m_temp[k][i]=m_temp[k][i]^c_temp[k-1][i];
		c_temp[k]=_3DES_Encrypt(m_temp[k]);
		c=c+c_temp[k];
		k++;
	}
	while(8*k<m.length());
	c_temp[k]="\0";
	return c;
}

string Decrypt_All_Data_CBC_PKCS7(string c)//CBCģʽ���ܣ�PKCS7��ʽ���
{
	int k=0;
	string p="";
	do
	{
		p_temp[k]=_3DES_Decrypt(c_temp[k]);

		//�������
		if(k==0)
			for(int i=0;i<8;i++)
				p_temp[k][i]=p_temp[k][i]^IV[i];
		else
			for(int i=0;i<8;i++)
				p_temp[k][i]=p_temp[k][i]^c_temp[k-1][i];
		//�������
		for(int i=0;i<p_temp[k].length();i++)
			if(p_temp[k][i]<0x08) 
				p_temp[k]=p_temp[k].substr(0,i);
		
		p=p+p_temp[k];
		k++;
	}
	while(c_temp[k]!="\0");
	return p;
}

string Encrypt_All_Data_CBC_ANSIX923(string m)//CBCģʽ���ܣ�ANSI X.923��ʽ���
{
	string c="";
	int k=0;
	
	do
	{
		m_temp[k]=m.substr(8*k,8);
		
		//�������
		if(m_temp[k].length()<8)
		{
			int count_sub=8-m_temp[k].length();
			if(count_sub-1>0)
				m_temp[k].append(count_sub-1,0x00);
			m_temp[k].append(1,(char)count_sub);
		}

		//�������
		if(k==0)
			for(int i=0;i<8;i++)
				m_temp[k][i]=m_temp[k][i]^IV[i];
		else
			for(int i=0;i<8;i++)
				m_temp[k][i]=m_temp[k][i]^c_temp[k-1][i];
		c_temp[k]=_3DES_Encrypt(m_temp[k]);
		c=c+c_temp[k];
		k++;
	}
	while(8*k<m.length());
	c_temp[k]="\0";
	return c;
}

string Decrypt_All_Data_CBC_ANSIX923(string c)//CBCģʽ���ܣ�ANSI X.923��ʽ���
{
	int k=0;
	string p="";
	do
	{
		p_temp[k]=_3DES_Decrypt(c_temp[k]);

		//�������
		if(k==0)
			for(int i=0;i<8;i++)
				p_temp[k][i]=p_temp[k][i]^IV[i];
		else
			for(int i=0;i<8;i++)
				p_temp[k][i]=p_temp[k][i]^c_temp[k-1][i];
		//�������
		for(int i=0;i<p_temp[k].length();i++)
			if(p_temp[k][i]<0x08) 
				p_temp[k]=p_temp[k].substr(0,i);
		
		p=p+p_temp[k];
		k++;
	}
	while(c_temp[k]!="\0");
	return p;
}

string Encrypt_All_Data_CBC_ISO10126(string m)//CBCģʽ���ܣ�ISO 10126��ʽ���
{
	string c="";
	int k=0;
	
	do
	{
		m_temp[k]=m.substr(8*k,8);
		
		//�������
		if(m_temp[k].length()<8)
		{
			int count_sub=8-m_temp[k].length();
			if(count_sub-1>0)
			{
				srand((unsigned)time(NULL));
				unsigned int fill=rand()%256;
				m_temp[k].append(count_sub-1,(char)fill);
			}
			m_temp[k].append(1,(char)count_sub);
		}

		//�������
		if(k==0)
			for(int i=0;i<8;i++)
				m_temp[k][i]=m_temp[k][i]^IV[i];
		else
			for(int i=0;i<8;i++)
				m_temp[k][i]=m_temp[k][i]^c_temp[k-1][i];
		c_temp[k]=_3DES_Encrypt(m_temp[k]);
		c=c+c_temp[k];
		k++;
	}
	while(8*k<m.length());
	c_temp[k]="\0";
	return c;
}

string Decrypt_All_Data_CBC_ISO10126(string c)//CBCģʽ���ܣ�ISO 10126��ʽ���
{
	int k=0;
	string p="";
	do
	{
		p_temp[k]=_3DES_Decrypt(c_temp[k]);

		//�������
		if(k==0)
			for(int i=0;i<8;i++)
				p_temp[k][i]=p_temp[k][i]^IV[i];
		else
			for(int i=0;i<8;i++)
				p_temp[k][i]=p_temp[k][i]^c_temp[k-1][i];
		//�������
		for(int i=0;i<p_temp[k].length();i++)
			if(p_temp[k][i]<0x08) 
				p_temp[k]=p_temp[k].substr(0,p_temp[k].length()-(int)p_temp[k][i]);
		
		p=p+p_temp[k];
		k++;
	}
	while(c_temp[k]!="\0");
	return p;
}


string Encrypt_All_Data_CFB_ZERO(string m)//CFBģʽ���ܣ����ֽ����
{
	string c="";
	int k=0;
	
	do
	{
		m_temp[k]=m.substr(8*k,8);
		
		//�������
		if(m_temp[k].length()<8)
		{
			int count_sub=8-m_temp[k].length();
			m_temp[k].append(count_sub,0x00);
		}

		//�������
		string iv((char *)IV);
		if(k==0)
			c_temp[k]=_3DES_Encrypt(iv);
		else
			c_temp[k]=_3DES_Encrypt(c_temp[k-1]);
		for(int i=0;i<8;i++)
			c_temp[k][i]=c_temp[k][i]^m_temp[k][i];
		c=c+c_temp[k];
		k++;
	}
	while(8*k<m.length());
	c_temp[k]="\0";
	return c;
}

string Decrypt_All_Data_CFB_ZERO(string c)//CFBģʽ���ܣ����ֽ����
{
	int k=0;
	string p="";
	do
	{
		string iv((char *)IV);
		if(k==0)
			p_temp[k]=_3DES_Encrypt(iv);
		else
			p_temp[k]=_3DES_Encrypt(c_temp[k-1]);
		p_temp[k]=p_temp[k].substr(0,8);
		//�������
		for(int i=0;i<8;i++)
			p_temp[k][i]=p_temp[k][i]^c_temp[k][i];
		//�������
		for(i=0;i<p_temp[k].length();i++)
			if(p_temp[k][i]<0x08) 
				p_temp[k]=p_temp[k].substr(0,i);
		
		p=p+p_temp[k];
		k++;
	}
	while(c_temp[k]!="\0");
	return p;
}


string Encrypt_All_Data_CFB_PKCS7(string m)//CFBģʽ���ܣ�PKCS7��ʽ���
{
	string c="";
	int k=0;
	
	do
	{
		m_temp[k]=m.substr(8*k,8);
		
		//�������
		if(m_temp[k].length()<8)
		{
			int count_sub=8-m_temp[k].length();
			m_temp[k].append(count_sub,(char)count_sub);
		}

		//�������
		string iv((char *)IV);
		if(k==0)
			c_temp[k]=_3DES_Encrypt(iv);
		else
			c_temp[k]=_3DES_Encrypt(c_temp[k-1]);
		for(int i=0;i<8;i++)
			c_temp[k][i]=c_temp[k][i]^m_temp[k][i];
		c=c+c_temp[k];
		k++;
	}
	while(8*k<m.length());
	c_temp[k]="\0";
	return c;
}

string Decrypt_All_Data_CFB_PKCS7(string c)//CFBģʽ���ܣ�PKCS7��ʽ���
{
	int k=0;
	string p="";
	do
	{
		string iv((char *)IV);
		if(k==0)
			p_temp[k]=_3DES_Encrypt(iv);
		else
			p_temp[k]=_3DES_Encrypt(c_temp[k-1]);
		p_temp[k]=p_temp[k].substr(0,8);
		//�������
		for(int i=0;i<8;i++)
			p_temp[k][i]=p_temp[k][i]^c_temp[k][i];
		//�������
		for(i=0;i<p_temp[k].length();i++)
			if(p_temp[k][i]<0x08) 
				p_temp[k]=p_temp[k].substr(0,i);
		
		p=p+p_temp[k];
		k++;
	}
	while(c_temp[k]!="\0");
	return p;
}


string Encrypt_All_Data_CFB_ANSIX923(string m)//CFBģʽ���ܣ�ANSI X.923��ʽ���
{
	string c="";
	int k=0;
	
	do
	{
		m_temp[k]=m.substr(8*k,8);
		
		//�������
		if(m_temp[k].length()<8)
		{
			int count_sub=8-m_temp[k].length();
			if(count_sub-1>0)
				m_temp[k].append(count_sub-1,0x00);
			m_temp[k].append(1,(char)count_sub);
		}

		//�������
		string iv((char *)IV);
		if(k==0)
			c_temp[k]=_3DES_Encrypt(iv);
		else
			c_temp[k]=_3DES_Encrypt(c_temp[k-1]);
		for(int i=0;i<8;i++)
			c_temp[k][i]=c_temp[k][i]^m_temp[k][i];
		c=c+c_temp[k];
		k++;
	}
	while(8*k<m.length());
	c_temp[k]="\0";
	return c;
}

string Decrypt_All_Data_CFB_ANSIX923(string c)//CFBģʽ���ܣ�ANSI X.923��ʽ���
{
	int k=0;
	string p="";
	do
	{
		string iv((char *)IV);
		if(k==0)
			p_temp[k]=_3DES_Encrypt(iv);
		else
			p_temp[k]=_3DES_Encrypt(c_temp[k-1]);
		p_temp[k]=p_temp[k].substr(0,8);
		//�������
		for(int i=0;i<8;i++)
			p_temp[k][i]=p_temp[k][i]^c_temp[k][i];
		//�������
		for(i=0;i<p_temp[k].length();i++)
			if(p_temp[k][i]<0x08) 
				p_temp[k]=p_temp[k].substr(0,i);
		
		p=p+p_temp[k];
		k++;
	}
	while(c_temp[k]!="\0");
	return p;
}


string Encrypt_All_Data_CFB_ISO10126(string m)//CFBģʽ���ܣ�ISO 10126��ʽ���
{
	string c="";
	int k=0;
	
	do
	{
		m_temp[k]=m.substr(8*k,8);
		
		//�������
		if(m_temp[k].length()<8)
		{
			int count_sub=8-m_temp[k].length();
			if(count_sub-1>0)
			{
				srand((unsigned)time(NULL));
				unsigned int fill=rand()%256;
				m_temp[k].append(count_sub-1,(char)fill);
			}
			m_temp[k].append(1,(char)count_sub);
		}

		//�������
		string iv((char *)IV);
		if(k==0)
			c_temp[k]=_3DES_Encrypt(iv);
		else
			c_temp[k]=_3DES_Encrypt(c_temp[k-1]);
		
		for(int i=0;i<8;i++)
			c_temp[k][i]=c_temp[k][i]^m_temp[k][i];
		c=c+c_temp[k];
		k++;
	}
	while(8*k<m.length());
	c_temp[k]="\0";
	return c;
}

string Decrypt_All_Data_CFB_ISO10126(string c)//CFBģʽ���ܣ�ISO 10126��ʽ���
{
	int k=0;
	string p="";
	do
	{
		string iv((char *)IV);
		if(k==0)
			p_temp[k]=_3DES_Encrypt(iv);
		else
			p_temp[k]=_3DES_Encrypt(c_temp[k-1]);
		p_temp[k]=p_temp[k].substr(0,8);
		//�������
		for(int i=0;i<8;i++)
			p_temp[k][i]=p_temp[k][i]^c_temp[k][i];
		//�������
		for(i=0;i<p_temp[k].length();i++)
			if(p_temp[k][i]<0x08) 
				p_temp[k]=p_temp[k].substr(0,p_temp[k].length()-(int)p_temp[k][i]);
		
		p=p+p_temp[k];
		k++;
	}
	while(c_temp[k]!="\0");
	return p;
}


string Encrypt_All_Data_OFB_ZERO(string m)//OFBģʽ���ܣ����ֽ����
{
	string c="";
	int k=0;
	for(int i=0;i<100;i++)
			c_temp[i]="";
	do
	{
		m_temp[k]=m.substr(8*k,8);
		
		//�������
		if(m_temp[k].length()<8)
		{
			int count_sub=8-m_temp[k].length();
			m_temp[k].append(count_sub,0x00);
		}

		//�������
		string iv((char *)IV);
		string key=iv;
		for(int i=0;i<k+1;i++)
			key=_3DES_Encrypt(key);
		
		for(i=0;i<8;i++)
			c_temp[k].append(1,(char)key[i]^m_temp[k][i]);
		c=c+c_temp[k];
		k++;
	}
	while(8*k<m.length());
	c_temp[k]="\0";
	return c;
}

string Decrypt_All_Data_OFB_ZERO(string c)//OFBģʽ���ܣ����ֽ����
{
	int k=0;
	string p="";
	for(int i=0;i<100;i++)
			p_temp[i]="";
	do
	{
		string iv((char *)IV);
		string key=iv;
		for(int i=0;i<k+1;i++)
			key=_3DES_Encrypt(key);
		key=key.substr(0,8);
		//�������
		
		for(i=0;i<8;i++)
			p_temp[k].append(1,key[i]^c_temp[k][i]);
		//�������
		for(i=0;i<p_temp[k].length();i++)
			if(p_temp[k][i]<0x08) 
				p_temp[k]=p_temp[k].substr(0,i);
		
		p=p+p_temp[k];
		k++;
	}
	while(c_temp[k]!="\0");
	return p;
}


string Encrypt_All_Data_OFB_PKCS7(string m)//OFBģʽ���ܣ�PKCS7��ʽ���
{
	string c="";
	int k=0;
	for(int i=0;i<100;i++)
			c_temp[i]="";
	do
	{
		m_temp[k]=m.substr(8*k,8);
		
		//�������
		if(m_temp[k].length()<8)
		{
			int count_sub=8-m_temp[k].length();
			m_temp[k].append(count_sub,(char)count_sub);
		}

		//�������
		string iv((char *)IV);
		string key=iv;
		for(int i=0;i<k+1;i++)
			key=_3DES_Encrypt(key);
		
		for(i=0;i<8;i++)
			c_temp[k].append(1,(char)key[i]^m_temp[k][i]);
		c=c+c_temp[k];
		k++;
	}
	while(8*k<m.length());
	c_temp[k]="\0";
	return c;
}

string Decrypt_All_Data_OFB_PKCS7(string c)//OFBģʽ���ܣ�PKCS7��ʽ���
{
	int k=0;
	string p="";
	for(int i=0;i<100;i++)
		p_temp[i]="";
	do
	{
		string iv((char *)IV);
		string key=iv;
		for(int i=0;i<k+1;i++)
			key=_3DES_Encrypt(key);
		key=key.substr(0,8);
		//�������
		
		for(i=0;i<8;i++)
			p_temp[k].append(1,key[i]^c_temp[k][i]);
		//�������
		for(i=0;i<p_temp[k].length();i++)
			if(p_temp[k][i]<0x08) 
				p_temp[k]=p_temp[k].substr(0,i);
		
		p=p+p_temp[k];
		k++;
	}
	while(c_temp[k]!="\0");
	return p;
}

string Encrypt_All_Data_OFB_ANSIX923(string m)//OFBģʽ���ܣ�ANSI X.923��ʽ���
{
	string c="";
	int k=0;
	for(int i=0;i<100;i++)
			c_temp[i]="";
	do
	{
		m_temp[k]=m.substr(8*k,8);
		
		//�������
		if(m_temp[k].length()<8)
		{
			int count_sub=8-m_temp[k].length();
			if(count_sub-1>0)
				m_temp[k].append(count_sub-1,0x00);
			m_temp[k].append(1,(char)count_sub);
		}

		//�������
		string iv((char *)IV);
		string key=iv;
		for(int i=0;i<k+1;i++)
			key=_3DES_Encrypt(key);
		
		for(i=0;i<8;i++)
			c_temp[k].append(1,(char)key[i]^m_temp[k][i]);
		c=c+c_temp[k];
		k++;
	}
	while(8*k<m.length());
	c_temp[k]="\0";
	return c;
}

string Decrypt_All_Data_OFB_ANSIX923(string c)//OFBģʽ���ܣ�ANSI X.923��ʽ���
{
	int k=0;
	string p="";
	for(int i=0;i<100;i++)
		p_temp[i]="";
	do
	{
		string iv((char *)IV);
		string key=iv;
		for(int i=0;i<k+1;i++)
			key=_3DES_Encrypt(key);
		key=key.substr(0,8);
		//�������
		
		for(i=0;i<8;i++)
			p_temp[k].append(1,key[i]^c_temp[k][i]);
		//�������
		for(i=0;i<p_temp[k].length();i++)
			if(p_temp[k][i]<0x08) 
				p_temp[k]=p_temp[k].substr(0,i);
		
		p=p+p_temp[k];
		k++;
	}
	while(c_temp[k]!="\0");
	return p;
}

string Encrypt_All_Data_OFB_ISO10126(string m)//OFBģʽ���ܣ�ISO 10126��ʽ���
{
	string c="";
	int k=0;
	for(int i=0;i<100;i++)
			c_temp[i]="";
	do
	{
		m_temp[k]=m.substr(8*k,8);
		
		//�������
		if(m_temp[k].length()<8)
		{
			int count_sub=8-m_temp[k].length();
			if(count_sub-1>0)
			{
				srand((unsigned)time(NULL));
				unsigned int fill=rand()%256;
				m_temp[k].append(count_sub-1,(char)fill);
			}
			m_temp[k].append(1,(char)count_sub);
		}

		//�������
		string iv((char *)IV);
		string key=iv;
		for(int i=0;i<k+1;i++)
			key=_3DES_Encrypt(key);
		
		for(i=0;i<8;i++)
			c_temp[k].append(1,(char)key[i]^m_temp[k][i]);
		c=c+c_temp[k];
		k++;
	}
	while(8*k<m.length());
	c_temp[k]="\0";
	return c;
}

string Decrypt_All_Data_OFB_ISO10126(string c)//OFBģʽ���ܣ�ISO 10126��ʽ���
{
	int k=0;
	string p="";
	for(int i=0;i<100;i++)
		p_temp[i]="";
	do
	{
		string iv((char *)IV);
		string key=iv;
		for(int i=0;i<k+1;i++)
			key=_3DES_Encrypt(key);
		key=key.substr(0,8);
		//�������
		
		for(i=0;i<8;i++)
			p_temp[k].append(1,key[i]^c_temp[k][i]);
		//�������
		for(i=0;i<p_temp[k].length();i++)
			if(p_temp[k][i]<0x08) 
				p_temp[k]=p_temp[k].substr(0,p_temp[k].length()-(int)p_temp[k][i]);
		
		
		p=p+p_temp[k];
		k++;
	}
	while(c_temp[k]!="\0");
	return p;
}



string Encrypt_All_Data_CTR_ZERO(string m)//CTRģʽ���ܣ����ֽ����
{
	string c="";
	int k=0;
	for(int i=0;i<100;i++)
		ctr_temp[i]="";
	do
	{
		m_temp[k]=m.substr(8*k,8);
		//�������
		if(m_temp[k].length()<8)
		{
			int count_sub=8-m_temp[k].length();
			m_temp[k].append(count_sub,0x00);
		}
		//�������
		ctr_temp[k].append(1,(char)k);
		while(ctr_temp[k].length()<8)
			ctr_temp[k].append(1,'0');
		c_temp[k]=_3DES_Encrypt(ctr_temp[k]);
		for(int i=0;i<8;i++)
			c_temp[k][i]=c_temp[k][i]^m_temp[k][i];
		c_temp[k]=c_temp[k].substr(0,8);
		c=c+c_temp[k];
		k++;
	}
	while(8*k<m.length());
	c_temp[k]="\0";
	return c;
}

string Decrypt_All_Data_CTR_ZERO(string c)//CTRģʽ���ܣ����ֽ����
{
	int k=0;
	string p="";
	for(int i=0;i<100;i++)
		p_temp[i]="";
	do
	{
		m_temp[k]=_3DES_Encrypt(ctr_temp[k]);
		for(int i=0;i<8;i++)
			p_temp[k].append(1,(char)(m_temp[k][i]^c_temp[k][i]));
		//�������
		for(i=0;i<p_temp[k].length();i++)
			if(p_temp[k][i]<0x08) 
				p_temp[k]=p_temp[k].substr(0,i);
		p=p+p_temp[k];
		k++;
	}
	while(c_temp[k]!="\0");
	return p;
}

string Encrypt_All_Data_CTR_PKCS7(string m)//CTRģʽ���ܣ�PKCS7��ʽ���
{
	string c="";
	int k=0;
	for(int i=0;i<100;i++)
		ctr_temp[i]="";
	do
	{
		m_temp[k]=m.substr(8*k,8);
		//�������
		if(m_temp[k].length()<8)
		{
			int count_sub=8-m_temp[k].length();
			m_temp[k].append(count_sub,(char)count_sub);
		}
		//�������
		ctr_temp[k].append(1,(char)k);
		while(ctr_temp[k].length()<8)
			ctr_temp[k].append(1,'0');
		c_temp[k]=_3DES_Encrypt(ctr_temp[k]);
		for(int i=0;i<8;i++)
			c_temp[k][i]=c_temp[k][i]^m_temp[k][i];
		c_temp[k]=c_temp[k].substr(0,8);
		c=c+c_temp[k];
		k++;
	}
	while(8*k<m.length());
	c_temp[k]="\0";
	return c;
}

string Decrypt_All_Data_CTR_PKCS7(string c)//CTRģʽ���ܣ�PKCS7��ʽ���
{
	int k=0;
	string p="";
	for(int i=0;i<100;i++)
		p_temp[i]="";
	do
	{
		m_temp[k]=_3DES_Encrypt(ctr_temp[k]);
		for(int i=0;i<8;i++)
			p_temp[k].append(1,(char)(m_temp[k][i]^c_temp[k][i]));
		//�������
		for(i=0;i<p_temp[k].length();i++)
			if(p_temp[k][i]<0x08) 
				p_temp[k]=p_temp[k].substr(0,i);
		p=p+p_temp[k];
		k++;
	}
	while(c_temp[k]!="\0");
	return p;
}


string Encrypt_All_Data_CTR_ANSIX923(string m)//CTRģʽ���ܣ�ANSI X.923��ʽ���
{
	string c="";
	int k=0;
	for(int i=0;i<100;i++)
		ctr_temp[i]="";
	do
	{
		m_temp[k]=m.substr(8*k,8);
		//�������
		if(m_temp[k].length()<8)
		{
			int count_sub=8-m_temp[k].length();
			if(count_sub-1>0)
				m_temp[k].append(count_sub-1,0x00);
			m_temp[k].append(1,(char)count_sub);
		}
		//�������
		ctr_temp[k].append(1,(char)k);
		while(ctr_temp[k].length()<8)
			ctr_temp[k].append(1,'0');
		c_temp[k]=_3DES_Encrypt(ctr_temp[k]);
		for(int i=0;i<8;i++)
			c_temp[k][i]=c_temp[k][i]^m_temp[k][i];
		c_temp[k]=c_temp[k].substr(0,8);
		c=c+c_temp[k];
		k++;
	}
	while(8*k<m.length());
	c_temp[k]="\0";
	return c;
}

string Decrypt_All_Data_CTR_ANSIX923(string c)//CTRģʽ���ܣ�ANSI X.923��ʽ���
{
	int k=0;
	string p="";
	for(int i=0;i<100;i++)
		p_temp[i]="";
	do
	{
		m_temp[k]=_3DES_Encrypt(ctr_temp[k]);
		for(int i=0;i<8;i++)
			p_temp[k].append(1,(char)(m_temp[k][i]^c_temp[k][i]));
		//�������
		for(i=0;i<p_temp[k].length();i++)
			if(p_temp[k][i]<0x08) 
				p_temp[k]=p_temp[k].substr(0,i);
		p=p+p_temp[k];
		k++;
	}
	while(c_temp[k]!="\0");
	return p;
}

string Encrypt_All_Data_CTR_ISO10126(string m)//CTRģʽ���ܣ�ISO 10126��ʽ���
{
	string c="";
	int k=0;
	for(int i=0;i<100;i++)
		ctr_temp[i]="";
	do
	{
		m_temp[k]=m.substr(8*k,8);
		//�������
		if(m_temp[k].length()<8)
		{
			int count_sub=8-m_temp[k].length();
			if(count_sub-1>0)
			{
				srand((unsigned)time(NULL));
				unsigned int fill=rand()%256;
				m_temp[k].append(count_sub-1,(char)fill);
			}
			m_temp[k].append(1,(char)count_sub);
		}

		//�������
		ctr_temp[k].append(1,(char)k);
		while(ctr_temp[k].length()<8)
			ctr_temp[k].append(1,'0');
		c_temp[k]=_3DES_Encrypt(ctr_temp[k]);
		for(int i=0;i<8;i++)
			c_temp[k][i]=c_temp[k][i]^m_temp[k][i];
		c_temp[k]=c_temp[k].substr(0,8);
		c=c+c_temp[k];
		k++;
	}
	while(8*k<m.length());
	c_temp[k]="\0";
	return c;
}

string Decrypt_All_Data_CTR_ISO10126(string c)//CTRģʽ���ܣ�ISO 10126��ʽ���
{
	int k=0;
	string p="";
	for(int i=0;i<100;i++)
		p_temp[i]="";
	do
	{
		m_temp[k]=_3DES_Encrypt(ctr_temp[k]);
		for(int i=0;i<8;i++)
			p_temp[k].append(1,(char)(m_temp[k][i]^c_temp[k][i]));
		//�������
		for(i=0;i<p_temp[k].length();i++)
			if(p_temp[k][i]<0x08) 
				p_temp[k]=p_temp[k].substr(0,p_temp[k].length()-(int)p_temp[k][i]);
		p=p+p_temp[k];
		k++;
	}
	while(c_temp[k]!="\0");
	return p;
}


int main()

{
/*
unsigned char pt[PACKETLEN+1];//����
unsigned char ct[PACKETLEN+1];//����
//�м���
unsigned char temp1[PACKETLEN+1];
unsigned char temp2[PACKETLEN+1];
//��Կ
unsigned char key1[8]={'a','a','a','a','a','a','a','a'};//1
unsigned char key2[8]={'a','a','a','a','a','a','a','a'};//2
unsigned char key3[8]={'a','a','a','a','a','a','a','a'};//3

	int i = 0;
	int in_len = PACKETLEN;//����
	time_t t;                 //�����б�֤ÿ�β������������ͬ
    srand( (unsigned) time( &t ) ); 

	pt[in_len] = '\0';
	//����ͨ�����������
	for(i=0;i<in_len;i++)
		pt[i] = 97+rand()*26/RAND_MAX;
	printf("Origin Data:%s\n",pt);
	//��Կͨ�����������
	for(i=0;i<in_len;i++)
	{
		key1[i] = 97+rand()*26/RAND_MAX;
		key2[i] = 97+rand()*26/RAND_MAX;
		key3[i] = 97+rand()*26/RAND_MAX;
	}

des_key skey1,skey2,skey3;
//��β���
pt[in_len]=ct[in_len]='\0';
temp1[in_len]=temp2[in_len]='\0';
//��ʼ��
des_setup((unsigned char*)key1,PACKETLEN,0,&skey1);
des_setup((unsigned char*)key2,PACKETLEN,0,&skey2);
des_setup((unsigned char*)key3,PACKETLEN,0,&skey3);
//���ܹ���
des_ecb_encrypt(pt,temp1,&skey1);//k1����
des_ecb_decrypt(temp1,temp2,&skey2);//k2����
des_ecb_encrypt(temp2,ct,&skey3);//k3����
//���ܹ���
des_ecb_decrypt(ct,temp2,&skey3);//k3����
des_ecb_encrypt(temp2,temp1,&skey2);//k2����
des_ecb_decrypt(temp1,pt,&skey1);//k1����

printf("����%s\n",pt);

printf("����%s\n",ct);

printf("�ָ�����%s\n",pt); 
*/

Inintialize_Encrypt_Decrypt("abcsssss","defuuuuu","uuutghtg");
string m_t;//="yyuuip112wweqweqwewfscx";
cout<<"��������:";
cin>>m_t;
cout<<"����:"<<endl<<m_t<<endl;


string c_t="";
string p_t="";
int k=0;
/*
do
{
	m_temp[k]=m_t.substr(8*k,8);
	c_temp[k]=_3DES_Encrypt(m_temp[k]);
	c_t=c_t+c_temp[k];
	k++;
}
while(8*k<m_t.length());
*/
//string c_t="";
/*
k=0;
do
{
	//q_temp[100]=c_t.substr(8*k,8);
	p_temp[k]=_3DES_Decrypt(c_temp[k]);
	p_t=p_t+p_temp[k];
	k++;
}
while(8*k<m_t.length());
*/




/*

cout<<"����:"<<endl;
c_t=Encrypt_All_Data_ECB_ZERO(m_t);
cout<<c_t<<endl;


p_t=Decrypt_All_Data_ECB_ZERO(c_t);

cout<<"�ָ�����:"<<endl<<p_t<<endl;

cout<<"����:"<<endl;
c_t=Encrypt_All_Data_ECB_PKCS7(m_t);
cout<<c_t<<endl;


p_t=Decrypt_All_Data_ECB_PKCS7(c_t);

cout<<"�ָ�����:"<<endl<<p_t<<endl;
cout<<"����:"<<endl;
c_t=Encrypt_All_Data_ECB_ANSIX923(m_t);
cout<<c_t<<endl;


p_t=Decrypt_All_Data_ECB_ANSIX923(c_t);

cout<<"�ָ�����:"<<endl<<p_t<<endl;
cout<<"����:"<<endl;
c_t=Encrypt_All_Data_ECB_ISO10126(m_t);
cout<<c_t<<endl;


p_t=Decrypt_All_Data_ECB_ISO10126(c_t);

cout<<"�ָ�����:"<<endl<<p_t<<endl;

cout<<"����:"<<endl;
c_t=Encrypt_All_Data_CBC_ZERO(m_t);
cout<<c_t<<endl;


p_t=Decrypt_All_Data_CBC_ZERO(c_t);

cout<<"�ָ�����:"<<endl<<p_t<<endl;

cout<<"����:"<<endl;
c_t=Encrypt_All_Data_CBC_PKCS7(m_t);
cout<<c_t<<endl;


p_t=Decrypt_All_Data_CBC_PKCS7(c_t);

cout<<"�ָ�����:"<<endl<<p_t<<endl;
cout<<"����:"<<endl;
c_t=Encrypt_All_Data_CBC_ANSIX923(m_t);
cout<<c_t<<endl;


p_t=Decrypt_All_Data_CBC_ANSIX923(c_t);

cout<<"�ָ�����:"<<endl<<p_t<<endl;
cout<<"����:"<<endl;
c_t=Encrypt_All_Data_CBC_ISO10126(m_t);
cout<<c_t<<endl;


p_t=Decrypt_All_Data_CBC_ISO10126(c_t);

cout<<"�ָ�����:"<<endl<<p_t<<endl;


cout<<"����:"<<endl;
c_t=Encrypt_All_Data_CFB_ZERO(m_t);
cout<<c_t<<endl;


p_t=Decrypt_All_Data_CFB_ZERO(c_t);

cout<<"�ָ�����:"<<endl<<p_t<<endl;

cout<<"����:"<<endl;
c_t=Encrypt_All_Data_CFB_PKCS7(m_t);
cout<<c_t<<endl;


p_t=Decrypt_All_Data_CFB_PKCS7(c_t);

cout<<"�ָ�����:"<<endl<<p_t<<endl;
cout<<"����:"<<endl;
c_t=Encrypt_All_Data_CFB_ANSIX923(m_t);
cout<<c_t<<endl;


p_t=Decrypt_All_Data_CFB_ANSIX923(c_t);

cout<<"�ָ�����:"<<endl<<p_t<<endl;
cout<<"����:"<<endl;
c_t=Encrypt_All_Data_CFB_ISO10126(m_t);
cout<<c_t<<endl;


p_t=Decrypt_All_Data_CFB_ISO10126(c_t);

cout<<"�ָ�����:"<<endl<<p_t<<endl;



cout<<"����:"<<endl;
c_t=Encrypt_All_Data_OFB_ZERO(m_t);
cout<<c_t<<endl;


p_t=Decrypt_All_Data_OFB_ZERO(c_t);

cout<<"�ָ�����:"<<endl<<p_t<<endl;


cout<<"����:"<<endl;
c_t=Encrypt_All_Data_OFB_PKCS7(m_t);
cout<<c_t<<endl;


p_t=Decrypt_All_Data_OFB_PKCS7(c_t);

cout<<"�ָ�����:"<<endl<<p_t<<endl;

cout<<"����:"<<endl;
c_t=Encrypt_All_Data_OFB_ANSIX923(m_t);
cout<<c_t<<endl;


p_t=Decrypt_All_Data_OFB_ANSIX923(c_t);

cout<<"�ָ�����:"<<endl<<p_t<<endl;

cout<<"����:"<<endl;
c_t=Encrypt_All_Data_OFB_ISO10126(m_t);
cout<<c_t<<endl;


p_t=Decrypt_All_Data_OFB_ISO10126(c_t);

cout<<"�ָ�����:"<<endl<<p_t<<endl;
cout<<endl<<endl;
for(int i=0;i<8;i++)
	cout<<hex<<(int)IV[i]<<"\t";

*/
cout<<"����:"<<endl;
c_t=Encrypt_All_Data_CTR_ISO10126(m_t);
cout<<c_t<<endl;


p_t=Decrypt_All_Data_CTR_ISO10126(c_t);

cout<<"�ָ�����:"<<endl<<p_t<<endl;

system("PAUSE");

return 0;

}

