#include<bits/stdc++.h>
using namespace std;
struct Node{
	int x,y,z;
	Node(int a,int b,int c):x(a),y(b),z(c){}
	Node(){}
};
int n,m,L,T,ans; 
bool G[1300][130][65];
bool judge(int x,int y,int z){
	if(x<0||x>=n||y<0||y>=m||z<0||z>=L) return false;  //2019/11/16/0:08发现，此处注意先后顺序，否则会段错误 
	if(G[x][y][z]==0) return false;
	return true;
}
int X[6]={0,0,-1,1,0,0};
int Y[6]={0,0,0,0,1,-1};
int Z[6]={1,-1,0,0,0,0};
int BFS(Node s){
	queue<Node> q;
	q.push(s);
	int num=0;
	G[s.x][s.y][s.z]=0;
	while(q.size()){
		num++;
		Node now=q.front();q.pop();
		for(int i=0;i<6;i++){
			int newx=now.x+X[i];
			int newy=now.y+Y[i];
			int newz=now.z+Z[i];
		//	if(newx>=0&&newx<n&&newy>=0&&newy<m&&newz>=0&&newz<L&&G[newx][newy][newz]){
			if(judge(newx,newy,newz)){
				q.push(Node(newx,newy,newz));
				G[newx][newy][newz]=0;
			}
		}
	}
	if(num>=T) return num;
	return 0;
}
int main() {
	scanf("%d%d%d%d",&n,&m,&L,&T);
	for(int z=0;z<L;z++){
		for(int x=0;x<n;x++){   //注意这里读入的顺序，要x在前，2019//11/16/0：01发现 
			for(int y=0;y<m;y++){
				scanf("%d",&G[x][y][z]);
			}
		}
	}
	for(int z=0;z<L;z++){
		for(int x=0;x<n;x++){
			for(int y=0;y<m;y++){
				if(G[x][y][z]){
					ans+=BFS(Node(x,y,z));
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
/*
3 4 5 2
1 1 1 1
1 1 1 1
1 1 1 1
0 0 1 1
0 0 1 1
0 0 1 1
1 0 1 1
0 1 0 0
0 0 0 0
1 0 1 1
0 0 0 0
0 0 0 0
0 0 0 1
0 0 0 1
1 0 0 0
*/
