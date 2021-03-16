#include<bits/stdc++.h>
using namespace std;
const int inf=0x3fffffff;
struct Node{
	int data,leftBlack,rightBlack;
	Node *left,*right;
	Node(int a){
		data=a;
		leftBlack=rightBlack=1;
		left=right=NULL;
	}
};
int T,n; 
bool ans;
void insert(Node* &root,int v){
	if(root==NULL){
		root=new Node(v);
		return;
	}
	if(abs(v)<abs(root->data)) insert(root->left,v);
	else insert(root->right,v);
}
int DFS(Node* &root){
	if(root==NULL) {
		root=new Node(inf);
		return 1;
	}
/*	int num=DFS(root->left);
	root->leftBlack=root->data>0?num+1:num;
	num=DFS(root->right);
	root->rightBlack=root->data>0?num+1:num;*/ //���ֲ�ͬ��д�� 
	root->leftBlack=DFS(root->left);
	root->rightBlack=DFS(root->right);
	return root->data>0?root->leftBlack+1:root->leftBlack;
}
void inOrder(Node* root){
	if(root->data==inf||ans==false) return;
	if(root->data<0&&(root->left->data<0||root->right->data<0)) ans=false;
	if(root->leftBlack!=root->rightBlack) ans=false;
	inOrder(root->left);
	inOrder(root->right);
}
int main() {
	scanf("%d",&T);
	while(T--){
		ans=true;
		Node *root=NULL;
		int v;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&v);
			insert(root,v);
		}
		DFS(root);
		inOrder(root);
	//	printf("%s\n",ans&&root->data>0?"YES":"NO");//2019/11/3//11:12���ִ��� 
		printf("%s\n",ans&&root->data>0?"Yes":"No");
	}
	return 0;
}
/*
3
9
7 -2 1 5 -4 -11 8 14 -15
9
11 -2 1 -7 5 -4 8 14 -15
8
10 -7 5 -6 8 15 -11 17
*/
