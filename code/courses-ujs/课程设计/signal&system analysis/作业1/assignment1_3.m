%assignment 1.3
%y=rectpuls(t);
%����Ϊt=0;
t=-2:1/10000:2;%�趨t�ķ�Χ
wid=2;%�趨���
y=rectpuls(t,wid);%���ʽ
plot(t,y);%��ͼ
ylim([-0.5,1.5]);%�趨���귶Χ
grid on;%��������