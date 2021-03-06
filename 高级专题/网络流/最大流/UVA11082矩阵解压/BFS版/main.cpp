#include<bits/stdc++.h>
using namespace std;
const int maxn=55;
struct Edge{
	int from,to,cap,flow;
	Edge(int a,int b,int c,int d):from(a),to(b),cap(c),flow(d){}
};
vector<vector<int>> G(maxn);
vector<Edge> edges;
void InsertEdge(int a,int b,int cap){
	G[a].push_back(edges.size());
	edges.push_back(Edge(a,b,cap,0));
	G[b].push_back(edges.size());
	edges.push_back(Edge(b,a,0,0));
}
int Max_Flow(int st,int ed){
	int flow=0;
	while(true){
		int a[maxn]={0},p[maxn]={0};
		a[st]=INT_MAX; 
		queue<int> q;
		q.push(st);
		while(!q.empty()){
			int u=q.front();q.pop();
			for(auto i:G[u]){
				Edge e=edges[i];
				if(!a[e.to]&&e.cap>e.flow){
					a[e.to]=min(a[u],e.cap-e.flow);
					p[e.to]=i;
					q.push(e.to);
				}
			}
			if(a[ed])
				break;
		}
		if(!a[ed])
			break;
		for(int i=ed;i!=st;i=edges[p[i]].from){
			edges[p[i]].flow+=a[ed];
			edges[p[i]^1].flow-=a[ed];
		}
		flow+=a[ed];
	}
	return flow;
}
int main(){
    int T,R,C;
	scanf("%d",&T);
	for(int ii=1;ii<=T;ii++){
		printf("Matrix %d\n",ii);
		scanf("%d%d",&R,&C);
		int matrix[R+1][C+1]={0},A,B=0;
		for(int i=1;i<=R;i++){
			scanf("%d",&A);
			InsertEdge(0,i,A-B-C);
			for(int j=1;j<=C;j++){
				matrix[i][j]=edges.size();  //2020/2/5/15:03发现，这里的顺序不能反 
				InsertEdge(i,j+R,19);   //2020/2/2/15:12发现，这里是j+R,写成了i+R	
			//	matrix[i][j]=edges.size()-1;  //这样也行 
			}
			B=A;
		}
		B=0;
		for(int i=1;i<=C;i++){
			scanf("%d",&A);
			InsertEdge(i+R,R+C+1,A-B-R);
			B=A;
		}
		Max_Flow(0,R+C+1);
		for(int i=1;i<=R;i++){
			for(int j=1;j<=C;j++)
				printf("%d%s",edges[matrix[i][j]].flow+1,j==C?"\n":" ");
		}
		puts("");
		fill(G.begin(),G.end(),vector<int>());
		edges.clear();
	} 
    return 0;
}
/*
2
3 4
10 31 58
10 20 37 58
3 4
10 31 58
10 20 37 58
*/
