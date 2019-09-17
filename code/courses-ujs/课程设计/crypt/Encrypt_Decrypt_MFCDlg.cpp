
// Encrypt_Decrypt_MFCDlg.cpp : ʵ���ļ�
//
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS 1//ȥ��������ʾ
#endif
#include "stdafx.h"
#include "Encrypt_Decrypt_MFC.h"
#include "Encrypt_Decrypt_MFCDlg.h"
#include "afxdialogex.h"
#include "des.h"

#include <string>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
//�ӽ��ܴ���


void CEncrypt_Decrypt_MFCDlg::_3DES_Startup(string k1, string k2, string k3)//3des��Կ��ʼ��
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < 8; i++)
		//IV[i] = (unsigned char)(rand() % 255 + 1);
		IV[i] = (unsigned char)((i+2)*16+(i+5));//�����������IV
	//����м����
	for (int i = 0; i < 100; i++)
	{
		m_temp[i] = "";
		c_temp[i] = "";
		p_temp[i] = "";
		ctr_temp[i] = "";
	}
	//stringת����unsigned char*����
	int n1 = k1.length();
	int n2 = k2.length();
	int n3 = k3.length();
	unsigned char *key1 = new unsigned char[8];
	unsigned char *key2 = new unsigned char[8];
	unsigned char *key3 = new unsigned char[8];
	strcpy((char*)key1, k1.c_str());
	strcpy((char*)key2, k2.c_str());
	strcpy((char*)key3, k3.c_str());
	key1[7] = 0;
	key2[7] = 0;
	key3[7] = 0;
	des_setup((unsigned char*)key1, 8, 0, &s_k1);//��ʼ����Կk1
	des_setup((unsigned char*)key2, 8, 0, &s_k2);//��ʼ����Կk2
	des_setup((unsigned char*)key3, 8, 0, &s_k3);//��ʼ����Կk3
}

string CEncrypt_Decrypt_MFCDlg::_3DES_Encrypt(string m)//3des���ܺ���
{
	unsigned char *pt = new unsigned char[m.length() + 1];
	unsigned char *temp1 = new unsigned char[m.length() + 1];
	unsigned char *temp2 = new unsigned char[m.length() + 1];
	unsigned char *ct = new unsigned char[m.length() + 1];
	for (int i = 0; i < m.length() + 1; i++)
	{
		pt[i] = 0;
		temp1[i] = 0;
		temp2[i] = 0;
		ct[i] = 0;
	}
	//stringת����unsigned char*����
	strcpy((char *)pt, m.c_str());
	pt[m.length()] = 0;
	des_ecb_encrypt(pt, temp1, &s_k1);//��k1����
	des_ecb_decrypt(temp1, temp2, &s_k2);//��k2����
	des_ecb_encrypt(temp2, ct, &s_k3);//��k3����
	string c((char *)ct);
	//unsigned charת����string ����
	return c;
}

string CEncrypt_Decrypt_MFCDlg::_3DES_Decrypt(string c)//3des���ܺ���
{
	unsigned char *pt = new unsigned char[c.length() + 1];
	unsigned char *temp1 = new unsigned char[c.length() + 1];
	unsigned char *temp2 = new unsigned char[c.length() + 1];
	unsigned char *ct = new unsigned char[c.length() + 1];
	for (int i = 0; i < c.length() + 1; i++)
	{
		pt[i] = 0;
		temp1[i] = 0;
		temp2[i] = 0;
		ct[i] = 0;
	}
	//stringת����unsigned char *����
	strcpy((char *)ct, c.c_str());
	ct[c.length()] = 0;
	des_ecb_decrypt(ct, temp2, &s_k3);//��k3����
	des_ecb_encrypt(temp2, temp1, &s_k2);//��k2����
	des_ecb_decrypt(temp1, pt, &s_k1);//��k1����
	//unsigned char *ת����string����
	string m((char *)pt);
	return m;
}

void CEncrypt_Decrypt_MFCDlg::Inintialize_Encrypt_Decrypt(string s1, string s2, string s3)//3des��ʼ��
{
	_3DES_Startup(s1, s2, s3);//������Կ��ʼ������
}


string CEncrypt_Decrypt_MFCDlg::Encrypt_All_Data_ECB_ZERO(string m)//ECBģʽ���ܣ����ֽ����
{
	string c = "";
	int k = 0;

	do
	{
		m_temp[k] = m.substr(8 * k, 8);
		//�������
		if (m_temp[k].length() < 8)
		{
			int count_sub = 8 - m_temp[k].length();
			m_temp[k].append(count_sub, 0x00);
		}
		c_temp[k] = _3DES_Encrypt(m_temp[k]);
		c = c + c_temp[k];
		k++;
	} while (8 * k < m.length());
	c_temp[k] = "\0";
	return c;
}

string CEncrypt_Decrypt_MFCDlg::Decrypt_All_Data_ECB_ZERO(string c)//ECBģʽ���ܣ����ֽ����
{
	int k = 0;
	string p = "";
	do
	{
		p_temp[k] = _3DES_Decrypt(c_temp[k]);
		//�������
		for (int i = 0; i < p_temp[k].length(); i++)
		if (p_temp[k][i] < 0x08)
			p_temp[k] = p_temp[k].substr(0, i);
		p = p + p_temp[k];
		k++;
	} while (c_temp[k] != "\0");
	return p;
}

string CEncrypt_Decrypt_MFCDlg::Encrypt_All_Data_ECB_PKCS7(string m)//ECBģʽ���ܣ�PKCS7��ʽ���
{
	string c = "";
	int k = 0;

	do
	{
		m_temp[k] = m.substr(8 * k, 8);
		//�������
		if (m_temp[k].length() < 8)
		{
			int count_sub = 8 - m_temp[k].length();
			m_temp[k].append(count_sub, (char)count_sub);
		}
		c_temp[k] = _3DES_Encrypt(m_temp[k]);
		c = c + c_temp[k];
		k++;
	} while (8 * k < m.length());
	c_temp[k] = "\0";
	return c;
}

string CEncrypt_Decrypt_MFCDlg::Decrypt_All_Data_ECB_PKCS7(string c)//ECBģʽ���ܣ�PKCS7��ʽ���
{
	int k = 0;
	string p = "";
	do
	{
		p_temp[k] = _3DES_Decrypt(c_temp[k]);
		//�������
		for (int i = 0; i < p_temp[k].length(); i++)
		if (p_temp[k][i] < 0x08)
			p_temp[k] = p_temp[k].substr(0, i);
		p = p + p_temp[k];
		k++;
	} while (c_temp[k] != "\0");
	return p;
}


string CEncrypt_Decrypt_MFCDlg::Encrypt_All_Data_ECB_ANSIX923(string m)//ECBģʽ���ܣ�ANSI X.923��ʽ���
{
	string c = "";
	int k = 0;

	do
	{
		m_temp[k] = m.substr(8 * k, 8);
		//�������
		if (m_temp[k].length()<8)
		{
			int count_sub = 8 - m_temp[k].length();
			if (count_sub - 1>0)
				m_temp[k].append(count_sub - 1, 0x00);
			m_temp[k].append(1, (char)count_sub);
		}
		c_temp[k] = _3DES_Encrypt(m_temp[k]);
		c = c + c_temp[k];
		k++;
	} while (8 * k < m.length());
	c_temp[k] = "\0";
	return c;
}

string CEncrypt_Decrypt_MFCDlg::Decrypt_All_Data_ECB_ANSIX923(string c)//ECBģʽ���ܣ�ANSI X.923��ʽ���
{
	int k = 0;
	string p = "";
	do
	{
		p_temp[k] = _3DES_Decrypt(c_temp[k]);
		//�������
		for (int i = 0; i < p_temp[k].length(); i++)
		if (p_temp[k][i] < 0x08)
			p_temp[k] = p_temp[k].substr(0, i);
		p = p + p_temp[k];
		k++;
	} while (c_temp[k] != "\0");
	return p;
}

string CEncrypt_Decrypt_MFCDlg::Encrypt_All_Data_ECB_ISO10126(string m)//ECBģʽ���ܣ�ISO 10126��ʽ���
{
	string c = "";
	int k = 0;

	do
	{
		m_temp[k] = m.substr(8 * k, 8);
		//�������
		if (m_temp[k].length()<8)
		{
			int count_sub = 8 - m_temp[k].length();
			if (count_sub - 1>0)
			{
				srand((unsigned)time(NULL));
				unsigned int fill = rand() % 256;
				m_temp[k].append(count_sub - 1, (char)fill);
			}
			m_temp[k].append(1, (char)count_sub);
		}
		c_temp[k] = _3DES_Encrypt(m_temp[k]);
		c = c + c_temp[k];
		k++;
	} while (8 * k < m.length());
	c_temp[k] = "\0";
	return c;
}

string CEncrypt_Decrypt_MFCDlg::Decrypt_All_Data_ECB_ISO10126(string c)//ECBģʽ���ܣ�ISO 10126��ʽ���
{
	int k = 0;
	string p = "";
	do
	{
		p_temp[k] = _3DES_Decrypt(c_temp[k]);
		//�������
		for (int i = 0; i < p_temp[k].length(); i++)
		if (p_temp[k][i] < 0x08)
			p_temp[k] = p_temp[k].substr(0, p_temp[k].length() - (int)p_temp[k][i]);
		p = p + p_temp[k];
		k++;
	} while (c_temp[k] != "\0");
	return p;
}


string CEncrypt_Decrypt_MFCDlg::Encrypt_All_Data_CBC_ZERO(string m)//CBCģʽ���ܣ����ֽ����
{
	string c = "";
	int k = 0;

	do
	{
		m_temp[k] = m.substr(8 * k, 8);

		//�������
		if (m_temp[k].length() < 8)
		{
			int count_sub = 8 - m_temp[k].length();
			m_temp[k].append(count_sub, 0x00);
		}

		//�������
		if (k == 0)
		for (int i = 0; i < 8; i++)
			m_temp[k][i] = m_temp[k][i] ^ IV[i];
		else
		for (int i = 0; i < 8; i++)
			m_temp[k][i] = m_temp[k][i] ^ c_temp[k - 1][i];
		c_temp[k] = _3DES_Encrypt(m_temp[k]);
		c = c + c_temp[k];
		k++;
	} while (8 * k < m.length());
	c_temp[k] = "\0";
	return c;
}

