#include<bits/stdc++.h>
using namespace std;
int main() {
	int N;
	scanf("%d",&N);
	vector<int> A(N);
	for(int i=0;i<N;i++)
		scanf("%d",&A[i]);
	sort(A.begin(),A.end(),greater<int>());
	int m,n=1,sqr=(int)sqrt(1.0*N);
	for(int i=2;i<=sqr;i++){
		if(N%i==0)
			n=i;
	}
	m=N/n;
	vector<vector<int>> G(m);
	fill(G.begin(),G.end(),vector<int>(n,-INT_MAX));
	int i=0,j=0,idx=0;
	while(idx<A.size()){
		while(j<n&&G[i][j]==-INT_MAX){
			G[i][j++]=A[idx++];
		};
		j--;i++;
		while(i<m&&G[i][j]==-INT_MAX){
			G[i++][j]=A[idx];
			idx=idx+1;
		}
		i--;j--;
		while(j>=0&&G[i][j]==-INT_MAX)
			G[i][j--]=A[idx++];
		j++;i--;
		while(i>=0&&G[i][j]==-INT_MAX)
			G[i--][j]=A[idx++];
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
1 2 3 4 5 6 7 8 9
*/
