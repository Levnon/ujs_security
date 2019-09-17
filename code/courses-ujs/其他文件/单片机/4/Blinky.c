#include <c8051f020.h>                    // SFR declarations

#define SYSCLK 2000000                    // approximate SYSCLK frequency in Hz

void PORT_Init (void);
void Timer0_Init (int counts);
void Timer0_ISR (void);
unsigned int xdata  p2led[]={0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe};

void main (void) {

 
   // disable watchdog timer
   WDTCN = 0xde;
   WDTCN = 0xad;
	
   PORT_Init ();
   Timer0_Init (SYSCLK / 12 / 10);        // Init Timer3 to generate interrupts
                                          // at a 10Hz rate.
   //LED1=1;
  
   EA = 1;	//���������ж� IE�жϼĴ����ĵ�һλ

   while (1) {                            // spin forever
   }
}


void PORT_Init (void)
{
   XBR2    = 0x40;                     // Enable crossbar and weak pull-ups
   //P1MDOUT |= 0x41;                    // enable P1.6 (LED) as push-pull output
}

void Timer0_Init (int counts)
{
   TCON = 0x00;                      // Stop Timer0; Clear TF0;
          //�嶨ʱ��
                                    // use SYSCLK/12 as timebase
   CKCON = 0x00; //ʱ�ӿ��ƼĴ���
   TH0 = -counts/0xff;   //��ʱ�� ��ֵ
   TL0 = -counts % 0xff;

 //  IE   |= 0x01;                     // enable Timer0 interrupts
   ET0 = 1;   //����ʱ��0�ж����� �жϼĴ���
   TMOD |= 0x01; // ��ʽ�Ĵ��� T0�����ڷ�ʽ1
   TCON |= 0x10; // ���ƼĴ��� T0����


}

void Timer0_ISR (void) interrupt 1
{
   int counts;
   static int count;
   static int i=9,j=0;
   static int led=0xff;
   
   //TCON &= ~(0x80); // clear TF0
   count++;

//   TH0 = 0xBD;
//   TL0 = 0xE5;
   counts = SYSCLK / 12 / 10;
   TH0 = -counts/0xff;   //��ʱ�� ��ֵ
   TL0 = -counts % 0xff;

   if(count==5)
   {
    count=0;
    P3=led;
	if(j==7) j++;
	if(j>=0&&j<7)
	P2=p2led[j];
	else if(j>=8&&j<=15)
	P2=p2led[15-j];
	led=led<<1;
    i--;
	j++;
	if(j==15)
	j=2;
    if(i==0)
     {i=9;
      led=0xff;
     } 
   }
}
    //LED = ~LED;// change state of LED