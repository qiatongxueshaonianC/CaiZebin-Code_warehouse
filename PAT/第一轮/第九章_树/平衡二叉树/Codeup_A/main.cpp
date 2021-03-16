#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data,height;
	Node *left,*right;
	Node(int a):data(a),height(1),left(NULL),right(NULL){}
};
int getHeight(Node* root){
	if(root==NULL) return 0;
	return root->height;
}
void updateHeight(Node* &root){
	root->height=max(getHeight(root->left),getHeight(root->right))+1;
}
int getBalancefact(Node* root){
	return getHeight(root->left)-getHeight(root->right);
}
void L(Node* &root){
	Node* temp=root->right;
	root->right=temp->left;
	temp->left=root;
	updateHeight(root);
	updateHeight(temp);
	root=temp;
}
void R(Node* &root){
	Node* temp=root->left;
	root->left=temp->right;
	temp->right=root;
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
			if(getBalancefact(root->left)==1){  //LLÐÍ 
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
			if(getBalancefact(root->right)==-1){  //RRÐÍ 
				L(root); 
			}else{   //RLÐÍ 
				R(root->right);
				L(root);
			}
		} 
	}
}
bool search(Node* root,int v){
	if(root==NULL) return false;
	if(root->data==v){
		printf("1");
		return true;
	}
	if(v<root->data){
		search(root->left,v);
	}else search(root->right,v);
}
int n,k; 
int main() {
	scanf("%d%d",&n,&k);
	int v;
	Node *root=NULL;
	for(int i=0;i<n;i++){
		scanf("%d",&v);
		insert(root,v);
	}
	for(int i=0;i<k;i++){
		scanf("%d",&v);
		if(!search(root,v))
			printf("0");
		printf("%s",i<k-1?" ":"\n");
	}
	return 0;
}
/*
8 3
1 3 5 7 8 9 10 15
9 2 5
*/