string CEncrypt_Decrypt_MFCDlg::Decrypt_All_Data_CBC_ZERO(string c)//CBCģʽ���ܣ����ֽ����
{
	int k = 0;
	string p = "";
	do
	{
		p_temp[k] = _3DES_Decrypt(c_temp[k]);

		//�������
		if (k == 0)
		for (int i = 0; i < 8; i++)
			p_temp[k][i] = p_temp[k][i] ^ IV[i];
		else
		for (int i = 0; i < 8; i++)
			p_temp[k][i] = p_temp[k][i] ^ c_temp[k - 1][i];
		//�������
		for (int i = 0; i < p_temp[k].length(); i++)
		if (p_temp[k][i] < 0x08)
			p_temp[k] = p_temp[k].substr(0, i);

		p = p + p_temp[k];
		k++;
	} while (c_temp[k] != "\0");
	return p;
}


string CEncrypt_Decrypt_MFCDlg::Encrypt_All_Data_CBC_PKCS7(string m)//CBCģʽ���ܣ�PKCS7��ʽ���
{
	string c = "";
	int k = 0;

	do
	{
		m_temp[k] = m.substr(8 * k, 8);

		//�������
		if (m_temp[k].length() < 8)
		{
			int count_sub = 8 - m_temp[k].length();
			m_temp[k].append(count_sub, (char)count_sub);
		}

		//�������
		if (k == 0)
		for (int i = 0; i < 8; i++)
			m_temp[k][i] = m_temp[k][i] ^ IV[i];
		else
		for (int i = 0; i < 8; i++)
			m_temp[k][i] = m_temp[k][i] ^ c_temp[k - 1][i];
		c_temp[k] = _3DES_Encrypt(m_temp[k]);
		c = c + c_temp[k];
		k++;
	} while (8 * k < m.length());
	c_temp[k] = "\0";
	return c;
}

string CEncrypt_Decrypt_MFCDlg::Decrypt_All_Data_CBC_PKCS7(string c)//CBCģʽ���ܣ�PKCS7��ʽ���
{
	int k = 0;
	string p = "";
	do
	{
		p_temp[k] = _3DES_Decrypt(c_temp[k]);

		//�������
		if (k == 0)
		for (int i = 0; i < 8; i++)
			p_temp[k][i] = p_temp[k][i] ^ IV[i];
		else
		for (int i = 0; i < 8; i++)
			p_temp[k][i] = p_temp[k][i] ^ c_temp[k - 1][i];
		//�������
		for (int i = 0; i < p_temp[k].length(); i++)
		if (p_temp[k][i] < 0x08)
			p_temp[k] = p_temp[k].substr(0, i);

		p = p + p_temp[k];
		k++;
	} while (c_temp[k] != "\0");
	return p;
}

string CEncrypt_Decrypt_MFCDlg::Encrypt_All_Data_CBC_ANSIX923(string m)//CBCģʽ���ܣ�ANSI X.923��ʽ���
{
	string c = "";
	int k = 0;

	do
	{
		m_temp[k] = m.substr(8 * k, 8);

		//�������
		if (m_temp[k].length()<8)
		{
			int count_sub = 8 - m_temp[k].length();
			if (count_sub - 1>0)
				m_temp[k].append(count_sub - 1, 0x00);
			m_temp[k].append(1, (char)count_sub);
		}

		//�������
		if (k == 0)
		for (int i = 0; i < 8; i++)
			m_temp[k][i] = m_temp[k][i] ^ IV[i];
		else
		for (int i = 0; i < 8; i++)
			m_temp[k][i] = m_temp[k][i] ^ c_temp[k - 1][i];
		c_temp[k] = _3DES_Encrypt(m_temp[k]);
		c = c + c_temp[k];
		k++;
	} while (8 * k < m.length());
	c_temp[k] = "\0";
	return c;
}

string CEncrypt_Decrypt_MFCDlg::Decrypt_All_Data_CBC_ANSIX923(string c)//CBCģʽ���ܣ�ANSI X.923��ʽ���
{
	int k = 0;
	string p = "";
	do
	{
		p_temp[k] = _3DES_Decrypt(c_temp[k]);

		//�������
		if (k == 0)
		for (int i = 0; i < 8; i++)
			p_temp[k][i] = p_temp[k][i] ^ IV[i];
		else
		for (int i = 0; i < 8; i++)
			p_temp[k][i] = p_temp[k][i] ^ c_temp[k - 1][i];
		//�������
		for (int i = 0; i < p_temp[k].length(); i++)
		if (p_temp[k][i] < 0x08)
			p_temp[k] = p_temp[k].substr(0, i);

		p = p + p_temp[k];
		k++;
	} while (c_temp[k] != "\0");
	return p;
}

string CEncrypt_Decrypt_MFCDlg::Encrypt_All_Data_CBC_ISO10126(string m)//CBCģʽ���ܣ�ISO 10126��ʽ���
{
	string c = "";
	int k = 0;

	do
	{
		m_temp[k] = m.substr(8 * k, 8);

		//�������
		if (m_temp[k].length()<8)
		{
			int count_sub = 8 - m_temp[k].length();
			if (count_sub - 1>0)
			{
				srand((unsigned)time(NULL));
				unsigned int fill = rand() % 256;
				m_temp[k].append(count_sub - 1, (char)fill);
			}
			m_temp[k].append(1, (char)count_sub);
		}

		//�������
		if (k == 0)
		for (int i = 0; i < 8; i++)
			m_temp[k][i] = m_temp[k][i] ^ IV[i];
		else
		for (int i = 0; i < 8; i++)
			m_temp[k][i] = m_temp[k][i] ^ c_temp[k - 1][i];
		c_temp[k] = _3DES_Encrypt(m_temp[k]);
		c = c + c_temp[k];
		k++;
	} while (8 * k < m.length());
	c_temp[k] = "\0";
	return c;


}

string CEncrypt_Decrypt_MFCDlg::Decrypt_All_Data_CBC_ISO10126(string c)//CBCģʽ���ܣ�ISO 10126��ʽ���
{
	int k = 0;
	string p = "";
	do
	{
		p_temp[k] = _3DES_Decrypt(c_temp[k]);

		//�������
		if (k == 0)
		for (int i = 0; i < 8; i++)
			p_temp[k][i] = p_temp[k][i] ^ IV[i];
		else
		for (int i = 0; i < 8; i++)
			p_temp[k][i] = p_temp[k][i] ^ c_temp[k - 1][i];
		//�������
		for (int i = 0; i < p_temp[k].length(); i++)
		if (p_temp[k][i] < 0x08)
			p_temp[k] = p_temp[k].substr(0, p_temp[k].length() - (int)p_temp[k][i]);

		p = p + p_temp[k];
		k++;
	} while (c_temp[k] != "\0");
	return p;


}


string CEncrypt_Decrypt_MFCDlg::Encrypt_All_Data_CFB_ZERO(string m)//CFBģʽ���ܣ����ֽ����
{
	string c = "";
	int k = 0;

	do
	{
		m_temp[k] = m.substr(8 * k, 8);

		//�������
		if (m_temp[k].length() < 8)
		{
			int count_sub = 8 - m_temp[k].length();
			m_temp[k].append(count_sub, 0x00);
		}

		//�������
		string iv((char *)IV);
		if (k == 0)
			c_temp[k] = _3DES_Encrypt(iv);
		else
			c_temp[k] = _3DES_Encrypt(c_temp[k - 1]);
		for (int i = 0; i < 8; i++)
			c_temp[k][i] = c_temp[k][i] ^ m_temp[k][i];
		c = c + c_temp[k];
		k++;
	} while (8 * k < m.length());
	c_temp[k] = "\0";
	return c;


}

string CEncrypt_Decrypt_MFCDlg::Decrypt_All_Data_CFB_ZERO(string c)//CFBģʽ���ܣ����ֽ����
{
	int k = 0;
	string p = "";
	do
	{
		string iv((char *)IV);
		if (k == 0)
			p_temp[k] = _3DES_Encrypt(iv);
		else
			p_temp[k] = _3DES_Encrypt(c_temp[k - 1]);
		p_temp[k] = p_temp[k].substr(0, 8);
		//�������
		for (int i = 0; i < 8; i++)
			p_temp[k][i] = p_temp[k][i] ^ c_temp[k][i];
		//�������
		for (int i = 0; i < p_temp[k].length(); i++)
		if (p_temp[k][i] < 0x08)
			p_temp[k] = p_temp[k].substr(0, i);

		p = p + p_temp[k];
		k++;
	} while (c_temp[k] != "\0");
	return p;


}


string CEncrypt_Decrypt_MFCDlg::Encrypt_All_Data_CFB_PKCS7(string m)//CFBģʽ���ܣ�PKCS7��ʽ���
{
	string c = "";
	int k = 0;

	do
	{
		m_temp[k] = m.substr(8 * k, 8);

		//�������
		if (m_temp[k].length() < 8)
		{
			int count_sub = 8 - m_temp[k].length();
			m_temp[k].append(count_sub, (char)count_sub);
		}

		//�������
		string iv((char *)IV);
		if (k == 0)
			c_temp[k] = _3DES_Encrypt(iv);
		else
			c_temp[k] = _3DES_Encrypt(c_temp[k - 1]);
		for (int i = 0; i < 8; i++)
			c_temp[k][i] = c_temp[k][i] ^ m_temp[k][i];
		c = c + c_temp[k];
		k++;
	} while (8 * k < m.length());
	c_temp[k] = "\0";
	return c;


}

