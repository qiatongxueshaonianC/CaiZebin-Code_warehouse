clc
clear
load('20-69Ԥ�⺣��.mat');
%����ѡ��ԭʼ�����е�10-50�к�140-220��
Fa=zeros(41,81);
Fb=zeros(41,81);
%��ʼ���м����1��2
R=zeros(41,81);
G=zeros(41,81);
B=ones(41,81);
B=B./2;
%��ʼ��RGB����
C=zeros(41,81,3);
%��ʼ����ͼ����C
set(gcf,'DoubleBuffer','on');%�趨ͼƬ��Ӧ��Ļ��С
ox=30;
oy=25;
%������ĳ�ʼλ��
Min=min(min(T1));%ѡ���½�ص�λ��
D=zeros(2,51);%����һ���վ�������ʾ���λ��
D(:,1)=[ox,oy];%��¼��ĳ�ʼλ��
n=51;%��ʼ��n
title(['T = ',num2str(52-n)]);%�ڱ��⴦��ʾʱ��
while n>1
    n=n-1;%ÿ�θ��¶�Ҫʹn��1���������Ϊʱ�䵥λ��1
   for i=1:2
       F=T1((ox-1):(ox+1),(oy-1):(oy+1),n);%ѡȡ�㸽����3*3�ĸ��λ��
       N=length(find(F<1200&F>900)); %��¼��ָ���¶��ڵĸ��ĸ���
       if N>0  %������������ĸ����������
           [r,c]=find(F<1200&F>900); %�����Щ����λ��
           m=unidrnd(N);%���ѡ����
           ox=ox-2+r(m);
           oy=oy-2+c(m);%�������λ��
           D(:,n+1)=[ox,oy];%��D�м�¼���λ��
       else%���û������Ҫ��ĸ�㣬��ôλ�ò���
           ox=ox;
           oy=oy;
       end
   end
   D(:,52-n)=[ox,oy];
for i=1:41
    for j=1:81
        if T1(i,j,n)>0 
            Fa(i,j)=T1(i,j,n);
%         elseif T1(i,j,n)==Min
%             Fb(i,j)=0;
        else
            Fb(i,j)=T1(i,j,n);
        end
    end
end
%��ԭʼ���ݵĵ�һ�㵼�����Fa��Fb
%�����ǽ�ԭʼ�������������Ĳ��ֵ���Fa
%���������Ĳ��ֵ���Fb
% for i=1:41
%     for j=1:81
%         if T1(i,j,n)==M
%             Fb(i,j)=0;
%             G(i,j)=1;
%         end
%     end
% end
%��һ��ѭ������˼�ǽ�������½�ص�λ�ñ�ע����
%��Fb����С��ֵȫ��ת��Ϊ0
%G��ɫ�����е���Ӧλ�ñ�עΪ1

 R=Fa./max(max(Fa));%������Ea��һ������R��ɫ����
 G=G+Fb./min(min(Fb)).*0.3;
  for i=1:41
    for j=1:81
        if T1(i,j,n)==Min
            G(i,j)=1;
        end
    end
  end
R(ox,oy)=1;
G(ox,oy)=0.7;
 %������Eb��һ�����ҳ���0.9���ۼ�G��ɫ����
 %����Ҫ˵��һ��0.9�����ã���������Ϊ�˵���ͼ�ο��ӻ������ɫ
 C(:,:,1)=R;
 C(:,:,2)=G;
 C(:,:,3)=B;
  %��RGB��ɫ���󸳸�C
imshow(C,'InitialMagnification','fit');%��ʾͼ��
hold on%����ͼ��
x = 0.5:81.5; %����ˮƽ�ֳ�81��
y = 0.5:41.5; %���费ֱ�ֳ�41��
 M = meshgrid(x,y); %��������
 N = meshgrid(y,x); %��������
 hold on%����ͼ��
 plot(x,N,'k'); %����ˮƽ����
 plot(M,y,'k'); %������ֱ����
  title(['T = ',num2str(51-n)]);%�ڶ���������ͼ��ı��⣬��ʾT=��ǰʱ��
 pause(0.01);%��ͣ0.1s
  f=getframe(gcf); 
    imind=frame2im(f);
    [imind,cm] = rgb2ind(imind,256);
    if n == 50
        imwrite(imind,cm,'infection2.gif','GIF', 'Loopcount',inf,'DelayTime',0.01);
    else
        imwrite(imind,cm,'infection2.gif','GIF','WriteMode','append','DelayTime',0.01);
    end 
end