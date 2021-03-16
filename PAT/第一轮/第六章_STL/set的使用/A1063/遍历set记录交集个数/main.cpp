#include<bits/stdc++.h>
using namespace std;
const int maxn=60;
int n; 
vector<unordered_set<int>> st(maxn);
int main() {
	scanf("%d",&n);
	int u,v;
	for(int i=1;i<=n;i++){
		scanf("%d",&u);
		while(u--){
			scanf("%d",&v);
			st[i].insert(v);
		}
	}
	scanf("%d",&n);
	int num;
	for(int i=0;i<n;i++){
		num=0;
		scanf("%d%d",&u,&v);
		for(auto i:st[u])
			if(st[v].find(i)!=st[u].end()) num++;
		printf("%.1lf%%\n",100.0*num/(st[u].size()+st[v].size()-num));
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