string CEncrypt_Decrypt_MFCDlg::Decrypt_All_Data_CFB_PKCS7(string c)//CFBģʽ���ܣ�PKCS7��ʽ���
{
	int k = 0;
	string p = "";
	do
	{
		string iv((char *)IV);
		if (k == 0)
			p_temp[k] = _3DES_Encrypt(iv);
		else
			p_temp[k] = _3DES_Encrypt(c_temp[k - 1]);
		p_temp[k] = p_temp[k].substr(0, 8);
		//�������
		for (int i = 0; i < 8; i++)
			p_temp[k][i] = p_temp[k][i] ^ c_temp[k][i];
		//�������
		for (int i = 0; i < p_temp[k].length(); i++)
		if (p_temp[k][i] < 0x08)
			p_temp[k] = p_temp[k].substr(0, i);

		p = p + p_temp[k];
		k++;
	} while (c_temp[k] != "\0");
	return p;


}


string CEncrypt_Decrypt_MFCDlg::Encrypt_All_Data_CFB_ANSIX923(string m)//CFBģʽ���ܣ�ANSI X.923��ʽ���
{
	string c = "";
	int k = 0;

	do
	{
		m_temp[k] = m.substr(8 * k, 8);

		//�������
		if (m_temp[k].length()<8)
		{
			int count_sub = 8 - m_temp[k].length();
			if (count_sub - 1>0)
				m_temp[k].append(count_sub - 1, 0x00);
			m_temp[k].append(1, (char)count_sub);
		}

		//�������
		string iv((char *)IV);
		if (k == 0)
			c_temp[k] = _3DES_Encrypt(iv);
		else
			c_temp[k] = _3DES_Encrypt(c_temp[k - 1]);
		for (int i = 0; i < 8; i++)
			c_temp[k][i] = c_temp[k][i] ^ m_temp[k][i];
		c = c + c_temp[k];
		k++;
	} while (8 * k < m.length());
	c_temp[k] = "\0";
	return c;
}

string CEncrypt_Decrypt_MFCDlg::Decrypt_All_Data_CFB_ANSIX923(string c)//CFBģʽ���ܣ�ANSI X.923��ʽ���
{
	int k = 0;
	string p = "";
	do
	{
		string iv((char *)IV);
		if (k == 0)
			p_temp[k] = _3DES_Encrypt(iv);
		else
			p_temp[k] = _3DES_Encrypt(c_temp[k - 1]);
		p_temp[k] = p_temp[k].substr(0, 8);
		//�������
		for (int i = 0; i < 8; i++)
			p_temp[k][i] = p_temp[k][i] ^ c_temp[k][i];
		//�������
		for (int i = 0; i < p_temp[k].length(); i++)
		if (p_temp[k][i] < 0x08)
			p_temp[k] = p_temp[k].substr(0, i);

		p = p + p_temp[k];
		k++;
	} while (c_temp[k] != "\0");
	return p;
}


string CEncrypt_Decrypt_MFCDlg::Encrypt_All_Data_CFB_ISO10126(string m)//CFBģʽ���ܣ�ISO 10126��ʽ���
{
	string c = "";
	int k = 0;

	do
	{
		m_temp[k] = m.substr(8 * k, 8);

		//�������
		if (m_temp[k].length()<8)
		{
			int count_sub = 8 - m_temp[k].length();
			if (count_sub - 1>0)
			{
				srand((unsigned)time(NULL));
				unsigned int fill = rand() % 256;
				m_temp[k].append(count_sub - 1, (char)fill);
			}
			m_temp[k].append(1, (char)count_sub);
		}

		//�������
		string iv((char *)IV);
		if (k == 0)
			c_temp[k] = _3DES_Encrypt(iv);
		else
			c_temp[k] = _3DES_Encrypt(c_temp[k - 1]);

		for (int i = 0; i < 8; i++)
			c_temp[k][i] = c_temp[k][i] ^ m_temp[k][i];
		c = c + c_temp[k];
		k++;
	} while (8 * k < m.length());
	c_temp[k] = "\0";
	return c;
}

string CEncrypt_Decrypt_MFCDlg::Decrypt_All_Data_CFB_ISO10126(string c)//CFBģʽ���ܣ�ISO 10126��ʽ���
{
	int k = 0;
	string p = "";
	do
	{
		string iv((char *)IV);
		if (k == 0)
			p_temp[k] = _3DES_Encrypt(iv);
		else
			p_temp[k] = _3DES_Encrypt(c_temp[k - 1]);
		p_temp[k] = p_temp[k].substr(0, 8);
		//�������
		for (int i = 0; i < 8; i++)
			p_temp[k][i] = p_temp[k][i] ^ c_temp[k][i];
		//�������
		for (int i = 0; i < p_temp[k].length(); i++)
		if (p_temp[k][i] < 0x08)
			p_temp[k] = p_temp[k].substr(0, p_temp[k].length() - (int)p_temp[k][i]);

		p = p + p_temp[k];
		k++;
	} while (c_temp[k] != "\0");
	return p;
}


string CEncrypt_Decrypt_MFCDlg::Encrypt_All_Data_OFB_ZERO(string m)//OFBģʽ���ܣ����ֽ����
{
	string c = "";
	int k = 0;
	for (int i = 0; i < 100; i++)
		c_temp[i] = "";
	do
	{
		m_temp[k] = m.substr(8 * k, 8);

		//�������
		if (m_temp[k].length() < 8)
		{
			int count_sub = 8 - m_temp[k].length();
			m_temp[k].append(count_sub, 0x00);
		}

		//�������
		string iv((char *)IV);
		string key = iv;
		for (int i = 0; i < k + 1; i++)
			key = _3DES_Encrypt(key);

		for (int i = 0; i < 8; i++)
			c_temp[k].append(1, (char)key[i] ^ m_temp[k][i]);
		c = c + c_temp[k];
		k++;
	} while (8 * k < m.length());
	c_temp[k] = "\0";
	return c;
}

string CEncrypt_Decrypt_MFCDlg::Decrypt_All_Data_OFB_ZERO(string c)//OFBģʽ���ܣ����ֽ����
{
	int k = 0;
	string p = "";
	for (int i = 0; i < 100; i++)
		p_temp[i] = "";
	do
	{
		string iv((char *)IV);
		string key = iv;
		for (int i = 0; i < k + 1; i++)
			key = _3DES_Encrypt(key);
		key = key.substr(0, 8);
		//�������

		for (int i = 0; i < 8; i++)
			p_temp[k].append(1, key[i] ^ c_temp[k][i]);
		//�������
		for (int i = 0; i < p_temp[k].length(); i++)
		if (p_temp[k][i] < 0x08)
			p_temp[k] = p_temp[k].substr(0, i);

		p = p + p_temp[k];
		k++;
	} while (c_temp[k] != "\0");
	return p;
}


string CEncrypt_Decrypt_MFCDlg::Encrypt_All_Data_OFB_PKCS7(string m)//OFBģʽ���ܣ�PKCS7��ʽ���
{
	string c = "";
	int k = 0;
	for (int i = 0; i < 100; i++)
		c_temp[i] = "";
	do
	{
		m_temp[k] = m.substr(8 * k, 8);

		//�������
		if (m_temp[k].length() < 8)
		{
			int count_sub = 8 - m_temp[k].length();
			m_temp[k].append(count_sub, (char)count_sub);
		}

		//�������
		string iv((char *)IV);
		string key = iv;
		for (int i = 0; i < k + 1; i++)
			key = _3DES_Encrypt(key);

		for (int i = 0; i < 8; i++)
			c_temp[k].append(1, (char)key[i] ^ m_temp[k][i]);
		c = c + c_temp[k];
		k++;
	} while (8 * k < m.length());
	c_temp[k] = "\0";
	return c;
}

string CEncrypt_Decrypt_MFCDlg::Decrypt_All_Data_OFB_PKCS7(string c)//OFBģʽ���ܣ�PKCS7��ʽ���
{
	int k = 0;
	string p = "";
	for (int i = 0; i < 100; i++)
		p_temp[i] = "";
	do
	{
		string iv((char *)IV);
		string key = iv;
		for (int i = 0; i < k + 1; i++)
			key = _3DES_Encrypt(key);
		key = key.substr(0, 8);
		//�������

		for (int i = 0; i < 8; i++)
			p_temp[k].append(1, key[i] ^ c_temp[k][i]);
		//�������
		for (int i = 0; i < p_temp[k].length(); i++)
		if (p_temp[k][i] < 0x08)
			p_temp[k] = p_temp[k].substr(0, i);

		p = p + p_temp[k];
		k++;
	} while (c_temp[k] != "\0");
	return p;
}

string CEncrypt_Decrypt_MFCDlg::Encrypt_All_Data_OFB_ANSIX923(string m)//OFBģʽ���ܣ�ANSI X.923��ʽ���
{
	string c = "";
	int k = 0;
	for (int i = 0; i < 100; i++)
		c_temp[i] = "";
	do
	{
		m_temp[k] = m.substr(8 * k, 8);

		//�������
		if (m_temp[k].length()<8)
		{
			int count_sub = 8 - m_temp[k].length();
			if (count_sub - 1>0)
				m_temp[k].append(count_sub - 1, 0x00);
			m_temp[k].append(1, (char)count_sub);
		}

		//�������
		string iv((char *)IV);
		string key = iv;
		for (int i = 0; i < k + 1; i++)
			key = _3DES_Encrypt(key);

		for (int i = 0; i < 8; i++)
			c_temp[k].append(1, (char)key[i] ^ m_temp[k][i]);
		c = c + c_temp[k];
		k++;
	} while (8 * k < m.length());
	c_temp[k] = "\0";
	return c;
}

string CEncrypt_Decrypt_MFCDlg::Decrypt_All_Data_OFB_ANSIX923(string c)//OFBģʽ���ܣ�ANSI X.923��ʽ���
{
	int k = 0;
	string p = "";
	for (int i = 0; i < 100; i++)
		p_temp[i] = "";
	do
	{
		string iv((char *)IV);
		string key = iv;
		for (int i = 0; i < k + 1; i++)
			key = _3DES_Encrypt(key);
		key = key.substr(0, 8);
		//�������

		for (int i = 0; i < 8; i++)
			p_temp[k].append(1, key[i] ^ c_temp[k][i]);
		//�������
		for (int i = 0; i < p_temp[k].length(); i++)
		if (p_temp[k][i] < 0x08)
			p_temp[k] = p_temp[k].substr(0, i);

		p = p + p_temp[k];
		k++;
	} while (c_temp[k] != "\0");
	return p;
}

