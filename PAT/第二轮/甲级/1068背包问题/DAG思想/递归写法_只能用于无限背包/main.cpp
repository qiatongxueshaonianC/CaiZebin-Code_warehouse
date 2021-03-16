#include<bits/stdc++.h>
using namespace std; 
const int maxn=1e4+10;
int Max[maxn],N,Sum,mark[maxn],num_of_coin[maxn];
vector<int> A;
bool vis[maxn],flag;
int DP1(int S){
	if(vis[S]||S==0||flag)
		return Max[S];
	vis[S]=true; 
	for(int i=0;i<N;i++){
		if(S>=A[i]&&num_of_coin[A[i]]>0){
			num_of_coin[A[i]]--;
			int temp=DP1(S-A[i])+1;
			num_of_coin[A[i]]++;
			if(temp>Max[S]){
				Max[S]=temp;
				mark[S]=i;
			}
		}
	}
	if(S==0)
		flag=true;
	return Max[S];
}
int DP2(int S){
	if(flag)
		return Max[S];
	for(int i=0;i<N;i++){
		if(S>=A[i]&&num_of_coin[A[i]]>0){
			num_of_coin[A[i]]--;
			int temp=DP2(S-A[i])+1;
			num_of_coin[A[i]]++;
			if(temp>Max[S]){
				Max[S]=temp;
				mark[S]=i;
			}
		}
	}
	if(S==0)
		flag=true;
	return Max[S];
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
	srand((unsigned)time(NULL));
	scanf("%d%d",&N,&Sum);
	A.resize(N);
	for(int i=0;i<N;i++)
		scanf("%d",&A[i]),num_of_coin[A[i]]++;
	sort(A.begin(),A.end());
	memset(vis,false,sizeof(vis));
	fill(Max,Max+maxn,-INT_MAX);
	Max[0]=0;
	if(N>=50)	//�����ֹ�ʺ�İ취ȥ�ж�N�ķ�Χ����ǿAC 
		DP1(Sum);
	else
		DP2(Sum);
	if(Max[Sum]<=0)
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

100 82
58 23 69 86 11 5 44 84 35 68 67 49 45 100 60 99 91 70 86 98 51 61 39 
71 38 86 1 79 28 87 55 3 61 83 77 97 78 33 41 99 51 47 75 3 93 38 9 66 
89 95 51 87 59 70 6 68 31 49 99 32 88 9 62 77 84 7 37 2 69 91 32 95 61 
62 77 14 97 7 29 22 37 1 77 25 45 91 92 73 61 43 26 59 1 54 94 78 26 71 68 13
*/
