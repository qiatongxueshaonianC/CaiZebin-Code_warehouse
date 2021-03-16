#include<bits/stdc++.h> 
using namespace std;
const int inf=0x3fffffff;
const int maxn=110;
typedef pair<double,int> P;
struct Node{
	int to;
	double dis;
	Node(int a,double b):to(a),dis(b){}
};
vector<double> d;
vector<pair<double,double>> point;
vector<Node> G[maxn];
int n;
bool vis[maxn];
bool Prim(int s){
	d.clear();
	for(int i=0;i<n;i++){
		d.push_back(inf);
	}
	fill(vis,vis+maxn,false);
	d[s]=0;
	priority_queue<P,vector<P>,greater<P> >q;
	q.push(P(0,s));
	while(!q.empty()){
		P now=q.top();q.pop();
		int u=now.second;
		if(now.first>d[u]) continue;
		vis[u]=true;
		for(auto i:G[u]){
			int v=i.to;
			double dis=i.dis;
			if(vis[v]==false){
				if(dis<d[v]){
					d[v]=dis;  // d[v].begin()=d[v].back();
					q.push(P(d[v],v));
				}
			}
		}
	}
	if(count(vis,vis+n,false)==0) return true;
	return false;
}
int main() {
	while(scanf("%d",&n)){
		if(n==0) break;
		double x0,y0;
		for(int i=0;i<n;i++){
			cin>>x0>>y0;
			point.push_back(make_pair(x0,y0));
		}
		for(int i=0;i<n;i++){
			x0=point[i].first;
			y0=point[i].second;
			double x,y;
			for(int j=i+1;j<n;j++){
				x=point[j].first;
				y=point[j].second;
				double temp=pow((x-x0),2)+pow((y-y0),2);
				temp=sqrt(temp);
				Node node(j,temp);
				G[i].push_back(node);
				node.to =i;
				G[j].push_back(node);
			}
		}
		if(!Prim(1)) puts("-1");
		else {
			double ans=0;
			for(int i=0;i<n;i++)
				ans+=d[i];
			printf("%.2lf\n",ans);
		}
		for(int i=0;i<n;i++){
			G[i].clear();
		}
		point.clear();
	}
	return 0;
}
/*
3
2723.62 7940.81
8242.67 11395.00
4935.54 6761.32
9
10519.52 11593.66
12102.35 2453.15
7235.61 10010.83
211.13 4283.23
5135.06 1287.85
2337.48 2075.61
6279.72 13928.13
65.79 1677.86
5324.26 125.56
0
*/