string CEncrypt_Decrypt_MFCDlg::Encrypt_All_Data_OFB_ISO10126(string m)//OFBģʽ���ܣ�ISO 10126��ʽ���
{
	string c = "";
	int k = 0;
	for (int i = 0; i < 100; i++)
		c_temp[i] = "";
	do
	{
		m_temp[k] = m.substr(8 * k, 8);

		//�������
		if (m_temp[k].length()<8)
		{
			int count_sub = 8 - m_temp[k].length();
			if (count_sub - 1>0)
			{
				srand((unsigned)time(NULL));
				unsigned int fill = rand() % 256;
				m_temp[k].append(count_sub - 1, (char)fill);
			}
			m_temp[k].append(1, (char)count_sub);
		}

		//�������
		string iv((char *)IV);
		string key = iv;
		for (int i = 0; i < k + 1; i++)
			key = _3DES_Encrypt(key);

		for (int i = 0; i < 8; i++)
			c_temp[k].append(1, (char)key[i] ^ m_temp[k][i]);
		c = c + c_temp[k];
		k++;
	} while (8 * k < m.length());
	c_temp[k] = "\0";
	return c;
}

string CEncrypt_Decrypt_MFCDlg::Decrypt_All_Data_OFB_ISO10126(string c)//OFBģʽ���ܣ�ISO 10126��ʽ���
{
	int k = 0;
	string p = "";
	for (int i = 0; i < 100; i++)
		p_temp[i] = "";
	do
	{
		string iv((char *)IV);
		string key = iv;
		for (int i = 0; i < k + 1; i++)
			key = _3DES_Encrypt(key);
		key = key.substr(0, 8);
		//�������

		for (int i = 0; i < 8; i++)
			p_temp[k].append(1, key[i] ^ c_temp[k][i]);
		//�������
		for (int i = 0; i < p_temp[k].length(); i++)
		if (p_temp[k][i] < 0x08)
			p_temp[k] = p_temp[k].substr(0, p_temp[k].length() - (int)p_temp[k][i]);


		p = p + p_temp[k];
		k++;
	} while (c_temp[k] != "\0");
	return p;
}



string CEncrypt_Decrypt_MFCDlg::Encrypt_All_Data_CTR_ZERO(string m)//CTRģʽ���ܣ����ֽ����
{
	string c = "";
	int k = 0;
	for (int i = 0; i < 100; i++)
		ctr_temp[i] = "";
	do
	{
		m_temp[k] = m.substr(8 * k, 8);
		//�������
		if (m_temp[k].length() < 8)
		{
			int count_sub = 8 - m_temp[k].length();
			m_temp[k].append(count_sub, 0x00);
		}
		//�������
		ctr_temp[k].append(1, (char)k);
		while (ctr_temp[k].length() < 8)
			ctr_temp[k].append(1, '0');
		c_temp[k] = _3DES_Encrypt(ctr_temp[k]);
		for (int i = 0; i < 8; i++)
			c_temp[k][i] = c_temp[k][i] ^ m_temp[k][i];
		c_temp[k] = c_temp[k].substr(0, 8);
		c = c + c_temp[k];
		k++;
	} while (8 * k < m.length());
	c_temp[k] = "\0";
	return c;
}

string CEncrypt_Decrypt_MFCDlg::Decrypt_All_Data_CTR_ZERO(string c)//CTRģʽ���ܣ����ֽ����
{
	int k = 0;
	string p = "";
	for (int i = 0; i < 100; i++)
		p_temp[i] = "";
	do
	{
		m_temp[k] = _3DES_Encrypt(ctr_temp[k]);
		for (int i = 0; i < 8; i++)
			p_temp[k].append(1, (char)(m_temp[k][i] ^ c_temp[k][i]));
		//�������
		for (int i = 0; i < p_temp[k].length(); i++)
		if (p_temp[k][i] < 0x08)
			p_temp[k] = p_temp[k].substr(0, i);
		p = p + p_temp[k];
		k++;
	} while (c_temp[k] != "\0");
	return p;
}

string CEncrypt_Decrypt_MFCDlg::Encrypt_All_Data_CTR_PKCS7(string m)//CTRģʽ���ܣ�PKCS7��ʽ���
{
	string c = "";
	int k = 0;
	for (int i = 0; i < 100; i++)
		ctr_temp[i] = "";
	do
	{
		m_temp[k] = m.substr(8 * k, 8);
		//�������
		if (m_temp[k].length() < 8)
		{
			int count_sub = 8 - m_temp[k].length();
			m_temp[k].append(count_sub, (char)count_sub);
		}
		//�������
		ctr_temp[k].append(1, (char)k);
		while (ctr_temp[k].length() < 8)
			ctr_temp[k].append(1, '0');
		c_temp[k] = _3DES_Encrypt(ctr_temp[k]);
		for (int i = 0; i < 8; i++)
			c_temp[k][i] = c_temp[k][i] ^ m_temp[k][i];
		c_temp[k] = c_temp[k].substr(0, 8);
		c = c + c_temp[k];
		k++;
	} while (8 * k < m.length());
	c_temp[k] = "\0";
	return c;
}

string CEncrypt_Decrypt_MFCDlg::Decrypt_All_Data_CTR_PKCS7(string c)//CTRģʽ���ܣ�PKCS7��ʽ���
{
	int k = 0;
	string p = "";
	for (int i = 0; i < 100; i++)
		p_temp[i] = "";
	do
	{
		m_temp[k] = _3DES_Encrypt(ctr_temp[k]);
		for (int i = 0; i < 8; i++)
			p_temp[k].append(1, (char)(m_temp[k][i] ^ c_temp[k][i]));
		//�������
		for (int i = 0; i < p_temp[k].length(); i++)
		if (p_temp[k][i] < 0x08)
			p_temp[k] = p_temp[k].substr(0, i);
		p = p + p_temp[k];
		k++;
	} while (c_temp[k] != "\0");
	return p;
}


string CEncrypt_Decrypt_MFCDlg::Encrypt_All_Data_CTR_ANSIX923(string m)//CTRģʽ���ܣ�ANSI X.923��ʽ���
{
	string c = "";
	int k = 0;
	for (int i = 0; i < 100; i++)
		ctr_temp[i] = "";
	do
	{
		m_temp[k] = m.substr(8 * k, 8);
		//�������
		if (m_temp[k].length()<8)
		{
			int count_sub = 8 - m_temp[k].length();
			if (count_sub - 1>0)
				m_temp[k].append(count_sub - 1, 0x00);
			m_temp[k].append(1, (char)count_sub);
		}
		//�������
		ctr_temp[k].append(1, (char)k);
		while (ctr_temp[k].length() < 8)
			ctr_temp[k].append(1, '0');
		c_temp[k] = _3DES_Encrypt(ctr_temp[k]);
		for (int i = 0; i < 8; i++)
			c_temp[k][i] = c_temp[k][i] ^ m_temp[k][i];
		c_temp[k] = c_temp[k].substr(0, 8);
		c = c + c_temp[k];
		k++;
	} while (8 * k < m.length());
	c_temp[k] = "\0";
	return c;
}

string CEncrypt_Decrypt_MFCDlg::Decrypt_All_Data_CTR_ANSIX923(string c)//CTRģʽ���ܣ�ANSI X.923��ʽ���
{
	int k = 0;
	string p = "";
	for (int i = 0; i < 100; i++)
		p_temp[i] = "";
	do
	{
		m_temp[k] = _3DES_Encrypt(ctr_temp[k]);
		for (int i = 0; i < 8; i++)
			p_temp[k].append(1, (char)(m_temp[k][i] ^ c_temp[k][i]));
		//�������
		for (int i = 0; i < p_temp[k].length(); i++)
		if (p_temp[k][i] < 0x08)
			p_temp[k] = p_temp[k].substr(0, i);
		p = p + p_temp[k];
		k++;
	} while (c_temp[k] != "\0");
	return p;
}

string CEncrypt_Decrypt_MFCDlg::Encrypt_All_Data_CTR_ISO10126(string m)//CTRģʽ���ܣ�ISO 10126��ʽ���
{
	string c = "";
	int k = 0;
	for (int i = 0; i < 100; i++)
		ctr_temp[i] = "";
	do
	{
		m_temp[k] = m.substr(8 * k, 8);
		//�������
		if (m_temp[k].length()<8)
		{
			int count_sub = 8 - m_temp[k].length();
			if (count_sub - 1>0)
			{
				srand((unsigned)time(NULL));
				unsigned int fill = rand() % 256;
				m_temp[k].append(count_sub - 1, (char)fill);
			}
			m_temp[k].append(1, (char)count_sub);
		}

		//�������
		ctr_temp[k].append(1, (char)k);
		while (ctr_temp[k].length() < 8)
			ctr_temp[k].append(1, '0');
		c_temp[k] = _3DES_Encrypt(ctr_temp[k]);
		for (int i = 0; i < 8; i++)
			c_temp[k][i] = c_temp[k][i] ^ m_temp[k][i];
		c_temp[k] = c_temp[k].substr(0, 8);
		c = c + c_temp[k];
		k++;
	} while (8 * k < m.length());
	c_temp[k] = "\0";
	return c;
}

string CEncrypt_Decrypt_MFCDlg::Decrypt_All_Data_CTR_ISO10126(string c)//CTRģʽ���ܣ�ISO 10126��ʽ���
{
	int k = 0;
	string p = "";
	for (int i = 0; i < 100; i++)
		p_temp[i] = "";
	do
	{
		m_temp[k] = _3DES_Encrypt(ctr_temp[k]);
		for (int i = 0; i < 8; i++)
			p_temp[k].append(1, (char)(m_temp[k][i] ^ c_temp[k][i]));
		//�������
		for (int i = 0; i < p_temp[k].length(); i++)
		if (p_temp[k][i] < 0x08)
			p_temp[k] = p_temp[k].substr(0, p_temp[k].length() - (int)p_temp[k][i]);
		p = p + p_temp[k];
		k++;
	} while (c_temp[k] != "\0");
	return p;
}



