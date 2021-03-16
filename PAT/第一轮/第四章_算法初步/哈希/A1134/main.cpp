#include<bits/stdc++.h>
using namespace std; 
multiset<pair<int,int>> edge;
int main() {
	int n,m,k,u,v,ans;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d",&u,&v);
		edge.insert({u,v});
	} 
	scanf("%d",&k);
	while(k--){
		bool harsh[n+1]={false},flag=true;
		int num=0;
		scanf("%d",&m);
		for(int i=0;i<m;i++){
			scanf("%d",&v);
			harsh[v]=true;
		}
		for(auto i:edge){
			if(harsh[i.first]==false&&harsh[i.second]==false){
				flag=false;
				break;
			}
		}
		printf("%s\n",flag?"Yes":"No");
	}
	return 0;
}
/*
10 11
8 7
6 8
4 5
8 4
8 1
1 2
1 4
9 8
9 1
1 0
2 4
5
4 0 3 8 4
6 6 1 7 5 4 9
3 1 8 4
2 2 8
7 9 8 7 6 5 4 2
*/
