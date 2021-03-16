#include<bits/stdc++.h>
using namespace std; 
const int maxn=2*1e4+10;
struct Edge{
	int v1,v2,cost;
	string name;
	Edge(int a,int b,int c,char d[]):v1(a),v2(b),cost(c),name(d){}
	bool operator <(const Edge& u)const{
		return cost<u.cost;
	}
}; 
vector<Edge> edges,ans;
set<string> cent_num;
int N,M,father[maxn],Cost;
int findFather(int a){
	if(father[a]<0)
		return a;
	int temp=findFather(father[a]);
	father[a]=temp;
	return temp;
}
void Solve(){
	fill(father,father+N+1,-1);
	for(int i=0;i<edges.size();i++){
		vector<Edge> temp{edges[i]};
		while(edges[i+1].cost==edges[i].cost){
			temp.push_back(edges[i+1]);
			i++;
		}
		sort(temp.begin(),temp.end(),[](const Edge& a,const Edge&b){
				return (cent_num.find(a.name)!=cent_num.end()&&cent_num.find(b.name)==cent_num.end());
		});
		for(Edge e:temp){
			int fa=findFather(e.v1),fb=findFather(e.v2);
			if(fa>fb)
				swap(fa,fb);
			if(fa!=fb){
				father[fa]+=father[fb];
				father[fb]=fa;
				ans.push_back(e);
				cent_num.insert(e.name);
				Cost+=e.cost;
			}	
		}
	}
	printf("%d %d\n",cent_num.size(),Cost);
	sort(ans.begin(),ans.end(),[](const Edge& a,const Edge& b){
		return a.name!=b.name?a.name<b.name:a.cost<b.cost;
	});
	for(auto i:ans)
		printf("%d %d %s %d\n",i.v1,i.v2,i.name.c_str(),i.cost);
}
int main() {
	scanf("%d%d",&N,&M);
	char name[10];
	while(M--){
		int a,b,cost;
		scanf("%d%d%s%d",&a,&b,&name,&cost);
		edges.push_back(Edge(a,b,cost,name));
	}
	sort(edges.begin(),edges.end());
	Solve();
	return 0;
}
/*
6 9
4 3 CBC 32
1 5 HSB 43
1 0 HSB 32
0 2 CTB 28
4 2 CBC 19
2 3 CBC 28
0 4 ABC 28
1 2 ABC 32
3 1 CTB 19
*/