// CEncrypt_Decrypt_MFCDlg �Ի���



CEncrypt_Decrypt_MFCDlg::CEncrypt_Decrypt_MFCDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CEncrypt_Decrypt_MFCDlg::IDD, pParent)
	, m_encryptway(0)
	, m_fillway(0)
	, m_enchoose(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CEncrypt_Decrypt_MFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_KEYBYTES, m_cb_keybytes);
	//	DDX_Control(pDX, IDC_LIST2, m_list_key);
	//  DDX_Control(pDX, IDC_RADIO1, m_encrypt_way);
}

BEGIN_MESSAGE_MAP(CEncrypt_Decrypt_MFCDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CEncrypt_Decrypt_MFCDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CEncrypt_Decrypt_MFCDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDSETKEY, &CEncrypt_Decrypt_MFCDlg::OnBnClickedSetkey)
	ON_BN_CLICKED(IDENCRYPT, &CEncrypt_Decrypt_MFCDlg::OnBnClickedEncrypt)
	ON_BN_CLICKED(IDDECRYPT, &CEncrypt_Decrypt_MFCDlg::OnBnClickedDecrypt)
	ON_BN_CLICKED(IDC_RADIO11, &CEncrypt_Decrypt_MFCDlg::OnBnClickedRadio11)
	ON_BN_CLICKED(IDC_RADIO12, &CEncrypt_Decrypt_MFCDlg::OnBnClickedRadio12)
	ON_BN_CLICKED(IDC_RADIO13, &CEncrypt_Decrypt_MFCDlg::OnBnClickedRadio13)
	ON_BN_CLICKED(IDC_RADIO14, &CEncrypt_Decrypt_MFCDlg::OnBnClickedRadio14)
	ON_BN_CLICKED(IDC_RADIO15, &CEncrypt_Decrypt_MFCDlg::OnBnClickedRadio15)
	ON_BN_CLICKED(IDC_RADIO21, &CEncrypt_Decrypt_MFCDlg::OnBnClickedRadio21)
	ON_BN_CLICKED(IDC_RADIO22, &CEncrypt_Decrypt_MFCDlg::OnBnClickedRadio22)
	ON_BN_CLICKED(IDC_RADIO23, &CEncrypt_Decrypt_MFCDlg::OnBnClickedRadio23)
	ON_BN_CLICKED(IDC_RADIO24, &CEncrypt_Decrypt_MFCDlg::OnBnClickedRadio24)
	ON_BN_CLICKED(IDC_RADIO31, &CEncrypt_Decrypt_MFCDlg::OnBnClickedRadio31)
	ON_BN_CLICKED(IDC_RADIO32, &CEncrypt_Decrypt_MFCDlg::OnBnClickedRadio32)
	ON_BN_CLICKED(IDCHOOSEFILE, &CEncrypt_Decrypt_MFCDlg::OnBnClickedChoosefile)
	ON_CBN_SELCHANGE(IDC_COMBO_KEYBYTES, &CEncrypt_Decrypt_MFCDlg::OnCbnSelchangeComboKeybytes)
//	ON_WM_NCHITTEST()
//ON_WM_NCXBUTTONDOWN()
//ON_WM_NCHITTEST()
ON_WM_NCHITTEST()
//ON_WM_CTLCOLOR()
ON_WM_CTLCOLOR()
ON_WM_TIMER()
//ON_EN_CHANGE(IDC_EDIT_KEY, &CEncrypt_Decrypt_MFCDlg::OnEnChangeEditKey)
END_MESSAGE_MAP()


// CEncrypt_Decrypt_MFCDlg ��Ϣ�������

BOOL CEncrypt_Decrypt_MFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	SetTimer(1, 1000, NULL);
	
	m_cb_keybytes.AddString(L"8�ֽ�");
	m_cb_keybytes.AddString(L"24�ֽ�");
	GetDlgItem(IDENCRYPT)->ShowWindow(FALSE);
	GetDlgItem(IDDECRYPT)->ShowWindow(FALSE);
	GetDlgItem(IDCHOOSEFILE)->ShowWindow(FALSE);
	GetDlgItem(IDC_BITSTRING_EDIT)->ShowWindow(FALSE);//���ر�������
	GetDlgItem(IDC_STATIC7)->ShowWindow(FALSE);
	GetDlgItem(IDC_PLAIN_EDIT)->EnableWindow(FALSE);
	GetDlgItem(IDC_CONFIDENTIAL_EDIT)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_KEY1)->ShowWindow(FALSE);
	GetDlgItem(IDC_EDIT_KEY2)->ShowWindow(FALSE);
	GetDlgItem(IDC_EDIT_KEY3)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC3)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC4)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC5)->ShowWindow(FALSE);
	GetDlgItem(IDC_PLAIN_EDIT)->ShowWindow(FALSE);//��ʾ���������
	GetDlgItem(IDC_STATIC1)->ShowWindow(FALSE);
	GetDlgItem(IDC_EDIT_KEY)->ShowWindow(FALSE);//������Կ�����
	GetDlgItem(IDSETKEY)->ShowWindow(FALSE);//����������Կ��ť
	GetDlgItem(IDC_CONFIDENTIAL_EDIT)->ShowWindow(FALSE);//�������Ŀ�
	GetDlgItem(IDC_BITSTRING_EDIT)->ShowWindow(FALSE);//���ر�������
	GetDlgItem(IDC_ORIGINAL_EDIT)->ShowWindow(FALSE);//����ԭ�Ŀ�
	GetDlgItem(IDC_STATIC6)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC7)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC8)->ShowWindow(FALSE);
	//GetDlgItem(IDC_STATIC2)->ShowWindow(FALSE);
	//GetDlgItem(IDC_COMBO_KEYBYTES)->ShowWindow(FALSE);//������Կѡ��λ��������
	//GetDlgItem(IDC_ORIGINAL_EDIT)->EnableWindow(FALSE);
	GetDlgItem(IDC_BITSTRING_EDIT)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_KEY1)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_KEY2)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_KEY3)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO11)->ShowWindow(FALSE);
	GetDlgItem(IDC_RADIO12)->ShowWindow(FALSE);
	GetDlgItem(IDC_RADIO13)->ShowWindow(FALSE);
	GetDlgItem(IDC_RADIO14)->ShowWindow(FALSE);
	GetDlgItem(IDC_RADIO15)->ShowWindow(FALSE);
	GetDlgItem(IDC_RADIO21)->ShowWindow(FALSE);
	GetDlgItem(IDC_RADIO22)->ShowWindow(FALSE);
	GetDlgItem(IDC_RADIO23)->ShowWindow(FALSE);
	GetDlgItem(IDC_RADIO24)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC9)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC10)->ShowWindow(FALSE);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CEncrypt_Decrypt_MFCDlg::OnPaint()
{
	CRect   rect;
	CPaintDC   dc(this);
	GetClientRect(rect);
	dc.FillSolidRect(rect, RGB(186,226,234));   //����
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CEncrypt_Decrypt_MFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CEncrypt_Decrypt_MFCDlg::OnBnClickedOk()//ȷ����Ӧ
{
	// TODO: Add your control notification handler code here
	
}


void CEncrypt_Decrypt_MFCDlg::OnBnClickedCancel()//ȡ����Ӧ
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}


