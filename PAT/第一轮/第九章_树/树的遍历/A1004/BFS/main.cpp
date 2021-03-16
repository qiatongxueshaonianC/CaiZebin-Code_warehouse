#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
struct Node{
	int level;
	vector<int> child;
}Tree[maxn];
int n,m,num_level,ans[maxn]; 
void BFS(int s){
	Tree[s].level=0;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int now=q.front();q.pop();
		if(Tree[now].child.size()==0) ans[Tree[now].level]++;
		if(Tree[now].level>num_level) num_level=Tree[now].level;
		for(auto i:Tree[now].child){
			Tree[i].level=Tree[now].level+1;
			q.push(i);
		}
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
	BFS(1);
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
