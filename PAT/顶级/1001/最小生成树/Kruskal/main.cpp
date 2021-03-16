#include<bits/stdc++.h>
using namespace std; 
const int maxn=1010;
struct Edge{
	int cost,u,v;
	Edge(int a,int b,int c):u(a),v(b),cost(c){} 
}; 
int N,M,father[maxn];
vector<Edge> edges;
int findFather(int a){
	if(father[a]==a)
		return a;
	int temp=findFather(father[a]);
	father[a]=temp;
	return temp;
}
int Kruskal(int i){
	int edge_num=0,cost=0;
	iota(father,father+N+1,0);
	for(auto e:edges){
		if(e.u==i||e.v==i) continue;
		int fa=findFather(e.u),fb=findFather(e.v);
		if(fa!=fb){
			++edge_num; 
			cost+=e.cost;
			father[fa]=fb;
		}
        if(edge_num==N-2) break;
	}
	return cost=edge_num==N-2?cost:INT_MAX;
}
void solve(){
	vector<pair<int,int>> ans;
	for(int i=1;i<=N;i++){
		iota(father,father+N+1,0);
		ans.push_back(make_pair(Kruskal(i),i));	
	}
	sort(ans.begin(),ans.end(),[](const pair<int,int>& a,const pair<int,int>& b){
		return a.first!=b.first?a.first>b.first:a.second<b.second;
	});
	if(ans[0].first==0) printf("0");
	else{
		printf("%d",ans[0].second);
		for(int k=1;k<=N;k++){
			if(ans[k].first==ans[0].first)
				printf(" %d",ans[k].second);
			else break;
		}
	}
}
int main() {
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++){
		int a,b,cost,d;
		scanf("%d%d%d%d",&a,&b,&cost,&d);
		edges.push_back(Edge(a,b,d==0?cost:0));
	}
	sort(edges.begin(),edges.end(),[](const Edge& u,const Edge& v){
		return u.cost<v.cost;  //2020/2/8/21:25���֣�����Ҫ�������򣬱�֤����С����ǰ�� 
	});
	solve();
	return 0;
}
/*
4 5
1 2 1 1
1 3 1 1
2 3 1 0
2 4 1 1
3 4 1 0

4 5
1 2 1 1
1 3 1 1
2 3 1 0
2 4 1 1
3 4 2 1
*/
