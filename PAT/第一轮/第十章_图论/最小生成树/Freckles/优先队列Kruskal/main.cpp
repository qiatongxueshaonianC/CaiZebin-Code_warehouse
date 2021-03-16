#include<bits/stdc++.h> 
using namespace std;
const int maxn=110;
struct Node{
	int u,v;
	double dis;
	Node(int a,int b,double c):u(a),v(b),dis(c){}
	bool friend operator < (Node a,Node b){
		return a.dis>b.dis ;
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
	while(scanf("%d",&n)){
		vector<pair<double,double> >G;
		if(n==0) break;
		iota(father,father+n,0);
		double u,v,dis;
		for(int i=0;i<n;i++){
			scanf("%lf%lf",&u,&v);
		//	cin>>u>>v;
			G.push_back(make_pair(u,v));
		}
		for(int i=0;i<n;i++){
			double x0=G[i].first,y0=G[i].second;
			for(int j=i+1;j<n;j++){
				double x=G[j].first,y=G[j].second;
				double temp=(x-x0)*(x-x0)+(y-y0)*(y-y0);
				temp=sqrt(temp);
				Node node(i,j,temp);
				q.push(node);
			}
		}
		double ans=0;
		int num_edge=0;
		while(num_edge!=n-1){
			Node now=q.top();q.pop();
			int fa=findFather(now.u);
			int fb=findFather(now.v);
			if(fa!=fb){
				father[fa]=fb;
				ans+=now.dis;
				num_edge++;
			}
		}
		printf("%.2lf\n",ans);
		while(!q.empty()){
			q.pop();
		}
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
