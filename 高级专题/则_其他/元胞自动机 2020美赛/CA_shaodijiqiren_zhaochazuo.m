% 扫地代码
% 
% %一间封闭的空房间, 一个人在里面随意移动
% %状态变化规则：
% %1.四周没有墙壁时，以等概率方式移动到周围8个位置之一；
% %2.位于墙角时，以等概率方式移动到周围3个位置之一；
% %3.位于墙边非墙角时，以等概率方式移动到周围5个位置之一
% close all;
% clc;
% clear;
% M=22;%房间大小M行,包括两行墙
% N=18;%房间大小N列,包括两列墙
% %房间状态初始化
% R=ones(M,N);%初始化R房间矩阵
% R(1,:)=0;
% R(M,:)=0;
% R(:,1)=0;
% R(:,N)=0;
% %R的边界初始化为0
% G=R;%G初始化为R
% B=R;%B初始化为R
% i=unidrnd(M-2)+1;%随机选取初始位置行标
% j=unidrnd(N-2)+1;%随机选取初始位置列标
% G(i,j)=0;%在G中更新初始点
% B(i,j)=0;%在B中更新初始点
% ima=cat(3,R,G,B);%ima为R，G，B拼接而成的3维数组
% imshow(ima,'InitialMagnification','fit');%初始状态图显示
% 
% neighbour=[-1 -1;-1 0;-1 1;0 -1;0 1;1 -1;1 0;1 1];%当前位置邻域
% %i,j始终表示人所在位置的坐标
% t=0;%初始化时间
% while 1
%     t=t+1;%更新时间
%      if 2<i && i<M-1 && 2<j && j<N-1  %人在内部
%          r=unidrnd(8);       
%      elseif i==2 && j==2   %人在左上墙角
%          r=randsrc(1,1,[5 7 8]);    %下、右、右下三个方向{1，0}，{0，1},{1,1}
%      elseif i==2 && j==N-1   %人在右上墙角
%          r=randsrc(1,1,[4 6 7]);
%      elseif i==M-1 && j==2   %人在左下墙角
%          r=randsrc(1,1,[2 3 5]);
%      elseif i==M-1 && j==N-1   %人在右下墙角
%          r=randsrc(1,1,[1 2 4]);
%      elseif i==2 && 2<j && j<N-1  %人在上墙边非墙角
%          r=randsrc(1,1,[4 5 6 7 8]);
%      elseif i==M-1 && 2<j && j<N-1  %人在下墙边非墙角
%          r=randsrc(1,1,[1 2 3 4 5]);
%      elseif 2<i && i<M-1 && j==2  %人在左墙边非墙角
%          r=randsrc(1,1,[2 3 5 7 8]);
%      else 2<i && i<M-1 && j==N-1;  %人在右墙边非墙角
%          r=randsrc(1,1,[1 2 4 6 7]);
%      end
%      i=i+neighbour(r,1); %更新位置坐标
%      j=j+neighbour(r,2); %更新位置坐标
%      G(i,j)=0;  %更新当前人所在位置为红色
%      B(i,j)=0;  %更新当前人所在位置为红色
%      ima=cat(3,R,G,B);%更新ima数组
%      imshow(ima,'InitialMagnification','fit');
%      sum=0;%初始化sum
%      for m=1:M
%          for n=1:N
%            sum=sum+G(m,n);  %计算G矩阵的各个元素之和
%          end
%      end
%      if sum<1
%          break;
%      end
%      %如果元素之和恰好等于0，就说明遍历了所有的位置
%      pause(0.0001);%间隔0.0001秒
% end


%找插座代码
%
%一间封闭的空房间, 一个人在里面随意移动
%状态变化规则：
%1.四周没有墙壁时，以等概率方式移动到周围8个位置之一；
%2.位于墙角时，以等概率方式移动到周围3个位置之一；
%3.位于墙边非墙角时，以等概率方式移动到周围5个位置之一
close all;
clc;
clear;
M=22;%房间大小M行,包括两行墙
N=18;%房间大小N列,包括两列墙
%房间状态初始化
R=ones(M,N);%初始化R房间矩阵
R(1,:)=0;
R(M,:)=0;
R(:,1)=0;
R(:,N)=0;
%R的边界初始化为0
G=R;%G初始化为R
B=R;%B初始化为R
i=unidrnd(M-2)+1;%随机选取初始位置行标
j=unidrnd(N-2)+1;%随机选取初始位置列标
G(i,j)=0;%在G中更新初始点
B(i,j)=0;%在B中更新初始点
ima=cat(3,R,G,B);%ima为R，G，B拼接而成的3维数组
imshow(ima,'InitialMagnification','fit');%初始状态图显示

neighbour=[-1 -1;-1 0;-1 1;0 -1;0 1;1 -1;1 0;1 1];%当前位置邻域
%i,j始终表示人所在位置的坐标
t=0;%初始化时间
while 1
    t=t+1;%更新时间
     if 2<i && i<M-1 && 2<j && j<N-1  %人在内部
         r=unidrnd(8);       
     elseif i==2 && j==2   %人在左上墙角
         r=randsrc(1,1,[5 7 8]);
     elseif i==2 && j==N-1   %人在右上墙角
         r=randsrc(1,1,[4 6 7]);
     elseif i==M-1 && j==2   %人在左下墙角
         r=randsrc(1,1,[2 3 5]);
     elseif i==M-1 && j==N-1   %人在右下墙角
         r=randsrc(1,1,[1 2 4]);
     elseif i==2 && 2<j && j<N-1  %人在上墙边非墙角
         r=randsrc(1,1,[4 5 6 7 8]);
     elseif i==M-1 && 2<j && j<N-1  %人在下墙边非墙角
         r=randsrc(1,1,[1 2 3 4 5]);
     elseif 2<i && i<M-1 && j==2  %人在左墙边非墙角
         r=randsrc(1,1,[2 3 5 7 8]);
     else 2<i && i<M-1 && j==N-1;  %人在右墙边非墙角
         r=randsrc(1,1,[1 2 4 6 7]);
     end
     i=i+neighbour(r,1); %更新位置坐标
     j=j+neighbour(r,2); %更新位置坐标
     G(i,j)=0;  %更新当前人所在位置为红色
     B(i,j)=0;  %更新当前人所在位置为红色
     if(i==5&&j==7) %找到插座
         G(i,j)=0.75;
     end;
     ima=cat(3,R,G,B);%更新ima数组
     imshow(ima,'InitialMagnification','fit');
    if i==12 && j==3 %找到终止点
        R(i,j)=0.7;
        G(i,j)=0.7;
        B(i,j)=0.7;
        ima=cat(3,R,G,B);%更新ima数组
        imshow(ima,'InitialMagnification','fit');
        break;
    end
     pause(0.0001);%间隔0.0001秒
end