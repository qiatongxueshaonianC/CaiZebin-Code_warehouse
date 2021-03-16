#include<bits/stdc++.h>
using namespace std; 
const int maxn=2*1e4+10;
set<string> st;
struct Edge{
	int v1,v2,cost;
	string name;
	Edge(int a,int b,int c,char d[]):v1(a),v2(b),cost(c),name(d){}
/*	bool operator <(const Edge& u)const{
		return (cost>u.cost||cost==u.cost&&st.find(u.name)!=st.end());  //长度相同的情况下机构尽量少 
	}*/
	bool friend operator <(const Edge& u,const Edge& v){  //优先队列中“右端(即v)"是优先的 
		if(u.cost!=v.cost) return u.cost>v.cost;
		return st.find(v.name)!=st.end(); 
	}
}; 
priority_queue<Edge> q;
vector<Edge> ans;
int N,M,father[maxn]; 
int findFather(int a){
	if(father[a]<0)
		return a;
	int temp=findFather(father[a]);
	father[a]=temp;
	return temp;
}
void Solve(){
	fill(father,father+N,-1);
	int edge_num=0,Cost=0;  //可以加快结束循环 
	while(!q.empty()&&edge_num!=N-1){
		Edge e=q.top();
		int fa=findFather(e.v1),fb=findFather(e.v2);
		if(fa>fb)
			swap(fa,fb);
		if(fa!=fb){
			father[fa]+=father[fb];
			father[fb]=fa;
			st.insert(e.name);q.pop();  //这时候出队能体现动态调整
			ans.push_back(e);
			Cost+=e.cost;
			edge_num++;
		}else q.pop();  //要记得出队 
	}
	sort(ans.begin(),ans.end(),[](const Edge& a,const Edge& b){
		return a.name!=b.name?a.name<b.name:a.cost<b.cost;
	});
	printf("%d %d\n",st.size(),Cost);
	for(auto i:ans)
		printf("%d %d %s %d\n",i.v1,i.v2,i.name.c_str(),i.cost); 
}
int main() {
	scanf("%d%d",&N,&M);
	char name[10];
	while(M--){
		int a,b,cost;
		scanf("%d%d%s%d",&a,&b,&name,&cost);
		q.push(Edge(a,b,cost,name));
	}
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
