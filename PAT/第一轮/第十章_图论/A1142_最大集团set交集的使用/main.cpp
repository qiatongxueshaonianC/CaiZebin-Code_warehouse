#include<bits/stdc++.h>
using namespace std;
const int maxn=210;
set<int> G[maxn];
int n; 
int main() {
	int nv,m,u,v;
	scanf("%d%d",&n,&nv);
	for(int i=1;i<=nv;i++){
		scanf("%d%d",&u,&v);
		G[u].insert(v);
		G[v].insert(u);
	}
	scanf("%d",&m);
	while(m--){
		int pre;
		bool flag=false;
		scanf("%d%d",&nv,&pre);
		set<int> ans,st=G[pre],temp;
		st.insert(pre);
		vector<int> A;
		A.push_back(pre);
		for(int i=1;i<nv;i++){
			scanf("%d",&u);
			G[u].insert(u);  //此处输入的u可能图中并不存在这个点 
			set_intersection(G[u].begin(),G[u].end(),st.begin(),st.end(),inserter(temp,temp.begin()));
			//这里只能这么写，如果不用temp之间写st会出错，这可能和内部的实现有关 
			A.push_back(u);
			st=temp;
		}
		for(int i=1;i<A.size();i++){
			if(G[A[i]].find(pre)==G[A[i]].end()){
				puts("Not a Clique");
				flag=true;break;
			}
			pre=A[i];
		}
		if(!flag){
			if(st.size()==nv) puts("Yes");
			else puts("Not Maximal");
		}
	} 
	return 0;
}
/*
8 10
5 6
7 8
6 4
3 6
4 5
2 3
8 2
2 7
5 3
3 4
6
4 5 4 3 6
3 2 8 7
2 2 3
1 1
3 4 3 6
3 3 2 1
*/
