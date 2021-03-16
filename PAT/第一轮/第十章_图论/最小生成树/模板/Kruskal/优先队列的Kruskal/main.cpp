#include<bits/stdc++.h> 
using namespace std;
const int maxn=50010;
struct Node{
	int u,v,dis;
	Node(int a,int b,int c){
		u=a;v=b;dis=c;
	}
	bool friend operator <(Node a,Node b){
		return a.dis>b.dis;
	}
};
int n,m,root,father[maxn];
int findFather(int a){
	if(father[a]==a)
		return a;
	int temp=findFather(father[a]);
	father[a]=temp;
	return temp;
}
int main() {
	priority_queue<Node> q;
	int c1,c2,dis,ans,edge_num=0;
	scanf("%d%d%d",&n,&m,&root);
	while(m--){
		scanf("%d%d%d",&c1,&c2,&dis);
		Node node(c1,c2,dis);
		q.push(node);
	}
	iota(father,father+maxn,0);
	while(edge_num!=n-1){
		Node now=q.top();q.pop();
		int fa=findFather(now.u);
		int fb=findFather(now.v);
		if(fa!=fb){
			father[fa]=fb;
			ans=now.dis ;
			edge_num++;
		}
	}
	puts(to_string(ans).c_str());
	return 0;
}
/*
4
5
1
1 2 3
1 3 4
1 4 5
2 3 8
3 4 2
*/
