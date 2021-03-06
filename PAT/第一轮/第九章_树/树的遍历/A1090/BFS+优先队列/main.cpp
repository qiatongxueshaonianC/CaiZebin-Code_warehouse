#include<bits/stdc++.h>
using namespace std; 
const int maxn=100010;
struct Node{
	int layer;
	vector<int> child;
	bool operator <(const Node & u)const{
		return layer<u.layer;	
	} 
/*	bool friend operator <(Node a,Node b){
		return a.layer<b.layer;
	}*/
}Tree[maxn];
int n,ans_num;
double p,r; 
priority_queue<Node> ans;
void BFS(int s){
	queue<int> q;
	q.push(s);
	ans.push(Tree[s]);
	while(!q.empty()){
		int now=q.front();q.pop();
		if(Tree[now].child.size()==0){
			if(Tree[now].layer>ans.top().layer){
				ans_num=1;
				ans.push(Tree[now]);
			}
			else if(Tree[now].layer==ans.top().layer) ans_num++; 
		}
		for(auto i:Tree[now].child){
			Tree[i].layer=Tree[now].layer+1;
			q.push(i);
		}
	}
}
int main() {
	scanf("%d%lf%lf",&n,&p,&r);
	int v,root;
	for(int i=0;i<n;i++){
		scanf("%d",&v);
		if(v==-1) root=i;
		else Tree[v].child.push_back(i);
	}
	BFS(root);
	printf("%.2lf %d",p*pow(1+r/100,ans.top().layer),ans_num);
	return 0;
}
/*
9 1.80 1.00
1 5 4 4 -1 4 5 3 6
*/
