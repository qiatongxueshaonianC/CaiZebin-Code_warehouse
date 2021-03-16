#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data,level;
	Node *left,*right,*father;
	Node(int a):data(a),level(1),left(NULL),right(NULL),father(NULL){}
	Node():left(NULL),level(1),right(NULL),father(NULL){}
};
int n,m;
unordered_map<int,Node*> mp;
vector<int> in,pre; 
Node* create(int prel,int prer,int inl,int inr,int level){
	if(prel>prer) return NULL;
	Node *now=new Node(pre[prel]);
	now->level=level;
	int k=inl;
	for(int i=inl;i<=inr;i++){
		if(in[i]==now->data){
			k=i;break;
		}
	}
	int numleft=k-inl;
	now->left=create(prel+1,prel+numleft,inl,k-1,level+1);
	now->right=create(prel+numleft+1,prer,k+1,inr,level+1);
	if(now->left!=NULL) now->left->father=now;
	if(now->right!=NULL) now->right->father=now;
	mp[now->data]=now;
	return now;
}
int main() {
	scanf("%d%d",&m,&n);
	in.resize(n+1),pre.resize(n+1);
	for(int i=0;i<n;i++)
		scanf("%d",&in[i]);
	for(int i=0;i<n;i++)
		scanf("%d",&pre[i]);
	Node* root=create(0,n-1,0,n-1,0);
	int u,v;
//	bool flag;
	while(m--){
		scanf("%d%d",&u,&v);
		if(mp.find(u)==mp.end()||mp.find(v)==mp.end()){
			if(mp.find(u)==mp.end()&&mp.find(v)==mp.end())printf("ERROR: %d and %d are not found.\n",u,v);
			else if(mp.find(u)==mp.end()) printf("ERROR: %d is not found.\n",u);
			else printf("ERROR: %d is not found.\n",v);
		}else{
		//	flag=false;
			Node *leu,*lev,*temp1,*temp2;
			leu=mp[u];
			lev=mp[v];
			if(leu->level<lev->level) {
				swap(leu,lev);//flag=true;
			}
			temp1=leu;temp2=lev;
			while(temp1->level!=lev->level) temp1=temp1->father;
			if(temp1->data==lev->data) printf("%d is an ancestor of %d.\n",lev->data,leu->data);
			else{
				while(temp1->data!=temp2->data){
					temp1=temp1->father;
					temp2=temp2->father;
				}
			//	printf("LCA of %d and %d is %d.\n",flag?v:u,flag?u:v,temp1->data);
				printf("LCA of %d and %d is %d.\n",u,v,temp1->data);//2019/11/4/15£º40¸ÄÕý 
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
