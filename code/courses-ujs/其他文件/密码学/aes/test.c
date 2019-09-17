#include "RIJNDAEL.h"

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAXNUM 255
#define RAND_MAX 0x7fff



void main()

{
	int i;
	u4byte IV[4]={0x12345678,0x90123456,0x78901234,0x56789012};//��ʼ����IV
	u4byte ori1[4],ori2[4],ri[8],ri1[4],ri2[4];
	u4byte out_block1[4],de_block1[4];
	u4byte out_block2[4],de_block2[4];
	u4byte out_block[8],de_block[8];
	u4byte in_key[4]={0x11111111,0x22222222,0x33333333,0x44444444};//��Կ��ʼ��
	u4byte plaint_block1[4]={0x31506040,0x28315060,0x40283150,0x60402831};//���Ŀ�1
	u4byte plaint_block2[4]={0x50604028,0x31506040,0x28315060,0x40283150};//���Ŀ�2
	u4byte x1,x2,x3,x4;
 	time_t t;                 //�����б�֤ÿ�β������������ͬ
    srand( (unsigned) time( &t ) ); 

	printf("ECB~~Start~~~~~~~~~~~~~~\n");
	//���������Կ
	for(i=0;i<4;i++)
	{
		x1 = rand()*MAXNUM/RAND_MAX;
		x2 = rand()*MAXNUM/RAND_MAX;
		x3 = rand()*MAXNUM/RAND_MAX;
		x4 = rand()*MAXNUM/RAND_MAX;
		in_key[i] = 0;
		in_key[i] = x1;
		in_key[i]<<=8;
		in_key[i] += x2;
		in_key[i]<<=8;
		in_key[i] += x3;
		in_key[i]<<=8;
		in_key[i] += x4;
	}


	set_key(in_key,128);//����128λ����Կ

	encrypt(plaint_block1,out_block1);//�������Ŀ�1
	encrypt(plaint_block2,out_block2);//�������Ŀ�2
	//ƴ�����Ŀ�
	for (i=0;i<4;i++)
	{
		out_block[i]=out_block1[i];
	}
	for (i=4;i<8;i++)
	{
		out_block[i]=out_block2[i-4];
	}
	printf("Encryption:\n���ģ� \n");
	for(i=0;i<8;i++)
		printf("%x",out_block[i]);
	printf("\n");

	decrypt(out_block1,de_block1);//�������Ŀ�1
	decrypt(out_block2,de_block2);//�������Ŀ�2
	//ƴ�����Ŀ�
	for (i=0;i<4;i++)
	{
		de_block[i]=de_block1[i];
	}
	for (i=4;i<8;i++)
	{
		de_block[i]=de_block2[i-4];
	}
	printf("Decryption!\n�ָ�ԭ�ģ� \n");
	for(i=0;i<8;i++)
		printf("%x",de_block[i]);
	printf("\n");
	printf("CBC~~Start~~~~~~~~~~~~~~\n");
	//���������Կ
	for(i=0;i<4;i++)
	{
		x1 = rand()*MAXNUM/RAND_MAX;
		x2 = rand()*MAXNUM/RAND_MAX;
		x3 = rand()*MAXNUM/RAND_MAX;
		x4 = rand()*MAXNUM/RAND_MAX;
		in_key[i] = 0;
		in_key[i] = x1;
		in_key[i]<<=8;
		in_key[i] += x2;
		in_key[i]<<=8;
		in_key[i] += x3;
		in_key[i]<<=8;
		in_key[i] += x4;
	}


	set_key(in_key,128);//����128λ����Կ
	for (i=0;i<4;i++)
	{
		ori1[i]=plaint_block1[i]^IV[i];//���ʼ�������
	}
	encrypt(ori1,out_block1);//�����������Ŀ�1
	for (i=0;i<4;i++)
	{
		ori2[i]=out_block1[i]^plaint_block2[i];//�����Ŀ�1���
	}
	encrypt(ori2,out_block2);//�����������Ŀ�2
	//ƴ�����Ŀ�
	for (i=0;i<4;i++)
	{
		ri[i]=out_block1[i];
	}
	for (i=4;i<8;i++)
	{
		ri[i]=out_block2[i-4];
	}
	printf("Encryption:\n���ģ� \n");
	for(i=0;i<8;i++)
		printf("%x",ri[i]);
	printf("\n");
	decrypt(out_block1,de_block1);//�������Ŀ�1
	decrypt(out_block2,de_block2);//�������Ŀ�2
	for (i=0;i<4;i++)
	{
		ri2[i]=out_block1[i]^de_block2[i];//�����Ŀ�1���
	}
	for (i=0;i<4;i++)
	{
		ri1[i]=IV[i]^de_block1[i];//��IV���
	}
	//ƴ�����Ŀ�
	for (i=0;i<4;i++)
	{
		ri[i]=ri1[i];
	}
	for (i=4;i<8;i++)
	{
		ri[i]=ri2[i-4];
	}
	printf("Decryption!\n�ָ�ԭ�ģ� \n");
	for(i=0;i<8;i++)
		printf("%x",ri[i]);
	printf("\n");
}