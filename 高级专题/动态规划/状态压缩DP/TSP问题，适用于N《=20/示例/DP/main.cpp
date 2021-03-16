#include<bits/stdc++.h>
using namespace std;
const int maxn=17; 
struct Point{
	double x,y;
	int id;
	string name;
};
vector<Point> p;
int N,pre[maxn];
double dp[1<<maxn][maxn],dis[maxn][maxn];
double getdis(Point a,Point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
void init(){
	cin>>N;
	p.resize(N);
	for(int i=0;i<N;i++)
		cin>>p[i].name>>p[i].x>>p[i].y,p[i].id=i;
	for(int i=0;i<N;i++){
		for(int j=i+1;j<N;j++){
			dis[i][j]=dis[j][i]=getdis(p[i],p[j]);
		}
	}
}
double DP(int S,int v){
	if(dp[S][v]>=0)
		return dp[S][v];
	if(S==(1<<N)-1&&v==0)
		return dp[S][v]=0;
	double res=1e18;
	for(int u=0;u<N;u++){
		if(!(S>>u&1)){
			double tp=DP(S|(1<<u),u)+dis[v][u];
			if(res>tp){
				res=tp;
				pre[u]=v;
			}
		}
	}
	return dp[S][v]=res;
}
void Solve(){
	init();
	memset(dp,-1,sizeof(dp));
	cout<<DP(0,0)<<endl;
}
int main(){
	std::ios::sync_with_stdio(false);
	Solve();
	return 0;
}
/*
16
A 2.5 4.0
B 1.2 -2.4
C 8.7 1.2
D 3.6 12.1
E -5.5 0.94
F -6.6 -12.6
G 0.18 5.219
H 12.5 14.3609
I 22.5 -5.26
J 1.61 4.5
K 2.1 -5.6
L 0 25
M 9.2 -32
N -1 7
O -5 -8
P 21 35
*/ 
