%assignment 2.2
%�������ǲ��ź�Ƶ��
%��������ű�
function value=fun(t,w)
 if (abs(t)<=1)
     value=(1-abs(t)).*(exp(j*w*t));
 else value=0;
end
