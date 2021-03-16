#include<bits/stdc++.h> 
using namespace std;
const int maxn=110;
struct Node{
	int u,v,dis;
	Node(int a,int b,int c):u(a),v(b),dis(c){}
	bool friend operator < (Node a,Node b){
		return a.dis>b.dis;
	}
}; 
int n,father[maxn];
vector<Node>G[maxn];
int findFather(int a){
	if(father[a]==a)
		return a;
	int temp=findFather(father[a]);
	father[a]=temp;
	return temp;
} 
int main() {
	priority_queue<Node> q;
	while(scanf("%d",&n)){
		if(n==0) break;
		iota(father,father+n,0);
		int loop=n*(n-1)/2;
		int u,v,dis,flag;
		for(int i=0;i<loop;i++){
			scanf("%d%d%d%d",&u,&v,&dis,&flag);
			if(flag==1) dis=0;
			Node node(u,v,dis);
			q.push(node);
		}
		int ans=0,num_edge=0;
		while(!q.empty()){
			Node now=q.top();q.pop();
			int fa=findFather(now.u);
			int fb=findFather(now.v);
			if(fa!=fb){
				father[fa]=fb;
				ans+=now.dis;
				num_edge++;
			}
		}
		if(num_edge!=n-1) puts("-1");
		else
			printf("%d\n",ans); 
	}
	return 0;
}
/*
4
1 2 1 1
1 3 6 0
1 4 2 1
2 3 3 0
2 4 5 0
3 4 4 0
3
1 2 1 1
2 3 2 1
1 3 1 0
0
*/
