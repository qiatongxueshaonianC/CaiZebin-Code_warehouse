#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
struct Node{
	int weight;
	int sumweight;
	vector<int> child;
}Tree[maxn];
int n,m,Sum;
vector<int> ans;
bool cmp(int a,int b){
	return Tree[a].weight>Tree[b].weight;
}
void DFS(int s){
	if(Tree[s].child.size()==0&&Tree[s].sumweight==Sum){
		for(auto i:ans){
			printf("%d ",Tree[i].weight);
		}
		printf("%d\n",Tree[s].weight);
	}
	ans.push_back(s); 
	for(auto i:Tree[s].child){
		Tree[i].sumweight=Tree[s].sumweight+Tree[i].weight;
		DFS(i);
	}
	ans.pop_back();
}
int main() {
	scanf("%d%d%d",&n,&m,&Sum);
	for(int i=0;i<n;i++){
		scanf("%d",&Tree[i].weight);
	}
	for(int i=0;i<m;i++){
		int id,k,v;
		scanf("%d%d",&id,&k);
		while(k--){
			scanf("%d",&v);
			Tree[id].child.push_back(v);
		}
		sort(Tree[id].child.begin(),Tree[id].child.end(),cmp);
	}
	Tree[0].sumweight=Tree[0].weight;
	DFS(0);
	return 0;
}
/*
20 9 24
10 2 4 3 5 10 2 18 9 7 2 2 1 3 12 1 8 6 2 2
00 4 01 02 03 04
02 1 05
04 2 06 07
03 3 11 12 13
06 1 09
07 2 08 10
16 1 15
13 3 14 16 17
17 2 18 19
*/
