%assignment 2.2
%�������ǲ��ź�Ƶ��
%�������ű�
w = linspace(-6 * pi,6*pi,512);%����������
n = length(w);%��������w�ĳ���
F = zeros(1,N);%����ȫ0�ľ���
for i=1:n
    F(i)=quadl(@fun,-1,1,[],[],w(i));%�����
end
subplot(2,1,1);%��ͼ��1
plot(w,F);%F��ͼ��
grid on;%��������
subplot(2,1,2);%��ͼ��2
plot(w,F-sinc(w./2./pi).^2);%���ͼ��
grid on;%��������