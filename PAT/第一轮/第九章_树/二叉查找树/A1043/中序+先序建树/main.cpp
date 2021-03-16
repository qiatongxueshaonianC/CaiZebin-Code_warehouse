/*这道题有点坑，在二叉查找树中竟然允许相同节点的存在，这对利用“中序+先序”建树的方法来说
很不友好，因为当遇到相同的节点时要判断该相同节点按照题目的要求是在右子树还是在左子树，然
而题目中又有镜像树的存在，这时相同节点出现的子树需要“调换”，通过一个flag来实现不同方向
的遍历搜索即可*/ 
#include<bits/stdc++.h>
using namespace std; 
const int maxn=1010;
struct Node{
	int data;
	Node *left,*right;
	Node(){
		left=right=NULL;
	}
};
int n,num_node;
vector<int> pre,in,temp;
Node* createPre(int prel,int prer,int inl,int inr,int flag){
	if(prel>prer) return NULL;
	Node* now=new Node;
	now->data=pre[prel];
	int k=inl;  //不加的话默认k=0,最后k-inl会变成负数，出现段错误 
	if(flag==0){
		for(int i=inl;i<=inr;i++){
			if(in[i]==now->data){
				k=i;
				break;
			} 
		}
	}else{
		for(int i=inr;i>=inl;i--){
			if(in[i]==now->data){
				k=i;
				break;
			} 
		}
	}
	int numleft=k-inl;
	now->left=createPre(prel+1,prel+numleft,inl,k-1,flag);
	now->right=createPre(prel+numleft+1,prer,k+1,inr,flag);
	return now;
}
void inOrder(Node* root){
	if(root==NULL) return;
	inOrder(root->left);
	temp.push_back(root->data);
	inOrder(root->right);
}
void postOrder(Node* root){
	if(root==NULL) return;
	postOrder(root->left);
	postOrder(root->right);
	printf("%d%s",root->data,++num_node<n?" ":"");
}
int main() {
	scanf("%d",&n);
	int v;
	for(int i=0;i<n;i++){
		scanf("%d",&v);
		pre.push_back(v);
	}
	in=pre;
	sort(in.begin(),in.end());
	Node* root=createPre(0,n-1,0,n-1,0);
	inOrder(root);
//	if(equal(temp.begin(),temp.end(),in.begin()))
	if(temp==in){
		puts("YES");
		postOrder(root);
	}else{
		root=NULL;
		temp.clear();
		reverse(in.begin(),in.end());
		root=createPre(0,n-1,0,n-1,1);
		inOrder(root);
		if(temp==in){
			puts("YES");
			num_node=0;
			postOrder(root);
		}
		else puts("NO");
	}
	return 0;
}
/*
7
8 6 5 7 10 8 11

7
8 10 11 8 6 7 5

7
8 6 8 5 10 9 11
*/

