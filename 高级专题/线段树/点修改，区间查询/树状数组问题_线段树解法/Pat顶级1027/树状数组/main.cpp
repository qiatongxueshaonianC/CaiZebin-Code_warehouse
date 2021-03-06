#include<bits/stdc++.h>
#define lowbit(x) x&(-x)
using namespace std; 
const int maxn=1010;
int N,A[maxn],Sum;
void init(){
	int C[N+1]={};
	for(int i=N-1;i>=0;i--){
		int x=A[i],y=A[i];
		for(x;x>0;x-=lowbit(x))
			Sum+=C[x];
		for(y;y<=N;y+=lowbit(y))
			C[y]++;
	}
}
void Solve(){
	for(int i=0;i<N;i++){
		int C[N+1]={},ans=0;
		for(int j=i;j<N;j++){
			int x=A[j],y=A[j],left_less_than=0,left_more_than=0;
			for(x;x>0;x-=lowbit(x))
				left_less_than+=C[x];
			for(y;y<=N;y+=lowbit(y))
				C[y]++;
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
