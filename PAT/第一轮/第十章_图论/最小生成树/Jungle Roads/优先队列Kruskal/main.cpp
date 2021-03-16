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
int n,father[maxn],harsh[256];
int findFather(int a){
	if(father[a]==a)
		return a;
	int temp=findFather(father[a]);
	father[a]=temp;
	return temp;
}
void init(){
	for(int i=0;i<27;i++){
		harsh['A'+i]=i;
	}
}
int main() {
	init();
	while(scanf("%d",&n)){
		if(n==0) break;
		iota(father,father+n,0);
		priority_queue<Node> q;
		for(int i=1;i<n;i++){
			char c0,c1;
			int u,loop,v,dis;
			cin>>c0>>loop;
			u=harsh[c0];
			for(int j=0;j<loop;j++){
				cin>>c1>>dis;
				v=harsh[c1];
				Node node(u,v,dis);
				q.push(node);
			}
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
		printf("%d\n",ans);
	}
	return 0;
}
/*
3
A 1 B 42
B 1 C 87
6
A 2 B 13 E 55
B 1 C 1
C 1 D 20
D 1 E 4
E 1 F 76
0
*/
