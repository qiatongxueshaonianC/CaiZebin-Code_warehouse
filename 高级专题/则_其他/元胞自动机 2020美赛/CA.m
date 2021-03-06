load('20-69预测海温.mat');
%我们选择原始数据中的10-50行和140-220列
Fa=zeros(41,81);
Fb=zeros(41,81);
%初始化中间矩阵1，2
R=zeros(41,81);
G=zeros(41,81);
B=ones(41,81);
B=B/2;
%初始化RGB矩阵
C=zeros(41,81,3);
%初始化绘图矩阵C
set(gcf,'DoubleBuffer','on');%设定图片适应屏幕大小
ox=30;
oy=25;
%给出鱼的初始位置
Min=min(min(T1));%选择出陆地的位置
D=zeros(2,51);%产生一个空矩阵来表示鱼的位置
D(:,1)=[ox,oy];%记录鱼的初始位置
n=51;%初始化n
title(['T = ',num2str(52-n)]);%在标题处显示时间
while n>1
    n=n-1;%每次更新都要使n加1，可以理解为时间单位加1
   F=T1((ox-1):(ox+1),(oy-1):(oy+1),n);%选取鱼附近的3*3的格点位置
   N=length(find(F<1200&F>900)); %记录在指定温度内的格点的个数
   if N>0  %如果满足条件的格点数大于零
   [r,c]=find(F<1200&F>900); %输出这些格点的位置
   m=unidrnd(N);%随机选择格点
   ox=ox-2+r(m);
   oy=oy-2+c(m);%更新鱼的位置
   D(:,n+1)=[ox,oy];%在D中记录鱼的位置
   else%如果没有满足要求的格点，那么位置不变
       ox=ox;
       oy=oy;
   end
   if N>0  %如果满足条件的格点数大于零
   [r,c]=find(F<1200&F>900); %输出这些格点的位置
   m=unidrnd(N);%随机选择格点
   ox=ox-2+r(m);
   oy=oy-2+c(m);%更新鱼的位置
   D(:,n+1)=[ox,oy];%在D中记录鱼的位置
   else%如果没有满足要求的格点，那么位置不变
       ox=ox;
       oy=oy;
   end

for i=1:41
    for j=1:81
        if T1(i,j,n)>0
            Fa(i,j)=T1(i,j,n);
        else
            Fb(i,j)=T1(i,j,n);  %陆地代表的位置温度标记为负无穷
        end
    end
end
%将原始数据的第一层导入矩阵Fa，Fb
%规则是将原始数据中正整数的部分导入Fa
%将负整数的部分导入Fb
% for i=1:41
%     for j=1:81
%         if T1(i,j,n)==Min
%             Fb(i,j)=0;
%             G(i,j)=1;
%         end
%     end
% end
%这一个循环的意思是将数据中陆地的位置标注出来
%将Fb中最小的值全部转换为0
%G显色矩阵中的相应位置标注为1

 R=Fa/max(max(Fa));%将矩阵Ea归一化赋给R显色矩阵
 G=G+Fb/min(min(Fb)).*0.3;
 for i=1:41
    for j=1:81
        if T1(i,j,n)==Min
            G(i,j)=1;
        end
    end
 end
R(ox,oy)=1;
G(ox,oy)=0.7;
 %将矩阵Eb归一化并且乘以0.9再累加G显色矩阵
 %这里要说明一下0.9的作用，本质上是为了调节图形可视化后的颜色
 C(:,:,1)=R;
 C(:,:,2)=G;
 C(:,:,3)=B;
  %将RGB显色矩阵赋给C
imshow(C,'InitialMagnification','fit');%显示图像
hold on%保持图像
x = 0.5:81.5; %假设水平分成81格
y = 0.5:41.5; %假设垂直分成41格
 M = meshgrid(x,y); %产生网格
 N = meshgrid(y,x); %产生网格
 hold on%保持图像
 plot(x,N,'k'); %画出水平横线
 plot(M,y,'k'); %画出垂直竖线
  title(['T = ',num2str(51-n)]);%第二行是设置图像的标题，显示T=当前时刻
 pause(0.01);%暂停0.1s
  f=getframe(gcf);
    imind=frame2im(f);
    [imind,cm] = rgb2ind(imind,256);
    if n == 1
        imwrite(imind,cm,'infection1.gif','GIF', 'Loopcount',inf,'DelayTime',0.01);
    else
        imwrite(imind,cm,'infection1.gif','GIF','WriteMode','append','DelayTime',0.01);
    end
end