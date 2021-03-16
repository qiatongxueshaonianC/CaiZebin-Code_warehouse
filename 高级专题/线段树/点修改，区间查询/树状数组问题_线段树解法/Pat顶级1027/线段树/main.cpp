#include<bits/stdc++.h>
#define lowbit(x) x&(-x)
using namespace std; 
const int maxn=1010;
int N,A[maxn],sum[maxn<<2],Sum;
void update(int rt,int L,int R,int pos,int num){
	if(L==R&&L==pos)
		sum[rt]+=num;
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
	int Mid=(l+r)/2,temp=0;
	if(L<=Mid)
		temp+=query(rt*2,l,Mid,L,R);
	if(R>Mid)
		temp+=query(rt*2+1,Mid+1,r,L,R);
	return temp;
}
void init(){
	for(int i=N-1;i>=0;i--){
		update(1,1,N,A[i],1);
		Sum+=query(1,1,N,1,A[i-1]);
	}
}
void Solve(){
	for(int i=0;i<N;i++){
		int ans=0;
		memset(sum,0,sizeof(sum));
		for(int j=i;j<N;j++){
			int left_less_than=0,left_more_than=0;
			update(1,1,N,A[j],1);
			left_less_than=query(1,1,N,1,A[j]-1);  //¼ÆËã×ó±ßÐ¡ÓÚ 
			left_more_than=j-i-left_less_than;
			ans+=(left_less_than-left_more_than);
			printf("%s%d",j==0?"":" ",Sum+ans);
		}
	}
}
int main() {
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		scanf("%d",&A[i]);
	init();
	Solve();
	return 0;
}
/*
3
2 1 3
*/
