%assignment 3.1

g=dsolve('Dg+3*g=ynl','g(0)=0');%���Ծ��Ӧ
h=diff(g);%��弤��Ӧ

w=-5*pi:1/10000:5*pi;%Ƶ�ʷ�Χ
a=[1,3]; 
b=[3];
H=freqs(b,a,w); %Ƶ����Ӧ
subplot(2,1,1);%��ͼ��1
plot(w,abs(H));%������ͼ
grid on;%��������
subplot(2,1,2);%��ͼ��2
plot(w,angle(H));%����λͼ
grid on;%��������