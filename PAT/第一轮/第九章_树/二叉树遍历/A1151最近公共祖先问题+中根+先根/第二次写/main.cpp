#include<bits/stdc++.h>
using namespace std; 
struct Node{
	int data,level;
	Node *father;
	Node(int a):data(a),father(NULL){};
	Node(){}
};
vector<int> in,pre;
set<int> inorder;
map<int,Node*> mp;
Node *create(int prel,int prer,int inl,int inr,int level){
	if(prel>prer) return NULL;
	Node *now=new Node(pre[prel]);
	now->level=level;
	int k=inl;
	for(;k<=inr;k++){
		if(now->data==in[k])
			break;
	}
	int numleft=k-inl;
	Node *left=create(prel+1,prel+numleft,inl,k-1,level+1);
	Node *right=create(prel+numleft+1,prer,k+1,inr,level+1);
	if(left!=NULL) left->father=now;
	if(right!=NULL) right->father=now;
	mp[now->data]=now;
	return now;
}
int main() {
	int m,n,u,v;
	scanf("%d%d",&m,&n);
	pre.resize(n);in.resize(n);
	for(int i=0;i<n;i++){
		scanf("%d",&in[i]);
		inorder.insert(in[i]);
	}
	for(int i=0;i<n;i++)
		scanf("%d",&pre[i]);
	Node *root=create(0,n-1,0,n-1,1);
	for(int i=0;i<m;i++){
		scanf("%d%d",&u,&v);
		auto iu=inorder.find(u);
		auto iv=inorder.find(v);
		if(iu==inorder.end()||iv==inorder.end()){
			if(iu==iv)
				printf("ERROR: %d and %d are not found.\n",u,v);
			else if(iu==inorder.end())
				printf("ERROR: %d is not found.\n",u);
			else
				printf("ERROR: %d is not found.\n",v);
		}else{
			Node *pu=mp[u];
			Node *pv=mp[v];
			bool flag=true;
			if(pu->level<pv->level){
				swap(pu,pv);
				flag=false;
			}
			while(pu->level!=pv->level){
				pu=pu->father;
			}
			if(pv->data==pu->data)
				printf("%d is an ancestor of %d.\n",flag?v:u,flag?u:v);
			else{
				while(pu->data!=pv->data){
					pu=pu->father;
					pv=pv->father;
				}
				printf("LCA of %d and %d is %d.\n",u,v,pu->data);
			}
		}
	}
	return 0;
}
/*
6 8
7 2 3 4 6 5 1 8
5 3 7 2 6 4 8 1
2 6
8 1
7 9
12 -3
0 8
99 99
*/
