#include<bits/stdc++.h> 
using namespace std;
const int maxn=110;
struct Node{
	int u,v,dis;
	Node(int a,int b,int c):u(a),v(b),dis(c){};
	bool friend operator < (Node a,Node b){
		return a.dis>b.dis;
	}
};
int n,father[maxn]; 
int findFather(int a){
	if(father[a]==a)
		return a;
	int temp=findFather(father[a]);
	father[a]=temp;
	return temp;
}
int main() {
	priority_queue<Node> q;
	int u,v,dis;
	while(scanf("%d",&n)){
		if(n==0) break;
		iota(father,father+n,0);
		int loop=n*(n-1)/2;
		for(int i=0;i<loop;i++){
			scanf("%d%d%d",&u,&v,&dis);
			Node node(u,v,dis);
			q.push(node);
		}
		int ans=0,num_edge=0;
		while(num_edge!=n-1){
			Node now=q.top();q.pop();
			int fa=findFather(now.u );
			int fb=findFather(now.v);
			if(fa!=fb){
				ans+=now.dis ;
				father[fa]=fb;
				num_edge++;
			}
		}
		while(!q.empty()){
			q.pop(); //Çå¿Õ¶ÓÁÐ£» 
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
8
1 2 42
1 3 68
1 4 35
1 5 1
1 6 70
1 7 25
1 8 79
2 3 59
2 4 63
2 5 65
2 6 6
2 7 46
2 8 82
3 4 28
3 5 62
3 6 92
3 7 96
3 8 43
4 5 28
4 6 37
4 7 92
4 8 5
5 6 3
5 7 54
5 8 93
6 7 83
6 8 22
7 8 17
0
*/
