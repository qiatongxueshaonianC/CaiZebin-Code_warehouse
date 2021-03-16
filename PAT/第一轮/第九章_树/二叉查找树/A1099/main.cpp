#include<bits/stdc++.h>
using namespace std; 
const int maxn=110;
struct Node{
	int data,left,right;
}Tree[maxn];
int in[maxn],n,x;
void create(int s){
	if(s==-1) return;
	create(Tree[s].left);
	Tree[s].data=in[x++];
	create(Tree[s].right);
}
void layerOrder(int s){
	queue<int> q;
	q.push(s);
	while(q.size()){
		int now=q.front();q.pop();
		if(Tree[now].left!=-1) q.push(Tree[now].left);
		if(Tree[now].right!=-1) q.push(Tree[now].right);
		printf("%d%s",Tree[now].data,q.empty()?"":" ");
	}
}
int main() {
	scanf("%d",&n);
	int u,v;
	for(int i=0;i<n;i++){
		scanf("%d%d",&u,&v);
		Tree[i].left=u;
		Tree[i].right=v;
	}
	for(int i=0;i<n;i++){
		scanf("%d",&in[i]);
	}
	sort(in,in+n);
	create(0);
	layerOrder(0);
	return 0;
}
/*
9
1 6
2 3
-1 -1
-1 4
5 -1
-1 -1
7 -1
-1 8
-1 -1
73 45 11 58 82 25 67 38 42
*/
