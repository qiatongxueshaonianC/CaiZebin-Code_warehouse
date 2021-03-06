#include<bits/stdc++.h>
using namespace std; 
const int maxn=110;
struct Node{
	int layer;
	vector<int> child;
}Tree[maxn];
int n,m,temp[maxn];
pair<int,int> ans;
void BFS(int s){
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int now=q.front();q.pop();
		temp[Tree[now].layer]++;
		if(temp[Tree[now].layer]>ans.first) {
			ans.first=temp[Tree[now].layer];
			ans.second=Tree[now].layer;
		}
		for(auto i:Tree[now].child){
			Tree[i].layer=Tree[now].layer+1;
			q.push(i);
		}
	}
}
int main() {
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int v,id,loop;
		scanf("%d%d",&id,&loop);
		while(loop--){
			scanf("%d",&v);
			Tree[id].child.push_back(v);
		}
	}
	Tree[1].layer=1;
	BFS(1); 
	printf("%d %d\n",ans.first,ans.second);
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
