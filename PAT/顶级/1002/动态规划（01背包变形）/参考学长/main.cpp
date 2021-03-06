#include<bits/stdc++.h>
using namespace std; 
struct Node{
	int profit,need,dl;
	bool operator <(const Node& a){
		return dl!=a.dl?dl<a.dl:need<a.need;
	}
};
vector<Node> A;
int N,ans,T,dp[55][100000];
void F(){
	for(int i=1;i<A.size();i++){
		for(int j=1;j<=T;j++){
			dp[i][j]=dp[i-1][j];
			int k=min(j,A[i].dl)-A[i].need;  //在0~A[i].dl-A[i].need之间开始第i个任务都行 
			if(k>=0) //dp[i][j]:在前j天按要求完成前i个任务中的若干个，使得效益值最大 
				dp[i][j]=max(dp[i][j],dp[i-1][k]+A[i].profit);
		}
	}
} 
bool cmp(const Node& a,const Node& b){
		return a.dl>b.dl;
}
int main() {
	scanf("%d",&N);
	A.resize(N+1);
	for(int i=1;i<=N;i++)
		scanf("%d%d%d",&A[i].profit,&A[i].need,&A[i].dl);
	Node I=(*min_element(A.begin(),A.end(),cmp));
	T=I.dl;
	sort(A.begin(),A.end());
	F();
	printf("%d",dp[N][T]); 
	return 0;
}
/*
4
7 1 3
10 2 3
6 1 2
5 1 1

3
6 3 3
3 2 2
4 1 3
*/