void CEncrypt_Decrypt_MFCDlg::OnBnClickedSetkey()//����������Կ��ť
{
	// TODO: Add your control notification handler code here
	//��ʾ3����Կ��
	GetDlgItem(IDC_EDIT_KEY1)->ShowWindow(TRUE);
	GetDlgItem(IDC_EDIT_KEY2)->ShowWindow(TRUE);
	GetDlgItem(IDC_EDIT_KEY3)->ShowWindow(TRUE);
	GetDlgItem(IDC_STATIC3)->ShowWindow(TRUE);
	GetDlgItem(IDC_STATIC4)->ShowWindow(TRUE);
	GetDlgItem(IDC_STATIC5)->ShowWindow(TRUE);
	GetDlgItem(IDSETKEY)->ShowWindow(FALSE);//����������Կ��ť
	CString CKey;
	GetDlgItem(IDC_EDIT_KEY)->GetWindowText(CKey);//��ȡ��Կ
	string skey;
	CStringA temp(CKey.GetBuffer(0));
	CKey.ReleaseBuffer();
	skey = temp.GetBuffer(0);
	temp.ReleaseBuffer();
	string key1, key2, key3;
	int nIndex = m_cb_keybytes.GetCurSel();
	CString indexText;
	m_cb_keybytes.GetLBText(nIndex, indexText);
	if (indexText==L"8�ֽ�")//ѡ��8�ֽ���Կ
	{
		//�����ʾ��Ϣ
		if (skey.length()<8)
		{
			::MessageBox(NULL, L"��Կ����8�ֽڣ�ϵͳ�����㣡", L"��ʾ", MB_OK|MB_ICONINFORMATION);
		}
		if (skey.length()>8)
		{
			::MessageBox(NULL, L"��Կ����8�ֽڣ�ϵͳȥ�����ಿ�֣�", L"��ʾ", MB_OK | MB_ICONINFORMATION);
		}
		while (skey.length()<8)
		{
			skey.append(1, '0');//����8�ֽڲ���
		}
		skey = skey.substr(0, 8);//����8�ֽڽض�
		//3����Կ��Ϊ�������ɵ�8�ֽ���Կ
		key1 = skey;
		key2 = skey;
		key3 = skey;
	}
	else if (indexText == L"24�ֽ�")//ѡ��24�ֽ���Կ
	{
		//�����ʾ��Ϣ
		if (skey.length()<24)
		{
			::MessageBox(NULL, L"��Կ����24�ֽڣ�ϵͳ�����㣡", L"��ʾ", MB_OK | MB_ICONINFORMATION);
		}
		if (skey.length()>24)
		{
			::MessageBox(NULL, L"��Կ����24�ֽڣ�ϵͳȥ�����ಿ�֣�", L"��ʾ", MB_OK | MB_ICONINFORMATION);
		}
		while (skey.length() < 24)//����24�ֽڲ���
		{
			skey.append(1, '0');
		}
		skey = skey.substr(0, 24);//����24�ֽڽض�
		//��Կ1Ϊ0-7�ֽ�
		key1 = skey.substr(0, 8);
		//��Կ2Ϊ8-15�ֽ�
		key2 = skey.substr(8, 8);
		//��Կ3Ϊ16-23�ֽ�
		key3 = skey.substr(16, 8);
	}
	//��3����Կת��ΪCString����
	CString k1,k2,k3;
	k1 = CA2T(key1.c_str());
	k2 = CA2T(key2.c_str());
	k3 = CA2T(key3.c_str());
	Inintialize_Encrypt_Decrypt(key1, key2, key3);//��ʼ����Կ
	//��������Կ��ʾ����
	GetDlgItem(IDC_EDIT_KEY1)->SetWindowText(k1);
	GetDlgItem(IDC_EDIT_KEY2)->SetWindowText(k2);
	GetDlgItem(IDC_EDIT_KEY3)->SetWindowText(k3);
	GetDlgItem(IDSETKEY)->EnableWindow(FALSE);//����������Կ��ť
	GetDlgItem(IDC_COMBO_KEYBYTES)->EnableWindow(FALSE);//����ѡ���ֽ���ѡ��
	GetDlgItem(IDC_EDIT_KEY)->EnableWindow(FALSE);//������Կ�����
	GetDlgItem(IDENCRYPT)->ShowWindow(TRUE);//���ü��ܰ�ť
	//���ü���ģʽ�����ģʽѡ���
	GetDlgItem(IDC_RADIO11)->ShowWindow(TRUE);
	GetDlgItem(IDC_RADIO12)->ShowWindow(TRUE);
	GetDlgItem(IDC_RADIO13)->ShowWindow(TRUE);
	GetDlgItem(IDC_RADIO14)->ShowWindow(TRUE);
	GetDlgItem(IDC_RADIO15)->ShowWindow(TRUE);
	GetDlgItem(IDC_RADIO21)->ShowWindow(TRUE);
	GetDlgItem(IDC_RADIO22)->ShowWindow(TRUE);
	GetDlgItem(IDC_RADIO23)->ShowWindow(TRUE);
	GetDlgItem(IDC_RADIO24)->ShowWindow(TRUE);
	GetDlgItem(IDC_STATIC9)->ShowWindow(TRUE);
	GetDlgItem(IDC_STATIC10)->ShowWindow(TRUE);

}


void CEncrypt_Decrypt_MFCDlg::OnBnClickedEncrypt()//���¼��ܰ�ť
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDSETKEY)->EnableWindow(FALSE);//����������Կ��ť
	GetDlgItem(IDC_COMBO_KEYBYTES)->EnableWindow(FALSE);//������Կѡ���
	GetDlgItem(IDC_EDIT_KEY)->EnableWindow(FALSE);//������Կ�����
	GetDlgItem(IDC_CONFIDENTIAL_EDIT)->ShowWindow(TRUE);//��ʾ���Ŀ�
	GetDlgItem(IDC_STATIC6)->ShowWindow(TRUE);
	GetDlgItem(IDSETKEY)->ShowWindow(FALSE);//����������Կ��ť
	GetDlgItem(IDC_EDIT_KEY1)->ShowWindow(FALSE);
	GetDlgItem(IDC_EDIT_KEY2)->ShowWindow(FALSE);
	GetDlgItem(IDC_EDIT_KEY3)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC3)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC4)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC5)->ShowWindow(FALSE);
	if (m_enchoose == 0)
	{
		GetDlgItem(IDC_BITSTRING_EDIT)->ShowWindow(TRUE);//��ʾ��������
		GetDlgItem(IDC_STATIC7)->ShowWindow(TRUE);
	}
	GetDlgItem(IDC_ORIGINAL_EDIT)->ShowWindow(FALSE);//�������Ŀ�
	GetDlgItem(IDC_STATIC8)->ShowWindow(FALSE);
	//���ü���ģʽ�����ģʽѡ���
	GetDlgItem(IDC_PLAIN_EDIT)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO11)->ShowWindow(FALSE);
	GetDlgItem(IDC_RADIO12)->ShowWindow(FALSE);
	GetDlgItem(IDC_RADIO13)->ShowWindow(FALSE);
	GetDlgItem(IDC_RADIO14)->ShowWindow(FALSE);
	GetDlgItem(IDC_RADIO15)->ShowWindow(FALSE);
	GetDlgItem(IDC_RADIO21)->ShowWindow(FALSE);
	GetDlgItem(IDC_RADIO22)->ShowWindow(FALSE);
	GetDlgItem(IDC_RADIO23)->ShowWindow(FALSE);
	GetDlgItem(IDC_RADIO24)->ShowWindow(FALSE);
	GetDlgItem(IDC_RADIO31)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO32)->EnableWindow(FALSE);
	GetDlgItem(IDC_STATIC9)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC10)->ShowWindow(FALSE);
	UpdateData(TRUE);
	CString CPlainText;
	if (m_enchoose==1)//ѡ������ļ�
		CPlainText = cfileplain;//����Ϊ�ļ�����
	else
		GetDlgItem(IDC_PLAIN_EDIT)->GetWindowText(CPlainText);//��ȡ�����������Ϣ
	//CStringת��Ϊstring����
	CStringA t(CPlainText.GetBuffer(0));
	CPlainText.ReleaseBuffer();
	string m_t = t.GetBuffer(0);//m_tΪ����
	t.ReleaseBuffer();
	string c_t;



	//����ѡ��ļ���ģʽ����䷽ʽ����
	if (m_encryptway == 0 && m_fillway == 0)
		c_t = Encrypt_All_Data_ECB_ZERO(m_t);
	else if (m_encryptway == 0 && m_fillway == 1)
		c_t = Encrypt_All_Data_ECB_PKCS7(m_t);
	else if (m_encryptway == 0 && m_fillway == 2)
		c_t = Encrypt_All_Data_ECB_ANSIX923(m_t);
	else if (m_encryptway == 0 && m_fillway == 3)
		c_t = Encrypt_All_Data_ECB_ISO10126(m_t);
	else if (m_encryptway == 1 && m_fillway == 0)
		c_t = Encrypt_All_Data_CBC_ZERO(m_t);
	else if (m_encryptway == 1 && m_fillway == 1)
		c_t = Encrypt_All_Data_CBC_PKCS7(m_t);
	else if (m_encryptway == 1 && m_fillway == 2)
		c_t = Encrypt_All_Data_CBC_ANSIX923(m_t);
	else if (m_encryptway == 1 && m_fillway == 3)
		c_t = Encrypt_All_Data_CBC_ISO10126(m_t);
	else if (m_encryptway == 2 && m_fillway == 0)
		c_t = Encrypt_All_Data_CFB_ZERO(m_t);
	else if (m_encryptway == 2 && m_fillway == 1)
		c_t = Encrypt_All_Data_CFB_PKCS7(m_t);
	else if (m_encryptway == 2 && m_fillway == 2)
		c_t = Encrypt_All_Data_CFB_ANSIX923(m_t);
	else if (m_encryptway == 2 && m_fillway == 3)
		c_t = Encrypt_All_Data_CFB_ISO10126(m_t);
	else if (m_encryptway == 3 && m_fillway == 0)
		c_t = Encrypt_All_Data_OFB_ZERO(m_t);
	else if (m_encryptway == 3 && m_fillway == 1)
		c_t = Encrypt_All_Data_OFB_PKCS7(m_t);
	else if (m_encryptway == 3 && m_fillway == 2)
		c_t = Encrypt_All_Data_OFB_ANSIX923(m_t);
	else if (m_encryptway == 3 && m_fillway == 3)
		c_t = Encrypt_All_Data_OFB_ISO10126(m_t);
	else if (m_encryptway == 4 && m_fillway == 0)
		c_t = Encrypt_All_Data_CTR_ZERO(m_t);
	else if (m_encryptway == 4 && m_fillway == 1)
		c_t = Encrypt_All_Data_CTR_PKCS7(m_t);
	else if (m_encryptway == 4 && m_fillway == 2)
		c_t = Encrypt_All_Data_CTR_ANSIX923(m_t);
	else if (m_encryptway == 4 && m_fillway == 3)
		c_t = Encrypt_All_Data_CTR_ISO10126(m_t);
	


	string temp0 = "";//��������16���ƣ�
	for (int i = 0; i < c_t.length(); i++)
	{
		int t0 = (int)c_t[i];//��¼�ַ�����ĳһλ�ַ�
		if (t0 < 0) t0 = 256 + t0;//��������
		char c0, c1;
		c0 = (t0 % 16 < 10) ? (t0 % 16 + '0') : (t0 % 16 - 10 + 'A');//16���Ƶĵ�λ
		c1 = (t0 / 16 < 10) ? (t0 / 16 + '0') : (t0 / 16 - 10 + 'A');//16���Ƶĸ�λ
		//�ַ���׷���ַ�
		temp0.append("0x");
		temp0.append(1, c1);
		temp0.append(1, c0);
		temp0.append(" ");
		if ((i + 1) % 7 == 0) temp0.append("\r\n");//����
	}
	
	CString CConText;
	CConText = CA2T(c_t.c_str());
	if (m_enchoose == 1)//�ļ�����
	{
		//�����ܽ�����浽�ļ���
		// ���ù�����   
		TCHAR szFilter[] = _T("�ı��ļ�(*.txt)|*.txt|�����ļ�(*.*)|*.*||");
		// ���챣���ļ��Ի���   
		CFileDialog fileDlg(FALSE, _T("txt"), NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter, this);
		fileDlg.m_ofn.lpstrTitle = L"���������ļ�";
		CString strFilePath;
		if (IDOK == fileDlg.DoModal())
		{
			// ���������ļ��Ի����ϵġ����桱��ť����ѡ����ļ�·����ʾ���༭����   
			strFilePath = fileDlg.GetPathName();
			// �ж��ļ��Ƿ����,���������ȥ��ֻ������
			if (PathFileExists(strFilePath) && !PathIsDirectory(strFilePath))
			{
				DWORD dwAttrs = GetFileAttributes(strFilePath);
				if (dwAttrs != INVALID_FILE_ATTRIBUTES
					&& (dwAttrs & FILE_ATTRIBUTE_READONLY))
				{
					dwAttrs &= ~FILE_ATTRIBUTE_READONLY;
					SetFileAttributes(strFilePath, dwAttrs);
				}
			}
			// ���ļ�
			CStdioFile file;
			BOOL ret = file.Open(strFilePath,CFile::modeCreate  | CFile::modeWrite | CFile::shareDenyWrite);
			if (!ret)
			{
				::AfxMessageBox(L"���ļ�ʧ��");
				return;
			}
			file.SeekToEnd();
			file.WriteString(CConText);//д���ļ�
			file.Close();//�ر��ļ�
			strFilePath = L"<�ļ�>" + strFilePath;//��ʾ�ļ�·��
			GetDlgItem(IDC_CONFIDENTIAL_EDIT)->SetWindowText(strFilePath);
		}
		
	}
	else//�ַ�������
	{
		GetDlgItem(IDC_CONFIDENTIAL_EDIT)->SetWindowText(CConText);//��ʾ���ܺ���ַ���
		CString t1;
		t1 = CA2T(temp0.c_str());
		GetDlgItem(IDC_BITSTRING_EDIT)->SetWindowText(t1);//��ʾ���ܺ�ı��ش�
	}
	GetDlgItem(IDENCRYPT)->ShowWindow(FALSE);//���ü��ܰ�ť
	GetDlgItem(IDDECRYPT)->ShowWindow(TRUE);//���ý��ܰ�ť
	GetDlgItem(IDC_ORIGINAL_EDIT)->SetWindowText(L"");//��ս��ܿ�����

}


