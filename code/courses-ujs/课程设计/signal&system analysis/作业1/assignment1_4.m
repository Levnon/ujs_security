%assignment 1.4
%y=dirac(t);
%�弤����;
t=-2:1/10000:2;%�趨t�ķ�Χ
y=dirac(t);%���ʽ
y=1*sign(y);
plot(t,y);%��ͼ
ylim([-0.5,1.5]);%�趨���귶Χ
grid on;%��������