%assignment 4
%���ο�˹��Ƶ��
%y(t)=sin(40*pi*t)+sin(24*pi*t)
n1=[40*pi]; %sinkt�е�ϵ��
v1=[1 0 ((40*pi)^2)]; %������˹�任
c1=tf(n1,v1); %L[sinkt]=k/(s^2+k^2)
n2=[24*pi]; %sinkt�е�ϵ��
v2=[1 0 ((24*pi)^2)]; %������˹�任
c2=tf(n2,v2);  %L[sinkt]=k/(s^2+k^2)
c=c1+c2;%����ϵͳ��������˹�任
nyquist(c);%�ο�˹��Ƶ��ͼ