#include<bits/stdc++.h>
using namespace std; 
const int maxn=1010;
int main() {
	int n,group,id,score,A[maxn]={0},ans=0;
	memset(A,sizeof(A),0);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d-%d %d",&group,&id,&score);
		A[group]+=score;
	}
	score=0;
	for(int i=0;i<maxn;i++){
		if(A[i]>=score){
			score=A[i];
			ans=i;
		}
	}
	printf("%d %d",ans,score);
	return 0;
}
/*
6
3-10 99
11-5 87
102-1 0
102-3 100
11-9 89
3-2 61
*/
