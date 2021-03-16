#include<bits/stdc++.h>
using namespace std;
const int maxn=1010;
bool G[maxn][maxn]; 
//int G[maxn][maxn];
int main() {
	int n,m,u,v,T;
	scanf("%d%d",&n,&m);
	vector<int> inDegree(maxn),InDegree(maxn);
	for(int i=0;i<m;i++){
		scanf("%d%d",&u,&v);
		G[u][v]=1;
		InDegree[v]++;
	}
	scanf("%d",&T);
	bool space=false;
	for(int k=0;k<T;k++){
		inDegree=InDegree;
		vector<int> A(n);
		for(int i=0;i<n;i++)
			scanf("%d",&A[i]);
		for(int i=0;i<n;i++){
			if(inDegree[A[i]]!=0){
				printf("%s%d",space?" ":"",k);
				space=true;break;
			}else{
				for(int j=0;j<maxn;j++)
					if(G[A[i]][j]!=0)
						inDegree[j]--;
			}
		}
	}
	return 0;
}
/*
6 8
1 2
1 3
5 2
5 4
2 3
2 6
3 4
6 4
5
1 5 2 3 6 4
5 1 2 6 3 4
5 1 2 3 6 4
5 2 1 6 3 4
1 2 3 4 5 6
*/
