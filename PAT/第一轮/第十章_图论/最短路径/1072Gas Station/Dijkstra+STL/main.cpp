#include<bits/stdc++.h> 
using namespace std;
const int maxn=1100;
const int inf=0x3fffffff;
int d[maxn],G[maxn][maxn];
bool vis[maxn]={false};
int n,m,k,ds; 
vector<pair<string,pair<double,double> > >mp;
void Dijkstra(int s){
	fill(d,d+maxn,inf);
	fill(vis,vis+maxn,false);
	d[s]=0;
	for(int i=1;i<=n+m;i++){
		int u=-1,Min=inf;
		for(int j=1;j<=n+m;j++)
			vis[j]==false&&d[j]<Min?Min=d[j],u=j:1;
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
bool cmp(pair<string,pair<double,double> >a,pair<string,pair<double,double> >b){
	if(a.second.first!=b.second.first) return a.second.first>b.second.first;
	else if(a.second.second!=b.second.second) return a.second.second<b.second.second;
	else return a.first<b.first;
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
	int min=0,minDis;
	double avg;             //每次计算最短路时都返回最短路中的最大值以及最小值，在最大值 
	bool flag=false;        //满足条件的前提下去最小值最大的 
	for(int i=n+1;i<=n+m;i++){
		minDis=inf; avg=0;
		Dijkstra(i);
		for(int i=1;i<=n;i++){
			if(d[i]>ds){
				minDis=-1;
				break;
			}
			if(d[i]<minDis) minDis=d[i];
			avg+=1.0*d[i]/n;
		}
		if(minDis==-1) continue;
		if(minDis>=min){
			min=minDis;
			string gas='G'+to_string(i-n);
			mp.push_back(make_pair(gas,make_pair((double)min,avg)));
			flag=true;
		}
	}
	sort(mp.begin(),mp.end(),cmp);
	if(flag){
			auto i=mp.begin();
		puts(i->first.c_str());
		printf("%.1lf %.1lf\n",i->second.first,i->second.second);
	}else puts("No Solution");
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
