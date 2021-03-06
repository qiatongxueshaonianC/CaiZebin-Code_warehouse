#include<bits/stdc++.h>
using namespace std; 
int main() {
	int n,m,u,v;
	scanf("%d",&n);
	vector<set<int>> A(n+1);
	for(int i=1;i<=n;i++){
		scanf("%d",&u);
		while(u--){
			scanf("%d",&v);
			A[i].insert(v);
		}
	}
	scanf("%d",&m);
	while(m--){
		scanf("%d%d",&u,&v);
		set<int> ans;
		set_intersection(A[u].begin(),A[u].end(),A[v].begin(),A[v].end(),inserter(ans,ans.begin()));
		printf("%.1lf%\n",100.0*ans.size()/(A[u].size()+A[v].size()-ans.size()));
	}
	return 0;
}
/*
3
3 99 87 101
4 87 101 5 87
7 99 101 18 5 135 18 99
2
1 2
1 3
*/
