#include<bits/stdc++.h>
using namespace std; 
const int maxn=110;
struct Node{
	int layer;
	vector<int> child;
}Tree[maxn];
int n,m,ans[maxn],num_level; 
void DFS(int s){
	ans[Tree[s].layer]++;
	if(Tree[s].layer>num_level) num_level=Tree[s].layer;
	for(auto i:Tree[s].child){
		Tree[i].layer=Tree[s].layer+1;
		DFS(i);
	}
}
int main() {
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int v,loop,id;
		scanf("%d%d",&id,&loop);
		while(loop--){
			scanf("%d",&v);
			Tree[id].child.push_back(v);
		}
	}
	Tree[1].layer=1;
	DFS(1);
	int max=0;
	for(int i=1;i<=num_level;i++){
		if(ans[i]>max) {
			max=ans[i];
			n=i;
		}
	}
	printf("%d %d\n",max,n);
	return 0;
}
/*
23 13
21 1 23
01 4 03 02 04 05
03 3 06 07 08
06 2 12 13
13 1 21
08 2 15 16
02 2 09 10
11 2 19 20
17 1 22
05 1 11
07 1 14
09 1 17
10 1 18
*/
