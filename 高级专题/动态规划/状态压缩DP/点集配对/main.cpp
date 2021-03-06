/*
提醒推荐：五星
刘汝佳《算法竞赛入门经典》，集合上的动态规划---最优配对问题
题意：空间里有n个点P0,P1,...,Pn-1，你的任务是把它们配成n/2对（n是偶数），使得每个点恰好在一个点对中。所有点对中两点的距离之和应尽量小。
状态：d(i,S)表示把前i个点中，位于集合S中的元素两两配对的最小距离和
状态转移方程为：d(i,S)=min{|PiPj|+d(i-1,S-{i}-{j}}
书上的解法有些问题，正解见方法一
方法二：状态可以进行压缩，i的值其实隐藏在S中，S中最高位为1的即为i，所以需要一次查找,从n-1到0进行一次历编即可，整个运算下来，平均查找次数仅为2。而且方法二比方法一情况简单很多，也比较容易理解。
方法三：这道题用递归实现更好一些，因为只需要判断n为偶数的情况，这就是递归运算的好处，而非递归则需要全部都进行一次运算。
技巧：①处使用有个技巧，传递引用而不是下标，书写会方便很多。
*/
 
 
//方法一：正解。。。
#include <cstdio>
#include <cstring>
#include <cmath>
const int nMax=21;
const double INF=1e10;
int n;
struct Node
{
	int x,y,z;
}node[nMax];
double d[nMax][1<<nMax];
void init()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d %d %d",&node[i].x,&node[i].y,&node[i].z);
}
double min(double a,double b)
{
	return a<b?a:b;
}
double dis(Node &a,Node &b)//①
{
	return sqrt((double)(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));
}
/* 
void solve()
{
	for(int i=0;i<n;i++)
	{
		for(int s=0;s<(1<<(i+1));s++) 
		{
			if(s==0) d[i][s]=0;
			else d[i][s]=INF;
			if((s & (1<<i)))
			{
				for(int j=i-1;j>=0;j--)
				if((s & (1<<j)))
					d[i][s]=min(d[i][s],dis(node[i],node[j])+d[i-2][s^(1<<i)^(1<<j)]);
			}
			else if(i!=0)
			{
				d[i][s]=d[i-1][s];
			}
		}
	}
}*/  //我的看法： 
void solve()
{
	for(int i=0;i<(1<<n);i++)
		d[0][i]=0; 
	for(int i=1;i<=n;i++)
	{
		for(int s=0;s<(1<<(i+1));s++) 
		{
			if(s==0) d[i][s]=0;
			else d[i][s]=INF;
			if((s & (1<<i)))
			{
				for(int j=i-1;j>=0;j--)
				if((s & (1<<j)))
					d[i][s]=min(d[i][s],dis(node[i],node[j])+d[i-2][s^(1<<i)^(1<<j)]);
			}
			else if(i!=0)
			{
				d[i][s]=d[i-1][s];
			}
		}
	}
} 
int main()
{
	freopen("f://data.in","r",stdin);
	init();
	solve();
	printf("%.3lf\n",d[n-1][(1<<n)-1]);
	return 0;
}
 
 
//方法二：推荐。。。
//#define TEST
#include <cstdio>
#include <cstring>
#include <cmath>
const int nMax=21;
const double INF=1e10;
int n,S;
struct Node
{
	int x,y,z;
}node[nMax];
double d[1<<nMax];
void init()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d %d %d",&node[i].x,&node[i].y,&node[i].z);
	S=1<<n;
	for(int i=1;i<S;i++)
		d[i]=-1;
	d[0]=0;
}
double min(double a,double b)
{
	return a<b?a:b;
}
double dis(Node &a,Node &b)
{
	return sqrt((double)(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));
}
double dp(int p)
{
	if(d[p]!=-1) return d[p];
	d[p]=INF;
	int i,j;
	for(i=n-1;i>=0;i--)
		if(p & (1<<i))
			break;
	for(j=i-1;j>=0;j--)
		if(p & (1<<j))
			d[p]=min(d[p],dis(node[i],node[j])+dp(p^(1<<i)^(1<<j)));
#ifdef TEST
	printf("%d %d\n",p,d[p]);
#endif
	return d[p];
}
int main()
{
	freopen("f://data.in","r",stdin);
	init();
	printf("%.3lf\n",dp(S-1));
	return 0;
}
 
 
//方法三：递归实现
#include <cstdio>
#include <cstring>
#include <cmath>
const int nMax=21;
const double INF=1e10;
int n,S;
struct Node
{
	int x,y,z;
}node[nMax];
double d[1<<nMax];
void init()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d %d %d",&node[i].x,&node[i].y,&node[i].z);
	S=1<<n;
	d[0]=0;
}
double min(double a,double b)
{
	return a<b?a:b;
}
double dis(Node &a,Node &b)
{
	return sqrt((double)(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));
}
void solve()
{
	for(int s=1;s<S;s++)
	{
		int i,j;
		d[s]=INF;
		for(i=n-1;i>=0;i--)
			if(s & 1<<i)
				break;
		for(j=i-1;j>=0;j--)
			if(s & 1<<j)
				d[s]=min(d[s],dis(node[i],node[j])+d[s^(1<<i)^(1<<j)]);
	}
}
int main()
{
	freopen("f://data.in","r",stdin);
	init();
	solve();
	printf("%.3lf\n",d[S-1]);
	return 0;
}

