#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
struct Node{
	int level;
	vector<int> child;
}Tree[maxn];
int n,m,num_level,ans[maxn];
void DFS(int s){
	if(Tree[s].child.size()==0) {
		ans[Tree[s].level]++;
		if(num_level<Tree[s].level) num_level=Tree[s].level;
	}
	for(auto i:Tree[s].child){
		Tree[i].level=Tree[s].level+1;
		DFS(i);
	}
}
int main() {
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int id,k,v;
		scanf("%d%d",&id,&k);
		while(k--){
			scanf("%d",&v);
			Tree[id].child.push_back(v);
		}
	}
	Tree[0].level=0;
	DFS(1);
	for(int i=0;i<=num_level;i++){
		printf("%d",ans[i]);
		if(i<num_level) printf(" ");
	}
	return 0;
}
/*
2 1
01 1 02
*/
