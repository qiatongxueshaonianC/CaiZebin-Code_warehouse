#include<bits/stdc++.h>
using namespace std;
const int maxn=210;
const int inf=0x3fffffff;
int n,m; 
unordered_map<int,int>G[maxn]; 
int main() {
	scanf("%d%d",&n,&m);
	int u,v,dis,T;
	pair<int,int> ans={inf,inf};
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&u,&v,&dis);
		G[u].insert({v,dis});
		G[v].insert({u,dis});
	}
	scanf("%d",&T);
	for(int k=1;k<=T;k++){
		dis=0;
		scanf("%d",&m);
		vector<int> A(m);
		set<int> st;
		for(int i=0;i<m;i++){
			scanf("%d",&A[i]);
			st.insert(A[i]);
		}
		for(int i=0;i<m-1;i++){
			auto it=G[A[i]].find(A[i+1]);
			if(it!=G[A[i]].end()) dis+=it->second;
			else{
				dis=inf;break;
			}
		}
		if(dis==inf)
			printf("Path %d: NA (Not a TS cycle)\n",k);
		else{
			if(A[0]==A[m-1]&&st.size()==n&&m==n+1) {
				printf("Path %d: %d (TS simple cycle)\n",k,dis);
				if(dis<ans.second){
					ans.first=k;
					ans.second=dis;
				}
			}
			else if(A[0]==A[m-1]&&st.size()==n){
				printf("Path %d: %d (TS cycle)\n",k,dis);
				if(dis<ans.second){
					ans.first=k;
					ans.second=dis;
				}
			}else{
				printf("Path %d: %d (Not a TS cycle)\n",k,dis);
			}
		}
	}
	printf("Shortest Dist(%d) = %d",ans.first,ans.second);
	return 0;
}
/*
6 10
6 2 1
3 4 1
1 5 1
2 5 1
3 1 8
4 1 6
1 6 1
6 3 1
1 2 1
4 5 1
7
7 5 1 4 3 6 2 5
7 6 1 3 4 5 2 6
6 5 1 4 3 6 2
9 6 2 1 6 3 4 5 2 6
4 1 2 5 1
7 6 1 2 5 4 3 1
7 6 3 2 5 4 1 6
*/
