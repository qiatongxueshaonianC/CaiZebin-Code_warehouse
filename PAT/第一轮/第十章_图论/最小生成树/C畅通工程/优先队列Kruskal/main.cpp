#include<bits/stdc++.h> 
using namespace std;
const int maxn=110;
struct Node{
	int u,v,dis;
	Node(int a,int b,int c):u(a),v(b),dis(c){}
	bool friend operator < (Node a,Node b){
		return a.dis >b.dis ;
	}
}; 
int n,m,father[maxn];
vector<Node> G[maxn];
int findFather(int a){
	if(father[a]==a)
		return a;
	int temp=findFather(father[a]);
	father[a]=temp;
	return temp;
}
int main() {
	while(scanf("%d%d",&n,&m)){
		priority_queue<Node> q;
		if(n==0) break;
		iota(father,father+m,0);
		int u,v,dis;
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&u,&v,&dis);
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
				ans+=now.dis ;
				num_edge++;
			}
		}
		if(num_edge!=m-1) puts("?");
		else printf("%d\n",ans);
	}
	return 0;
}
/*
3 4
1 2 1
2 3 2
3 4 3
2 4
1 2 1
3 4 2
0 5
*/
