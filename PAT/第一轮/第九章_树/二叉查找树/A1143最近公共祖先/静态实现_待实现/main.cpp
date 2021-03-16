#include<bits/stdc++.h>
using namespace std;
using LL=long long;
struct Node{
	int data,level;
	LL idx;
	Node(int a,LL b,int c):data(a),idx(b),level(c){}
	Node():idx(0),level(1){}
};
int M,n;
vector<int> pre,in;
unordered_map<LL,Node> mp; 
unordered_map<int,LL> data2idx;
void create(int prel,int prer,int inl,int inr,int lev,LL root_idx){
	if(prel>prer) return;
	Node now=Node(pre[prel],root_idx,lev);
	int k=inl;
	for(int i=inl;i<=inr;i++){
		if(in[i]==now.data){
			k=i;break;
		}
	}
	int numleft=k-inl;
	create(prel+1,prel+numleft,inl,k-1,lev+1,root_idx<<1);
	create(prel+numleft+1,prer,k+1,inr,lev+1,(root_idx<<1)+1);
	data2idx[now.data]=root_idx;
	mp[root_idx]=now;
}
int main() {
	scanf("%d%d",&M,&n);
	int u,v;
	for(int i=0;i<n;i++){
		scanf("%d",&v);
		pre.push_back(v);
	}
	in=pre;
	sort(in.begin(),in.end());//ÖÐÐòÐòÁÐ
	create(0,n-1,0,n-1,-1,1); 
	while(M--){
		scanf("%d%d",&u,&v);
		if(data2idx.find(u)==data2idx.end()||data2idx.find(v)==data2idx.end()){
			if(data2idx.find(u)==data2idx.end()&&data2idx.find(v)==data2idx.end())
				printf("ERROR: %d and %d are not found.\n",u,v);
			else if(data2idx.find(u)==data2idx.end()) printf("ERROR: %d is not found.\n",u);
			else if(data2idx.find(v)==data2idx.end()) printf("ERROR: %d is not found.\n",v);
		}else{
			Node leu=mp[data2idx[u]],lev=mp[data2idx[v]];
			bool flag=false;
			if(leu.level<lev.level){
				swap(lev,leu);
				flag=true;
			} 
			Node temp=leu;
			while(temp.level!=lev.level) temp=mp[temp.idx/2];
			if(lev.data==temp.data) printf("%d is an ancestor of %d.\n",lev.data,leu.data);
			else{
				Node tempv=lev;
				while(temp.data!=tempv.data){
					temp=mp[temp.idx/2];
					tempv=mp[tempv.idx/2];
				}
				printf("LCA of %d and %d is %d.\n",flag?lev.data:leu.data,flag?leu.data:lev.data,temp.data);
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
