#include<bits/stdc++.h>
using namespace std;
struct Node{
	int x,y,z;
	Node(int a,int b,int c):x(a),y(b),z(c){}
	Node(){}
};
vector<vector<int>> trans={{0,0,1},{0,0,-1},{0,1,0},{0,-1,0},{1,0,0},{-1,0,0}};
int n,m,L,T;//G[1300][130][65];
vector<vector<vector<int>>> G(1300);
bool inq[1300][130][65];
int BFS(Node s){
	int num=0;
	queue<Node> q;
	q.push(s);
	inq[s.x][s.y][s.z]=true;
	while(q.size()){
		num++;
		Node now=q.front();q.pop();
		for(int i=0;i<6;i++){
			int xx=now.x+trans[i][0];
			int yy=now.y+trans[i][1];
			int zz=now.z+trans[i][2];
			if(xx>=0&&xx<n&&yy>=0&&yy<m&&zz>=0&&zz<L&&G[xx][yy][zz]==1&&inq[xx][yy][zz]==false){
				q.push(Node(xx,yy,zz));
				inq[xx][yy][zz]=true;
			}
		}
	}
	return num>=T?num:0;
}
int main() {
	vector<vector<int>> temp(130);
	fill(temp.begin(),temp.end(),vector<int>(65));
	fill(G.begin(),G.end(),temp);
	int ans=0;
	scanf("%d%d%d%d%*c",&n,&m,&L,&T);
	for(int z=0;z<L;z++){
		for(int x=0;x<n;x++){
			string s;
			getline(cin,s);
			stringstream str(s);
			int y=0; 
			while(str>>G[x][y++][z]){}
//			for(int y=0;y<m;y++)
//				scanf("%d",&G[x][y][z]);
		}
	}
	for(int z=0;z<L;z++){
		for(int x=0;x<n;x++){
			for(int y=0;y<m;y++){
				if(inq[x][y][z]==false&&G[x][y][z]==1){
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
