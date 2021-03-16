#include<bits/stdc++.h> 
using namespace std;
const int maxn=1100;
const int inf=0x3fffffff;
int d[maxn],G[maxn][maxn];
bool vis[maxn]={false};
int n,m,k,ds; 
void Dijkstra(int s){
	fill(d,d+maxn,inf);
	memset(vis,false,sizeof(vis));
	d[s]=0;
	for(int i=1;i<=n+m;i++){
		int u=-1,Min=inf;
		for(int j=1;j<=n+m;j++)
			if(vis[j]==false&&d[j]<Min){
				u=j;
				Min=d[j];
			}
		if(u==-1) return;
		vis[u]=true;
		for(int v=1;v<=n+m;v++){
			if(vis[v]==false&&G[u][v]!=inf){
				if(d[u]+G[u][v]<d[v]){
					d[v]=d[u]+G[u][v];
				}
			}
			
		}
	}
}
int main() {
	fill(G[0],G[0]+maxn*maxn,inf);
	string c1,c2;
	int u,v,dis;
	scanf("%d%d%d%d",&n,&m,&k,&ds);
	for(int i=0;i<k;i++){
		cin>>c1>>c2>>dis;
		if(c1[0]=='G'){
			c1.erase(c1.begin());
			u=stoi(c1)+n;
		}else u=stoi(c1);
		if(c2[0]=='G'){
			c2.erase(c2.begin());
			v=stoi(c2)+n;
		}else v=stoi(c2);
		G[u][v]=G[v][u]=dis;	
	}
	double ansDis=-1,ansAvg=inf;
	int ansID=-1;
	for(int i=n+1;i<=n+m;i++){
		double minDis=inf,avg=0;
		Dijkstra(i);
		for(int j=1;j<=n;j++){
			if(d[j]>ds){
				minDis=-1;
				break;
			}
			if(d[j]<minDis) minDis=d[j];
			avg+=1.0*d[j]/n;
		}
		if(minDis==-1) continue;
		if(minDis>ansDis){
			ansDis=minDis;
			ansID=i;
			ansAvg=avg;
		}else if(minDis==ansDis&&avg<ansAvg){
			ansID=i;
			ansAvg=avg;
		}
	}
	if(ansID==-1) puts("No Solution");
	else{
		printf("G%d\n",ansID-n);
		printf("%.1f %.1f\n",ansDis,ansAvg);
	}
	return 0;
}
/*
4 3 11 5
1 2 2
1 4 2
1 G1 4
1 G2 3
2 3 2
2 G2 1
3 4 2
3 G3 2
4 G1 3
G2 G1 1
G3 G2 2
*/

/*
2 1 2 10
1 G1 9
2 G1 20
*/
