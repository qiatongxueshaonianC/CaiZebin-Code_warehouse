#include<bits/stdc++.h>
using namespace std; 
const int maxn=510;
struct Edge{
	int c1,c2,cost;
	Edge(int a,int b,int c):c1(a),c2(b),cost(c){}
};
vector<Edge> use,repair;
int N,M,father[maxn],cost[maxn];
bool cont(int a){
	if(a>0) return true;
	return false;
}
int findFather(int a){
	if(father[a]==a)
		return a;
	int temp=findFather(father[a]);
	father[a]=temp;
	return temp; 
} 
int countBlocks(){
	int Root[N+1]={0};
	for(int i=1;i<=N;i++)
		Root[findFather(i)]++;
	return count_if(Root,Root+N+1,cont);
}
int main() {
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++){
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if(d==0)
			repair.push_back(Edge(a,b,c));
		else
			use.push_back(Edge(a,b,c));
	}
	for(int i=1;i<=N;i++){
		iota(father,father+N+1,0);
		for(auto e:use){
			int fa=findFather(e.c1),fb=findFather(e.c2);
			if(fa!=fb&&fa!=i&&fb!=i)
				father[fa]=fb;
		}
		for(auto e:repair){
			int fa=findFather(e.c1),fb=findFather(e.c2);
			if(fa!=fb&&fa!=i&&fb!=i){
				cost[i]+=e.cost;
				father[fa]=fb;
			}
		}
		if(countBlocks()>2)
			cost[i]=INT_MAX;
	} 
	vector<int> ans;
	int idx=max_element(cost,cost+N+1)-cost;
	if(cost[idx]==0)
		puts("0");
	else{
		ans.push_back(idx);
		for(int i=idx+1;i<=N;i++){
			if(cost[i]==cost[idx])
				ans.push_back(i);
		}
		sort(ans.begin(),ans.end());
		for(auto i:ans)
			printf("%s%d",i==*ans.begin()?"":" ",i);	
	}
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
