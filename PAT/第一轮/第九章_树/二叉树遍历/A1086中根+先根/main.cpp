#include<bits/stdc++.h>
using namespace std; 
struct Node{
	int data;
	Node *left,*right;
	Node(int a):data(a),left(NULL),right(NULL){}
	Node(){}
};
vector<int> pre,in; 
stack<int> st;
int n,num;
Node* create(int prel,int prer,int inl,int inr){
	if(prel>prer) return NULL;
	Node* now=new Node;
	now->data=pre[prel];
	int k=inl;
	for(;k<=inr;k++){
		if(in[k]==now->data)
			break;
	}
	int numleft=k-inl;
	now->left=create(prel+1,prel+numleft,inl,k-1);
	now->right=create(prel+numleft+1,prer,k+1,inr);
	return now;
}
void PostOrder(Node* root){
	if(root==NULL) return;
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d",root->data);
	if(++num<n) printf(" ");
	else puts("");
}
int main() {
	scanf("%d",&n);
	string s;
	for(int i=0;i<2*n;i++){
		cin>>s;
		transform(s.begin(),s.end(),s.begin(),::tolower);
		if(s=="push"){
			int v;
			cin>>v;
			pre.push_back(v);
			st.push(v);
		}else{
			in.push_back(st.top());
			st.pop();
		}
	}
	Node* root=create(0,n-1,0,n-1);
	PostOrder(root);
	return 0;
}
/*
6
Push 1
Push 2
Push 3
Pop
Pop
Push 4
Pop
Pop
Push 5
Push 6
Pop
Pop
*/
