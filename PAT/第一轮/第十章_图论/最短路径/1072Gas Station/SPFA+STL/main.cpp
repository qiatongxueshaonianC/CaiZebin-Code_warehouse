#include<bits/stdc++.h> 
using namespace std;
const int maxn=1100;
const int inf=0x3fffffff;
typedef pair<int,int> P;
struct Node{
	int to,dis;
	Node(int a,int b):to(a),dis(b){};
};
int n,m,k,ds,d[maxn],numinq[maxn];
bool inq[maxn]={false};
vector<Node> G[maxn];
vector<pair<string,pair<double,double> > >mp; 
int change(string&s){
	if(s[0]=='G') {	
		s.erase(s.begin());
		return stoi(s)+n;
	}
	else return stoi(s);
}
bool cmp(pair<string,pair<int,int>> a,pair<string,pair<int,int> > b){
	if(a.second.first!=b.second.first) return a.second.first>b.second.first;
	else if(a.second.second!=b.second.second) return a.second.second<b.second.second;
	else return a.first<b.first;
}
bool SPFA(int s){
	fill(d,d+maxn,inf);
	fill(inq,inq+maxn,false);
	d[s]=0;
	queue<int> q;
	q.push(s);
	numinq[s]++;
	inq[s]=true;
	while(!q.empty()){
		int u=q.front();q.pop();
		inq[u]=false;
		for(auto i:G[u]){
			int v=i.to,dis=i.dis;
			if(d[u]+dis<d[v]){
				d[v]=d[u]+dis;
				if(!inq[v]){
					q.push(v);
					inq[v]=true;
					numinq[v]++;
					if(numinq[v]>=n+m) return false;
				}
			}
		}
	}
	return true;
} 
int main() {
	scanf("%d%d%d%d",&n,&m,&k,&ds);
	string c1,c2;
	int u,v,dis;
	for(int i=0;i<k;i++){
		cin>>c1>>c2>>dis;
		u=change(c1);
		v=change(c2);
		Node node(v,dis);
		G[u].push_back(node);
		node.to =u;
		G[v].push_back(node);
	}
	int minDis,min=0;
	double avg;
	bool flag=false;
	for(int i=n+1;i<=n+m;i++){
		avg=0;minDis=inf;
		SPFA(i);
		for(int j=1;j<=n;j++){
			if(d[j]>ds){
				minDis=-1;
				break;
			}
			if(d[j]<minDis) minDis=d[j];
			avg+=1.0*d[j]/n;
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
