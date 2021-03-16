#include<bits/stdc++.h>
using namespace std; 
const int maxn=40;
int In[maxn],Post[maxn],N;
struct Node{
	int data;
	Node *left,*right;
};
void Read(int* a){
	for(int i=0;i<N;i++){
		cin>>a[i];
	}
}
Node* create(int inl,int inr,int posl,int posr){
	if(inl>inr){
		return NULL;
	}
	Node* now=new Node();
	now->data=Post[posr];
	int k=inl;
	for(;k<=inr;k++){
		if(In[k]==now->data){
			break;
		}
	}
	int num_left=k-inl;
	now->left=create(inl,k-1,posl,posl+num_left-1);
	now->right=create(k+1,inr,posl+num_left,posr-1);
	return now;
}
void BFS(Node* root){
	queue<Node*> q;
	q.push(root);
	while(!q.empty()){
		Node* now=q.front();q.pop();
		if(now->left!=NULL)	q.push(now->left);
		if(now->right!=NULL)q.push(now->right);
		cout<<now->data<<(q.empty()?"\n":" ");
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin>>N;
	Read(Post);
	Read(In);
	Node* root=create(0,N-1,0,N-1);
	BFS(root);
	return 0;
}
/*
7
2 3 1 5 7 6 4
1 2 3 4 5 6 7
*/
