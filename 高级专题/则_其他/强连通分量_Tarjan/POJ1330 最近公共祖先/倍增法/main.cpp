/*	思路：首先建树，根据没有父亲的节点为根节点，找到根，遍历一次树，得到各个节点的level，最后使用倍增法*/ 
// 算法复杂度：O(n) 
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std; 
const int maxn=10010; 
struct Node{
	int father,level;
	vector<int> child;
	Node(){father=-1;level=0;}
}Tree[maxn];
int N;
void PreOrder(int root){
	for(int i=0;i<Tree[root].child.size();i++){
		int nxt=Tree[root].child[i];
		Tree[nxt].level=Tree[root].level+1;
		PreOrder(nxt);
	}
}
void init(){
	for(int i=0;i<=N;i++){
		Tree[i].father=-1;
		Tree[i].level=0;
		Tree[i].child.clear();
	}
}
int main() {
	int t;
	scanf("%d",&t);
	while(t--){
		init();
		scanf("%d",&N);
		int u,v;
		for(int i=0;i<N-1;i++){
			scanf("%d%d",&u,&v);
			Tree[u].child.push_back(v);
			Tree[v].father=u;
		}
		int root;
		for(int i=1;i<=N;i++){
			if(Tree[i].father==-1){
				root=i;
				break;	
			}
		}
		Tree[root].level=1;
		PreOrder(root);
		scanf("%d%d",&u,&v);
		if(Tree[u].level>Tree[v].level)
			swap(u,v);
		while(Tree[v].level>Tree[u].level)
			v=Tree[v].father;
		while(u!=v){
			u=Tree[u].father;
			v=Tree[v].father;
		}
		printf("%d%s",u,t==0?"":"\n");
	}
	return 0;
}
/*
2
16
1 14
8 5
10 16
5 9
4 6
8 4
4 10
1 13
6 15
10 11
6 7
10 2
16 3
8 1
16 12
16 7
5
2 3
3 4
3 1
1 5
3 5
*/
