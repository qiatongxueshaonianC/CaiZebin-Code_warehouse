#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<algorithm>
#include<cmath>
#include<climits>
#include<numeric>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<list>
using namespace std; 
const int maxn=5010;
int sum[maxn<<2],N,A[maxn]; 
void update(int rt,int L,int R,int pos,int num){
	if(L==R&&L==pos)
		sum[rt]=num;
	else{
		int Mid=(L+R)/2;
		if(pos<=Mid)
			update(rt*2,L,Mid,pos,num);
		else
			update(rt*2+1,Mid+1,R,pos,num);
		sum[rt]=sum[rt*2]+sum[rt*2+1];
	}
}
int query(int rt,int l,int r,int L,int R){
	if(L>R)
		return 0;
	if(L<=l&&r<=R)
		return sum[rt];
	int Mid=(l+r)/2,ans=0;
	if(L<=Mid)
		ans+=query(rt*2,l,Mid,L,R);
	if(R>Mid)
		ans+=query(rt*2+1,Mid+1,r,L,R);
	return ans;
}
int main() {
	while(cin>>N){
		for(int i=0;i<N;i++){
			scanf("%d",&A[i]);
			A[i]++;
		}
		int Sum=0,right_less[maxn],right_more[maxn];
		for(int i=N-1;i>=0;i--){
			update(1,1,N,A[i],1);
			right_less[i]=query(1,1,N,1,A[i]-1);
			right_more[i]=(N-1-i)-right_less[i];
			Sum+=right_less[i];		//初始序列的逆序数 
		}
		int ans=0,left_less[maxn],left_more[maxn];
		memset(sum,0,sizeof(sum));
		for(int i=0;i<N;i++){
			update(1,1,N,A[i],1);
			left_less[i]=query(1,1,N,1,A[i]-1);
			left_more[i]=i-left_less[i];
		}
		int Min=Sum;
		for(int i=0;i<N;i++){
			ans+=(right_more[i]-right_less[i]-left_less[i]+left_more[i]);
			Min=min(Min,Sum+ans);
		}
		printf("%d\n",Min);
	}
	return 0;
}
/*
10
1 3 6 9 0 8 5 7 4 2
*/
