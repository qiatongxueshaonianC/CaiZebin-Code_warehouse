#include<bits/stdc++.h>
using namespace std; 
int main() {
	int N,M,L,R,replace;
	scanf("%d%d%d%d%d",&N,&M,&L,&R,&replace);
	vector<vector<int>> G(N); 
	fill(G.begin(),G.end(),vector<int>(M));
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			scanf("%d",&G[i][j]);
			if(G[i][j]>=L&&G[i][j]<=R)
				G[i][j]=replace;
		}
	}
	for(auto i:G){
		for(vector<int>::iterator j=i.begin();j!=i.end();j++)
			printf("%s%03d",j==i.begin()?"":" ",*j);
		puts("");
	}
}
/*
3 5 100 150 0
3 189 254 101 119
150 233 151 99 100
88 123 149 0 255
*/
