%�ļ�����extractdctadv.m
%�������ܣ�����������DCT������Ϣ����ȡ
%�����ʽ������
%tt=extractdctadv('lennahide.jpg','2.txt',1982,40)
%����˵����
%imageΪ�Ѿ�������Ϣ��ͼ��
%permissionΪͼ���ʽ
%msgΪ��ȡ��Ϣ��ŵ�λ��
%keyΪ��Կ�������������ѡ��
%countΪ��Ϣ�ı��������ɲ��뷽����
function result=extractdctadv()
frr=fopen('1.txt','r');
[msg,count]=fread(frr,'ubit1');
data0=imread('_lena.bmp','bmp');
data0=double(data0)/255;
%��ͼ���һ������ȡ
data=data0(:,:,1);
%�ֿ���DCT�任
T=dctmtx(8);
DCTcheck=blkproc(data,[8 8],'P1*x*P2',T,T');
%��������Ŀ�ѡ��,ȷ��ͼ�����׵�ַ
[row,col]=size(DCTcheck);
row=floor(row/8);
col=floor(col/8);
a=zeros([row col]);
[k1,k2]=randinterval(a,count,2001);
for i=1:count    
	k1(1,i)=(k1(1,i)-1)*8+1;    
	k2(1,i)=(k2(1,i)-1)*8+1;
end

%׼����ȡ����д��Ϣ
frr = fopen('1secret.txt' , 'w'); 
for i=1:count
   if DCTcheck(k1(i)+4,k2(i)+1)<=DCTcheck(k1(i)+3,k2(i)+2) 
      fwrite(frr,0,'ubit1');
      result(i,1)=0;
  else
     fwrite(frr,1,'ubit1'); 
     result(i,1)=1;
   end
end
fclose(frr);
