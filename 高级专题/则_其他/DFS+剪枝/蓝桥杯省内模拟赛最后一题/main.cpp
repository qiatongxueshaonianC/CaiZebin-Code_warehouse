#include<bits/stdc++.h>
#define f(x) (x)*(x) 
using namespace std;
const int maxn=1020;
bool vis[maxn]={false};
struct Node{
	int x,y,r;
	Node(int a,int b,int c){
		x=a;y=b;r=c;
	}
	Node(){};
}A[maxn]; 
vector<int> G[maxn];
int n,sum[maxn],best;
bool ok(int p){
	for(int i=0;i<n;i++){
		if(i==p||vis[i]==false)	continue;	//只要求和目前选的那么多个点不冲突就行
		if(f(A[i].r+A[p].r)>f(A[i].x-A[p].x)+f(A[i].y-A[p].y)) 	//圆心间的距离小于半径和的距离
			return false; 
	}
	return true;
}
void DFS(int idx,int S){
	if(S+sum[idx]<=best)
		return;
	if(idx==n){
		best=max(best,S);
		return;
	}
	if(ok(idx)){
		vis[idx]=true;
		DFS(idx+1,S+f(A[idx].r));
	}
	vis[idx]=false;
	DFS(idx+1,S);
}
int main() {
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;i++)
		scanf("%d%d%d",&A[i].x,&A[i].y,&A[i].r);
	sum[n-1]=f(A[n-1].r);
	for(int i=n-2;i>=0;i--)
		sum[i]=sum[i+1]+f(A[i].r);
	DFS(0,0);
	printf("%d\n",best);
	return 0; 
}
/*
4
1 1 3
9 9 7
8 8 6
4 5 4
*/
