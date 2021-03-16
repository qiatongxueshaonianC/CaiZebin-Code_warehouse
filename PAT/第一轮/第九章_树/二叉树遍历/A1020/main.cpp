#include<bits/stdc++.h>
using namespace std; 
vector<int> post,in;
int n,num;
struct Node{
	int data;
	Node *left,*right;
	Node(int a){
		data=a;
		left=right=NULL;
	}
	Node(){}
};
Node* create(int postl,int postr,int inl,int inr){
	if(postl>postr) return NULL;
	Node* now=new Node;
	now->data=post[postr];
	int k=inl;
	for(;k<=inr;k++){
		if(in[k]==now->data){
			break;
		}
	}
	int numleft=k-inl;
	now->left=create(postl,postl+numleft-1,inl,k-1);
	now->right=create(postl+numleft,postr-1,k+1,inr);
	return now;
}
void Layerorder(Node* root){
	queue<Node*> q;
	q.push(root);
	while(!q.empty()){
		Node* now=q.front();q.pop();
		printf("%d",now->data);
		if(++num<n) printf(" ");
		if(now->left!=NULL) q.push(now->left);
		if(now->right!=NULL) q.push(now->right);
	}
}
int main() {
	int value;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&value);
		post.push_back(value);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&value);
		in.push_back(value);
	}
	Node* root=create(0,n-1,0,n-1);
	Layerorder(root);
	puts("");
	return 0;
}
/*
7
2 3 1 5 7 6 4
1 2 3 4 5 6 7
*/
