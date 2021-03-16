#include<bits/stdc++.h>
using namespace std;
const int maxn=16;
struct Node{
	int x,y;
	Node(int a,int b):x(a),y(b){}
	Node(){}
}st,ed;
int G[maxn][maxn],n,m;
int X[]={0,-1,0,1};
int Y[]={-1,0,1,0};
vector<Node> ans;
bool vis[maxn][maxn];
bool judge(int x,int y){
	if(x>n||x<=0||y>m||y<=0) return false;
	if(vis[x][y]==true||G[x][y]==0) return false;
	return true;
}
void DFS(Node now){
	if(now.x==ed.x&&now.y==ed.y){
		ans.push_back(now);
		int tp=0;
		for(auto i:ans){
			printf("(%d,%d)",i.x,i.y);
			if(tp<ans.size()-1) printf("->");
			tp++;
		}
		puts("");
		ans.pop_back();
		return;
	}
	ans.push_back(now);
	vis[now.x][now.y]=true;
	for(int i=0;i<4;i++){
		int newx=now.x+X[i];
		int newy=now.y+Y[i];
		if(judge(newx,newy)){
			Node node(newx,newy);
			DFS(node);
		}
	}
	ans.pop_back();
	vis[now.x][now.y]=false;
}
int main() {
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			scanf("%d",&G[i][j]);
	}
	scanf("%d%d",&st.x,&st.y);
	scanf("%d%d",&ed.x,&ed.y);
	DFS(st);
	return 0;
}
/*
5 6
1 0 0 1 0 1
1 1 1 1 1 1
0 0 1 1 1 0
1 1 1 1 1 0
1 1 1 0 1 1
1 1
5 6
*/
