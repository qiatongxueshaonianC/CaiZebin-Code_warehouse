#include<bits/stdc++.h>
using namespace std; 
struct Node{
	int data,height;
	Node *left,*right;
	Node(int a){
		height=1;
		data=a;
		left=right=NULL;
	}
}; 
int n;
vector<int> ans;
int getHeight(Node* root){
	if(root==NULL) return 0;
	return root->height;
}
void updateHeight(Node* &root){
	root->height=max(getHeight(root->left),getHeight(root->right))+1;
}
int getBalancefact(Node *root){
	return getHeight(root->left)-getHeight(root->right);
}
void R(Node* &root){
	Node* temp=root->left;
	root->left=temp->right;
	temp->right=root;
	updateHeight(root);  //ÏÈºóË³Ðò 
	updateHeight(temp);
	root=temp;
}
void L(Node* &root){
	Node* temp=root->right;
	root->right=temp->left;
	temp->left=root;
	updateHeight(root);
	updateHeight(temp);
	root=temp;
}
void insert(Node* &root,int v){
	if(root==NULL){
		root=new Node(v);
		return;
	}
	if(v<root->data){
		insert(root->left,v);
		updateHeight(root);
		if(getBalancefact(root)==2){
			if(getBalancefact(root->left)==1){
				R(root);
			}else{
				L(root->left);
				R(root);
			}
		}
	}else{
		insert(root->right,v);
		updateHeight(root);
		if(getBalancefact(root)==-2){
			if(getBalancefact(root->right)==-1){
				L(root);
			}else{
				R(root->right);
				L(root);
			}
		}
	}
}
bool levelOrder(Node* root){
	queue<Node*> q;
	q.push(root);
	while(q.size()){
		Node* now=q.front();q.pop();
	//	ans.push_back(now->data);
		if(now->left!=NULL) q.push(now->left);
		if(now->right!=NULL) q.push(now->right); 
		printf("%d%s",now->data,q.size()?" ":"\n");
	}
	queue<Node*> q1;
	q1.push(root);
	while(q1.size()){
		Node* now=q1.front();q1.pop();
		if(now==NULL){
			while(q1.size()){
				if(q1.front()!=NULL) 
					return false;
				q1.pop();
			}
			return true;
		}
		q1.push(now->left);
		q1.push(now->right);
	}
}
int main() {
	scanf("%d",&n);
	Node *root=NULL;
	int v;
	for(int i=0;i<n;i++){
		scanf("%d",&v);
		insert(root,v);
	}
	bool flag=levelOrder(root);
	printf("%s\n",flag?"YES":"NO");
	return 0;
}
/*
5
88 70 61 63 65

8
88 70 61 96 120 90 65 68
*/
