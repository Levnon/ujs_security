Picture = imread('magic.bmp','bmp');  
  

  
Double_Picture = Picture;  
Double_Picture = double(Double_Picture);  
%��ͼ��ת���ɶ�����  
path2_id = fopen('secret.txt' , 'r'); %��ȡ������Ϣ�ļ�  
[msg , len] = fread(path2_id , 'ubit1');  
[m , n] = size(Double_Picture);  
  
p = 1; %pΪ������Ϣ�ļ�����  
for f2 = 1:n  
    for f1 = 1:m  
        Double_Picture(f1 , f2) = Double_Picture(f1,f2) - mod(Double_Picture(f1 , f2) , 2) + msg(p , 1);  
        if(p == len)   
            break;  
        end;  
        p = p + 1;  
    end;  
      
    if(p == len)   
        break;  
    end;   
end;  
  
Double_Picture = uint8(Double_Picture);  
imwrite(Double_Picture , '_magic.bmp');  
subplot(1 , 2 , 1) ; imshow(Picture);title('ԭʼͼ��');  
subplot(1 , 2 , 2) ; imshow(Double_Picture);title('����ͼ��');  
