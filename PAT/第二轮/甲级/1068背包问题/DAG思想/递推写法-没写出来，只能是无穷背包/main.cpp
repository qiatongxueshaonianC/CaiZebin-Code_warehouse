#include<bits/stdc++.h>
using namespace std; 
const int maxn=1e4+10;
int Max[maxn],N,Sum,mark[maxn],num_of_coin[maxn];
vector<int> A;
bool vis[maxn];
void DP(int S){		//递推写法，只能是用于无穷背包 
	for(int i=1;i<=S;i++){
		for(int j=0;j<N;j++){
			if(i>=A[j]){
				if(Max[i]<Max[i-A[j]]+1){
					Max[i]=Max[i-A[j]]+1;
					mark[i]=j;
				}
			}
		}
	}
}
void print_ans(int S){
	printf("%d",A[mark[S]]);
	S-=A[mark[S]];
	while(S){
		printf(" %d",A[mark[S]]);
		S-=A[mark[S]];
	}
}
int main() {
	scanf("%d%d",&N,&Sum);
	A.resize(N);
	for(int i=0;i<N;i++)
		scanf("%d",&A[i]),num_of_coin[A[i]]++;
	sort(A.begin(),A.end());
	memset(vis,false,sizeof(vis));
	fill(Max,Max+maxn,-INT_MAX);
	Max[0]=0;
	DP(Sum);
	if(Max[Sum]<0)
		puts("No Solution");
	else
		print_ans(Sum);
	return 0;
}
/*
8 9
5 9 8 7 2 3 4 1

14 9
5 9 8 7 2 3 4 1 1 1 1 1 1 1

4 8
7 2 4 3
*/
