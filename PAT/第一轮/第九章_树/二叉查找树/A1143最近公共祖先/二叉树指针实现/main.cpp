#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data,level;
	Node *father,*left,*right;
	Node(int a){
		data=a;
		level=1;
		father=left=right=NULL;
	}
	Node(){
		father=left=right=NULL;
		level=1;
	}
};
int M,n;
vector<int> pre,in;
unordered_set<int> st;
unordered_map<int,Node*> mp; 
Node* create(int prel,int prer,int inl,int inr,int lev){
	if(prel>prer) return NULL;
	Node* now=new Node(pre[prel]);
	now->level=lev;
	int k=inl;
	for(int i=inl;i<=inr;i++){
		if(in[i]==now->data){
			k=i;break;
		}
	}
	int numleft=k-inl;
	now->left=create(prel+1,prel+numleft,inl,k-1,lev+1);
	if(now->left!=NULL)
		now->left->father=now;
	now->right=create(prel+numleft+1,prer,k+1,inr,lev+1);
	if(now->right!=NULL)
		now->right->father=now;
	mp[now->data]=now;
	return now;
}
//Node* find(Node* root,int v){
//	if(root->data==v) return root;
//	if(v<root->data) return find(root->left,v);
//	else return find(root->right,v);
//}
int main() {
	scanf("%d%d",&M,&n);
	int u,v;
	for(int i=0;i<n;i++){
		scanf("%d",&v);
		pre.push_back(v);
		st.insert(v);
	}
	in=pre;
	sort(in.begin(),in.end());//��������
	Node* root=create(0,n-1,0,n-1,-1); 
	while(M--){
		scanf("%d%d",&u,&v);
		if(st.find(u)==st.end()||st.find(v)==st.end()){
			if(st.find(u)==st.end()&&st.find(v)==st.end())
				printf("ERROR: %d and %d are not found.\n",u,v);
			else if(st.find(u)==st.end()) printf("ERROR: %d is not found.\n",u);
			else if(st.find(v)==st.end()) printf("ERROR: %d is not found.\n",v);
		}else{
//			Node* leu=find(root,u);
//			Node* lev=find(root,v);
			Node *leu=mp[u],*lev=mp[v];
			bool flag=false;
			if(leu->level<lev->level){
				swap(lev,leu);
				flag=true;
			} 
			Node* temp=leu;
			while(temp->level!=lev->level) temp=temp->father;
			if(lev->data==temp->data) printf("%d is an ancestor of %d.\n",lev->data,leu->data);
			else{
				Node* tempv=lev;
				while(temp->data!=tempv->data){
					temp=temp->father;
					tempv=tempv->father;
				}
				printf("LCA of %d and %d is %d.\n",flag?lev->data:leu->data,flag?leu->data:lev->data,temp->data);
			}
		}
	}
}
/*
6 8
6 3 1 2 5 4 8 7
2 5
8 7
1 9
12 -3
0 8
99 99
*/