void CEncrypt_Decrypt_MFCDlg::OnBnClickedDecrypt()//���½��ܰ�ť
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDENCRYPT)->ShowWindow(TRUE);//���ü��ܰ�ť
	GetDlgItem(IDDECRYPT)->ShowWindow(FALSE);//���ý��ܰ�ť
	GetDlgItem(IDC_CONFIDENTIAL_EDIT)->ShowWindow(FALSE);//�������Ŀ�
	GetDlgItem(IDC_BITSTRING_EDIT)->ShowWindow(FALSE);//���ر�������
	GetDlgItem(IDC_ORIGINAL_EDIT)->ShowWindow(TRUE);//��ʾԭ�Ŀ�
	GetDlgItem(IDC_STATIC6)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC7)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC8)->ShowWindow(TRUE);
	UpdateData(TRUE);
	CString CConText;
	if (m_enchoose == 1)//�����ļ�
	{
		CString strFilePath;
		GetDlgItem(IDC_CONFIDENTIAL_EDIT)->GetWindowText(strFilePath);//��ȡ�ļ�·��
		strFilePath = strFilePath.Mid(4);//ȥ�����Ŀ�ǰ���<�ļ�>��ʶ��
		CStdioFile file;
		CString strText;
		//���ļ�
		if (!file.Open(strFilePath, CFile::modeRead))
		{
			::AfxMessageBox(_T("�ļ���ʧ�ܡ�"));
			return;
		}
		//���ļ�
		strText = _T("");
		CConText = L"";
		while (file.ReadString(strText))
			CConText = CConText + strText;//׷�ӵ�������
		//�ر��ļ�
		file.Close();
	}
	else
		GetDlgItem(IDC_PLAIN_EDIT)->GetWindowText(CConText);//��ȡ���Ŀ���Ϣ
	//CStringת����string����
	CStringA t(CConText.GetBuffer(0));
	CConText.ReleaseBuffer();
	string c_t = t.GetBuffer(0);//c_tΪ����
	t.ReleaseBuffer();
	string m_t;



	//����ѡ��ļ��ܷ�ʽ�����ģʽ����
	if (m_encryptway == 0 && m_fillway == 0)
		m_t = Decrypt_All_Data_ECB_ZERO(c_t);
	else if (m_encryptway == 0 && m_fillway == 1)
		m_t = Decrypt_All_Data_ECB_PKCS7(c_t);
	else if (m_encryptway == 0 && m_fillway == 2)
		m_t = Decrypt_All_Data_ECB_ANSIX923(c_t);
	else if (m_encryptway == 0 && m_fillway == 3)
		m_t = Decrypt_All_Data_ECB_ISO10126(c_t);
	else if (m_encryptway == 1 && m_fillway == 0)
		m_t = Decrypt_All_Data_CBC_ZERO(c_t);
	else if (m_encryptway == 1 && m_fillway == 1)
		m_t = Decrypt_All_Data_CBC_PKCS7(c_t);
	else if (m_encryptway == 1 && m_fillway == 2)
		m_t = Decrypt_All_Data_CBC_ANSIX923(c_t);
	else if (m_encryptway == 1 && m_fillway == 3)
		m_t = Decrypt_All_Data_CBC_ISO10126(c_t);
	else if (m_encryptway == 2 && m_fillway == 0)
		m_t = Decrypt_All_Data_CFB_ZERO(c_t);
	else if (m_encryptway == 2 && m_fillway == 1)
		m_t = Decrypt_All_Data_CFB_PKCS7(c_t);
	else if (m_encryptway == 2 && m_fillway == 2)
		m_t = Decrypt_All_Data_CFB_ANSIX923(c_t);
	else if (m_encryptway == 2 && m_fillway == 3)
		m_t = Decrypt_All_Data_CFB_ISO10126(c_t);
	else if (m_encryptway == 3 && m_fillway == 0)
		m_t = Decrypt_All_Data_OFB_ZERO(c_t);
	else if (m_encryptway == 3 && m_fillway == 1)
		m_t = Decrypt_All_Data_OFB_PKCS7(c_t);
	else if (m_encryptway == 3 && m_fillway == 2)
		m_t = Decrypt_All_Data_OFB_ANSIX923(c_t);
	else if (m_encryptway == 3 && m_fillway == 3)
		m_t = Decrypt_All_Data_OFB_ISO10126(c_t);
	else if (m_encryptway == 4 && m_fillway == 0)
		m_t = Decrypt_All_Data_CTR_ZERO(c_t);
	else if (m_encryptway == 4 && m_fillway == 1)
		m_t = Decrypt_All_Data_CTR_PKCS7(c_t);
	else if (m_encryptway == 4 && m_fillway == 2)
		m_t = Decrypt_All_Data_CTR_ANSIX923(c_t);
	else if (m_encryptway == 4 && m_fillway == 3)
		m_t = Decrypt_All_Data_CTR_ISO10126(c_t);
	/*if (m_enchoose == 1)//�����ļ�
	{
		CString strFilePath;
		GetDlgItem(IDC_PLAIN_EDIT)->GetWindowText(strFilePath);//��ȡ�ļ�·��
		strFilePath = strFilePath.Mid(4);//ȥ�����Ŀ�ǰ���<�ļ�>��ʶ��
		CStdioFile file;
		CString strText;
		//���ļ�
		if (!file.Open(strFilePath, CFile::modeRead))
		{
			::AfxMessageBox(_T("�ļ���ʧ�ܡ�"));
			return;
		}
		//���ļ�
		strText = _T("");
		CString cplain;
		cplain = L"";
		while (file.ReadString(strText))
			cplain = cplain + strText;//׷�ӵ�������
		//�ر��ļ�
		file.Close();
		CStringA t1(cplain.GetBuffer(0));
		cplain.ReleaseBuffer();
		m_t = t1.GetBuffer(0);
		t1.ReleaseBuffer();
	}
	else
	{
		CString cplain;
		GetDlgItem(IDC_PLAIN_EDIT)->GetWindowText(cplain);
		CStringA t1(cplain.GetBuffer(0));
		cplain.ReleaseBuffer();
		m_t = t1.GetBuffer(0);
		t1.ReleaseBuffer();
	}*/
	//stringת��Ϊcstring����
	CString COriText;
	COriText = CA2T(m_t.c_str());
	if (m_enchoose == 1)//�����ļ�
	{
		// ���ù�����   
		TCHAR szFilter[] = _T("�ı��ļ�(*.txt)|*.txt|�����ļ�(*.*)|*.*||");
		// ���챣���ļ��Ի���   
		CFileDialog fileDlg(FALSE, _T("txt"), NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter, this);
		fileDlg.m_ofn.lpstrTitle = L"����ԭ���ļ�";
		CString strFilePath;
		if (IDOK == fileDlg.DoModal())
		{
			// ���������ļ��Ի����ϵġ����桱��ť����ѡ����ļ�·����ʾ���༭����   
			strFilePath = fileDlg.GetPathName();
			// �ж��ļ��Ƿ����,���������ȥ��ֻ������
			if (PathFileExists(strFilePath) && !PathIsDirectory(strFilePath))
			{
				DWORD dwAttrs = GetFileAttributes(strFilePath);
				if (dwAttrs != INVALID_FILE_ATTRIBUTES
					&& (dwAttrs & FILE_ATTRIBUTE_READONLY))
				{
					dwAttrs &= ~FILE_ATTRIBUTE_READONLY;
					SetFileAttributes(strFilePath, dwAttrs);
				}
			}
			// ���ļ�
			CStdioFile file;
			BOOL ret = file.Open(strFilePath, CFile::modeCreate | CFile::modeWrite | CFile::shareDenyWrite);
			if (!ret)
			{
				::AfxMessageBox(L"���ļ�ʧ��");
				return;
			}
			file.SeekToEnd();
			file.WriteString(COriText);//д���ļ�
			file.Close();
			strFilePath = L"<�ļ�>" + strFilePath;//��¼�ļ�·��
			GetDlgItem(IDC_ORIGINAL_EDIT)->SetWindowText(strFilePath);//��ʾ�ļ�·��
		}

	}
	else//�����ַ���
		GetDlgItem(IDC_ORIGINAL_EDIT)->SetWindowText(COriText);//��ʾ���ܺ��ԭ��




	GetDlgItem(IDSETKEY)->EnableWindow(TRUE);//����������Կ��ť
	GetDlgItem(IDC_COMBO_KEYBYTES)->EnableWindow(TRUE);//����������Կλ����
	GetDlgItem(IDC_EDIT_KEY)->EnableWindow(TRUE);//������Կ�����




	//���ü���ģʽ�����ģʽѡ���
	GetDlgItem(IDC_RADIO11)->ShowWindow(TRUE);
	GetDlgItem(IDC_RADIO12)->ShowWindow(TRUE);
	GetDlgItem(IDC_RADIO13)->ShowWindow(TRUE);
	GetDlgItem(IDC_RADIO14)->ShowWindow(TRUE);
	GetDlgItem(IDC_RADIO15)->ShowWindow(TRUE);
	GetDlgItem(IDC_RADIO21)->ShowWindow(TRUE);
	GetDlgItem(IDC_RADIO22)->ShowWindow(TRUE);
	GetDlgItem(IDC_RADIO23)->ShowWindow(TRUE);
	GetDlgItem(IDC_RADIO24)->ShowWindow(TRUE);
	GetDlgItem(IDC_RADIO31)->EnableWindow(TRUE);
	GetDlgItem(IDC_RADIO32)->EnableWindow(TRUE);
	GetDlgItem(IDC_STATIC9)->ShowWindow(TRUE);
	GetDlgItem(IDC_STATIC10)->ShowWindow(TRUE);
	GetDlgItem(IDC_PLAIN_EDIT)->EnableWindow(TRUE);//�������������
	GetDlgItem(IDC_CONFIDENTIAL_EDIT)->SetWindowText(L"");//������Ŀ�
	GetDlgItem(IDC_BITSTRING_EDIT)->SetWindowText(L"");//��ձ�������
	GetDlgItem(IDSETKEY)->ShowWindow(TRUE);//����������Կ��ť
}





