//教训：树的高度和层数是两个概念，层数上，根节点为第0层，但是高度是最高的
//高度为0的叶子节点其不一定在底下两层 
#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node *left,*right;
	Node(int a){
		data=a;
		left=right=NULL;
	}
};
int n,ans[1000],maxLevel; 
void insert(Node* &root,int v){
	if(root==NULL){
		root=new Node(v);
		return;
	}
	if(v>root->data)
		insert(root->right,v);
	else
		insert(root->left,v);
}
void DFS(Node* root,int level){
	if(root==NULL) {
		maxLevel=max(maxLevel,level);
		return;
	}
	ans[level]++;
	DFS(root->left,level+1);
	DFS(root->right,level+1);
}
int main() {
	scanf("%d",&n);
	Node* root=NULL;
	int v;
	for(int i=0;i<n;i++){
		scanf("%d",&v);
		insert(root,v);
	}
	DFS(root,0);
	printf("%d + %d = %d\n",ans[maxLevel-1],ans[maxLevel-2],ans[maxLevel-1]+ans[maxLevel-2]);
	return 0;
}
/*
9
25 30 42 16 20 20 35 -5 28
*/
