#include<bits/stdc++.h>
using namespace std;
int main() {
	int N,u,n=1;
	scanf("%d",&N);
	priority_queue<int> q;
	for(int i=0;i<N;i++){
		scanf("%d",&u);
		q.push(u);
	}
	int sqr=(int)sqrt(N);
	for(int i=2;i<=sqr;i++){
		if(N%i==0)
			n=i;
	}
	int m=N/n,idx=0;
	vector<vector<int>> G(m);
	fill(G.begin(),G.end(),vector<int>(n,-INT_MAX));
	int i=0,j=0;
	while(!q.empty()){
		while(j<n&&G[i][j]==-INT_MAX){
			G[i][j++]=q.top();
			q.pop();
		};
		j--;i++;
		while(i<m&&G[i][j]==-INT_MAX){
			G[i++][j]=q.top();
			q.pop();
		}
		i--;j--;
		while(j>=0&&G[i][j]==-INT_MAX){
			G[i][j--]=q.top();
			q.pop();
		}
		j++;i--;
		while(i>=0&&G[i][j]==-INT_MAX){
			G[i--][j]=q.top();
			q.pop();
		}
		i++;j++;
	}
	for(auto I:G){
		for(int j=0;j<I.size();j++)
			printf("%d%s",I[j],j==I.size()-1?"\n":" ");
	}
	return 0; 
}
/*
12
37 76 20 98 76 42 53 95 60 81 58 93

7
1 2 3 4 5 6 7 
*/