void CEncrypt_Decrypt_MFCDlg::OnBnClickedRadio11()//ECBģʽ
{
	// TODO: Add your control notification handler code here
	m_encryptway = 0;


}


void CEncrypt_Decrypt_MFCDlg::OnBnClickedRadio12()//CBCģʽ
{
	// TODO: Add your control notification handler code here
	m_encryptway = 1;


}


void CEncrypt_Decrypt_MFCDlg::OnBnClickedRadio13()//CFBģʽ
{
	// TODO: Add your control notification handler code here
	m_encryptway = 2;


}


void CEncrypt_Decrypt_MFCDlg::OnBnClickedRadio14()//OFBģʽ
{
	// TODO: Add your control notification handler code here
	m_encryptway = 3;
}


void CEncrypt_Decrypt_MFCDlg::OnBnClickedRadio15()//CTRģʽ
{
	// TODO: Add your control notification handler code here
	m_encryptway = 4;


}


void CEncrypt_Decrypt_MFCDlg::OnBnClickedRadio21()//ZEROģʽ
{
	// TODO: Add your control notification handler code here
	m_fillway = 0;
}


void CEncrypt_Decrypt_MFCDlg::OnBnClickedRadio22()//PKCS7ģʽ
{
	// TODO: Add your control notification handler code here
	m_fillway = 1;


}


void CEncrypt_Decrypt_MFCDlg::OnBnClickedRadio23()//ANSI X.923ģʽ
{
	// TODO: Add your control notification handler code here
	m_fillway = 2;


}


void CEncrypt_Decrypt_MFCDlg::OnBnClickedRadio24()//ISO 10126ģʽ
{
	// TODO: Add your control notification handler code here
	m_fillway = 3;
}


void CEncrypt_Decrypt_MFCDlg::OnBnClickedRadio31()//ѡ������ַ�����ʽ
{
	// TODO: Add your control notification handler code here
	m_enchoose = 0;


	GetDlgItem(IDC_PLAIN_EDIT)->ShowWindow(TRUE);//��ʾ���������
	GetDlgItem(IDC_STATIC1)->ShowWindow(TRUE);
	GetDlgItem(IDCHOOSEFILE)->ShowWindow(FALSE);//����ѡ���ļ���ť

	GetDlgItem(IDC_PLAIN_EDIT)->EnableWindow(TRUE);//�������������
	GetDlgItem(IDC_PLAIN_EDIT)->SetWindowText(L"");//������������
	GetDlgItem(IDC_CONFIDENTIAL_EDIT)->SetWindowText(L"");//������Ŀ�
	GetDlgItem(IDC_ORIGINAL_EDIT)->SetWindowText(L"");//���ԭ�Ŀ�
}


void CEncrypt_Decrypt_MFCDlg::OnBnClickedRadio32()//ѡ������ļ���ʽ
{
	// TODO: Add your control notification handler code here
	m_enchoose = 1;

	GetDlgItem(IDC_STATIC7)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC1)->ShowWindow(TRUE);
	GetDlgItem(IDC_PLAIN_EDIT)->ShowWindow(FALSE);//�������������
	GetDlgItem(IDCHOOSEFILE)->ShowWindow(TRUE);//����ѡ���ļ���ť
	GetDlgItem(IDC_PLAIN_EDIT)->EnableWindow(FALSE);//�������������

	GetDlgItem(IDC_PLAIN_EDIT)->SetWindowText(L"");//������Ŀ�
	GetDlgItem(IDC_CONFIDENTIAL_EDIT)->SetWindowText(L"");//������Ŀ�
	GetDlgItem(IDC_ORIGINAL_EDIT)->SetWindowText(L"");//���ԭ�Ŀ�
}


void CEncrypt_Decrypt_MFCDlg::OnBnClickedChoosefile()
{
	// TODO: Add your control notification handler code here
	// ���ù�����   
	TCHAR szFilter[] = _T("�ı��ļ�(*.txt)|*.txt|�����ļ�(*.*)|*.*||");
	// ������ļ��Ի���   
	CFileDialog fileDlg(TRUE, _T("txt"), NULL, 0, szFilter, this);
	fileDlg.m_ofn.lpstrTitle = L"�������ļ�";
	CString strFilePath;


	if (IDOK == fileDlg.DoModal())
	{
		// ���������ļ��Ի����ϵġ��򿪡���ť����ѡ����ļ�·����ʾ���༭����   
		strFilePath = fileDlg.GetPathName();
		CStdioFile file;
		CString strText;
		//���ļ�
		if (!file.Open(strFilePath, CFile::modeRead))
		{
			::AfxMessageBox(_T("�ļ���ʧ�ܡ�"));
			return;
		}
		//���ļ�
		strText = _T("");
		cfileplain = L"";
		while (file.ReadString(strText))
			cfileplain = cfileplain + strText;


		//�ر��ļ�
		file.Close();
		GetDlgItem(IDC_PLAIN_EDIT)->ShowWindow(TRUE);//��ʾ���������
		strFilePath = L"<�ļ�>" + strFilePath;
		GetDlgItem(IDC_PLAIN_EDIT)->SetWindowText(strFilePath);
	}
}


void CEncrypt_Decrypt_MFCDlg::OnCbnSelchangeComboKeybytes()
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_EDIT_KEY)->ShowWindow(TRUE);//��ʾ��Կ�����
	GetDlgItem(IDSETKEY)->ShowWindow(TRUE);//��ʾ������Կ��ť
	GetDlgItem(IDC_EDIT_KEY)->SetWindowText(L"");//��Կ��������


}


LRESULT CEncrypt_Decrypt_MFCDlg::OnNcHitTest(CPoint point)
{
	// TODO: Add your message handler code here and/or call default


	int ret = CDialog::OnNcHitTest(point);
	
	//��ֹ�ı䴰�ڴ�С
	if (HTTOP == ret || HTBOTTOM == ret || HTLEFT == ret || HTRIGHT == ret || HTBOTTOMLEFT == ret || HTBOTTOMRIGHT == ret || HTTOPLEFT == ret || HTTOPRIGHT == ret || HTCAPTION == ret)
		return HTCLIENT;



	return ret;

}




HBRUSH CEncrypt_Decrypt_MFCDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	// TODO:  Change any attributes of the DC here
	if (nCtlColor == CTLCOLOR_BTN)          //���İ�ť��ɫ
	{
		
		pDC->SetTextColor(RGB(254, 1, 1));
		pDC->SetBkColor(RGB(117, 31, 111));
		HBRUSH b = CreateSolidBrush(RGB(186, 226, 234));
		return b;
	}

	else if (nCtlColor == CTLCOLOR_EDIT)   //���ı༭��
	{
		
		pDC->SetTextColor(RGB(24, 6, 102));
		pDC->SetBkColor(RGB(254, 198, 103));
		HBRUSH b = CreateSolidBrush(RGB(186, 226, 234));
		return b;


	}
	 if (nCtlColor == CTLCOLOR_STATIC)  //���ľ�̬�ı�
	{


		pDC->SetTextColor(RGB(254, 1, 1));
		pDC->SetBkColor(RGB(186, 226, 234));
		HBRUSH b = CreateSolidBrush(RGB(186, 226, 234));
		return b;


	}




	// TODO:  Return a different brush if the default is not desired
	return hbr;
}




void CEncrypt_Decrypt_MFCDlg::OnTimer(UINT_PTR nIDEvent)
{
	
	CString strTime;
	CTime tm;
	tm = CTime::GetCurrentTime();
	strTime = tm.Format("%Y-%m-%d %H:%M:%S");
	SetDlgItemText(IDC_ShowTime, strTime);        //��ʾϵͳʱ��



	// TODO: Add your message handler code here and/or call default
	CDialogEx::OnTimer(nIDEvent);
}




