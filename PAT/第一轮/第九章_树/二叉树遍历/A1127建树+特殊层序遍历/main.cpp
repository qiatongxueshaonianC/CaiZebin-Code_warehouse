#include<bits/stdc++.h>
using namespace std;
const int maxn=40;
struct Node{
	int data,level;
	Node *left,*right;
	Node(int a){
		data=a;
		level=0;
		left=right=NULL;
	}
};
int n,in[maxn],post[maxn]; 
vector<vector<int> > ans(maxn);
Node* create(int postl,int postr,int inl,int inr){
	if(postl>postr) return NULL;
	Node* now=new Node(post[postr]);
	int k=inl;
	for(int i=inl;i<=inr;i++){
		if(in[i]==now->data){
			k=i;
			break;
		}
	}
	int numleft=k-inl;
	now->left=create(postl,postl+numleft-1,inl,k-1);
	now->right=create(postl+numleft,postr-1,k+1,inr);
	return now;
}
void levelOrder(Node* root){
	queue<Node*> q;
	q.push(root);
	while(q.size()){
		Node* now=q.front();q.pop();
		ans[now->level].push_back(now->data);
		if(now->left!=NULL){
			now->left->level=now->level+1; 
			q.push(now->left);
		}
		if(now->right!=NULL){
			now->right->level=now->level+1;
			q.push(now->right);
		}
	}
}
int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&in[i]);
	for(int i=0;i<n;i++)
		scanf("%d",&post[i]);
	Node* root=create(0,n-1,0,n-1);
	levelOrder(root);
	for(int i=0;!ans[i].empty();i++){
		if(i%2==0){
			for(auto j=--ans[i].end();j>=ans[i].begin();j--)
			//	printf("%d%s",*j,j==ans[i].begin()?"\n":" ");
				printf("%d%s",*j,j==ans[i].begin()&&ans[i+1].empty()?"\n":" ");
		}else{
			for(auto j=ans[i].begin();j<ans[i].end();j++)
			//	printf("%d%s",*j,j==--ans[i].end()?"\n":" ");
				printf("%d%s",*j,j==--ans[i].end()&&ans[i+1].empty()?"\n":" ");
		}
	}
	return 0;
}
/*
8
12 11 20 17 1 15 8 5
12 20 17 11 15 8 5 1
*/
