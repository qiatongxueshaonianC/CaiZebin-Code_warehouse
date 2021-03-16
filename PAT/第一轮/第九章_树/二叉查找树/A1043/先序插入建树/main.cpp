#include<bits/stdc++.h>
using namespace std; 
const int maxn=1010;
struct Node{
	int data;
	Node *left,*right;
	Node(int a):data(a),left(nullptr),right(nullptr){}
};
int n,num_node;
vector<int> pre,test; 
void create(Node* &root,int s){
	if(root==nullptr){
		root=new Node(s);
		return;
	}
	if(s<root->data){
		create(root->left,s);
	}else{
		create(root->right,s);
	}	
}
void preOrder(Node* root){
	if(root==NULL) return;
	test.push_back(root->data);
	preOrder(root->left);
	preOrder(root->right);
}
void postOrder(Node* root){
	if(root==nullptr) return;
	postOrder(root->left);
	postOrder(root->right);
	printf("%d%s",root->data,++num_node<n?" ":"");
}
void preOrderM(Node* root){
	if(root==NULL) return;
	test.push_back(root->data);
	preOrderM(root->right);   //ÏÈÓÒºó×ó£» 
	preOrderM(root->left);
}
void postOrderM(Node* root){
	if(root==nullptr) return;
	postOrderM(root->right);
	postOrderM(root->left);
	printf("%d%s",root->data,++num_node<n?" ":"");
}
int main() {
	scanf("%d",&n);
	int v;
	Node* root=nullptr;
	for(int i=0;i<n;i++){
		scanf("%d",&v);
		pre.push_back(v);
		create(root,v);
	}
	preOrder(root);
	if(equal(pre.cbegin(),pre.cend(),test.begin())){
		puts("YES");
		postOrder(root);
	}else{
		test.clear();
		preOrderM(root);
		if(pre==test){
			puts("YES");
			postOrderM(root);
		}else puts("NO");
	} 
}
/*
7
8 6 5 7 10 8 11

7
8 10 11 8 6 7 5

7
8 6 8 5 10 9 11
*/

