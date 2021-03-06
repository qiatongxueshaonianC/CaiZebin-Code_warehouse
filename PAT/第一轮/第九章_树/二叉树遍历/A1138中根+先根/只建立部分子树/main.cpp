#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node *left,*right;
	Node(){
		left=right=NULL;
	}
	Node(int a):data(a),left(NULL),right(NULL){}
};
int n; 
bool flag;
vector<int> pre,in;
Node *create(int prel,int prer,int inl,int inr){
	if(prel>prer) return NULL;
	Node *now=new Node(pre[prel]);
	int k=inl;
	for(int i=inl;i<=inr;i++){
		if(in[i]==now->data){
			k=i;break;
		}
	}
	int numleft=k-inl;
	now->left=create(prel+1,prel+numleft,inl,k-1);
	if(inr!=n-1||now->left==NULL)now->right=create(prel+numleft+1,prer,k+1,inr);
	return now;
}
void postOrder(Node* root){
	if(root==NULL) return;
	postOrder(root->left);
	postOrder(root->right);
	if(!flag){
		printf("%d\n",root->data);
		flag=true;
	}
}
int main() {
	scanf("%d",&n);
	pre.resize(n+1);
	in.resize(n+1);
	for(int i=0;i<n;i++)
		scanf("%d",&pre[i]);
	for(int i=0;i<n;i++)
		scanf("%d",&in[i]);
	Node *root=create(0,n-1,0,n-1);
	postOrder(root);
	return 0;
}
/*
7
1 2 3 4 5 6 7
2 3 1 5 4 7 6
*/
