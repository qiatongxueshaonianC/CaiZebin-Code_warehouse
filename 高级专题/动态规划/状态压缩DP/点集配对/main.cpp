/*
�����Ƽ�������
����ѡ��㷨�������ž��䡷�������ϵĶ�̬�滮---�����������
���⣺�ռ�����n����P0,P1,...,Pn-1����������ǰ��������n/2�ԣ�n��ż������ʹ��ÿ����ǡ����һ������С����е��������ľ���֮��Ӧ����С��
״̬��d(i,S)��ʾ��ǰi�����У�λ�ڼ���S�е�Ԫ��������Ե���С�����
״̬ת�Ʒ���Ϊ��d(i,S)=min{|PiPj|+d(i-1,S-{i}-{j}}
���ϵĽⷨ��Щ���⣬���������һ
��������״̬���Խ���ѹ����i��ֵ��ʵ������S�У�S�����λΪ1�ļ�Ϊi��������Ҫһ�β���,��n-1��0����һ�����༴�ɣ���������������ƽ�����Ҵ�����Ϊ2�����ҷ������ȷ���һ����򵥺ܶ࣬Ҳ�Ƚ�������⡣
��������������õݹ�ʵ�ָ���һЩ����Ϊֻ��Ҫ�ж�nΪż�������������ǵݹ�����ĺô������ǵݹ�����Ҫȫ��������һ�����㡣
���ɣ��ٴ�ʹ���и����ɣ��������ö������±꣬��д�᷽��ܶࡣ
*/
 
 
//����һ�����⡣����
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
double dis(Node &a,Node &b)//��
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
}*/  //�ҵĿ����� 
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
 
 
//���������Ƽ�������
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
 
 
//���������ݹ�ʵ��
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

