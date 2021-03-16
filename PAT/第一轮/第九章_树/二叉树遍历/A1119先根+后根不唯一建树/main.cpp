#include<bits/stdc++.h>
using namespace std; 
struct Node{
	int data;
	Node *left,*right;
	Node(int a){
		data=a;
		left=right=NULL;
	}
	Node():left(NULL),right(NULL){}
};
vector<int> pre,post;
bool flag=true;
int n,idx=0;
Node* create(int prel,int prer,int postl,int postr){
	if(prel==prer){
		Node* now;
		return now=new Node(pre[prel]);
	}
	Node* now=new Node(pre[prel]);
	int k=prel+1;
	while(pre[k]!=post[postr-1]) k++; //k����λ�����������ĸ� 
	if(k-prel>1){
		now->left=create(prel+1,k-1,postl,postl+(k-prel-2)); //�ұ߽���Ը���prel+1,k-1�Ƴ� 
		now->right=create(k,prer,postl+(k-prel-1),postr-1);
	}else{ 
		flag=false;
		now->right=create(k,prer,postl+k-prel-1,postr-1);
	} 
	return now;
}
void inorder(Node *root){
	if(root==NULL) return;
	inorder(root->left);
	printf("%d%s",root->data,++idx==n?"\n":" ");
	inorder(root->right);
}
int main() {
	scanf("%d",&n);
	pre.resize(n);post.resize(n);
	for(int i=0;i<n;i++)
		scanf("%d",&pre[i]);
	for(int i=0;i<n;i++)
		scanf("%d",&post[i]);
	Node* root=create(0,n-1,0,n-1);
	printf("%s\n",flag?"Yes":"No");
	inorder(root);
	return 0;
}
/*
7
1 2 3 4 6 7 5
2 6 7 4 5 3 1
*/
