#include "c8051f020.h" 
#include <intrins.h>

sbit	HD7279_DAT=P1^7;
sbit	HD7279_CLK=P1^6;

#define NOSELECT7279  	P5 |= 0x80		//SPICS4(P57)=1
#define SELECT7279  	P5 &= ~(0x80)  	//SPICS4(P57)=0;
#define Set7279DAT  	HD7279_DAT=1
#define Clr7279DAT  	HD7279_DAT=0
#define Set7279CLK  	HD7279_CLK=1
#define Clr7279CLK  	HD7279_CLK=0

//      HD7279����/��ʾ����             
 
//	I/O�ڳ�ʼ�� 

void Delay1ms(unsigned char T);
void Delay1s(unsigned char T);
void Delay1us(unsigned char T);

void Send7279Byte(unsigned char ch)
{	
	char i;
	SELECT7279;     	//��CS�͵�ƽ 
	Delay1us(50);		//��ʱ50��
	
	for (i=0;i<8;i++)
	{	
		if (ch&0x80)	//���7λ��HD7279A��DATA�� 
		{
			Set7279DAT;
		}
		else
		{
			Clr7279DAT;
		}
		Set7279CLK;		//��CLK�ߵ�ƽ 
		ch=ch<<1;		//������������ 
		Delay1us(8);	//��ʱ8��
		Clr7279CLK;		//��CLK�͵�ƽ 
		Delay1us(8);	//��ʱ50��
	}
	Clr7279DAT;			//������ϣ�DATA���õͣ����� 
}
unsigned char Receive7279Byte(void)
{
	unsigned char i,ch;
	ch=0;		
	Set7279DAT;			//DATA����Ϊ�ߵ�ƽ������״̬
	Delay1us(50);		//��ʱ50��
	for (i=0;i<8;i++)
	{
		Set7279CLK;		//��CLK�ߵ�ƽ
		Delay1us(8);	//��ʱ8��
		ch=ch<<1;		//������������1λ
		if (HD7279_DAT)
			ch+=1;		//����1λ����
		Clr7279CLK;		//��CLK�͵�ƽ
		Delay1us(8);	//��ʱ8��
	}
	Clr7279DAT;			//������ϣ�DATA�������óɵ͵�ƽ(���״̬)
	return ch;
}

void FlashLED(unsigned char No)
{
	char i;
	Send7279Byte(0x88);	//����˸ָ�� 
	i=0x1;
	while (No)
	{
		i=i<<1;
		No--;
	}
	Send7279Byte(~i);   //1��˸
	NOSELECT7279;     	//��CS�ߵ�ƽ 
}

/*
void BlankLED(unsigned char ch)
{
	Send7279Byte(0x98);	//������ָ�� 
	Send7279Byte(ch);   //1-��ʾ 0-����
	NOSELECT7279;     	//��CS�ߵ�ƽ 
}
*/

void MoveLeft(void)
{
	Send7279Byte(0xA1);	//������ָ�� 
	NOSELECT7279;     	//��CS�ߵ�ƽ 
}

void MoveRight(void)
{
	Send7279Byte(0xA0);	//������ָ�� 
	NOSELECT7279;     	//��CS�ߵ�ƽ 
}

unsigned char code BdSeg[]={
					0x7e,0x30,0x6d,0x79, // 0 1 2 3 
                   	0x33,0x5b,0x5f,0x70, // 4 5 6 7
                   	0x7f,0x7b,0x77,0x1f, // 8 9 a b
                   	0x4e,0x3d,0x4f,0x47, // c d e f
                   	0x00,0x01}; 
/*
;              b6
;             ----
;          b1| b0 |b5
;             ----        small
;          b2| b3 |b4
;             ---- .b7
*/
void DispLED(char *DispBuf,char ShowDot)//ShowDot ��ʾС����λ 
{
char i,ch;
	ShowDot--;
	for (i=0;i<6;i++)
	{
		ch=DispBuf[i];
		if ((ch>='a') && (ch<='f'))
		{
		   ch-='a';ch+=0xa;
		}
		if ((ch>='A') && (ch<='F'))
		{
		   ch-='A';ch+=0xa;
		}
		Send7279Byte(0x90+5-i);	//������
		if (ch==' ')
			Send7279Byte(0x00); 
		else
			if (ch=='-')
			 	Send7279Byte(0x01); 
			else 
			{
				if (ShowDot==i)
					Send7279Byte(0x80|BdSeg[ch&0x0f]); 
				else
					Send7279Byte(BdSeg[ch&0x0f]); 
			}
	}
	NOSELECT7279;     	//��CS�ߵ�ƽ 
}

char GetKeyValue(void)
{
	char KeyValue;
	if (CPT1CN&0x40) return -1;	//�޼����� 
	Send7279Byte(0x15);	//��������ָ�� 
	KeyValue=Receive7279Byte();
	NOSELECT7279;     	//��CS�ߵ�ƽ 
	return KeyValue; 
}

void WaitKeyOff(void)
{
	while  (!(CPT1CN&0x40));
}

void Test7279(bit LoopFlag)
{
	char i,KeyValue;
	Delay1ms(25);		//�ȴ�25ms��λʱ�� 
	Send7279Byte(0xA4);	//����λָ�� 
	NOSELECT7279;     	//��CS�ߵ�ƽ 
	if (LoopFlag==0) return;
	DispLED("123456",0); 	//��ʾ123456
	for (i=0;i<8;i++)
	{
		Delay1s(1);
		MoveLeft();
	}

	DispLED("123456",0); 	//��ʾ123456
	DispLED("7890AB",2); 	//��ʾ123456
	DispLED("CDEF -",3); 	//��ʾ123456

	for (i=0;i<6;i++)
	{
		Delay1s(1);
		MoveRight();
	}

	DispLED("F    1",1); 	//��ʾ123456

	FlashLED(0);	//��һλ��˸
	Delay1s(1);
	FlashLED(1);	//�ڶ�λ��˸
	Delay1s(1);
	FlashLED(8);	//����˸

	//BlankLED(0x23); //ע��:ִ��������,���������жϿڲ��ָܻ�.

	for (;;)
	{	
		KeyValue=GetKeyValue();
         if(KeyValue!=-1)
          {
		    Send7279Byte(0xC8);	//���ͼ���ֵ������ʽ1����������ʾ 
		    Send7279Byte(KeyValue%16);
		    NOSELECT7279;     	//��CS�ߵ�ƽ 
		    WaitKeyOff();
           }
	}
}
