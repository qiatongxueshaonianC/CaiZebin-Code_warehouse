#include<bits/stdc++.h>
using namespace std; 
struct Node{
	int data,height;
	Node *left,*right;
	Node(int a){
		data=a;
		left=right=NULL;
		height=1;
	} 
	Node(){}
};
int n;
int getHeight(Node* root){
	if(root==NULL) return 0;
	return root->height;
}
void updateHeight(Node* &root){   //�˴�һ��Ҫ������ 
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
void insert(Node* &root,int s){
	if(root==NULL){
		root=new Node(s);
		return;
	}
	if(s<root->data){
		insert(root->left,s);
		updateHeight(root);
		if(getBalancefact(root)==2){
			if(getBalancefact(root->left)==1){   //LL�� 
				R(root); 
			}else{
				L(root->left);    //LR�� 
				R(root);
			}
		}
	}else{
		insert(root->right,s);
		updateHeight(root);
		if(getBalancefact(root)==-2){
			if(getBalancefact(root->right)==-1){  //RR�ͣ� 
				L(root); 
			} else{
				R(root->right);
				L(root);
			}
		}
	}
}
int main() {
	scanf("%d",&n);
	Node* root=NULL;
	int v;
	for(int i=0;i<n;i++){
		scanf("%d",&v);
		insert(root,v);
	}
	printf("%d\n",root->data);
	return 0;
}
/*
5
88 70 61 96 120

7
88 70 61 96 120 90 65
*/
