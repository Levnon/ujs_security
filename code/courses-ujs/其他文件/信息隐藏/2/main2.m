Picture = imread('_magic.bmp','bmp');  
Picture = double(Picture);  
[m,n] = size(Picture);  
frr = fopen('_secret.txt' , 'w');  
len = 800; % �趨������Ϣ����  
p = 1;  
for f2 = 1:n  
    for f1 = 1:m  
        if bitand(Picture(f1,f2) , 1) == 1  % ˳����ȡ  
            fwrite(frr , 1 , 'ubit1');  
            
        else   
            fwrite(frr , 0 , 'ubit1');  
            
        end;  
        if p==len  
            break;  
        end;  
        p = p + 1;  
    end;  
    if p== len  
        break;  
    end;  
end;  
fclose(frr);  