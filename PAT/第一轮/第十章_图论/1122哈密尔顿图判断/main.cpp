#include<bits/stdc++.h>
using namespace std;
const int maxn=210;
vector<int> G[maxn];
set<int> st;
int n,m,k; 
bool judge(vector<int> vct){
	if(vct.size()!=n+1||st.size()!=n||vct.front()!=vct.back()) return false;
	for(int i=0;i<vct.size()-1;i++){  //2019/11/7/23:02发现，这里是vct.size()-1，不是减二 
		int u=vct[i],v=vct[i+1];
		if(find(G[u].begin(),G[u].end(),v)==G[u].end()) return false;
	}
	return true;
}
int main() {
	scanf("%d%d",&n,&m);
	int u,v;
	for(int i=0;i<m;i++){
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	scanf("%d",&k);
	while(k--){
		st.clear();
		scanf("%d",&u);
		vector<int> vct(u);
		for(int i=0;i<u;i++){
			scanf("%d",&vct[i]);
			st.insert(vct[i]);
		}
		printf("%s\n",judge(vct)?"YES":"NO");
	}
	return 0;
}
/*
6 10
6 2
3 4
1 5
2 5
3 1
4 1
1 6
6 3
1 2
4 5
6
7 5 1 4 3 6 2 5
6 5 1 4 3 6 2
9 6 2 1 6 3 4 5 2 6
4 1 2 5 1
7 6 1 3 4 5 2 6
7 6 1 2 5 4 3 1
*/
